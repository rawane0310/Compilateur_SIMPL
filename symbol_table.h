#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

/* ==================== TABLE DES SYMBOLES ==================== */
typedef struct {
    char name[100];
    char type[20];          // "ENTIER", "REEL", "CHAR", "BOOL", "TABLEAU"
    int is_array;
    int array_size;
    int line;
    int is_declared;        // Pour vérifier déclaration
    int is_initialized;     // Pour vérifier initialisation
    float val;
    char val_char;
    int val_bool;
} SymbolEntry;

extern SymbolEntry symbol_table[1000];
extern int symbol_count;

extern char* temp_var_names[100];
extern int temp_var_count;

/* ==================== FONCTIONS TABLE DES SYMBOLES ==================== */

// Ajouter avec vérification de double déclaration
int add_to_symbol_table_checked(char* name, char* type, int is_array, int size);

// Trouver un symbole
SymbolEntry* find_symbol(char* name);

// Vérifier si variable déclarée
int is_declared(char* name);

// Vérifier si variable initialisée
int is_initialized(char* name);

// Marquer comme initialisée
void mark_initialized(char* name);

// Obtenir le type
char* get_type(char* name);

// Vérifier compatibilité de types
int types_compatibles(char* type1, char* type2);

// Déterminer type résultat d'opération
char* result_type(char* type1, char* type2);

// Vérifier type numérique
int is_numeric(char* type);

// Afficher la table des symboles
void print_symbol_table();

#endif // SYMBOL_TABLE_H