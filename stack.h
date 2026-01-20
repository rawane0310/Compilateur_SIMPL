#ifndef STACK_H
#define STACK_H

/* ==================== PILE POUR GESTION DES ÉTIQUETTES ==================== */
typedef struct {
    char* labels[100];
    int top;
} LabelStack;

extern LabelStack label_stack;

// Initialiser la pile
void init_stack();

// Empiler une étiquette
void push_label(char* label);

// Dépiler une étiquette
char* pop_label();

// Consulter le sommet sans dépiler
char* peek_label();

#endif // STACK_H