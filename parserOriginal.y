%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "symbol_table.h"
#include "quadruplet.h"
#include "stack.h"

extern int yylex();
extern FILE* yyin;
extern int line_number;
extern int column_number;

void yyerror(const char* s);

/* ==================== VARIABLE GLOBALE POUR TYPES ==================== */
char current_decl_type[20];

%}

/* ==================== UNION AMÉLIORÉE ==================== */
%union {
    int entier;
    float reel;
    char* chaine;
    char caractere;
    int val_bool;
    
    struct {
        char* addr;
        char* type;
    } expr_info;
}

/* ==================== TOKENS ==================== */
%token MC_DEBUT_PROG MC_FIN_PROG MC_DECLARER MC_TAB MC_DE
%token MC_ENTIER MC_REEL MC_CHAR MC_BOOL
%token MC_LIRE MC_AFFICHER
%token MC_SI MC_ALORS MC_SINON MC_SINON_SI MC_FIN_SI
%token MC_POUR MC_FAIRE MC_FIN_POUR
%token MC_TANT_QUE MC_FIN_TQ MC_REPETER MC_JUSQU_A
%token OP_ET OP_OU OP_NON
%token BOOL_VRAI BOOL_FAUX

%token OP_AFFECTATION OP_PLUS OP_MOINS OP_MULT OP_DIV OP_MOD OP_PUISS
%token OP_EGAL OP_DIFF OP_INF OP_INF_EGAL OP_SUP OP_SUP_EGAL

%token SEPARATEUR DEUX_POINTS VIRGULE
%token PAR_OUV PAR_FERM CROCH_OUV CROCH_FERM ACC_OUV ACC_FERM

%token <entier> CONST_ENTIER
%token <reel> CONST_REEL
%token <caractere> CONST_CHAR
%token <chaine> CONST_STRING IDENTIFICATEUR

/* ==================== PRIORITÉS ==================== */
%left OP_OU
%left OP_ET
%left OP_EGAL OP_DIFF
%left OP_INF OP_INF_EGAL OP_SUP OP_SUP_EGAL
%left OP_PLUS OP_MOINS
%left OP_MULT OP_DIV OP_MOD
%right OP_PUISS
%right OP_NON

/* ==================== TYPES DES NON-TERMINAUX ==================== */
%type <expr_info> expression
%type <expr_info> bool_expr
%type <chaine> type

%start programme

%%

/* ==================== PROGRAMME ==================== */
programme:
    MC_DEBUT_PROG {
        printf("[LOG] Début du programme\n");
    } declarations instructions MC_FIN_PROG {
        printf("[LOG] Fin du programme\n");
        print_quadruplets();
    }
;

/* ==================== DÉCLARATIONS ==================== */
declarations:
    /* vide */
    | declarations declaration
;

declaration:
    MC_DECLARER liste_variables DEUX_POINTS type SEPARATEUR {
        for(int i = 0; i < temp_var_count; i++) {
            add_to_symbol_table_checked(temp_var_names[i], $4, 0, 0);
            free(temp_var_names[i]);
        }
        temp_var_count = 0;
        printf("[LOG] Déclaration de variable(s) de type %s\n", $4);
    }
    | MC_DECLARER IDENTIFICATEUR CROCH_OUV CONST_ENTIER CROCH_FERM DEUX_POINTS MC_TAB MC_DE type SEPARATEUR {
        if(add_to_symbol_table_checked($2, $9, 1, $4) == 0) {
            printf("[LOG] Déclaration tableau: %s[%d] de type %s\n", $2, $4, $9);
        }
    }
;

liste_variables:
    IDENTIFICATEUR {
        temp_var_names[temp_var_count++] = strdup($1);
    }
    | liste_variables VIRGULE IDENTIFICATEUR {
        temp_var_names[temp_var_count++] = strdup($3);
    }
;

type:
    MC_ENTIER { $$ = "ENTIER"; }
    | MC_REEL {  $$ = "REEL"; }
    | MC_CHAR {  $$ = "CHAR"; }
    | MC_BOOL {  $$ = "BOOL"; }
;

/* ==================== INSTRUCTIONS ==================== */
instructions:
    /* vide */
    | instructions instruction
;

instruction:
    affectation
    | lecture
    | affichage
    | condition
    | boucle_pour
    | boucle_tant_que
;

/* ==================== AFFECTATION ==================== */
affectation:
    IDENTIFICATEUR OP_AFFECTATION expression SEPARATEUR {
        if(!is_declared($1)) {
            YYABORT;
        }
        
        char* var_type = strdup(get_type($1));
        printf("DEBUG: Variable '%s' a le type '%s' (adresse %p)\n", $1, var_type, (void*)var_type);
        printf("DEBUG: Expression a le type '%s' (adresse %p)\n", $3.type, (void*)$3.type);
        printf("DEBUG: strcmp('%s', '%s') = %d\n", var_type, $3.type, strcmp(var_type, $3.type));
        
        if(!types_compatibles(var_type, $3.type)) {
            char error[200];
            sprintf(error, "Type incompatible : affectation de %s à %s", 
                    $3.type, var_type);
            yyerror(error);
            YYABORT;
        }
        
        insererQuadruplet(":=", $3.addr, "", $1);
        mark_initialized($1);
        
        printf("[SEMANTIQUE] Affectation: %s := %s (type %s)\n", 
               $1, $3.addr, $3.type);
    }
    
    | IDENTIFICATEUR CROCH_OUV expression CROCH_FERM OP_AFFECTATION expression SEPARATEUR {
        if(!is_declared($1)) {
            YYABORT;
        }
        
        SymbolEntry* sym = find_symbol($1);
        if(!sym->is_array) {
            char error[200];
            sprintf(error, "'%s' n'est pas un tableau", $1);
            yyerror(error);
            YYABORT;
        }
        
        if(strcmp($3.type, "ENTIER") != 0) {
            yyerror("L'indice d'un tableau doit être de type ENTIER");
            YYABORT;
        }
        
        char* array_type = get_type($1);
        if(!types_compatibles(array_type, $6.type)) {
            char error[200];
            sprintf(error, "Type incompatible pour le tableau '%s'", $1);
            yyerror(error);
            YYABORT;
        }
        
        char* temp = new_temp();
        insererQuadruplet("+", $1, $3.addr, temp);
        insererQuadruplet("[]=", $6.addr, "", temp);
        
        printf("[SEMANTIQUE] Affectation tableau: %s[%s] := %s\n", 
               $1, $3.addr, $6.addr);
    }
;

/* ==================== LECTURE ==================== */
lecture:
    MC_LIRE PAR_OUV IDENTIFICATEUR PAR_FERM SEPARATEUR {
        if(!is_declared($3)) {
            YYABORT;
        }
        
        insererQuadruplet("READ", "", "", $3);
        mark_initialized($3);
        
        printf("[LOG] Lecture: LIRE(%s)\n", $3);
    }
    
    | MC_LIRE PAR_OUV IDENTIFICATEUR CROCH_OUV expression CROCH_FERM PAR_FERM SEPARATEUR {
        if(!is_declared($3)) {
            YYABORT;
        }
        
        SymbolEntry* sym = find_symbol($3);
        if(!sym->is_array) {
            char error[200];
            sprintf(error, "'%s' n'est pas un tableau", $3);
            yyerror(error);
            YYABORT;
        }
        
        if(strcmp($5.type, "ENTIER") != 0) {
            yyerror("L'indice d'un tableau doit être de type ENTIER");
            YYABORT;
        }
        
        char* temp = new_temp();
        insererQuadruplet("+", $3, $5.addr, temp);
        insererQuadruplet("READ", "", "", temp);
        
        printf("[LOG] Lecture tableau: LIRE(%s[%s])\n", $3, $5.addr);
    }
;

/* ==================== AFFICHAGE ==================== */
affichage:
    MC_AFFICHER PAR_OUV expression PAR_FERM SEPARATEUR {
        insererQuadruplet("WRITE", $3.addr, "", "");
        printf("[LOG] Affichage de %s (type %s)\n", $3.addr, $3.type);
    }
    | MC_AFFICHER PAR_OUV CONST_STRING PAR_FERM SEPARATEUR {
        insererQuadruplet("WRITE", $3, "", "");
        printf("[LOG] Affichage de chaîne: %s\n", $3);
    }
;

/* ==================== CONDITION SI ==================== */
condition:
    MC_SI PAR_OUV bool_expr PAR_FERM {
        if(strcmp($3.type, "BOOL") != 0) {
            yyerror("La condition doit être de type BOOL");
            YYABORT;
        }
        
        char* label_else = new_label();
        char* label_fin = new_label();
        
        insererQuadruplet("BZ", $3.addr, "", label_else);
        
        push_label(label_fin);
        push_label(label_else);
        
    } MC_ALORS bloc_instructions parties_sinon MC_FIN_SI {
        char* label_fin = label_stack.labels[label_stack.top - 1];
        insererQuadruplet("", label_fin, "", "");
        
        pop_label();
        pop_label();
    }
;

parties_sinon:
    /* vide */ {
        char* label_else = peek_label();
        insererQuadruplet("", label_else, "", "");
    }
    
    | MC_SINON {
        char* label_fin = label_stack.labels[label_stack.top - 1];
        insererQuadruplet("BR", "", "", label_fin);
        
        char* label_else = peek_label();
        insererQuadruplet("", label_else, "", "");
        
    } bloc_instructions
;

/* ==================== BOUCLE POUR ==================== */
boucle_pour:
    MC_POUR PAR_OUV affectation SEPARATEUR {
        char* label_test = new_label();
        insererQuadruplet("", label_test, "", "");
        push_label(label_test);
        
    } bool_expr SEPARATEUR {
        if(strcmp($6.type, "BOOL") != 0) {
            yyerror("La condition de POUR doit être de type BOOL");
            YYABORT;
        }
        
        char* label_fin = new_label();
        char* label_corps = new_label();
        
        insererQuadruplet("BZ", $6.addr, "", label_fin);
        insererQuadruplet("BR", "", "", label_corps);
        
        char* label_incr = new_label();
        insererQuadruplet("", label_incr, "", "");
        
        push_label(label_incr);
        push_label(label_fin);
        push_label(label_corps);
        
    } affectation PAR_FERM {
        char* label_test = label_stack.labels[label_stack.top - 3];
        insererQuadruplet("BR", "", "", label_test);
        
        char* label_corps = pop_label();
        insererQuadruplet("", label_corps, "", "");
        
    } MC_FAIRE bloc_instructions MC_FIN_POUR {
        char* label_incr = label_stack.labels[label_stack.top - 1];
        insererQuadruplet("BR", "", "", label_incr);
        
        char* label_fin = pop_label();
        insererQuadruplet("", label_fin, "", "");
        
        pop_label();
        pop_label();
    }
;

/* ==================== BOUCLE TANT_QUE ==================== */
boucle_tant_que:
    MC_TANT_QUE {
        char* label_test = new_label();
        insererQuadruplet("", label_test, "", "");
        push_label(label_test);
        
    } PAR_OUV bool_expr PAR_FERM {
        if(strcmp($4.type, "BOOL") != 0) {
            yyerror("La condition de TANT_QUE doit être BOOL");
            YYABORT;
        }
        
        char* label_fin = new_label();
        insererQuadruplet("BZ", $4.addr, "", label_fin);
        push_label(label_fin);
        
    } MC_FAIRE bloc_instructions MC_FIN_TQ {
        char* label_test = label_stack.labels[label_stack.top - 1];
        insererQuadruplet("BR", "", "", label_test);
        
        char* label_fin = pop_label();
        insererQuadruplet("", label_fin, "", "");
        
        pop_label();
    }
;

/* ==================== BLOC ==================== */
bloc_instructions:
    ACC_OUV instructions ACC_FERM
;

/* ==================== EXPRESSIONS ARITHMÉTIQUES ==================== */
expression:
    expression OP_PLUS expression {
        if(!is_numeric($1.type) || !is_numeric($3.type)) {
            yyerror("Opération + sur types non numériques");
            YYABORT;
        }
        
        $$.addr = new_temp();
        $$.type = result_type($1.type, $3.type);
        insererQuadruplet("+", $1.addr, $3.addr, $$.addr);
    }
    
    | expression OP_MOINS expression {
        if(!is_numeric($1.type) || !is_numeric($3.type)) {
            yyerror("Opération - sur types non numériques");
            YYABORT;
        }
        
        $$.addr = new_temp();
        $$.type = result_type($1.type, $3.type);
        insererQuadruplet("-", $1.addr, $3.addr, $$.addr);
    }
    
    | expression OP_MULT expression {
        if(!is_numeric($1.type) || !is_numeric($3.type)) {
            yyerror("Opération * sur types non numériques");
            YYABORT;
        }
        
        $$.addr = new_temp();
        $$.type = result_type($1.type, $3.type);
        insererQuadruplet("*", $1.addr, $3.addr, $$.addr);
    }
    
    | expression OP_DIV expression {
        if(!is_numeric($1.type) || !is_numeric($3.type)) {
            yyerror("Opération / sur types non numériques");
            YYABORT;
        }
        
        $$.addr = new_temp();
        $$.type = result_type($1.type, $3.type);
        insererQuadruplet("/", $1.addr, $3.addr, $$.addr);
    }
    
    | expression OP_MOD expression {
        if(strcmp($1.type, "ENTIER") != 0 || strcmp($3.type, "ENTIER") != 0) {
            yyerror("Opération % réservée aux ENTIER");
            YYABORT;
        }
        
        $$.addr = new_temp();
        $$.type = strdup("ENTIER");
        insererQuadruplet("%", $1.addr, $3.addr, $$.addr);
    }
    
    | expression OP_PUISS expression {
        if(!is_numeric($1.type) || !is_numeric($3.type)) {
            yyerror("Opération ^ sur types non numériques");
            YYABORT;
        }
        
        $$.addr = new_temp();
        $$.type = result_type($1.type, $3.type);
        insererQuadruplet("^", $1.addr, $3.addr, $$.addr);
    }
    
    | PAR_OUV expression PAR_FERM {
        $$ = $2;
    }
    
    | IDENTIFICATEUR {
        if(!is_declared($1)) {
            YYABORT;
        }
        
        $$.addr = $1;
        $$.type = strdup(get_type($1));
    }
    
    | IDENTIFICATEUR CROCH_OUV expression CROCH_FERM {
        if(!is_declared($1)) {
            YYABORT;
        }
        
        SymbolEntry* sym = find_symbol($1);
        if(!sym->is_array) {
            char error[200];
            sprintf(error, "'%s' n'est pas un tableau", $1);
            yyerror(error);
            YYABORT;
        }
        
        if(strcmp($3.type, "ENTIER") != 0) {
            yyerror("L'indice d'un tableau doit être de type ENTIER");
            YYABORT;
        }
        
        char* temp1 = new_temp();
        char* temp2 = new_temp();
        insererQuadruplet("+", $1, $3.addr, temp1);
        insererQuadruplet("=[]", temp1, "", temp2);
        
        $$.addr = temp2;
        $$.type = strdup(get_type($1));
    }
    
    | CONST_ENTIER {
        char* temp = new_temp();
        char val[20];
        sprintf(val, "%d", $1);
        
        insererQuadruplet(":=", val, "", temp);
        
        $$.addr = temp;
        $$.type = strdup("ENTIER");
    }
    
    | CONST_REEL {
        char* temp = new_temp();
        char val[20];
        sprintf(val, "%.2f", $1);
        
        insererQuadruplet(":=", val, "", temp);
        
        $$.addr = temp;
        $$.type = strdup("REEL");
    }

    
;

/* ==================== EXPRESSIONS BOOLÉENNES ==================== */
bool_expr:
    expression OP_EGAL expression {
        if(!is_numeric($1.type) || !is_numeric($3.type)) {
            yyerror("Comparaison == sur types non numériques");
            YYABORT;
        }
        
        $$.addr = new_temp();
        $$.type = strdup("BOOL");
        insererQuadruplet("==", $1.addr, $3.addr, $$.addr);
    }
    
    | expression OP_DIFF expression {
        if(!is_numeric($1.type) || !is_numeric($3.type)) {
            yyerror("Comparaison != sur types non numériques");
            YYABORT;
        }
        
        $$.addr = new_temp();
        $$.type = strdup("BOOL");
        insererQuadruplet("!=", $1.addr, $3.addr, $$.addr);
    }
    
    | expression OP_INF expression {
        if(!is_numeric($1.type) || !is_numeric($3.type)) {
            yyerror("Comparaison < sur types non numériques");
            YYABORT;
        }
        
        $$.addr = new_temp();
        $$.type = strdup("BOOL");
        insererQuadruplet("<", $1.addr, $3.addr, $$.addr);
    }
    
    | expression OP_INF_EGAL expression {
        $$.addr = new_temp();
        $$.type = strdup("BOOL");
        insererQuadruplet("<=", $1.addr, $3.addr, $$.addr);
    }
    
    | expression OP_SUP expression {
        $$.addr = new_temp();
        $$.type = strdup("BOOL");
        insererQuadruplet(">", $1.addr, $3.addr, $$.addr);
    }
    
    | expression OP_SUP_EGAL expression {
        $$.addr = new_temp();
        $$.type = strdup("BOOL");
        insererQuadruplet(">=", $1.addr, $3.addr, $$.addr);
    }
    
    | bool_expr OP_ET bool_expr {
        if(strcmp($1.type, "BOOL") != 0 || strcmp($3.type, "BOOL") != 0) {
            yyerror("Opération ET sur types non booléens");
            YYABORT;
        }
        
        $$.addr = new_temp();
        $$.type = strdup("BOOL");
        insererQuadruplet("ET", $1.addr, $3.addr, $$.addr);
    }
    
    | bool_expr OP_OU bool_expr {
        if(strcmp($1.type, "BOOL") != 0 || strcmp($3.type, "BOOL") != 0) {
            yyerror("Opération OU sur types non booléens");
            YYABORT;
        }
        
        $$.addr = new_temp();
        $$.type = strdup("BOOL");
        insererQuadruplet("OU", $1.addr, $3.addr, $$.addr);
    }
    
    | OP_NON bool_expr {
        if(strcmp($2.type, "BOOL") != 0) {
            yyerror("Opération NON sur type non booléen");
            YYABORT;
        }
        
        $$.addr = new_temp();
        $$.type = strdup("BOOL");
        insererQuadruplet("NON", $2.addr, "", $$.addr);
    }
    
    | BOOL_VRAI {
        char* temp = new_temp();
        insererQuadruplet(":=", "true", "", temp);
        
        $$.addr = temp;
        $$.type = strdup("BOOL");
    }
    
    | BOOL_FAUX {
        char* temp = new_temp();
        insererQuadruplet(":=", "false", "", temp);
        
        $$.addr = temp;
        $$.type = strdup("BOOL");
    }
;

%%

/* ==================== FONCTIONS AUXILIAIRES ==================== */
void yyerror(const char* s) {
    fprintf(stderr, "File \"input\", line %d, character %d: %s\n", 
            line_number, column_number, s);
}

int main(int argc, char** argv) {
    FILE* input_file;
    
    init_stack();
    
    printf("=================================================\n");
    printf("  ANALYSEUR COMPLET POUR LE LANGAGE SIMPL\n");
    printf("=================================================\n\n");
    
    if(argc > 1) {
        input_file = fopen(argv[1], "r");
        if(!input_file) {
            fprintf(stderr, "Erreur: Impossible d'ouvrir '%s'\n", argv[1]);
            return 1;
        }
        yyin = input_file;
    } else {
        printf("Usage: %s <fichier.simpl>\n", argv[0]);
        return 1;
    }
    
    printf("--- ANALYSE EN COURS ---\n\n");
    
    int result = yyparse();
    
    printf("\n--- FIN DE L'ANALYSE ---\n");
    
    if(result == 0) {
        printf("\n COMPILATION RÉUSSIE!\n\n");
        print_symbol_table();
    } else {
        printf("\n COMPILATION ÉCHOUÉE\n");
    }
    
    if(argc > 1) fclose(input_file);
    
    return result;
}