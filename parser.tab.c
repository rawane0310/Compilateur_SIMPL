/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "symbol_table.h"
#include "quadruplet.h"
#include "stack.h"

extern int yylex();
extern FILE* yyin;
extern int line_number;
extern int column_number;

void yyerror(const char* s);

/* ==================== VARIABLE GLOBALE POUR TYPES ==================== */
char current_decl_type[20];


#line 92 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_MC_DEBUT_PROG = 3,              /* MC_DEBUT_PROG  */
  YYSYMBOL_MC_FIN_PROG = 4,                /* MC_FIN_PROG  */
  YYSYMBOL_MC_DECLARER = 5,                /* MC_DECLARER  */
  YYSYMBOL_MC_TAB = 6,                     /* MC_TAB  */
  YYSYMBOL_MC_DE = 7,                      /* MC_DE  */
  YYSYMBOL_MC_ENTIER = 8,                  /* MC_ENTIER  */
  YYSYMBOL_MC_REEL = 9,                    /* MC_REEL  */
  YYSYMBOL_MC_CHAR = 10,                   /* MC_CHAR  */
  YYSYMBOL_MC_BOOL = 11,                   /* MC_BOOL  */
  YYSYMBOL_MC_LIRE = 12,                   /* MC_LIRE  */
  YYSYMBOL_MC_AFFICHER = 13,               /* MC_AFFICHER  */
  YYSYMBOL_MC_SI = 14,                     /* MC_SI  */
  YYSYMBOL_MC_ALORS = 15,                  /* MC_ALORS  */
  YYSYMBOL_MC_SINON = 16,                  /* MC_SINON  */
  YYSYMBOL_MC_SINON_SI = 17,               /* MC_SINON_SI  */
  YYSYMBOL_MC_FIN_SI = 18,                 /* MC_FIN_SI  */
  YYSYMBOL_MC_POUR = 19,                   /* MC_POUR  */
  YYSYMBOL_MC_FAIRE = 20,                  /* MC_FAIRE  */
  YYSYMBOL_MC_FIN_POUR = 21,               /* MC_FIN_POUR  */
  YYSYMBOL_MC_TANT_QUE = 22,               /* MC_TANT_QUE  */
  YYSYMBOL_MC_FIN_TQ = 23,                 /* MC_FIN_TQ  */
  YYSYMBOL_MC_REPETER = 24,                /* MC_REPETER  */
  YYSYMBOL_MC_JUSQU_A = 25,                /* MC_JUSQU_A  */
  YYSYMBOL_OP_ET = 26,                     /* OP_ET  */
  YYSYMBOL_OP_OU = 27,                     /* OP_OU  */
  YYSYMBOL_OP_NON = 28,                    /* OP_NON  */
  YYSYMBOL_BOOL_VRAI = 29,                 /* BOOL_VRAI  */
  YYSYMBOL_BOOL_FAUX = 30,                 /* BOOL_FAUX  */
  YYSYMBOL_OP_AFFECTATION = 31,            /* OP_AFFECTATION  */
  YYSYMBOL_OP_PLUS = 32,                   /* OP_PLUS  */
  YYSYMBOL_OP_MOINS = 33,                  /* OP_MOINS  */
  YYSYMBOL_OP_MULT = 34,                   /* OP_MULT  */
  YYSYMBOL_OP_DIV = 35,                    /* OP_DIV  */
  YYSYMBOL_OP_MOD = 36,                    /* OP_MOD  */
  YYSYMBOL_OP_PUISS = 37,                  /* OP_PUISS  */
  YYSYMBOL_OP_EGAL = 38,                   /* OP_EGAL  */
  YYSYMBOL_OP_DIFF = 39,                   /* OP_DIFF  */
  YYSYMBOL_OP_INF = 40,                    /* OP_INF  */
  YYSYMBOL_OP_INF_EGAL = 41,               /* OP_INF_EGAL  */
  YYSYMBOL_OP_SUP = 42,                    /* OP_SUP  */
  YYSYMBOL_OP_SUP_EGAL = 43,               /* OP_SUP_EGAL  */
  YYSYMBOL_SEPARATEUR = 44,                /* SEPARATEUR  */
  YYSYMBOL_DEUX_POINTS = 45,               /* DEUX_POINTS  */
  YYSYMBOL_VIRGULE = 46,                   /* VIRGULE  */
  YYSYMBOL_PAR_OUV = 47,                   /* PAR_OUV  */
  YYSYMBOL_PAR_FERM = 48,                  /* PAR_FERM  */
  YYSYMBOL_CROCH_OUV = 49,                 /* CROCH_OUV  */
  YYSYMBOL_CROCH_FERM = 50,                /* CROCH_FERM  */
  YYSYMBOL_ACC_OUV = 51,                   /* ACC_OUV  */
  YYSYMBOL_ACC_FERM = 52,                  /* ACC_FERM  */
  YYSYMBOL_CONST_ENTIER = 53,              /* CONST_ENTIER  */
  YYSYMBOL_CONST_REEL = 54,                /* CONST_REEL  */
  YYSYMBOL_CONST_CHAR = 55,                /* CONST_CHAR  */
  YYSYMBOL_CONST_STRING = 56,              /* CONST_STRING  */
  YYSYMBOL_IDENTIFICATEUR = 57,            /* IDENTIFICATEUR  */
  YYSYMBOL_YYACCEPT = 58,                  /* $accept  */
  YYSYMBOL_programme = 59,                 /* programme  */
  YYSYMBOL_60_1 = 60,                      /* $@1  */
  YYSYMBOL_declarations = 61,              /* declarations  */
  YYSYMBOL_declaration = 62,               /* declaration  */
  YYSYMBOL_liste_variables = 63,           /* liste_variables  */
  YYSYMBOL_type = 64,                      /* type  */
  YYSYMBOL_instructions = 65,              /* instructions  */
  YYSYMBOL_instruction = 66,               /* instruction  */
  YYSYMBOL_affectation = 67,               /* affectation  */
  YYSYMBOL_lecture = 68,                   /* lecture  */
  YYSYMBOL_affichage = 69,                 /* affichage  */
  YYSYMBOL_condition = 70,                 /* condition  */
  YYSYMBOL_71_2 = 71,                      /* $@2  */
  YYSYMBOL_parties_sinon = 72,             /* parties_sinon  */
  YYSYMBOL_73_3 = 73,                      /* $@3  */
  YYSYMBOL_boucle_pour = 74,               /* boucle_pour  */
  YYSYMBOL_75_4 = 75,                      /* $@4  */
  YYSYMBOL_76_5 = 76,                      /* $@5  */
  YYSYMBOL_boucle_tant_que = 77,           /* boucle_tant_que  */
  YYSYMBOL_78_6 = 78,                      /* $@6  */
  YYSYMBOL_79_7 = 79,                      /* $@7  */
  YYSYMBOL_bloc_instructions = 80,         /* bloc_instructions  */
  YYSYMBOL_expression = 81,                /* expression  */
  YYSYMBOL_bool_expr = 82                  /* bool_expr  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   198

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  65
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  146

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   312


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    78,    78,    78,    87,    89,    93,   101,   114,   117,
     123,   124,   125,   126,   130,   132,   136,   137,   138,   139,
     140,   141,   146,   168,   205,   216,   244,   248,   256,   256,
     280,   285,   285,   297,   302,   297,   341,   346,   341,   369,
     374,   385,   396,   407,   418,   429,   440,   444,   453,   480,
     491,   502,   513,   521,   533,   544,   555,   566,   572,   578,
     584,   595,   606,   617,   625,   633
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "MC_DEBUT_PROG",
  "MC_FIN_PROG", "MC_DECLARER", "MC_TAB", "MC_DE", "MC_ENTIER", "MC_REEL",
  "MC_CHAR", "MC_BOOL", "MC_LIRE", "MC_AFFICHER", "MC_SI", "MC_ALORS",
  "MC_SINON", "MC_SINON_SI", "MC_FIN_SI", "MC_POUR", "MC_FAIRE",
  "MC_FIN_POUR", "MC_TANT_QUE", "MC_FIN_TQ", "MC_REPETER", "MC_JUSQU_A",
  "OP_ET", "OP_OU", "OP_NON", "BOOL_VRAI", "BOOL_FAUX", "OP_AFFECTATION",
  "OP_PLUS", "OP_MOINS", "OP_MULT", "OP_DIV", "OP_MOD", "OP_PUISS",
  "OP_EGAL", "OP_DIFF", "OP_INF", "OP_INF_EGAL", "OP_SUP", "OP_SUP_EGAL",
  "SEPARATEUR", "DEUX_POINTS", "VIRGULE", "PAR_OUV", "PAR_FERM",
  "CROCH_OUV", "CROCH_FERM", "ACC_OUV", "ACC_FERM", "CONST_ENTIER",
  "CONST_REEL", "CONST_CHAR", "CONST_STRING", "IDENTIFICATEUR", "$accept",
  "programme", "$@1", "declarations", "declaration", "liste_variables",
  "type", "instructions", "instruction", "affectation", "lecture",
  "affichage", "condition", "$@2", "parties_sinon", "$@3", "boucle_pour",
  "$@4", "$@5", "boucle_tant_que", "$@6", "$@7", "bloc_instructions",
  "expression", "bool_expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-108)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-66)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      28,  -108,     3,  -108,  -108,    12,   -17,  -108,     0,     7,
     -22,  -108,    17,    20,    21,    22,  -108,   -10,  -108,    27,
    -108,  -108,  -108,  -108,  -108,    29,   131,    23,    24,    19,
      30,    31,    46,    49,    49,  -108,    44,  -108,  -108,  -108,
    -108,    55,  -108,    14,  -108,  -108,    49,  -108,  -108,  -108,
      52,    56,   119,    30,    65,    71,    63,   142,   -19,    57,
      30,   154,    88,    69,  -108,    64,    49,   125,    66,    49,
      49,    49,    49,    49,    49,    49,    72,  -108,    49,    49,
      49,    49,    49,    49,    30,    30,  -108,  -108,   -11,    86,
     112,  -108,    94,  -108,  -108,   100,   111,   111,   106,   106,
     106,   106,  -108,   154,   154,   154,   154,   154,   154,  -108,
     123,   148,    30,  -108,    49,   157,   117,  -108,   115,   -16,
     149,   154,   131,   124,  -108,   155,    31,   115,   126,  -108,
      13,  -108,   174,   145,   171,  -108,  -108,   115,  -108,  -108,
    -108,  -108,   152,   115,   175,  -108
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     2,     0,     4,     1,    14,     0,     5,     0,     8,
       0,     3,     0,     0,     0,     0,    36,     0,    15,     0,
      17,    18,    19,    20,    21,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    16,     0,    10,    11,    12,
      13,     0,     9,     0,    52,    53,     0,    49,    50,    51,
       0,    47,     0,     0,    52,    53,    47,     0,     0,     0,
       0,    22,     0,     0,     6,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    62,     0,     0,
       0,     0,     0,     0,     0,     0,    28,    33,     0,     0,
       0,    24,     0,    46,    27,     0,    40,    41,    42,    43,
      44,    45,    26,    54,    55,    56,    57,    58,    59,    60,
      61,     0,     0,    37,     0,     0,     0,    48,     0,     0,
       0,    23,     0,     0,    14,    30,     0,     0,     0,    25,
       0,    31,     0,     0,     0,     7,    39,     0,    29,    34,
      38,    32,     0,     0,     0,    35
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -108,  -108,  -108,  -108,  -108,  -108,    73,    74,  -108,   -31,
    -108,  -108,  -108,  -108,  -108,  -108,  -108,  -108,  -108,  -108,
    -108,  -108,  -107,   -28,   -51
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,     5,     7,    10,    41,     8,    18,    19,
      20,    21,    22,   111,   132,   137,    23,   112,   142,    24,
      32,   120,   125,    57,    58
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      59,    52,    77,     4,    11,    61,    62,    84,    85,    88,
      84,    85,    12,    13,    14,    84,    85,     6,    67,    15,
     134,    33,    16,    26,    27,    12,    13,    14,   126,    86,
     141,     1,    15,   109,   110,    16,   144,   113,    92,    34,
       9,    95,    96,    97,    98,    99,   100,   101,    44,    45,
     103,   104,   105,   106,   107,   108,    25,    17,    53,    54,
      55,   119,    65,    66,    28,   136,    46,    29,    30,    31,
      17,    35,    47,    48,    49,    50,    51,    46,    44,    45,
      42,    43,    36,    47,    48,    49,   121,    56,    17,   -65,
     -65,   -63,   -63,    60,    63,   133,    46,   -64,   -64,    64,
      68,    87,    47,    48,    49,    69,    51,   -65,    91,   -63,
      94,   -65,    69,   -63,    90,   -64,   102,   114,   115,   -64,
      70,    71,    72,    73,    74,    75,    70,    71,    72,    73,
      74,    75,    70,    71,    72,    73,    74,    75,    89,    37,
      38,    39,    40,    75,   116,    72,    73,    74,    75,    84,
     117,    70,    71,    72,    73,    74,    75,    70,    71,    72,
      73,    74,    75,   118,   122,   123,   124,    76,   129,   127,
     135,   131,   143,    93,    70,    71,    72,    73,    74,    75,
      78,    79,    80,    81,    82,    83,    70,    71,    72,    73,
      74,    75,   138,   139,   140,   128,   145,     0,   130
};

static const yytype_int16 yycheck[] =
{
      31,    29,    53,     0,     4,    33,    34,    26,    27,    60,
      26,    27,    12,    13,    14,    26,    27,     5,    46,    19,
     127,    31,    22,    45,    46,    12,    13,    14,    44,    48,
     137,     3,    19,    84,    85,    22,   143,    48,    66,    49,
      57,    69,    70,    71,    72,    73,    74,    75,    29,    30,
      78,    79,    80,    81,    82,    83,    49,    57,    28,    29,
      30,   112,    48,    49,    47,    52,    47,    47,    47,    47,
      57,    44,    53,    54,    55,    56,    57,    47,    29,    30,
      57,    57,    53,    53,    54,    55,   114,    57,    57,    26,
      27,    26,    27,    47,    50,   126,    47,    26,    27,    44,
      48,    44,    53,    54,    55,    49,    57,    44,    44,    44,
      44,    48,    49,    48,    45,    44,    44,    31,     6,    48,
      32,    33,    34,    35,    36,    37,    32,    33,    34,    35,
      36,    37,    32,    33,    34,    35,    36,    37,    50,     8,
       9,    10,    11,    37,    50,    34,    35,    36,    37,    26,
      50,    32,    33,    34,    35,    36,    37,    32,    33,    34,
      35,    36,    37,    15,     7,    48,    51,    48,    44,    20,
      44,    16,    20,    48,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    32,    33,    34,    35,
      36,    37,    18,    48,    23,   122,    21,    -1,   124
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    59,    60,     0,    61,     5,    62,    65,    57,
      63,     4,    12,    13,    14,    19,    22,    57,    66,    67,
      68,    69,    70,    74,    77,    49,    45,    46,    47,    47,
      47,    47,    78,    31,    49,    44,    53,     8,     9,    10,
      11,    64,    57,    57,    29,    30,    47,    53,    54,    55,
      56,    57,    81,    28,    29,    30,    57,    81,    82,    67,
      47,    81,    81,    50,    44,    48,    49,    81,    48,    49,
      32,    33,    34,    35,    36,    37,    48,    82,    38,    39,
      40,    41,    42,    43,    26,    27,    48,    44,    82,    50,
      45,    44,    81,    48,    44,    81,    81,    81,    81,    81,
      81,    81,    44,    81,    81,    81,    81,    81,    81,    82,
      82,    71,    75,    48,    31,     6,    50,    50,    15,    82,
      79,    81,     7,    48,    51,    80,    44,    20,    64,    44,
      65,    16,    72,    67,    80,    44,    52,    73,    18,    48,
      23,    80,    76,    20,    80,    21
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    58,    60,    59,    61,    61,    62,    62,    63,    63,
      64,    64,    64,    64,    65,    65,    66,    66,    66,    66,
      66,    66,    67,    67,    68,    68,    69,    69,    71,    70,
      72,    73,    72,    75,    76,    74,    78,    79,    77,    80,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     5,     0,     2,     5,    10,     1,     3,
       1,     1,     1,     1,     0,     2,     2,     1,     1,     1,
       1,     1,     3,     6,     5,     8,     5,     5,     0,     9,
       0,     0,     3,     0,     0,    13,     0,     0,     9,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     4,     1,
       1,     1,     1,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* $@1: %empty  */
#line 78 "parser.y"
                  {
        printf("[LOG] Début du programme\n");
    }
#line 1271 "parser.tab.c"
    break;

  case 3: /* programme: MC_DEBUT_PROG $@1 declarations instructions MC_FIN_PROG  */
#line 80 "parser.y"
                                            {
        printf("[LOG] Fin du programme\n");
        print_quadruplets();
    }
#line 1280 "parser.tab.c"
    break;

  case 6: /* declaration: MC_DECLARER liste_variables DEUX_POINTS type SEPARATEUR  */
#line 93 "parser.y"
                                                            {
        for(int i = 0; i < temp_var_count; i++) {
            add_to_symbol_table_checked(temp_var_names[i], (yyvsp[-1].chaine), 0, 0);
            free(temp_var_names[i]);
        }
        temp_var_count = 0;
        printf("[LOG] Déclaration de variable(s) de type %s\n", (yyvsp[-1].chaine));
    }
#line 1293 "parser.tab.c"
    break;

  case 7: /* declaration: MC_DECLARER IDENTIFICATEUR CROCH_OUV CONST_ENTIER CROCH_FERM DEUX_POINTS MC_TAB MC_DE type SEPARATEUR  */
#line 101 "parser.y"
                                                                                                            {
        if(add_to_symbol_table_checked((yyvsp[-8].chaine), (yyvsp[-1].chaine), 1, (yyvsp[-6].entier)) == 0) {
            char min_str[20] = "0";
            char max_str[20];
            sprintf(max_str, "%d", (yyvsp[-6].entier) - 1);
            insererQuadruplet("BOUNDS", min_str, max_str, "");
            insererQuadruplet("ADEC", (yyvsp[-8].chaine), "", "");
            printf("[LOG] Déclaration tableau: %s[%d] de type %s\n", (yyvsp[-8].chaine), (yyvsp[-6].entier), (yyvsp[-1].chaine));
        }
    }
#line 1308 "parser.tab.c"
    break;

  case 8: /* liste_variables: IDENTIFICATEUR  */
#line 114 "parser.y"
                   {
        temp_var_names[temp_var_count++] = strdup((yyvsp[0].chaine));
    }
#line 1316 "parser.tab.c"
    break;

  case 9: /* liste_variables: liste_variables VIRGULE IDENTIFICATEUR  */
#line 117 "parser.y"
                                             {
        temp_var_names[temp_var_count++] = strdup((yyvsp[0].chaine));
    }
#line 1324 "parser.tab.c"
    break;

  case 10: /* type: MC_ENTIER  */
#line 123 "parser.y"
              { (yyval.chaine) = "ENTIER"; }
#line 1330 "parser.tab.c"
    break;

  case 11: /* type: MC_REEL  */
#line 124 "parser.y"
              {  (yyval.chaine) = "REEL"; }
#line 1336 "parser.tab.c"
    break;

  case 12: /* type: MC_CHAR  */
#line 125 "parser.y"
              {  (yyval.chaine) = "CHAR"; }
#line 1342 "parser.tab.c"
    break;

  case 13: /* type: MC_BOOL  */
#line 126 "parser.y"
              {  (yyval.chaine) = "BOOL"; }
#line 1348 "parser.tab.c"
    break;

  case 22: /* affectation: IDENTIFICATEUR OP_AFFECTATION expression  */
#line 146 "parser.y"
                                             {
        if(!is_declared((yyvsp[-2].chaine))) {
            YYABORT;
        }
        
        char* var_type = strdup(get_type((yyvsp[-2].chaine)));
        
        if(!types_compatibles(var_type, (yyvsp[0].expr_info).type)) {
            char error[200];
            sprintf(error, "Type incompatible : affectation de %s à %s", 
                    (yyvsp[0].expr_info).type, var_type);
            yyerror(error);
            YYABORT;
        }
        
        insererQuadruplet(":=", (yyvsp[0].expr_info).addr, "", (yyvsp[-2].chaine));
        mark_initialized((yyvsp[-2].chaine));
        
        printf("[SEMANTIQUE] Affectation: %s := %s (type %s)\n", 
               (yyvsp[-2].chaine), (yyvsp[0].expr_info).addr, (yyvsp[0].expr_info).type);
    }
#line 1374 "parser.tab.c"
    break;

  case 23: /* affectation: IDENTIFICATEUR CROCH_OUV expression CROCH_FERM OP_AFFECTATION expression  */
#line 168 "parser.y"
                                                                               {
        if(!is_declared((yyvsp[-5].chaine))) {
            YYABORT;
        }
        
        SymbolEntry* sym = find_symbol((yyvsp[-5].chaine));
        if(!sym->is_array) {
            char error[200];
            sprintf(error, "'%s' n'est pas un tableau", (yyvsp[-5].chaine));
            yyerror(error);
            YYABORT;
        }
        
        if(strcmp((yyvsp[-3].expr_info).type, "ENTIER") != 0) {
            yyerror("L'indice d'un tableau doit être de type ENTIER");
            YYABORT;
        }
        
        char* array_type = get_type((yyvsp[-5].chaine));
        if(!types_compatibles(array_type, (yyvsp[0].expr_info).type)) {
            char error[200];
            sprintf(error, "Type incompatible pour le tableau '%s'", (yyvsp[-5].chaine));
            yyerror(error);
            YYABORT;
        }
        
        char* temp = new_temp();
        insererQuadruplet("+", (yyvsp[-5].chaine), (yyvsp[-3].expr_info).addr, temp);
        insererQuadruplet("[]=", (yyvsp[0].expr_info).addr, "", temp);
        
        printf("[SEMANTIQUE] Affectation tableau: %s[%s] := %s\n", 
               (yyvsp[-5].chaine), (yyvsp[-3].expr_info).addr, (yyvsp[0].expr_info).addr);
    }
#line 1412 "parser.tab.c"
    break;

  case 24: /* lecture: MC_LIRE PAR_OUV IDENTIFICATEUR PAR_FERM SEPARATEUR  */
#line 205 "parser.y"
                                                       {
        if(!is_declared((yyvsp[-2].chaine))) {
            YYABORT;
        }
        
        insererQuadruplet("READ", "", "", (yyvsp[-2].chaine));
        mark_initialized((yyvsp[-2].chaine));
        
        printf("[LOG] Lecture: LIRE(%s)\n", (yyvsp[-2].chaine));
    }
#line 1427 "parser.tab.c"
    break;

  case 25: /* lecture: MC_LIRE PAR_OUV IDENTIFICATEUR CROCH_OUV expression CROCH_FERM PAR_FERM SEPARATEUR  */
#line 216 "parser.y"
                                                                                         {
        if(!is_declared((yyvsp[-5].chaine))) {
            YYABORT;
        }
        
        SymbolEntry* sym = find_symbol((yyvsp[-5].chaine));
        if(!sym->is_array) {
            char error[200];
            sprintf(error, "'%s' n'est pas un tableau", (yyvsp[-5].chaine));
            yyerror(error);
            YYABORT;
        }
        
        if(strcmp((yyvsp[-3].expr_info).type, "ENTIER") != 0) {
            yyerror("L'indice d'un tableau doit être de type ENTIER");
            YYABORT;
        }
        
        char* temp = new_temp();
        insererQuadruplet("+", (yyvsp[-5].chaine), (yyvsp[-3].expr_info).addr, temp);
        insererQuadruplet("READ", "", "", temp);
        
        printf("[LOG] Lecture tableau: LIRE(%s[%s])\n", (yyvsp[-5].chaine), (yyvsp[-3].expr_info).addr);
    }
#line 1456 "parser.tab.c"
    break;

  case 26: /* affichage: MC_AFFICHER PAR_OUV expression PAR_FERM SEPARATEUR  */
#line 244 "parser.y"
                                                       {
        insererQuadruplet("WRITE", (yyvsp[-2].expr_info).addr, "", "");
        printf("[LOG] Affichage de %s (type %s)\n", (yyvsp[-2].expr_info).addr, (yyvsp[-2].expr_info).type);
    }
#line 1465 "parser.tab.c"
    break;

  case 27: /* affichage: MC_AFFICHER PAR_OUV CONST_STRING PAR_FERM SEPARATEUR  */
#line 248 "parser.y"
                                                           {
        insererQuadruplet("WRITE", (yyvsp[-2].chaine), "", "");
        printf("[LOG] Affichage de chaîne: %s\n", (yyvsp[-2].chaine));
    }
#line 1474 "parser.tab.c"
    break;

  case 28: /* $@2: %empty  */
#line 256 "parser.y"
                                     {
        if(strcmp((yyvsp[-1].expr_info).type, "BOOL") != 0) {
            yyerror("La condition doit être de type BOOL");
            YYABORT;
        }
        
        char* label_else = new_label();
        char* label_fin = new_label();
        
        insererQuadruplet("BZ", (yyvsp[-1].expr_info).addr, "", label_else);
        
        push_label(label_fin);
        push_label(label_else);
        
    }
#line 1494 "parser.tab.c"
    break;

  case 29: /* condition: MC_SI PAR_OUV bool_expr PAR_FERM $@2 MC_ALORS bloc_instructions parties_sinon MC_FIN_SI  */
#line 270 "parser.y"
                                                         {
        char* label_fin = label_stack.labels[label_stack.top - 1];
        insererQuadruplet("", label_fin, "", "");
        
        pop_label();
        pop_label();
    }
#line 1506 "parser.tab.c"
    break;

  case 30: /* parties_sinon: %empty  */
#line 280 "parser.y"
               {
        char* label_else = peek_label();
        insererQuadruplet("", label_else, "", "");
    }
#line 1515 "parser.tab.c"
    break;

  case 31: /* $@3: %empty  */
#line 285 "parser.y"
               {
        char* label_fin = label_stack.labels[label_stack.top - 1];
        insererQuadruplet("BR", "", "", label_fin);
        
        char* label_else = peek_label();
        insererQuadruplet("", label_else, "", "");
        
    }
#line 1528 "parser.tab.c"
    break;

  case 33: /* $@4: %empty  */
#line 297 "parser.y"
                                           {
        char* label_test = new_label();
        insererQuadruplet("", label_test, "", "");
        push_label(label_test);
        
    }
#line 1539 "parser.tab.c"
    break;

  case 34: /* $@5: %empty  */
#line 302 "parser.y"
                                                {
        if(strcmp((yyvsp[-3].expr_info).type, "BOOL") != 0) {
            yyerror("La condition de POUR doit être de type BOOL");
            YYABORT;
        }
        
        char* label_fin = new_label();
        char* label_corps = new_label();
        
        insererQuadruplet("BZ", (yyvsp[-3].expr_info).addr, "", label_fin);
        insererQuadruplet("BR", "", "", label_corps);
        
        char* label_incr = new_label();
        insererQuadruplet("", label_incr, "", "");
        
        push_label(label_incr);
        push_label(label_fin);
        push_label(label_corps);
        
        char* label_test = label_stack.labels[label_stack.top - 3];
        insererQuadruplet("BR", "", "", label_test);
        
        char* label_corps_final = pop_label();
        insererQuadruplet("", label_corps_final, "", "");
        
    }
#line 1570 "parser.tab.c"
    break;

  case 35: /* boucle_pour: MC_POUR PAR_OUV affectation SEPARATEUR $@4 bool_expr SEPARATEUR affectation PAR_FERM $@5 MC_FAIRE bloc_instructions MC_FIN_POUR  */
#line 327 "parser.y"
                                             {
        char* label_incr = label_stack.labels[label_stack.top - 1];
        insererQuadruplet("BR", "", "", label_incr);
        
        char* label_fin = pop_label();
        insererQuadruplet("", label_fin, "", "");
        
        pop_label();
        pop_label();
    }
#line 1585 "parser.tab.c"
    break;

  case 36: /* $@6: %empty  */
#line 341 "parser.y"
                {
        char* label_test = new_label();
        insererQuadruplet("", label_test, "", "");
        push_label(label_test);
        
    }
#line 1596 "parser.tab.c"
    break;

  case 37: /* $@7: %empty  */
#line 346 "parser.y"
                                 {
        if(strcmp((yyvsp[-1].expr_info).type, "BOOL") != 0) {
            yyerror("La condition de TANT_QUE doit être BOOL");
            YYABORT;
        }
        
        char* label_fin = new_label();
        insererQuadruplet("BZ", (yyvsp[-1].expr_info).addr, "", label_fin);
        push_label(label_fin);
        
    }
#line 1612 "parser.tab.c"
    break;

  case 38: /* boucle_tant_que: MC_TANT_QUE $@6 PAR_OUV bool_expr PAR_FERM $@7 MC_FAIRE bloc_instructions MC_FIN_TQ  */
#line 356 "parser.y"
                                           {
        char* label_test = label_stack.labels[label_stack.top - 1];
        insererQuadruplet("BR", "", "", label_test);
        
        char* label_fin = pop_label();
        insererQuadruplet("", label_fin, "", "");
        
        pop_label();
    }
#line 1626 "parser.tab.c"
    break;

  case 40: /* expression: expression OP_PLUS expression  */
#line 374 "parser.y"
                                  {
        if(!is_numeric((yyvsp[-2].expr_info).type) || !is_numeric((yyvsp[0].expr_info).type)) {
            yyerror("Opération + sur types non numériques");
            YYABORT;
        }
        
        (yyval.expr_info).addr = new_temp();
        (yyval.expr_info).type = result_type((yyvsp[-2].expr_info).type, (yyvsp[0].expr_info).type);
        insererQuadruplet("+", (yyvsp[-2].expr_info).addr, (yyvsp[0].expr_info).addr, (yyval.expr_info).addr);
    }
#line 1641 "parser.tab.c"
    break;

  case 41: /* expression: expression OP_MOINS expression  */
#line 385 "parser.y"
                                     {
        if(!is_numeric((yyvsp[-2].expr_info).type) || !is_numeric((yyvsp[0].expr_info).type)) {
            yyerror("Opération - sur types non numériques");
            YYABORT;
        }
        
        (yyval.expr_info).addr = new_temp();
        (yyval.expr_info).type = result_type((yyvsp[-2].expr_info).type, (yyvsp[0].expr_info).type);
        insererQuadruplet("-", (yyvsp[-2].expr_info).addr, (yyvsp[0].expr_info).addr, (yyval.expr_info).addr);
    }
#line 1656 "parser.tab.c"
    break;

  case 42: /* expression: expression OP_MULT expression  */
#line 396 "parser.y"
                                    {
        if(!is_numeric((yyvsp[-2].expr_info).type) || !is_numeric((yyvsp[0].expr_info).type)) {
            yyerror("Opération * sur types non numériques");
            YYABORT;
        }
        
        (yyval.expr_info).addr = new_temp();
        (yyval.expr_info).type = result_type((yyvsp[-2].expr_info).type, (yyvsp[0].expr_info).type);
        insererQuadruplet("*", (yyvsp[-2].expr_info).addr, (yyvsp[0].expr_info).addr, (yyval.expr_info).addr);
    }
#line 1671 "parser.tab.c"
    break;

  case 43: /* expression: expression OP_DIV expression  */
#line 407 "parser.y"
                                   {
        if(!is_numeric((yyvsp[-2].expr_info).type) || !is_numeric((yyvsp[0].expr_info).type)) {
            yyerror("Opération / sur types non numériques");
            YYABORT;
        }
        
        (yyval.expr_info).addr = new_temp();
        (yyval.expr_info).type = result_type((yyvsp[-2].expr_info).type, (yyvsp[0].expr_info).type);
        insererQuadruplet("/", (yyvsp[-2].expr_info).addr, (yyvsp[0].expr_info).addr, (yyval.expr_info).addr);
    }
#line 1686 "parser.tab.c"
    break;

  case 44: /* expression: expression OP_MOD expression  */
#line 418 "parser.y"
                                   {
        if(strcmp((yyvsp[-2].expr_info).type, "ENTIER") != 0 || strcmp((yyvsp[0].expr_info).type, "ENTIER") != 0) {
            yyerror("Opération % réservée aux ENTIER");
            YYABORT;
        }
        
        (yyval.expr_info).addr = new_temp();
        (yyval.expr_info).type = strdup("ENTIER");
        insererQuadruplet("%", (yyvsp[-2].expr_info).addr, (yyvsp[0].expr_info).addr, (yyval.expr_info).addr);
    }
#line 1701 "parser.tab.c"
    break;

  case 45: /* expression: expression OP_PUISS expression  */
#line 429 "parser.y"
                                     {
        if(!is_numeric((yyvsp[-2].expr_info).type) || !is_numeric((yyvsp[0].expr_info).type)) {
            yyerror("Opération ^ sur types non numériques");
            YYABORT;
        }
        
        (yyval.expr_info).addr = new_temp();
        (yyval.expr_info).type = result_type((yyvsp[-2].expr_info).type, (yyvsp[0].expr_info).type);
        insererQuadruplet("^", (yyvsp[-2].expr_info).addr, (yyvsp[0].expr_info).addr, (yyval.expr_info).addr);
    }
#line 1716 "parser.tab.c"
    break;

  case 46: /* expression: PAR_OUV expression PAR_FERM  */
#line 440 "parser.y"
                                  {
        (yyval.expr_info) = (yyvsp[-1].expr_info);
    }
#line 1724 "parser.tab.c"
    break;

  case 47: /* expression: IDENTIFICATEUR  */
#line 444 "parser.y"
                     {
        if(!is_declared((yyvsp[0].chaine))) {
            YYABORT;
        }
        
        (yyval.expr_info).addr = (yyvsp[0].chaine);
        (yyval.expr_info).type = strdup(get_type((yyvsp[0].chaine)));
    }
#line 1737 "parser.tab.c"
    break;

  case 48: /* expression: IDENTIFICATEUR CROCH_OUV expression CROCH_FERM  */
#line 453 "parser.y"
                                                     {
        if(!is_declared((yyvsp[-3].chaine))) {
            YYABORT;
        }
        
        SymbolEntry* sym = find_symbol((yyvsp[-3].chaine));
        if(!sym->is_array) {
            char error[200];
            sprintf(error, "'%s' n'est pas un tableau", (yyvsp[-3].chaine));
            yyerror(error);
            YYABORT;
        }
        
        if(strcmp((yyvsp[-1].expr_info).type, "ENTIER") != 0) {
            yyerror("L'indice d'un tableau doit être de type ENTIER");
            YYABORT;
        }
        
        char* temp1 = new_temp();
        char* temp2 = new_temp();
        insererQuadruplet("+", (yyvsp[-3].chaine), (yyvsp[-1].expr_info).addr, temp1);
        insererQuadruplet("=[]", temp1, "", temp2);

        (yyval.expr_info).addr = temp2;
        (yyval.expr_info).type = strdup(get_type((yyvsp[-3].chaine)));
    }
#line 1768 "parser.tab.c"
    break;

  case 49: /* expression: CONST_ENTIER  */
#line 480 "parser.y"
                   {
        char* temp = new_temp();
        char val[20];
        sprintf(val, "%d", (yyvsp[0].entier));
        
        insererQuadruplet(":=", val, "", temp);
        
        (yyval.expr_info).addr = temp;
        (yyval.expr_info).type = strdup("ENTIER");
    }
#line 1783 "parser.tab.c"
    break;

  case 50: /* expression: CONST_REEL  */
#line 491 "parser.y"
                 {
        char* temp = new_temp();
        char val[20];
        sprintf(val, "%.2f", (yyvsp[0].reel));
        
        insererQuadruplet(":=", val, "", temp);
        
        (yyval.expr_info).addr = temp;
        (yyval.expr_info).type = strdup("REEL");
    }
#line 1798 "parser.tab.c"
    break;

  case 51: /* expression: CONST_CHAR  */
#line 502 "parser.y"
                 {
        char* temp = new_temp();
        char val[20];
        sprintf(val, "'%c'", (yyvsp[0].caractere));
        
        insererQuadruplet(":=", val, "", temp);
        
        (yyval.expr_info).addr = temp;
        (yyval.expr_info).type = strdup("CHAR");
    }
#line 1813 "parser.tab.c"
    break;

  case 52: /* expression: BOOL_VRAI  */
#line 513 "parser.y"
                {
        char* temp = new_temp();
        insererQuadruplet(":=", "true", "", temp);
        
        (yyval.expr_info).addr = temp;
        (yyval.expr_info).type = strdup("BOOL");
    }
#line 1825 "parser.tab.c"
    break;

  case 53: /* expression: BOOL_FAUX  */
#line 521 "parser.y"
                {
        char* temp = new_temp();
        insererQuadruplet(":=", "false", "", temp);
        
        (yyval.expr_info).addr = temp;
        (yyval.expr_info).type = strdup("BOOL");
    }
#line 1837 "parser.tab.c"
    break;

  case 54: /* bool_expr: expression OP_EGAL expression  */
#line 533 "parser.y"
                                  {
        if(!is_numeric((yyvsp[-2].expr_info).type) || !is_numeric((yyvsp[0].expr_info).type)) {
            yyerror("Comparaison == sur types non numériques");
            YYABORT;
        }
        
        (yyval.expr_info).addr = new_temp();
        (yyval.expr_info).type = strdup("BOOL");
        insererQuadruplet("==", (yyvsp[-2].expr_info).addr, (yyvsp[0].expr_info).addr, (yyval.expr_info).addr);
    }
#line 1852 "parser.tab.c"
    break;

  case 55: /* bool_expr: expression OP_DIFF expression  */
#line 544 "parser.y"
                                    {
        if(!is_numeric((yyvsp[-2].expr_info).type) || !is_numeric((yyvsp[0].expr_info).type)) {
            yyerror("Comparaison != sur types non numériques");
            YYABORT;
        }
        
        (yyval.expr_info).addr = new_temp();
        (yyval.expr_info).type = strdup("BOOL");
        insererQuadruplet("!=", (yyvsp[-2].expr_info).addr, (yyvsp[0].expr_info).addr, (yyval.expr_info).addr);
    }
#line 1867 "parser.tab.c"
    break;

  case 56: /* bool_expr: expression OP_INF expression  */
#line 555 "parser.y"
                                   {
        if(!is_numeric((yyvsp[-2].expr_info).type) || !is_numeric((yyvsp[0].expr_info).type)) {
            yyerror("Comparaison < sur types non numériques");
            YYABORT;
        }
        
        (yyval.expr_info).addr = new_temp();
        (yyval.expr_info).type = strdup("BOOL");
        insererQuadruplet("<", (yyvsp[-2].expr_info).addr, (yyvsp[0].expr_info).addr, (yyval.expr_info).addr);
    }
#line 1882 "parser.tab.c"
    break;

  case 57: /* bool_expr: expression OP_INF_EGAL expression  */
#line 566 "parser.y"
                                        {
        (yyval.expr_info).addr = new_temp();
        (yyval.expr_info).type = strdup("BOOL");
        insererQuadruplet("<=", (yyvsp[-2].expr_info).addr, (yyvsp[0].expr_info).addr, (yyval.expr_info).addr);
    }
#line 1892 "parser.tab.c"
    break;

  case 58: /* bool_expr: expression OP_SUP expression  */
#line 572 "parser.y"
                                   {
        (yyval.expr_info).addr = new_temp();
        (yyval.expr_info).type = strdup("BOOL");
        insererQuadruplet(">", (yyvsp[-2].expr_info).addr, (yyvsp[0].expr_info).addr, (yyval.expr_info).addr);
    }
#line 1902 "parser.tab.c"
    break;

  case 59: /* bool_expr: expression OP_SUP_EGAL expression  */
#line 578 "parser.y"
                                        {
        (yyval.expr_info).addr = new_temp();
        (yyval.expr_info).type = strdup("BOOL");
        insererQuadruplet(">=", (yyvsp[-2].expr_info).addr, (yyvsp[0].expr_info).addr, (yyval.expr_info).addr);
    }
#line 1912 "parser.tab.c"
    break;

  case 60: /* bool_expr: bool_expr OP_ET bool_expr  */
#line 584 "parser.y"
                                {
        if(strcmp((yyvsp[-2].expr_info).type, "BOOL") != 0 || strcmp((yyvsp[0].expr_info).type, "BOOL") != 0) {
            yyerror("Opération ET sur types non booléens");
            YYABORT;
        }
        
        (yyval.expr_info).addr = new_temp();
        (yyval.expr_info).type = strdup("BOOL");
        insererQuadruplet("ET", (yyvsp[-2].expr_info).addr, (yyvsp[0].expr_info).addr, (yyval.expr_info).addr);
    }
#line 1927 "parser.tab.c"
    break;

  case 61: /* bool_expr: bool_expr OP_OU bool_expr  */
#line 595 "parser.y"
                                {
        if(strcmp((yyvsp[-2].expr_info).type, "BOOL") != 0 || strcmp((yyvsp[0].expr_info).type, "BOOL") != 0) {
            yyerror("Opération OU sur types non booléens");
            YYABORT;
        }
        
        (yyval.expr_info).addr = new_temp();
        (yyval.expr_info).type = strdup("BOOL");
        insererQuadruplet("OU", (yyvsp[-2].expr_info).addr, (yyvsp[0].expr_info).addr, (yyval.expr_info).addr);
    }
#line 1942 "parser.tab.c"
    break;

  case 62: /* bool_expr: OP_NON bool_expr  */
#line 606 "parser.y"
                       {
        if(strcmp((yyvsp[0].expr_info).type, "BOOL") != 0) {
            yyerror("Opération NON sur type non booléen");
            YYABORT;
        }
        
        (yyval.expr_info).addr = new_temp();
        (yyval.expr_info).type = strdup("BOOL");
        insererQuadruplet("NON", (yyvsp[0].expr_info).addr, "", (yyval.expr_info).addr);
    }
#line 1957 "parser.tab.c"
    break;

  case 63: /* bool_expr: BOOL_VRAI  */
#line 617 "parser.y"
                {
        char* temp = new_temp();
        insererQuadruplet(":=", "true", "", temp);
        
        (yyval.expr_info).addr = temp;
        (yyval.expr_info).type = strdup("BOOL");
    }
#line 1969 "parser.tab.c"
    break;

  case 64: /* bool_expr: BOOL_FAUX  */
#line 625 "parser.y"
                {
        char* temp = new_temp();
        insererQuadruplet(":=", "false", "", temp);
        
        (yyval.expr_info).addr = temp;
        (yyval.expr_info).type = strdup("BOOL");
    }
#line 1981 "parser.tab.c"
    break;

  case 65: /* bool_expr: IDENTIFICATEUR  */
#line 633 "parser.y"
                     {
        if(!is_declared((yyvsp[0].chaine))) {
            YYABORT;
        }
        
        char* var_type = get_type((yyvsp[0].chaine));
        if(strcmp(var_type, "BOOL") != 0) {
            char error[200];
            sprintf(error, "'%s' n'est pas de type BOOL", (yyvsp[0].chaine));
            yyerror(error);
            YYABORT;
        }
        
        (yyval.expr_info).addr = (yyvsp[0].chaine);
        (yyval.expr_info).type = strdup("BOOL");
    }
#line 2002 "parser.tab.c"
    break;


#line 2006 "parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 651 "parser.y"


/* ==================== FONCTIONS AUXILIAIRES ==================== */
void yyerror(const char* s) {
    fprintf(stderr, "File \"input\", line %d, character %d: %s\n", 
            line_number, column_number, s);
}

int main(int argc, char** argv) {
    FILE* input_file;
    
    init_stack();
    
    printf("=================================================\n");
    printf("  ANALYSEUR COMPLET POUR LE LANGAGE SIMPL\n");
    printf("=================================================\n\n");
    
    if(argc > 1) {
        input_file = fopen(argv[1], "r");
        if(!input_file) {
            fprintf(stderr, "Erreur: Impossible d'ouvrir '%s'\n", argv[1]);
            return 1;
        }
        yyin = input_file;
    } else {
        printf("Usage: %s <fichier.simpl>\n", argv[0]);
        return 1;
    }
    
    printf("--- ANALYSE EN COURS ---\n\n");
    
    int result = yyparse();
    
    printf("\n--- FIN DE L'ANALYSE ---\n");
    
    if(result == 0) {
        printf("\n COMPILATION RÉUSSIE!\n\n");
        print_symbol_table();
    } else {
        printf("\n COMPILATION ÉCHOUÉE\n");
    }
    
    if(argc > 1) fclose(input_file);
    
    return result;
}
