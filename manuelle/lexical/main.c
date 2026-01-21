#include <stdio.h>
#include <string.h>
#include "automates.c"  

int main() {
    char chaine[256];
    printf("Entrez une chaîne à analyser :\n> ");
    fgets(chaine, sizeof(chaine), stdin);

    Automate autoEntier = auto_entier();
    Automate autoIdentificateur = auto_identificateur();
    Automate autoOperateur = auto_operateur();
    Automate autoSeparateur = auto_separateur();
    Automate autoMotCle = auto_mot_cle();

    char mot[256];
    int i = 0;
    int num_token = 1;
    int j = 0;
    for (int i = 0; i <= strlen(chaine); i++) {
        char c = chaine[i];
        
        if (c == ' ' || c == '\0' || c == '\n') {
            if (j > 0) {
                mot[j] = '\0';  // Terminer le mot
                printf("%2d. '%s' ", num_token++, mot);
                
                if (executer(&autoMotCle, mot)) {
                    printf("MOT-CLE\n");
                }
                else if (executer(&autoEntier, mot)) {
                    printf("ENTIER\n");
                }
                else if (executer(&autoIdentificateur, mot)) {
                    printf("IDENTIFICATEUR\n");
                }
                else if (executer(&autoOperateur, mot)) {
                    printf("OPERATEUR\n");
                }
                else if (executer(&autoSeparateur, mot)) {
                    printf("SEPARATEUR\n");
                }
                else {
                    printf("INCONNU\n");
                }
                
                j = 0;  // Réinitialiser pour le prochain mot
            }
        } else {
            mot[j] = c;
            j++;
        }
    }
    
    return 0;
}
