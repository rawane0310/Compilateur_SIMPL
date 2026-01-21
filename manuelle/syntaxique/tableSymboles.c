#include "tableSymboles.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

SymbolTable* creerTableSymboles() {
    SymbolTable* table = (SymbolTable*)malloc(sizeof(SymbolTable));
    if (!table) {
        fprintf(stderr, "Erreur allocation table des symboles\n");
        exit(1);
    }
    table->nb_symboles = 0;
    return table;
}

void ajouterSymbole(SymbolTable* table, const char* nom, TypeDonnee type) {
    if (table->nb_symboles >= MAX_SYMBOLES) {
        fprintf(stderr, "Erreur : table des symboles pleine\n");
        return;
    }
    
    Symbole* s = &table->symboles[table->nb_symboles];
    strncpy(s->nom, nom, MAX_NOM - 1);
    s->nom[MAX_NOM - 1] = '\0';
    s->type = type;
    s->est_tableau = false;
    s->taille_tableau = 0;
    s->est_declare = true;
    
    table->nb_symboles++;
}

void ajouterTableau(SymbolTable* table, const char* nom, TypeDonnee type, int taille) {
    if (table->nb_symboles >= MAX_SYMBOLES) {
        fprintf(stderr, "Erreur : table des symboles pleine\n");
        return;
    }
    
    Symbole* s = &table->symboles[table->nb_symboles];
    strncpy(s->nom, nom, MAX_NOM - 1);
    s->nom[MAX_NOM - 1] = '\0';
    s->type = type;
    s->est_tableau = true;
    s->taille_tableau = taille;
    s->est_declare = true;
    
    table->nb_symboles++;
}

bool rechercherSymbole(SymbolTable* table, const char* nom) {
    for (int i = 0; i < table->nb_symboles; i++) {
        if (strcmp(table->symboles[i].nom, nom) == 0) {
            return true;
        }
    }
    return false;
}

TypeDonnee obtenirType(SymbolTable* table, const char* nom) {
    for (int i = 0; i < table->nb_symboles; i++) {
        if (strcmp(table->symboles[i].nom, nom) == 0) {
            return table->symboles[i].type;
        }
    }
    return TYPE_INCONNU;
}

const char* nom_type(TypeDonnee type) {
    switch(type) {
        case TYPE_ENTIER: return "ENTIER";
        case TYPE_REEL: return "REEL";
        case TYPE_CHAR: return "CHAR";
        case TYPE_BOOL: return "BOOL";
        default: return "INCONNU";
    }
}

void afficherTableSymboles(SymbolTable* table) {
    printf("┌────────────────┬──────────┬──────────┬─────────────┐\n");
    printf("│ %-14s │ %-8s │ %-8s │ %-11s │\n", "Nom", "Type", "Tableau", "Taille");
    printf("├────────────────┼──────────┼──────────┼─────────────┤\n");
    
    for (int i = 0; i < table->nb_symboles; i++) {
        Symbole* s = &table->symboles[i];
        printf("│ %-14s │ %-8s │ %-8s │ %-11d │\n",
               s->nom,
               nom_type(s->type),
               s->est_tableau ? "Oui" : "Non",
               s->est_tableau ? s->taille_tableau : 0);
    }
    
    printf("└────────────────┴──────────┴──────────┴─────────────┘\n");
    printf("Total : %d symbole(s)\n", table->nb_symboles);
}

void libererTableSymboles(SymbolTable* table) {
    if (table) {
        free(table);
    }
}