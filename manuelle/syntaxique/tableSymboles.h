#ifndef TABLE_SYMBOLES_H
#define TABLE_SYMBOLES_H

#include <stdbool.h>

#define MAX_SYMBOLES 1000
#define MAX_NOM 100

typedef enum {
    TYPE_ENTIER,
    TYPE_REEL,
    TYPE_CHAR,
    TYPE_BOOL,
    TYPE_INCONNU
} TypeDonnee;

typedef struct {
    char nom[MAX_NOM];
    TypeDonnee type;
    bool est_tableau;
    int taille_tableau;  // Si est_tableau = true
    bool est_declare;
} Symbole;

typedef struct {
    Symbole symboles[MAX_SYMBOLES];
    int nb_symboles;
} SymbolTable;

// Fonctions de base
SymbolTable* creerTableSymboles();
void ajouterSymbole(SymbolTable* table, const char* nom, TypeDonnee type);
void ajouterTableau(SymbolTable* table, const char* nom, TypeDonnee type, int taille);
bool rechercherSymbole(SymbolTable* table, const char* nom);
TypeDonnee obtenirType(SymbolTable* table, const char* nom);
void afficherTableSymboles(SymbolTable* table);
void libererTableSymboles(SymbolTable* table);

// Utilitaires
const char* nom_type(TypeDonnee type);

#endif