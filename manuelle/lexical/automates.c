#include <stdio.h>
#include <string.h>

#define MAX_ETATS 50
#define MAX_SYMBOLES 256
#define ERREUR -1

// Structure d'un automate
typedef struct {
    int nb_etats;
    int etat_initial;
    int etats_finaux[MAX_ETATS];
    int nb_etats_finaux;
    int table[MAX_ETATS][MAX_SYMBOLES];
} Automate;

// Fonction pour exécuter un automate sur un mot
int executer(Automate *a, const char *mot) {
    int etat = a->etat_initial;
    
    for (int i = 0; mot[i] != '\0'; i++) {
        char c = mot[i];
        int nouvel_etat = a->table[etat][(unsigned char)c];
        
        if (nouvel_etat == ERREUR) {
            return 0;
        }
        etat = nouvel_etat;
    }
    
    for (int i = 0; i < a->nb_etats_finaux; i++) {
        if (a->etats_finaux[i] == etat) {
            return 1;  
        }
    }
    
    return 0;  
}

// Initialiser une table à ERREUR partout
void init_table(int table[MAX_ETATS][MAX_SYMBOLES]) {
    for (int i = 0; i < MAX_ETATS; i++) {
        for (int j = 0; j < MAX_SYMBOLES; j++) {
            table[i][j] = ERREUR;
        }
    }
}

//Automate pour les entiers
Automate auto_entier() {
    Automate a;
    a.nb_etats = 2;
    a.etat_initial = 0;
    a.nb_etats_finaux = 1;
    a.etats_finaux[0] = 1;
    init_table(a.table);

    for (char c = '0'; c <= '9'; c++) {
        a.table[0][c] = 1;
        a.table[1][c] = 1;
    }
    return a;
};

//Automate pour les identificateurs
Automate auto_identificateur() {
    Automate a;
    a.nb_etats = 2;
    a.etat_initial = 0;
    a.nb_etats_finaux = 1;
    a.etats_finaux[0] = 1;
    init_table(a.table);

    for (char c = 'a'; c <= 'z'; c++) {
        a.table[0][c] = 1;
        a.table[1][c] = 1;
    }
    for (char c = 'A'; c <= 'Z'; c++) {
        a.table[0][c] = 1;
        a.table[1][c] = 1;
    }
    for (char c = '0'; c <= '9'; c++) {
        a.table[1][c] = 1;
    }
    a.table[1]['_'] = 1;

    return a;
};

//Automate pour les operateurs 
Automate auto_operateur() {
    Automate a;
    a.nb_etats = 4;
    a.etat_initial = 0;
    a.nb_etats_finaux = 2;
    a.etats_finaux[0] = 1;
    a.etats_finaux[1] = 3;
    init_table(a.table);

    const char operateurs[] = "+-*/";
    for (size_t i = 0; i < strlen(operateurs); i++) {
        char c = operateurs[i];
        a.table[0][c] = 1;
    }
    a.table[0][':'] = 2;
    a.table[2]['='] = 3;

    return a;
};

//Automate pour les separateurs
Automate auto_separateur() {
    Automate a;
    a.nb_etats = 2;
    a.etat_initial = 0;
    a.nb_etats_finaux = 1;
    a.etats_finaux[0] = 1;
    init_table(a.table);

    const char separateurs[] = "();:";
    for (size_t i = 0; i < strlen(separateurs); i++) {
        char c = separateurs[i];
        a.table[0][c] = 1;
    }

    return a;
};

//Automate pour les mots-cles
Automate auto_mot_cle() {
    Automate a;
    a.nb_etats = 32;
    a.etat_initial = 0;
    a.nb_etats_finaux = 3;
    a.etats_finaux[0] = 17; // "AFFICHER" "ENTIER" "DECLARER"
    a.etats_finaux[1] = 25; // "DEBUT_PROG" "FIN_PROG"
    a.etats_finaux[2] = 31; // "LIRE"
    init_table(a.table);

    // Transitions pour "AFFICHER" "ENTIER" "DECLARER"
    a.table[0]['A'] = 1;
    a.table[1]['F'] = 2;
    a.table[2]['F'] = 3;
    a.table[3]['I'] = 4;
    a.table[4]['C'] = 5;
    a.table[5]['H'] = 15;

    a.table[0]['E'] = 7;
    a.table[7]['N'] = 8;
    a.table[8]['T'] = 9;
    a.table[9]['I'] = 15;

    a.table[0]['D'] = 10;
    a.table[10]['E'] = 11;
    a.table[11]['C'] = 12;
    a.table[12]['L'] = 13;
    a.table[13]['A'] = 14;
    a.table[14]['R'] = 15;

    a.table[15]['E'] = 16;
    a.table[16]['R'] = 17;

    // Transitions pour "DEBUT_PROG" "FIN_PROG"
    a.table[11]['B'] = 18; 
    a.table[18]['U'] = 19;
    a.table[19]['T'] = 20;

    a.table[0]['F'] = 26;
    a.table[26]['I'] = 27;
    a.table[27]['N'] = 20;

    a.table[20]['_'] = 21;
    a.table[21]['P'] = 22;
    a.table[22]['R'] = 23;
    a.table[23]['O'] = 24;
    a.table[24]['G'] = 25;

    // Transitions pour "LIRE"
    a.table[0]['L'] = 28;
    a.table[28]['I'] = 29;
    a.table[29]['R'] = 30;
    a.table[30]['E'] = 31;

    return a;
};