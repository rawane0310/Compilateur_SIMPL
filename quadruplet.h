#ifndef QUADRUPLET_H
#define QUADRUPLET_H

/* ==================== QUADRUPLETS ==================== */
typedef struct {
    char op[20];       // Opérateur : =, +, -, *, /, <, BZ, BR, etc.
    char arg1[50];     // Premier argument
    char arg2[50];     // Deuxième argument
    char res[50];      // Résultat
} Quadruplet;

extern Quadruplet quads[1000];
extern int qc;  // Compteur de quadruplets

/* ==================== GESTION DES TEMPORAIRES ==================== */
extern int temp_count;
extern int label_count;

// Créer un nouveau temporaire
char* new_temp();

// Créer une nouvelle étiquette
char* new_label();

// Insérer un quadruplet
void insererQuadruplet(char* op, char* arg1, char* arg2, char* res);

// Afficher tous les quadruplets
void print_quadruplets();

#endif // QUADRUPLET_H