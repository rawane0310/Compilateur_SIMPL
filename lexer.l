%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.tab.h"  /* Fichier généré par Bison */

/* Compteurs pour les lignes et colonnes */
int line_number = 1;
int column_number = 1;

/* Mise à jour de la position */
void update_position() {
    column_number += yyleng;
}

%}

/* Options Flex */
%option noyywrap
%option yylineno

/* Définitions des patterns */
DIGIT       [0-9]
LETTER      [a-zA-Z]
ALPHANUM    [a-zA-Z0-9_]

/* Types de nombres */
ENTIER      {DIGIT}+
REEL        {DIGIT}+"."{DIGIT}+

/* Identifiants */
IDENT       {LETTER}{ALPHANUM}*

/* Caractères et chaînes */
CHAR        '.'
STRING      \"[^\"]*\"

/* Espaces blancs */
WHITESPACE  [ \t\r]+
NEWLINE     \n

/* Commentaires */
COMMENT_LINE        ##.*
COMMENT_MULTI_START #\[

%%

 /* ========== GESTION DES COMMENTAIRES ========== */
{COMMENT_LINE} {
    update_position();
    /* Ignorer les commentaires sur une ligne */
}

{COMMENT_MULTI_START} {
    update_position();
    int c;
    int comment_line = line_number;
    int comment_col = column_number;
    int found_end = 0;

    /* Lire jusqu'à trouver ]# */
    while((c = input()) != EOF) {
        if(c == '\n') {
            line_number++;
            column_number = 1;
        } else {
            column_number++;
        }

        if(c == ']') {
            c = input();
            if(c == '#') {
                column_number++;
                found_end = 1;
                break;
            } else {
                unput(c);
            }
        }
    }

    if(!found_end) {
        fprintf(stderr, "Erreur ligne %d, col %d: Commentaire multi-ligne non fermé\n",
               comment_line, comment_col);
    }
}

 /* ========== MOTS-CLÉS RÉSERVÉS ========== */
"DEBUT_PROG"    { update_position(); return MC_DEBUT_PROG; }
"FIN_PROG"      { update_position(); return MC_FIN_PROG; }
"DECLARER"      { update_position(); return MC_DECLARER; }
"TAB"           { update_position(); return MC_TAB; }
"DE"            { update_position(); return MC_DE; }

 /* Types de données */
"ENTIER"        { update_position(); return MC_ENTIER; }
"REEL"          { update_position(); return MC_REEL; }
"CHAR"          { update_position(); return MC_CHAR; }
"BOOL"          { update_position(); return MC_BOOL; }

 /* Entrée/Sortie */
"LIRE"          { update_position(); return MC_LIRE; }
"AFFICHER"      { update_position(); return MC_AFFICHER; }

 /* Structures conditionnelles */
"SI"            { update_position(); return MC_SI; }
"ALORS"         { update_position(); return MC_ALORS; }
"SINON"         { update_position(); return MC_SINON; }
"SINON_SI"      { update_position(); return MC_SINON_SI; }
"FIN_SI"        { update_position(); return MC_FIN_SI; }

 /* Boucles */
"POUR"          { update_position(); return MC_POUR; }
"FAIRE"         { update_position(); return MC_FAIRE; }
"FIN_POUR"      { update_position(); return MC_FIN_POUR; }
"TANT_QUE"      { update_position(); return MC_TANT_QUE; }
"FIN_TQ"        { update_position(); return MC_FIN_TQ; }
"REPETER"       { update_position(); return MC_REPETER; }
"JUSQU_A"       { update_position(); return MC_JUSQU_A; }

 /* Opérateurs logiques */
"ET"            { update_position(); return OP_ET; }
"OU"            { update_position(); return OP_OU; }
"NON"           { update_position(); return OP_NON; }

 /* Valeurs booléennes */
"VRAI"          { update_position(); return BOOL_VRAI; }
"FAUX"          { update_position(); return BOOL_FAUX; }

 /* ========== OPÉRATEURS ========== */
":="            { update_position(); return OP_AFFECTATION; }
"+"             { update_position(); return OP_PLUS; }
"-"             { update_position(); return OP_MOINS; }
"*"             { update_position(); return OP_MULT; }
"/"             { update_position(); return OP_DIV; }
"%"             { update_position(); return OP_MOD; }
"^"             { update_position(); return OP_PUISS; }

 /* Opérateurs de comparaison */
"=="            { update_position(); return OP_EGAL; }
"!="            { update_position(); return OP_DIFF; }
"<"             { update_position(); return OP_INF; }
"<="            { update_position(); return OP_INF_EGAL; }
">"             { update_position(); return OP_SUP; }
">="            { update_position(); return OP_SUP_EGAL; }

 /* ========== SÉPARATEURS ========== */
";"             { update_position(); return SEPARATEUR; }
":"             { update_position(); return DEUX_POINTS; }
","             { update_position(); return VIRGULE; }
"("             { update_position(); return PAR_OUV; }
")"             { update_position(); return PAR_FERM; }
"["             { update_position(); return CROCH_OUV; }
"]"             { update_position(); return CROCH_FERM; }
"{"             { update_position(); return ACC_OUV; }
"}"             { update_position(); return ACC_FERM; }

 /* ========== LITTÉRAUX ========== */
{REEL} {
    yylval.reel = atof(yytext);
    update_position();
    return CONST_REEL;
}

{ENTIER} {
    yylval.entier = atoi(yytext);
    update_position();
    return CONST_ENTIER;
}

{CHAR} {
    yylval.caractere = yytext[1];
    update_position();
    return CONST_CHAR;
}

{STRING} {
    yylval.chaine = strdup(yytext);
    update_position();
    return CONST_STRING;
}

 /* ========== IDENTIFIANTS ========== */
{IDENT} {
    yylval.chaine = strdup(yytext);
    update_position();
    return IDENTIFICATEUR;
}

 /* ========== GESTION DES ESPACES ========== */
{WHITESPACE} {
    column_number += yyleng;
}

{NEWLINE} {
    line_number++;
    column_number = 1;
}

 /* ========== GESTION DES ERREURS ========== */
. {
    fprintf(stderr, "Erreur lexicale ligne %d, col %d: Caractère non reconnu '%s'\n",
           line_number, column_number, yytext);
    column_number++;
}

%%