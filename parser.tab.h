/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    MC_DEBUT_PROG = 258,           /* MC_DEBUT_PROG  */
    MC_FIN_PROG = 259,             /* MC_FIN_PROG  */
    MC_DECLARER = 260,             /* MC_DECLARER  */
    MC_TAB = 261,                  /* MC_TAB  */
    MC_DE = 262,                   /* MC_DE  */
    MC_ENTIER = 263,               /* MC_ENTIER  */
    MC_REEL = 264,                 /* MC_REEL  */
    MC_CHAR = 265,                 /* MC_CHAR  */
    MC_BOOL = 266,                 /* MC_BOOL  */
    MC_LIRE = 267,                 /* MC_LIRE  */
    MC_AFFICHER = 268,             /* MC_AFFICHER  */
    MC_SI = 269,                   /* MC_SI  */
    MC_ALORS = 270,                /* MC_ALORS  */
    MC_SINON = 271,                /* MC_SINON  */
    MC_SINON_SI = 272,             /* MC_SINON_SI  */
    MC_FIN_SI = 273,               /* MC_FIN_SI  */
    MC_POUR = 274,                 /* MC_POUR  */
    MC_FAIRE = 275,                /* MC_FAIRE  */
    MC_FIN_POUR = 276,             /* MC_FIN_POUR  */
    MC_TANT_QUE = 277,             /* MC_TANT_QUE  */
    MC_FIN_TQ = 278,               /* MC_FIN_TQ  */
    MC_REPETER = 279,              /* MC_REPETER  */
    MC_JUSQU_A = 280,              /* MC_JUSQU_A  */
    OP_ET = 281,                   /* OP_ET  */
    OP_OU = 282,                   /* OP_OU  */
    OP_NON = 283,                  /* OP_NON  */
    BOOL_VRAI = 284,               /* BOOL_VRAI  */
    BOOL_FAUX = 285,               /* BOOL_FAUX  */
    OP_AFFECTATION = 286,          /* OP_AFFECTATION  */
    OP_PLUS = 287,                 /* OP_PLUS  */
    OP_MOINS = 288,                /* OP_MOINS  */
    OP_MULT = 289,                 /* OP_MULT  */
    OP_DIV = 290,                  /* OP_DIV  */
    OP_MOD = 291,                  /* OP_MOD  */
    OP_PUISS = 292,                /* OP_PUISS  */
    OP_EGAL = 293,                 /* OP_EGAL  */
    OP_DIFF = 294,                 /* OP_DIFF  */
    OP_INF = 295,                  /* OP_INF  */
    OP_INF_EGAL = 296,             /* OP_INF_EGAL  */
    OP_SUP = 297,                  /* OP_SUP  */
    OP_SUP_EGAL = 298,             /* OP_SUP_EGAL  */
    SEPARATEUR = 299,              /* SEPARATEUR  */
    DEUX_POINTS = 300,             /* DEUX_POINTS  */
    VIRGULE = 301,                 /* VIRGULE  */
    PAR_OUV = 302,                 /* PAR_OUV  */
    PAR_FERM = 303,                /* PAR_FERM  */
    CROCH_OUV = 304,               /* CROCH_OUV  */
    CROCH_FERM = 305,              /* CROCH_FERM  */
    ACC_OUV = 306,                 /* ACC_OUV  */
    ACC_FERM = 307,                /* ACC_FERM  */
    CONST_ENTIER = 308,            /* CONST_ENTIER  */
    CONST_REEL = 309,              /* CONST_REEL  */
    CONST_CHAR = 310,              /* CONST_CHAR  */
    CONST_STRING = 311,            /* CONST_STRING  */
    IDENTIFICATEUR = 312           /* IDENTIFICATEUR  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 23 "parser.y"

    int entier;
    float reel;
    char* chaine;
    char caractere;
    int val_bool;
    
    struct {
        char* addr;
        char* type;
    } expr_info;

#line 134 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
