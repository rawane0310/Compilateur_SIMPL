#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

/* ==================== VARIABLE GLOBALE ==================== */
LabelStack label_stack;

/* ==================== FONCTIONS DE PILE ==================== */

void init_stack() {
    label_stack.top = -1;
}

void push_label(char* label) {
    label_stack.labels[++label_stack.top] = label;
}

char* pop_label() {
    if(label_stack.top >= 0)
        return label_stack.labels[label_stack.top--];
    return NULL;
}

char* peek_label() {
    if(label_stack.top >= 0)
        return label_stack.labels[label_stack.top];
    return NULL;
}