#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "tableSymboles.h" 
#include <ctype.h>
#define MAX_SYMBOLES 100
#define MAX_TERMINALS 100
#define MAX_REGLES 100
#define TALLE_MAX_ENSEMBLE 100
#define TAILLE_MAX_PILE 100
#define TAILLE_MAX_INPUT 1000

//les structures

typedef struct {
    char* elements[TALLE_MAX_ENSEMBLE];  
    int size;                             
} ensemble_symbole;


typedef struct {
    char* nonTerminal;  
    char* terminal;     
    char* production;   
} entree_tab_analyse;

typedef struct {
    entree_tab_analyse* entree;      
    int numEntrees;                   
    char** terminals;                 
    int numTerminals;
    char** nonTerminals;              
    int numNonTerminals;
    ensemble_symbole* debut;          
    ensemble_symbole* suivant;        
} Table_analyse;

typedef struct {
    char* items[TAILLE_MAX_PILE];  
    int top;                        
} pile_analyse;

//les fonctions de la pile

void init_pile(pile_analyse* pile) {
    pile->top = -1;  // Pile vide
}

void empiler(pile_analyse* pile, const char* item) {
    if (pile->top < TAILLE_MAX_PILE - 1) {
        pile->items[++pile->top] = strdup(item);
    }
}

char* depiler(pile_analyse* pile) {
    if (pile->top >= 0) {
        return pile->items[pile->top--];  // Retourner et décrémenter
    }
    return NULL;
}

//lire le sommet sans le retirer
char* sommet_pile(pile_analyse* pile) {
    if (pile->top >= 0) {
        return pile->items[pile->top];  // Juste lire, sans retirer
    }
    return NULL;
}

//fonctions des ensembles

void initensemble(ensemble_symbole* ensemble) {
    ensemble->size = 0;
}



void ajouter_a_ensemble(ensemble_symbole* ensemble, const char* element) {
    // Vérifier si l'élément existe déjà
    for (int i = 0; i < ensemble->size; i++) {
        if (strcmp(ensemble->elements[i], element) == 0) return;
    }
    // Ajouter l'élément
    ensemble->elements[ensemble->size] = strdup(element);
    ensemble->size++;
}

//init la table d'analyse
Table_analyse* initialiser_table_analyse() {
    Table_analyse* table = (Table_analyse*)malloc(sizeof(Table_analyse));
    table->entree = (entree_tab_analyse*)malloc(MAX_REGLES * sizeof(entree_tab_analyse));
    table->terminals = (char**)malloc(MAX_TERMINALS * sizeof(char*));
    table->nonTerminals = (char**)malloc(MAX_SYMBOLES * sizeof(char*));
    table->debut = (ensemble_symbole*)malloc(MAX_SYMBOLES * sizeof(ensemble_symbole));
    table->suivant = (ensemble_symbole*)malloc(MAX_SYMBOLES * sizeof(ensemble_symbole));
    
    for (int i = 0; i < MAX_SYMBOLES; i++) {
        initensemble(&table->debut[i]);
        initensemble(&table->suivant[i]);
    }
    
    table->numEntrees = 0;
    table->numTerminals = 0;
    table->numNonTerminals = 0;
    return table;
}

//calcul de debuts et suivants 

void DebutSuivant(Table_analyse* table) {

     int idxProgramme = 0;
     int idxListeDecl = 1;
     int idxDecl = 2;
    int idxListeInst = 3;
    int idxInst = 4;
    int idxAffectation = 5;
    int idxLecture = 6;
    int idxAffichage =7;
    int idxExpr =8;
    int idxExprPrime =9;
    int idxTerme =10;
    int idxTermePrime = 11;
    int idxFacteur = 12;
   
    // DEBUT(<programme>)
    ajouter_a_ensemble(&table->debut[idxProgramme], "DEBUT_PROG");
   
    // DEBUT(<ListeDecl>)
    ajouter_a_ensemble(&table->debut[idxListeDecl], "DECLARER");
    ajouter_a_ensemble(&table->debut[idxListeDecl], "ε");

    // DEBUT(<Decl>)
    ajouter_a_ensemble(&table->debut[idxDecl], "DECLARER");
    

     // DEBUT(<ListeInst>)
    ajouter_a_ensemble(&table->debut[idxListeInst], "ID");
     ajouter_a_ensemble(&table->debut[idxListeInst], "AFFICHER");
      ajouter_a_ensemble(&table->debut[idxListeInst], "LIRE");
    ajouter_a_ensemble(&table->debut[idxListeInst], "ε");

     // DEBUT(<Inst>)
    ajouter_a_ensemble(&table->debut[idxInst], "ID");
     ajouter_a_ensemble(&table->debut[idxInst], "AFFICHER");
      ajouter_a_ensemble(&table->debut[idxInst], "LIRE");

       // DEBUT(<Affectation>)
    ajouter_a_ensemble(&table->debut[idxAffectation], "ID");

    // DEBUT(<Affichage>)
    ajouter_a_ensemble(&table->debut[idxAffichage], "AFFICHER");

    // DEBUT(<Lecture>)
    ajouter_a_ensemble(&table->debut[idxLecture], "LIRE");

    // DEBUT(<Expr>)
    ajouter_a_ensemble(&table->debut[idxExpr], "ID");
     ajouter_a_ensemble(&table->debut[idxExpr], "ENTIER_LIT");
      ajouter_a_ensemble(&table->debut[idxExpr], "PAREN_OUV");

// DEBUT(<ExprPrime>) 
       ajouter_a_ensemble(&table->debut[ idxExprPrime], "PLUS");
    ajouter_a_ensemble(&table->debut[ idxExprPrime], "ε");

    // DEBUT(<TermePrime>) 
       ajouter_a_ensemble(&table->debut[ idxTermePrime], "MULT");
    ajouter_a_ensemble(&table->debut[ idxTermePrime], "ε");

    // DEBUT(<Facteur>) = DEBUT(<Terme>) = DEBUT(<Expr>)
    for (int i = 0; i < table->debut[idxExpr].size; i++) {
        ajouter_a_ensemble(&table->debut[idxTerme], table->debut[idxExpr].elements[i]);
        ajouter_a_ensemble(&table->debut[idxFacteur], table->debut[idxExpr].elements[i]);
    }

    
    // SUIVANT 
    ajouter_a_ensemble(&table->suivant[idxProgramme], "$");

    ajouter_a_ensemble(&table->suivant[idxListeDecl], "ID");
    ajouter_a_ensemble(&table->suivant[idxListeDecl], "AFFICHER");
    ajouter_a_ensemble(&table->suivant[idxListeDecl], "LIRE");
    ajouter_a_ensemble(&table->suivant[idxListeDecl], "FIN_PROG");
    

     ajouter_a_ensemble(&table->suivant[idxDecl], "ID");
    ajouter_a_ensemble(&table->suivant[idxDecl], "AFFICHER");
    ajouter_a_ensemble(&table->suivant[idxDecl], "LIRE");
    ajouter_a_ensemble(&table->suivant[idxDecl], "FIN_PROG");
    ajouter_a_ensemble(&table->suivant[idxDecl], "DECLARER");

   ajouter_a_ensemble(&table->suivant[idxListeInst], "FIN_PROG");

    /// SUIVANT(<Inst>) = SUIVANT(<Affectation>) = SUIVANT(<Lecture>) = SUIVANT(<Affichage>)
for (int i = 0; i < table->suivant[idxListeInst].size; i++) {
    ajouter_a_ensemble(&table->suivant[idxInst], table->suivant[idxListeInst].elements[i]);
    ajouter_a_ensemble(&table->suivant[idxAffectation], table->suivant[idxListeInst].elements[i]);
    ajouter_a_ensemble(&table->suivant[idxLecture], table->suivant[idxListeInst].elements[i]);
    ajouter_a_ensemble(&table->suivant[idxAffichage], table->suivant[idxListeInst].elements[i]);
}


     ajouter_a_ensemble(&table->suivant[idxExpr], "POINT_VIRGULE");
    ajouter_a_ensemble(&table->suivant[idxExpr], "PAREN_FERM");

         ajouter_a_ensemble(&table->suivant[idxExprPrime], "POINT_VIRGULE");
    ajouter_a_ensemble(&table->suivant[idxExprPrime], "PAREN_FERM");

         ajouter_a_ensemble(&table->suivant[idxTerme], "POINT_VIRGULE");
    ajouter_a_ensemble(&table->suivant[idxTerme], "PAREN_FERM");
     ajouter_a_ensemble(&table->suivant[idxTerme], "PLUS");

      ajouter_a_ensemble(&table->suivant[idxTermePrime], "POINT_VIRGULE");
    ajouter_a_ensemble(&table->suivant[idxTermePrime], "PAREN_FERM");
     ajouter_a_ensemble(&table->suivant[idxTermePrime], "PLUS");

      ajouter_a_ensemble(&table->suivant[idxFacteur], "POINT_VIRGULE");
    ajouter_a_ensemble(&table->suivant[idxFacteur], "PAREN_FERM");
     ajouter_a_ensemble(&table->suivant[idxFacteur], "PLUS");
       ajouter_a_ensemble(&table->suivant[idxFacteur], "MULT");

}

//ajouter une entree

void ajouter_entree_table_analyse(Table_analyse* table, const char* nonTerminal, const char* terminal, const char* production) {
    entree_tab_analyse entry;
    entry.nonTerminal = strdup(nonTerminal);
    entry.terminal = strdup(terminal);
    entry.production = strdup(production);
    table->entree[table->numEntrees++] = entry;
}

//creation de la table d'analyse
void creer_table_analyse(Table_analyse* table) {

    const char* nonTerminals[] = {"<Programme>", "<ListeDecl>", "<Decl>", "<ListeInst>", "<Inst>", "<Affectation>", "<Lecture>", "<Affichage>","<Expr>","<ExprPrime>", "<Terme>", "<TermePrime>", "<Facteur>"};
    for (int i = 0; i < 13; i++) {
        table->nonTerminals[i] = strdup(nonTerminals[i]);
    }
    table->numNonTerminals = 13;

    const char* terminals[] = {"DEBUT_PROG", "FIN_PROG", "DECLARER", "DEUX_POINTS", "ENTIER", "POINT_VIRGULE", 
"ID", "AFFECT", "LIRE", "PAREN_OUV", "PAREN_FERM", "AFFICHER", 
"PLUS", "MULT", "ENTIER_LIT", "$"};
    for (int i = 0; i < 16; i++) {
        table->terminals[i] = strdup(terminals[i]);
    }
    table->numTerminals = 16;

    DebutSuivant(table);

    // ========== RÈGLES POUR <Programme> ==========
    // <Programme> ::= DEBUT_PROG <ListeDecl> <ListeInst> FIN_PROG
    // DEBUT(<Programme>) = {DEBUT_PROG}
    ajouter_entree_table_analyse(table, "<Programme>", "DEBUT_PROG", "DEBUT_PROG <ListeDecl> <ListeInst> FIN_PROG");
    
    // ========== RÈGLES POUR <ListeDecl> ==========
    // <ListeDecl> ::= <Decl> <ListeDecl>
    // DEBUT(<ListeDecl>) = {DECLARER, ε}
    ajouter_entree_table_analyse(table, "<ListeDecl>", "DECLARER", "<Decl> <ListeDecl>");
    
    // <ListeDecl> ::= ε
    // Pour ε : on utilise SUIVANT(<ListeDecl>) = {ID, AFFICHER, LIRE, FIN_PROG}
    ajouter_entree_table_analyse(table, "<ListeDecl>", "ID", "ε");
    ajouter_entree_table_analyse(table, "<ListeDecl>", "AFFICHER", "ε");
    ajouter_entree_table_analyse(table, "<ListeDecl>", "LIRE", "ε");
    ajouter_entree_table_analyse(table, "<ListeDecl>", "FIN_PROG", "ε");

    // ========== RÈGLES POUR <Decl> ==========
    // <Decl> ::= DECLARER ID DEUX_POINTS ENTIER POINT_VIRGULE
    // DEBUT(<Decl>) = {DECLARER}
    ajouter_entree_table_analyse(table, "<Decl>", "DECLARER", "DECLARER ID DEUX_POINTS ENTIER POINT_VIRGULE");

    // ========== RÈGLES POUR <ListeInst> ==========
    // <ListeInst> ::= <Inst> <ListeInst>
    // DEBUT(<ListeInst>) = {ID, LIRE, AFFICHER, ε}
    ajouter_entree_table_analyse(table, "<ListeInst>", "ID", "<Inst> <ListeInst>");
    ajouter_entree_table_analyse(table, "<ListeInst>", "LIRE", "<Inst> <ListeInst>");
    ajouter_entree_table_analyse(table, "<ListeInst>", "AFFICHER", "<Inst> <ListeInst>");
    
    // <ListeInst> ::= ε
    // SUIVANT(<ListeInst>) = {FIN_PROG}
    ajouter_entree_table_analyse(table, "<ListeInst>", "FIN_PROG", "ε");

    // ========== RÈGLES POUR <Inst> ==========
    // <Inst> ::= <Affectation> | <Lecture> | <Affichage>
    // DEBUT(<Inst>) = {ID, LIRE, AFFICHER}
    ajouter_entree_table_analyse(table, "<Inst>", "ID", "<Affectation>");
    ajouter_entree_table_analyse(table, "<Inst>", "LIRE", "<Lecture>");
    ajouter_entree_table_analyse(table, "<Inst>", "AFFICHER", "<Affichage>");

    // ========== RÈGLES POUR <Affectation> ==========
    // <Affectation> ::= ID AFFECT <Expr> POINT_VIRGULE
    // DEBUT(<Affectation>) = {ID}
    ajouter_entree_table_analyse(table, "<Affectation>", "ID", "ID AFFECT <Expr> POINT_VIRGULE");

    // ========== RÈGLES POUR <Lecture> ==========
    // <Lecture> ::= LIRE PAREN_OUV ID PAREN_FERM POINT_VIRGULE
    // DEBUT(<Lecture>) = {LIRE}
    ajouter_entree_table_analyse(table, "<Lecture>", "LIRE", "LIRE PAREN_OUV ID PAREN_FERM POINT_VIRGULE");

    // ========== RÈGLES POUR <Affichage> ==========
    // <Affichage> ::= AFFICHER PAREN_OUV <Expr> PAREN_FERM POINT_VIRGULE
    // DEBUT(<Affichage>) = {AFFICHER}
    ajouter_entree_table_analyse(table, "<Affichage>", "AFFICHER", "AFFICHER PAREN_OUV <Expr> PAREN_FERM POINT_VIRGULE");

    // ========== RÈGLES POUR <Expr> ==========
    // <Expr> ::= <Terme> <ExprPrime>
    // DEBUT(<Expr>) = {ID, ENTIER_LIT, PAREN_OUV}
    ajouter_entree_table_analyse(table, "<Expr>", "ID", "<Terme> <ExprPrime>");
    ajouter_entree_table_analyse(table, "<Expr>", "ENTIER_LIT", "<Terme> <ExprPrime>");
    ajouter_entree_table_analyse(table, "<Expr>", "PAREN_OUV", "<Terme> <ExprPrime>");

    // ========== RÈGLES POUR <ExprPrime> ==========
    // <ExprPrime> ::= PLUS <Terme> <ExprPrime>
    // DEBUT(<ExprPrime>) = {PLUS, ε}
    ajouter_entree_table_analyse(table, "<ExprPrime>", "PLUS", "PLUS <Terme> <ExprPrime>");
    
    // <ExprPrime> ::= ε
    // SUIVANT(<ExprPrime>) = {POINT_VIRGULE, PAREN_FERM}
    ajouter_entree_table_analyse(table, "<ExprPrime>", "POINT_VIRGULE", "ε");
    ajouter_entree_table_analyse(table, "<ExprPrime>", "PAREN_FERM", "ε");

    // ========== RÈGLES POUR <Terme> ==========
    // <Terme> ::= <Facteur> <TermePrime>
    // DEBUT(<Terme>) = {ID, ENTIER_LIT, PAREN_OUV}
    ajouter_entree_table_analyse(table, "<Terme>", "ID", "<Facteur> <TermePrime>");
    ajouter_entree_table_analyse(table, "<Terme>", "ENTIER_LIT", "<Facteur> <TermePrime>");
    ajouter_entree_table_analyse(table, "<Terme>", "PAREN_OUV", "<Facteur> <TermePrime>");

    // ========== RÈGLES POUR <TermePrime> ==========
    // <TermePrime> ::= MULT <Facteur> <TermePrime>
    // DEBUT(<TermePrime>) = {MULT, ε}
    ajouter_entree_table_analyse(table, "<TermePrime>", "MULT", "MULT <Facteur> <TermePrime>");
    
    // <TermePrime> ::= ε
    // SUIVANT(<TermePrime>) = {PLUS, POINT_VIRGULE, PAREN_FERM}
    ajouter_entree_table_analyse(table, "<TermePrime>", "PLUS", "ε");
    ajouter_entree_table_analyse(table, "<TermePrime>", "POINT_VIRGULE", "ε");
    ajouter_entree_table_analyse(table, "<TermePrime>", "PAREN_FERM", "ε");

    // ========== RÈGLES POUR <Facteur> ==========
    // <Facteur> ::= ID | ENTIER_LIT | PAREN_OUV <Expr> PAREN_FERM
    // DEBUT(<Facteur>) = {ID, ENTIER_LIT, PAREN_OUV}
    ajouter_entree_table_analyse(table, "<Facteur>", "ID", "ID");
    ajouter_entree_table_analyse(table, "<Facteur>", "ENTIER_LIT", "ENTIER_LIT");
    ajouter_entree_table_analyse(table, "<Facteur>", "PAREN_OUV", "PAREN_OUV <Expr> PAREN_FERM");
}

void afficher_ensemble(const char* nom_ensemble, ensemble_symbole* ensemble) {
    printf("%s: { ", nom_ensemble);
    for (int i = 0; i < ensemble->size; i++) {
        printf("%s", ensemble->elements[i]);
        if (i < ensemble->size - 1) printf(", ");
    }
    printf(" }\n");
}

void afficher_debuts(Table_analyse* table) {
    printf("\nEnsembles DEBUT:\n");
    for (int i = 0; i < table->numNonTerminals; i++) {
        afficher_ensemble(table->nonTerminals[i], &table->debut[i]);
    }
}

void afficher_suivants(Table_analyse* table) {
    printf("\nEnsembles SUIVANT:\n");
    for (int i = 0; i < table->numNonTerminals; i++) {
        afficher_ensemble(table->nonTerminals[i], &table->suivant[i]);
    }
}

void afficher_table_analyse(Table_analyse* table) {
    printf("\nTable d'analyse syntaxique:\n\n");
    // En-tête
    printf("%-12s", "");
    for (int i = 0; i < table->numTerminals; i++) {
        printf("%-12s", table->terminals[i]);
    }
    printf("\n");
    // Ligne de séparation
    for (int i = 0; i < (table->numTerminals + 1) * 12; i++) {
        printf("-");
    }
    printf("\n");
    // Corps de la table
    for (int i = 0; i < table->numNonTerminals; i++) {
        printf("%-12s", table->nonTerminals[i]);
        
        for (int j = 0; j < table->numTerminals; j++) {
            bool found = false;
            for (int k = 0; k < table->numEntrees; k++) {
                if (strcmp(table->entree[k].nonTerminal, table->nonTerminals[i]) == 0 &&
                    strcmp(table->entree[k].terminal, table->terminals[j]) == 0) {
                    printf("%-50s", table->entree[k].production);
                    found = true;
                    break;
                }
            }
            if (!found) {
                printf("%-12s", "erreur");
            }
        }
        printf("\n");
    }
}


void liberer_table_analyse(Table_analyse* table) {
    for (int i = 0; i < table->numEntrees; i++) {
        free(table->entree[i].nonTerminal);
        free(table->entree[i].terminal);
        free(table->entree[i].production);
    }
    for (int i = 0; i < table->numTerminals; i++) {
        free(table->terminals[i]);
    }
    for (int i = 0; i < table->numNonTerminals; i++) {
        free(table->nonTerminals[i]);
        for (int j = 0; j < table->debut[i].size; j++) {
            free(table->debut[i].elements[j]);
        }
        for (int j = 0; j < table->suivant[i].size; j++) {
            free(table->suivant[i].elements[j]);
        }
    }
    free(table->entree);
    free(table->terminals);
    free(table->nonTerminals);
    free(table->debut);
    free(table->suivant);
    free(table);
}
const char* lire_table_analyse(Table_analyse* table, const char* nonTerminal, const char* terminal) {
    // Parcours des entrées de la table
    for (int i = 0; i < table->numEntrees; i++) {
        // Si une entrée correspond à la combinaison non-terminal/terminal
        if (strcmp(table->entree[i].nonTerminal, nonTerminal) == 0 &&
            strcmp(table->entree[i].terminal, terminal) == 0) {
            // Retourne la production associée
            return table->entree[i].production;
        }
    }
    // Si aucune entrée ne correspond, retourne "erreur"
    return "erreur";
}

typedef struct {
    char** tokens;
    int nb_token;
} tableau_tokens;

bool identifiant_valide(const char* id) {
    if (!id || strlen(id) == 0) return false;
    
    if (!isalpha(id[0]) && id[0] != '_') return false;
    
    for (int i = 1; id[i] != '\0'; i++) {
        if (!isalnum(id[i]) && id[i] != '_') return false;
    }
    
    const char* mots_cles[] = {
    "DEBUT_PROG", "FIN_PROG", "DECLARER", "ENTIER", "REEL", "CHAR", "BOOL",
    "LIRE", "AFFICHER", "SI", "ALORS", "SINON", "SINON_SI", "FIN_SI",
    "POUR", "FAIRE", "FIN_POUR", "TANT_QUE", "FIN_TQ", "REPETER", "JUSQU_A",
    "ET", "OU", "NON", "VRAI", "FAUX", "TAB", "DE"
};
    int nb_mots_cles = sizeof(mots_cles) / sizeof(mots_cles[0]);
    for (int i = 0; i < nb_mots_cles; i++) {
        if (strcasecmp(id, mots_cles[i]) == 0) return false;
    }
    return true;
}

tableau_tokens decouper_input(const char* input) {
    tableau_tokens result = {malloc(TAILLE_MAX_INPUT * sizeof(char*)), 0};
    char* copie_input = strdup(input);
    char* token = strtok(copie_input, " \t\n");
    
    while (token != NULL) {
        // Conversion des symboles vers leurs noms de tokens
        if (strcmp(token, ":") == 0) {
            result.tokens[result.nb_token++] = strdup("DEUX_POINTS");
        }
        else if (strcmp(token, ":=") == 0) {
            result.tokens[result.nb_token++] = strdup("AFFECT");
        }
        else if (strcmp(token, ";") == 0) {
            result.tokens[result.nb_token++] = strdup("POINT_VIRGULE");
        }
        else if (strcmp(token, "(") == 0) {
            result.tokens[result.nb_token++] = strdup("PAREN_OUV");
        }
        else if (strcmp(token, ")") == 0) {
            result.tokens[result.nb_token++] = strdup("PAREN_FERM");
        }
        else if (strcmp(token, "+") == 0) {
            result.tokens[result.nb_token++] = strdup("PLUS");
        }
        else if (strcmp(token, "*") == 0) {
            result.tokens[result.nb_token++] = strdup("MULT");
        }
        // Vérifier si c'est un entier littéral (tous les caractères sont des chiffres)
        else if (strlen(token) > 0 && isdigit(token[0])) {
            bool est_entier = true;
            for (int i = 0; token[i] != '\0'; i++) {
                if (!isdigit(token[i])) {
                    est_entier = false;
                    break;
                }
            }
            if (est_entier) {
                result.tokens[result.nb_token++] = strdup("ENTIER_LIT");
            } else {
                result.tokens[result.nb_token++] = strdup(token);
            }
        }
        // Vérifier si c'est un identifiant valide
        else if (identifiant_valide(token)) {
            result.tokens[result.nb_token++] = strdup("ID");
        }
        // Sinon, garder le token tel quel (mots-clés, etc.)
        else {
            result.tokens[result.nb_token++] = strdup(token);
        }
        
        token = strtok(NULL, " \t\n");
    }
     
    free(copie_input);
    return result;
}
// Fonction de reconnaissance syntaxique LL(1)

bool reconnaissance(Table_analyse* table, const char* input, SymbolTable* symTable) {
    // 1. Déclarer et initialiser la pile
    pile_analyse pile;
    init_pile(&pile);
    
    // 2. Empiler le symbole de fin '$' puis l'axiome '<Programme>'
    empiler(&pile, "$");
    empiler(&pile, "<Programme>");
    
    // 3. Découper l'input en tokens
    tableau_tokens tokens = decouper_input(input);
    
    // 4. Ajouter '$' à la fin de l'input
    tokens.tokens[tokens.nb_token] = strdup("$");
    tokens.nb_token++;
    
    // 5. Index du token courant
    int index_token = 0;
    
    // 6. Boucle principale d'analyse
    while (true) {
        // 6.1 Récupérer le sommet de la pile
        char* sommet = sommet_pile(&pile);
        
        // 6.2 Récupérer le token courant
        char* token_courant = tokens.tokens[index_token];
        
        printf("Pile: %s | Token: %s\n", sommet, token_courant);  // Debug
        
        // 6.3 CAS 1 : Succès - Pile vide et fin de l'input
        if (strcmp(sommet, "$") == 0 && strcmp(token_courant, "$") == 0) {
            printf("\n✓ Analyse syntaxique réussie !\n");
            
            // Libérer la mémoire des tokens
            for (int i = 0; i < tokens.nb_token; i++) {
                free(tokens.tokens[i]);
            }
            free(tokens.tokens);
            
            return true;
        }
        
        // 6.4 CAS 2 : Sommet est un TERMINAL
        if (sommet[0] != '<') {  // Les non-terminaux commencent par '<'
            if (strcmp(sommet, token_courant) == 0) {
                // Terminal correspond : on dépile et on avance dans l'input
                depiler(&pile);
                index_token++;
            } 
            else if (strcmp(sommet, "ε") == 0) {
                // Production epsilon : on dépile sans consommer de token
                depiler(&pile);
            }
            else {
                // Erreur : terminal attendu ne correspond pas
                printf("\n✗ Erreur syntaxique à la ligne %d\n", 1);
                printf("Attendu : '%s', Trouvé : '%s'\n", sommet, token_courant);
                
                // Libérer la mémoire
                for (int i = 0; i < tokens.nb_token; i++) {
                    free(tokens.tokens[i]);
                }
                free(tokens.tokens);
                
                return false;
            }
        }
        // 6.5 CAS 3 : Sommet est un NON-TERMINAL
        else {
            // Consulter la table d'analyse
            const char* production = lire_table_analyse(table, sommet, token_courant);
            
            if (strcmp(production, "erreur") == 0) {
                // Erreur : pas de production dans la table
                printf("\n✗ Erreur syntaxique à la ligne %d\n", 1);
                printf("Symbole inattendu '%s' pour le non-terminal '%s'\n", 
                       token_courant, sommet);
                
                // Libérer la mémoire
                for (int i = 0; i < tokens.nb_token; i++) {
                    free(tokens.tokens[i]);
                }
                free(tokens.tokens);
                
                return false;
            }
            
            // Dépiler le non-terminal
            depiler(&pile);
            
            // Si production n'est pas epsilon, empiler les symboles en ordre inverse
            if (strcmp(production, "ε") != 0) {
                // Découper la production en symboles
                char* copie_prod = strdup(production);
                char* symboles[50];  // Tableau temporaire pour les symboles
                int nb_symboles = 0;
                
                // Tokeniser la production
                char* symbole = strtok(copie_prod, " ");
                while (symbole != NULL) {
                    symboles[nb_symboles++] = strdup(symbole);
                    symbole = strtok(NULL, " ");
                }
                
                // Empiler dans l'ordre inverse
                for (int i = nb_symboles - 1; i >= 0; i--) {
                    empiler(&pile, symboles[i]);
                    free(symboles[i]);
                }
                
                free(copie_prod);
            }
            // Si production = ε, on ne fait rien (déjà dépilé)
        }
    }
    
    // Ne devrait jamais arriver ici
    return false;
}
int main() {
    printf("========================================\n");
    printf("  ANALYSEUR SYNTAXIQUE LL(1) - SIMPL\n");
    printf("========================================\n\n");
    
    // 1. Initialiser la table d'analyse
    printf("⏳ Initialisation de la table d'analyse...\n");
    Table_analyse* table = initialiser_table_analyse();
    creer_table_analyse(table);
    printf("✓ Table d'analyse créée avec succès !\n\n");
    
    // 2. Afficher les ensembles DEBUT
    afficher_debuts(table);
    
    // 3. Afficher les ensembles SUIVANT
    afficher_suivants(table);
    
    // 4. Afficher la table d'analyse
    afficher_table_analyse(table);
    
    // 5. Initialiser la table des symboles
    SymbolTable* symTable = creerTableSymboles();
    
    printf("\n========================================\n");
    printf("  TESTS DE PROGRAMMES\n");
    printf("========================================\n\n");
    
    // ===== TEST 1 : Programme correct simple =====
    printf("--- TEST 1 : Programme correct simple ---\n");
    const char* test1 = "DEBUT_PROG DECLARER x : ENTIER ; LIRE ( x ) ; AFFICHER ( x ) ; FIN_PROG";
    printf("Programme : %s\n\n", test1);
    bool resultat1 = reconnaissance(table, test1, symTable);
    printf("\nRésultat : %s\n\n", resultat1 ? "✓ ACCEPTÉ" : "✗ REJETÉ");
    
    // ===== TEST 2 : Programme avec expression =====
    printf("--- TEST 2 : Programme avec expression ---\n");
    const char* test2 = "DEBUT_PROG DECLARER y : ENTIER ; DECLARER z : ENTIER ; y := 5 + 3 * 2 ; AFFICHER ( y ) ; FIN_PROG";
    printf("Programme : %s\n\n", test2);
    bool resultat2 = reconnaissance(table, test2, symTable);
    printf("\nRésultat : %s\n\n", resultat2 ? "✓ ACCEPTÉ" : "✗ REJETÉ");
    
    // ===== TEST 3 : Programme sans déclarations =====
    printf("--- TEST 3 : Programme sans déclarations ---\n");
    const char* test3 = "DEBUT_PROG LIRE ( a ) ; AFFICHER ( a ) ; FIN_PROG";
    printf("Programme : %s\n\n", test3);
    bool resultat3 = reconnaissance(table, test3, symTable);
    printf("\nRésultat : %s\n\n", resultat3 ? "✓ ACCEPTÉ" : "✗ REJETÉ");
    
    // ===== TEST 4 : Programme avec parenthèses dans expression =====
    printf("--- TEST 4 : Expression avec parenthèses ---\n");
    const char* test4 = "DEBUT_PROG DECLARER res : ENTIER ; res := ( 10 + 5 ) * 2 ; FIN_PROG";
    printf("Programme : %s\n\n", test4);
    bool resultat4 = reconnaissance(table, test4, symTable);
    printf("\nRésultat : %s\n\n", resultat4 ? "✓ ACCEPTÉ" : "✗ REJETÉ");
    
    // ===== TEST 5 : Programme INVALIDE (manque point-virgule) =====
    printf("--- TEST 5 : Programme INVALIDE (manque ;) ---\n");
    const char* test5 = "DEBUT_PROG DECLARER x : ENTIER LIRE ( x ) ; FIN_PROG";
    printf("Programme : %s\n\n", test5);
    bool resultat5 = reconnaissance(table, test5, symTable);
    printf("\nRésultat : %s\n\n", resultat5 ? "✓ ACCEPTÉ" : "✗ REJETÉ");
    
    // ===== TEST 6 : Programme INVALIDE (manque FIN_PROG) =====
    printf("--- TEST 6 : Programme INVALIDE (manque FIN_PROG) ---\n");
    const char* test6 = "DEBUT_PROG DECLARER x : ENTIER ;";
    printf("Programme : %s\n\n", test6);
    bool resultat6 = reconnaissance(table, test6, symTable);
    printf("\nRésultat : %s\n\n", resultat6 ? "✓ ACCEPTÉ" : "✗ REJETÉ");
    
    // ===== TEST 7 : Programme complexe correct =====
    printf("--- TEST 7 : Programme complexe ---\n");
    const char* test7 = "DEBUT_PROG DECLARER a : ENTIER ; DECLARER b : ENTIER ; DECLARER c : ENTIER ; LIRE ( a ) ; LIRE ( b ) ; c := a + b * 2 ; AFFICHER ( c ) ; FIN_PROG";
    printf("Programme : %s\n\n", test7);
    bool resultat7 = reconnaissance(table, test7, symTable);
    printf("\nRésultat : %s\n\n", resultat7 ? "✓ ACCEPTÉ" : "✗ REJETÉ");
    
    // ===== TEST 8 : Expression complexe avec parenthèses imbriquées =====
    printf("--- TEST 8 : Parenthèses imbriquées ---\n");
    const char* test8 = "DEBUT_PROG DECLARER x : ENTIER ; x := ( ( 5 + 3 ) * 2 ) + 1 ; FIN_PROG";
    printf("Programme : %s\n\n", test8);
    bool resultat8 = reconnaissance(table, test8, symTable);
    printf("\nRésultat : %s\n\n", resultat8 ? "✓ ACCEPTÉ" : "✗ REJETÉ");
    
    // ===== RÉSUMÉ =====
    printf("\n========================================\n");
    printf("  RÉSUMÉ DES TESTS\n");
    printf("========================================\n");
    int total = 8;
    int passes = resultat1 + resultat2 + resultat3 + resultat4 + resultat7 + resultat8;
    int fails = !resultat5 + !resultat6;  // Tests 5 et 6 doivent échouer
    
    printf("Tests corrects acceptés : %d/6\n", passes);
    printf("Tests invalides rejetés : %d/2\n", fails);
    printf("Score total : %d/%d\n", passes + fails, total);
    
    if (passes == 6 && fails == 2) {
        printf("\n🎉 PARFAIT ! Tous les tests passent !\n");
    }
    
    // 6. Libérer la mémoire
    printf("\n⏳ Libération de la mémoire...\n");
    liberer_table_analyse(table);
    libererTableSymboles(symTable);
    printf("✓ Mémoire libérée !\n");
    
    printf("\n========================================\n");
    printf("  FIN DE L'ANALYSE\n");
    printf("========================================\n");
    
    return 0;
}