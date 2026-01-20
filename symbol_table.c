#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol_table.h"

extern int line_number;
extern void yyerror(const char* s);

/* ==================== VARIABLES GLOBALES ==================== */
SymbolEntry symbol_table[1000];
int symbol_count = 0;

char* temp_var_names[100];
int temp_var_count = 0;

/* ==================== FONCTIONS TABLE DES SYMBOLES ==================== */

// Ajouter avec vérification de double déclaration
int add_to_symbol_table_checked(char* name, char* type, int is_array, int size) {
    // Vérifier si déjà déclaré
    for(int i = 0; i < symbol_count; i++) {
        if(strcmp(symbol_table[i].name, name) == 0) {
            char error_msg[200];
            sprintf(error_msg, "Variable '%s' déjà déclarée ligne %d", 
                    name, symbol_table[i].line);
            yyerror(error_msg);
            return -1;
        }
    }
    
    // Insertion
    strcpy(symbol_table[symbol_count].name, name);
    strcpy(symbol_table[symbol_count].type, type);
    symbol_table[symbol_count].is_array = is_array;
    symbol_table[symbol_count].array_size = size;
    symbol_table[symbol_count].line = line_number;
    symbol_table[symbol_count].is_declared = 1;
    symbol_table[symbol_count].is_initialized = 0;
    symbol_count++;
    return 0;
}

// Trouver un symbole
SymbolEntry* find_symbol(char* name) {
    for(int i = 0; i < symbol_count; i++) {
        if(strcmp(symbol_table[i].name, name) == 0)
            return &symbol_table[i];
    }
    return NULL;
}

// Vérifier si variable déclarée
int is_declared(char* name) {
    SymbolEntry* sym = find_symbol(name);
    if(!sym) {
        char error_msg[200];
        sprintf(error_msg, "Variable '%s' non déclarée", name);
        yyerror(error_msg);
        return 0;
    }
    return 1;
}

// Marquer comme initialisée
void mark_initialized(char* name) {
    SymbolEntry* sym = find_symbol(name);
    if(sym) sym->is_initialized = 1;
}

// Obtenir le type
char* get_type(char* name) {
    SymbolEntry* sym = find_symbol(name);
    if(sym) return sym->type;
    return "UNKNOWN";
}

// Vérifier compatibilité de types
int types_compatibles(char* type1, char* type2) {
    // ENTIER == ENTIER
    if(strcmp(type1, type2) == 0) return 1;
    
    // ENTIER → REEL autorisé
    if(strcmp(type1, "REEL") == 0 && strcmp(type2, "ENTIER") == 0) return 1;
    
    // REEL → ENTIER interdit
    if(strcmp(type1, "ENTIER") == 0 && strcmp(type2, "REEL") == 0) {
        yyerror("Conversion REEL → ENTIER interdite (perte de précision)");
        return 0;
    }
    
    // CHAR et BOOL ne se convertissent pas
    return 0;
}

// Déterminer type résultat d'opération
char* result_type(char* type1, char* type2) {
    // Si un des deux est REEL, résultat REEL
    if(strcmp(type1, "REEL") == 0 || strcmp(type2, "REEL") == 0)
        return strdup("REEL");
    // Sinon ENTIER
    return strdup("ENTIER");
}

// Vérifier type numérique
int is_numeric(char* type) {
    return (strcmp(type, "ENTIER") == 0 || strcmp(type, "REEL") == 0);
}

// Afficher la table des symboles
void print_symbol_table() {
    printf("--- TABLE DES SYMBOLES ---\n");
    printf("%-20s %-10s %-10s %-10s %-10s\n", 
           "NOM", "TYPE", "TABLEAU", "TAILLE", "LIGNE");
    printf("-------------------------------------------------------------\n");
    for(int i = 0; i < symbol_count; i++) {
        printf("%-20s %-10s %-10s %-10d %-10d\n", 
               symbol_table[i].name,
               symbol_table[i].type,
               symbol_table[i].is_array ? "OUI" : "NON",
               symbol_table[i].array_size,
               symbol_table[i].line);
    }
}