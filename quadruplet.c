#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "quadruplet.h"

/* ==================== VARIABLES GLOBALES ==================== */
Quadruplet quads[1000];
int qc = 0;  // Compteur de quadruplets

int temp_count = 0;
int label_count = 0;

/* ==================== GESTION DES TEMPORAIRES ==================== */

char* new_temp() {
    char* temp = (char*)malloc(10);
    sprintf(temp, "T%d", temp_count++);
    return temp;
}

char* new_label() {
    char* label = (char*)malloc(10);
    sprintf(label, "L%d", label_count++);
    return label;
}

/* ==================== INSERTION QUADRUPLET ==================== */

void insererQuadruplet(char* op, char* arg1, char* arg2, char* res) {
    strcpy(quads[qc].op, op);
    strcpy(quads[qc].arg1, arg1 ? arg1 : "");
    strcpy(quads[qc].arg2, arg2 ? arg2 : "");
    strcpy(quads[qc].res, res ? res : "");
    qc++;
}

/* ==================== AFFICHAGE DES QUADRUPLETS ==================== */

void print_quadruplets() {
    printf("\n=== GÉNÉRATION DE CODE INTERMÉDIAIRE ===\n");
    for(int i = 0; i < qc; i++) {
        printf("Quad[%d] = [ %s , %s , %s , %s ]\n", 
               i+1, quads[i].op, quads[i].arg1, quads[i].arg2, quads[i].res);
    }
}