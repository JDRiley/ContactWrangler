/* A Bison parser, made by GNU Bison 2.7.  */

/* Skeleton implementation for Bison LALR(1) parsers in C++
   
      Copyright (C) 2002-2012 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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


/* First part of user declarations.  */
/* Line 279 of lalr1.cc  */
#line 11 "parser.y"


/* Just like lex, the text within this first region delimited by %{ and %}
 * is assumed to be C/C++ code and will be copied verbatim to the y.tab.c
 * file ahead of the definitions of the yyparse() function. Add other header
 * file inclusions or C++ variable declarations/prototypes that are needed
 * by your code here.
 */
//#include "Math_Lexer.h" // for yylex
#include "Rule_Implementor_Fwd_Decl.h"

#include "parser.h"
#include "Rule_Parser.h"
#include "Constant_Symbol.h"


using namespace jomike;
void yyerror(const char *msg); // standard error-handling routine

j_symbol_component* jtl::g_input_line = nullptr;



//template<typename... Args>
//void delete_tokens(Args... i_ptrs){
//	j_symbol_component* pointers[] = {i_ptrs...};
//#ifdef WIN32
//	for(auto f_pointer : pointers){
//		delete f_pointer;
//	}
//#else
//	int size = safe_int_cast(sizeof(pointers)/sizeof(Syntax_Tree_Component*));
//	for(int i=0; i < size; i++){
//		delete pointers[i];
//	}
//#endif
//
//}


/* Line 279 of lalr1.cc  */
#line 79 "rule_parsing_unit.cc"


#include "rule_parsing_unit.hh"

/* User implementation prologue.  */

/* Line 285 of lalr1.cc  */
#line 87 "rule_parsing_unit.cc"


# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* FIXME: INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (/*CONSTCOND*/ false)
# endif


/* Suppress unused-variable warnings by "using" E.  */
#define YYUSE(e) ((void) (e))

/* Enable debugging if requested.  */
#if YYDEBUG

/* A pseudo ostream that takes yydebug_ into account.  */
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)	\
do {							\
  if (yydebug_)						\
    {							\
      *yycdebug_ << Title << ' ';			\
      yy_symbol_print_ ((Type), (Value), (Location));	\
      *yycdebug_ << std::endl;				\
    }							\
} while (false)

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug_)				\
    yy_reduce_print_ (Rule);		\
} while (false)

# define YY_STACK_PRINT()		\
do {					\
  if (yydebug_)				\
    yystack_print_ ();			\
} while (false)

#else /* !YYDEBUG */

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Type, Value, Location) YYUSE(Type)
# define YY_REDUCE_PRINT(Rule)        static_cast<void>(0)
# define YY_STACK_PRINT()             static_cast<void>(0)

#endif /* !YYDEBUG */

#define yyerrok		(yyerrstatus_ = 0)
#define yyclearin	(yychar = yyempty_)

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace yy {
/* Line 353 of lalr1.cc  */
#line 182 "rule_parsing_unit.cc"

  /// Build a parser object.
  Rule_Parsing_Unit::Rule_Parsing_Unit (jtl::Rule_Implementor** i_rule_implementor_yyarg, jtl::Rule_Parser* i_parser_yyarg, jtl::Rule_Data i_rule_data_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      i_rule_implementor (i_rule_implementor_yyarg),
      i_parser (i_parser_yyarg),
      i_rule_data (i_rule_data_yyarg)
  {
  }

  Rule_Parsing_Unit::~Rule_Parsing_Unit ()
  {
  }

#if YYDEBUG
  /*--------------------------------.
  | Print this symbol on YYOUTPUT.  |
  `--------------------------------*/

  inline void
  Rule_Parsing_Unit::yy_symbol_value_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yyvaluep);
    std::ostream& yyo = debug_stream ();
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    switch (yytype)
      {
         default:
	  break;
      }
  }


  void
  Rule_Parsing_Unit::yy_symbol_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    *yycdebug_ << (yytype < yyntokens_ ? "token" : "nterm")
	       << ' ' << yytname_[yytype] << " ("
	       << *yylocationp << ": ";
    yy_symbol_value_print_ (yytype, yyvaluep, yylocationp);
    *yycdebug_ << ')';
  }
#endif

  void
  Rule_Parsing_Unit::yydestruct_ (const char* yymsg,
			   int yytype, semantic_type* yyvaluep, location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yymsg);
    YYUSE (yyvaluep);

    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

    switch (yytype)
      {
  
	default:
	  break;
      }
  }

  void
  Rule_Parsing_Unit::yypop_ (unsigned int n)
  {
    yystate_stack_.pop (n);
    yysemantic_stack_.pop (n);
    yylocation_stack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Rule_Parsing_Unit::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Rule_Parsing_Unit::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Rule_Parsing_Unit::debug_level_type
  Rule_Parsing_Unit::debug_level () const
  {
    return yydebug_;
  }

  void
  Rule_Parsing_Unit::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif

  inline bool
  Rule_Parsing_Unit::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  Rule_Parsing_Unit::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Rule_Parsing_Unit::parse ()
  {
    /// Lookahead and lookahead in internal form.
    int yychar = yyempty_;
    int yytoken = 0;

    // State.
    int yyn;
    int yylen = 0;
    int yystate = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// Semantic value of the lookahead.
    static semantic_type yyval_default;
    semantic_type yylval = yyval_default;
    /// Location of the lookahead.
    location_type yylloc;
    /// The locations where the error started and ended.
    location_type yyerror_range[3];

    /// $$.
    semantic_type yyval;
    /// @$.
    location_type yyloc;

    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    /* Initialize the stacks.  The initial state will be pushed in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystate_stack_ = state_stack_type (0);
    yysemantic_stack_ = semantic_stack_type (0);
    yylocation_stack_ = location_stack_type (0);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* New state.  */
  yynewstate:
    yystate_stack_.push (yystate);
    YYCDEBUG << "Entering state " << yystate << std::endl;

    /* Accept?  */
    if (yystate == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    /* Backup.  */
  yybackup:

    /* Try to take a decision without lookahead.  */
    yyn = yypact_[yystate];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    /* Read a lookahead token.  */
    if (yychar == yyempty_)
      {
        YYCDEBUG << "Reading a token: ";
        yychar = yylex (&yylval, &yylloc, i_parser);
      }

    /* Convert token to internal form.  */
    if (yychar <= yyeof_)
      {
	yychar = yytoken = yyeof_;
	YYCDEBUG << "Now at end of input." << std::endl;
      }
    else
      {
	yytoken = yytranslate_ (yychar);
	YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
      }

    /* If the proper action on seeing token YYTOKEN is to reduce or to
       detect an error, take that action.  */
    yyn += yytoken;
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yytoken)
      goto yydefault;

    /* Reduce or error.  */
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
	if (yy_table_value_is_error_ (yyn))
	  goto yyerrlab;
	yyn = -yyn;
	goto yyreduce;
      }

    /* Shift the lookahead token.  */
    YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

    /* Discard the token being shifted.  */
    yychar = yyempty_;

    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* Count tokens shifted since error; after three, turn off error
       status.  */
    if (yyerrstatus_)
      --yyerrstatus_;

    yystate = yyn;
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystate];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    /* If YYLEN is nonzero, implement the default value of the action:
       `$$ = $1'.  Otherwise, use the top of the stack.

       Otherwise, the following line sets YYVAL to garbage.
       This behavior is undocumented and Bison
       users should not rely upon it.  */
    if (yylen)
      yyval = yysemantic_stack_[yylen - 1];
    else
      yyval = yysemantic_stack_[0];

    // Compute the default @$.
    {
      slice<location_type, location_stack_type> slice (yylocation_stack_, yylen);
      YYLLOC_DEFAULT (yyloc, slice, yylen);
    }

    // Perform the reduction.
    YY_REDUCE_PRINT (yyn);
    switch (yyn)
      {
          case 2:
/* Line 670 of lalr1.cc  */
#line 205 "parser.y"
    {
	*i_rule_implementor = new Rule_Implementor((yysemantic_stack_[(4) - (3)].state_spec_list), i_rule_data);
	return true;
}
    break;

  case 3:
/* Line 670 of lalr1.cc  */
#line 212 "parser.y"
    {
	(yyval.state_decl_list) = new State_Declaration_List;
	(yyval.state_decl_list)->add_symbol((yysemantic_stack_[(1) - (1)].state_decl));
}
    break;

  case 4:
/* Line 670 of lalr1.cc  */
#line 216 "parser.y"
    {
	(yyval.state_decl_list) = (yysemantic_stack_[(2) - (1)].state_decl_list);
	(yyval.state_decl_list)->add_symbol((yysemantic_stack_[(2) - (2)].state_decl));
	(yyloc);
}
    break;

  case 5:
/* Line 670 of lalr1.cc  */
#line 223 "parser.y"
    {
	(yyval.state_decl) = new State_Declaration((yysemantic_stack_[(4) - (3)].identifier));
}
    break;

  case 6:
/* Line 670 of lalr1.cc  */
#line 226 "parser.y"
    {
	(yyval.state_decl) = new State_Declaration((yysemantic_stack_[(5) - (3)].identifier), (yysemantic_stack_[(5) - (4)].declaration_list));
}
    break;

  case 7:
/* Line 670 of lalr1.cc  */
#line 232 "parser.y"
    {
	(yyval.state_spec_list) = new State_Specification_List;
	(yyval.state_spec_list)->add_symbol((yysemantic_stack_[(1) - (1)].state_spec));
}
    break;

  case 8:
/* Line 670 of lalr1.cc  */
#line 236 "parser.y"
    {
	(yyval.state_spec_list) = (yysemantic_stack_[(2) - (1)].state_spec_list);
	(yyval.state_spec_list)->add_symbol((yysemantic_stack_[(2) - (2)].state_spec));
}
    break;

  case 9:
/* Line 670 of lalr1.cc  */
#line 243 "parser.y"
    {
	(yyval.state_spec) = new State_Specification((yysemantic_stack_[(5) - (3)].state_id), *(yysemantic_stack_[(5) - (5)].declaration_list));
}
    break;

  case 10:
/* Line 670 of lalr1.cc  */
#line 252 "parser.y"
    {
	(yyval.declaration_list) = (yysemantic_stack_[(3) - (2)].declaration_list);
}
    break;

  case 11:
/* Line 670 of lalr1.cc  */
#line 258 "parser.y"
    {

}
    break;

  case 12:
/* Line 670 of lalr1.cc  */
#line 261 "parser.y"
    {
	i_rule_data.add_filter((yysemantic_stack_[(2) - (2)].filter));
}
    break;

  case 13:
/* Line 670 of lalr1.cc  */
#line 267 "parser.y"
    {
	(yyval.filter) = new Wrangler_Filter((yysemantic_stack_[(5) - (3)].identifier), (yysemantic_stack_[(5) - (4)].filter_spec));
}
    break;

  case 14:
/* Line 670 of lalr1.cc  */
#line 273 "parser.y"
    {
	(yyval.filter_spec) = i_rule_data.get_filter((yysemantic_stack_[(1) - (1)].identifier)->identifier_name()).get_copy();
}
    break;

  case 15:
/* Line 670 of lalr1.cc  */
#line 276 "parser.y"
    {
	(yyval.filter_spec) = new Negated_Filter_Specification((yysemantic_stack_[(2) - (2)].filter_spec));
}
    break;

  case 16:
/* Line 670 of lalr1.cc  */
#line 279 "parser.y"
    {
	(yyval.filter_spec) = new Has_Filter_Specification(*(yysemantic_stack_[(5) - (4)].string_list));
	(yysemantic_stack_[(5) - (4)].string_list).destroy();
}
    break;

  case 17:
/* Line 670 of lalr1.cc  */
#line 283 "parser.y"
    {
	(yyval.filter_spec) = new Combined_Filter_Specification((yysemantic_stack_[(3) - (1)].filter_spec), (yysemantic_stack_[(3) - (3)].filter_spec));
}
    break;

  case 18:
/* Line 670 of lalr1.cc  */
#line 286 "parser.y"
    {
	(yyval.filter_spec) = (yysemantic_stack_[(3) - (2)].filter_spec);
}
    break;

  case 19:
/* Line 670 of lalr1.cc  */
#line 293 "parser.y"
    {
	(yyval.string_list) = new String_Constant_Symbol_List;
	(yyval.string_list)->add_symbol((yysemantic_stack_[(1) - (1)].string_constant));
}
    break;

  case 20:
/* Line 670 of lalr1.cc  */
#line 297 "parser.y"
    {
	(yyval.string_list) = (yysemantic_stack_[(3) - (1)].string_list);
	(yyval.string_list)->add_symbol((yysemantic_stack_[(3) - (3)].string_constant));
}
    break;

  case 21:
/* Line 670 of lalr1.cc  */
#line 304 "parser.y"
    {
	(yyval.state_id) = new State_ID((yysemantic_stack_[(1) - (1)].identifier));
}
    break;

  case 22:
/* Line 670 of lalr1.cc  */
#line 307 "parser.y"
    {
	(yyval.state_id) = new State_ID(new J_Symbol_Identifier("*"));
}
    break;

  case 23:
/* Line 670 of lalr1.cc  */
#line 313 "parser.y"
    {
	(yyval.statement) = new Expression_Statement((yysemantic_stack_[(2) - (1)].expression));
}
    break;

  case 24:
/* Line 670 of lalr1.cc  */
#line 316 "parser.y"
    {
	(yyval.statement) = (yysemantic_stack_[(1) - (1)].if_statement);
}
    break;

  case 25:
/* Line 670 of lalr1.cc  */
#line 320 "parser.y"
    {
	(yyval.statement) = (yysemantic_stack_[(2) - (1)].declaration);
}
    break;

  case 26:
/* Line 670 of lalr1.cc  */
#line 323 "parser.y"
    {
	(yyval.statement) = new Transfer_Statement((yysemantic_stack_[(3) - (2)].expression));
}
    break;

  case 27:
/* Line 670 of lalr1.cc  */
#line 329 "parser.y"
    {
	(yyval.expression) = (yysemantic_stack_[(4) - (3)].expression);
}
    break;

  case 28:
/* Line 670 of lalr1.cc  */
#line 334 "parser.y"
    {
	(yyval.if_statement) = new If_Statement((yysemantic_stack_[(2) - (1)].expression), (yysemantic_stack_[(2) - (2)].statement_block));
}
    break;

  case 29:
/* Line 670 of lalr1.cc  */
#line 337 "parser.y"
    {
	(yyval.if_statement) = new If_Statement((yysemantic_stack_[(4) - (1)].expression), (yysemantic_stack_[(4) - (2)].statement_block), (yysemantic_stack_[(4) - (4)].statement_block));
}
    break;

  case 30:
/* Line 670 of lalr1.cc  */
#line 340 "parser.y"
    {
	(yyval.if_statement) = new If_Statement((yysemantic_stack_[(4) - (1)].expression), (yysemantic_stack_[(4) - (2)].statement_block), (yysemantic_stack_[(4) - (4)].if_statement));
}
    break;

  case 31:
/* Line 670 of lalr1.cc  */
#line 343 "parser.y"
    {
	(yyval.if_statement) = new If_Statement((yysemantic_stack_[(5) - (1)].expression), (yysemantic_stack_[(5) - (2)].expression), (yysemantic_stack_[(5) - (4)].expression));
}
    break;

  case 32:
/* Line 670 of lalr1.cc  */
#line 349 "parser.y"
    {
	(yyval.statement_block) = new Statement_Block((yysemantic_stack_[(3) - (2)].symbol_list));
}
    break;

  case 33:
/* Line 670 of lalr1.cc  */
#line 354 "parser.y"
    {
(yyval.symbol_list) = new Specific_Symbol_List<j_symbol>();
}
    break;

  case 34:
/* Line 670 of lalr1.cc  */
#line 357 "parser.y"
    {
	(yyval.symbol_list) = (yysemantic_stack_[(2) - (1)].symbol_list);
	(yyval.symbol_list)->add_symbol((yysemantic_stack_[(2) - (2)].statement));
}
    break;

  case 35:
/* Line 670 of lalr1.cc  */
#line 363 "parser.y"
    {
	(yyval.declaration_list) = new Specific_Symbol_List<j_declaration>;
}
    break;

  case 36:
/* Line 670 of lalr1.cc  */
#line 366 "parser.y"
    {
	(yyval.declaration_list) = new Specific_Symbol_List<j_declaration>();
	(yyval.declaration_list)->add_symbol((yysemantic_stack_[(1) - (1)].declaration));
}
    break;

  case 37:
/* Line 670 of lalr1.cc  */
#line 370 "parser.y"
    {
	(yyval.declaration_list) = (yysemantic_stack_[(3) - (1)].declaration_list);
	(yyval.declaration_list)->add_symbol((yysemantic_stack_[(3) - (3)].declaration));
}
    break;

  case 38:
/* Line 670 of lalr1.cc  */
#line 377 "parser.y"
    {(yyval.declaration) = (yysemantic_stack_[(1) - (1)].declaration);}
    break;

  case 39:
/* Line 670 of lalr1.cc  */
#line 378 "parser.y"
    { 
	(yyval.declaration) = (yysemantic_stack_[(1) - (1)].declaration); 
}
    break;

  case 40:
/* Line 670 of lalr1.cc  */
#line 384 "parser.y"
    {
	std::unique_ptr<Declaration_List> decl_list(new Declaration_List);

	(yyval.declaration) = new Custom_Routine_Symbol((yysemantic_stack_[(4) - (2)].identifier), *decl_list, *(yysemantic_stack_[(4) - (3)].declaration_list), (yysemantic_stack_[(4) - (1)].type_syntax), (yysemantic_stack_[(4) - (4)].statement_block));
	(yysemantic_stack_[(4) - (1)].type_syntax).destroy();
	(yysemantic_stack_[(4) - (3)].declaration_list).destroy();
}
    break;

  case 41:
/* Line 670 of lalr1.cc  */
#line 391 "parser.y"
    {
	std::unique_ptr<Declaration_List> decl_list(new Declaration_List);

	(yyval.declaration) = new Custom_Routine_Symbol((yysemantic_stack_[(4) - (2)].identifier), *decl_list, *(yysemantic_stack_[(4) - (3)].declaration_list), (yysemantic_stack_[(4) - (1)].type_syntax), (yysemantic_stack_[(4) - (4)].statement_block));
	(yysemantic_stack_[(4) - (1)].type_syntax).destroy();
	(yysemantic_stack_[(4) - (3)].declaration_list).destroy();
}
    break;

  case 42:
/* Line 670 of lalr1.cc  */
#line 401 "parser.y"
    {
	(yyval.expression) = new Lambda_Expression((yysemantic_stack_[(4) - (2)].declaration_list), (yysemantic_stack_[(4) - (4)].statement_block));
}
    break;

  case 43:
/* Line 670 of lalr1.cc  */
#line 407 "parser.y"
    {
	(yyval.declaration_list) = (yysemantic_stack_[(3) - (2)].declaration_list);
}
    break;

  case 44:
/* Line 670 of lalr1.cc  */
#line 414 "parser.y"
    {(yyval.declaration) =  new Variable_Symbol((yysemantic_stack_[(2) - (1)].type_syntax), (yysemantic_stack_[(2) - (2)].identifier));
	
	
}
    break;

  case 45:
/* Line 670 of lalr1.cc  */
#line 418 "parser.y"
    {
	(yyval.declaration) = new Variable_Reference_Symbol((yysemantic_stack_[(4) - (1)].type_syntax), (yysemantic_stack_[(4) - (2)].identifier), (yysemantic_stack_[(4) - (4)].expression)); 
	
	
	
}
    break;

  case 46:
/* Line 670 of lalr1.cc  */
#line 424 "parser.y"
    {
	(yyval.declaration) = new Variable_Symbol((yysemantic_stack_[(4) - (1)].type_syntax), (yysemantic_stack_[(4) - (2)].identifier), *(yysemantic_stack_[(4) - (4)].expression));
	
	
	(yysemantic_stack_[(4) - (4)].expression).destroy();
	
}
    break;

  case 47:
/* Line 670 of lalr1.cc  */
#line 434 "parser.y"
    {(yyval.type_syntax) = make_double_type_syntax();}
    break;

  case 48:
/* Line 670 of lalr1.cc  */
#line 435 "parser.y"
    {(yyval.type_syntax) = make_int_type_syntax();}
    break;

  case 49:
/* Line 670 of lalr1.cc  */
#line 436 "parser.y"
    {(yyval.type_syntax) = make_bool_type_syntax();}
    break;

  case 50:
/* Line 670 of lalr1.cc  */
#line 437 "parser.y"
    {(yyval.type_syntax) = make_void_type_syntax(); }
    break;

  case 51:
/* Line 670 of lalr1.cc  */
#line 438 "parser.y"
    {(yyval.type_syntax) = make_string_type_syntax(); }
    break;

  case 52:
/* Line 670 of lalr1.cc  */
#line 439 "parser.y"
    {
	(yyval.type_syntax) = new Type_Aggregate((yysemantic_stack_[(3) - (2)].type_syntax_list));
}
    break;

  case 53:
/* Line 670 of lalr1.cc  */
#line 442 "parser.y"
    {
	(yyval.type_syntax) = make_void_type_syntax();
}
    break;

  case 54:
/* Line 670 of lalr1.cc  */
#line 448 "parser.y"
    {
	(yyval.type_syntax_list) = new Type_Syntax_List;
	(yyval.type_syntax_list)->add_symbol((yysemantic_stack_[(1) - (1)].type_syntax));
}
    break;

  case 55:
/* Line 670 of lalr1.cc  */
#line 452 "parser.y"
    {
	(yyval.type_syntax_list) = (yysemantic_stack_[(3) - (1)].type_syntax_list);
	(yyval.type_syntax_list)->add_symbol((yysemantic_stack_[(3) - (3)].type_syntax));
}
    break;

  case 56:
/* Line 670 of lalr1.cc  */
#line 460 "parser.y"
    {
	(yyval.expression) = new Void_Empty_Expression;
}
    break;

  case 57:
/* Line 670 of lalr1.cc  */
#line 463 "parser.y"
    {
	(yyval.expression) = (yysemantic_stack_[(1) - (1)].expression);
}
    break;

  case 58:
/* Line 670 of lalr1.cc  */
#line 471 "parser.y"
    {
	(yyval.expression) = (yysemantic_stack_[(1) - (1)].expression);
	
}
    break;

  case 59:
/* Line 670 of lalr1.cc  */
#line 475 "parser.y"
    {
	(yyval.expression) = (yysemantic_stack_[(1) - (1)].constant_symbol); 
}
    break;

  case 60:
/* Line 670 of lalr1.cc  */
#line 478 "parser.y"
    {
	(yyval.expression) = (yysemantic_stack_[(1) - (1)].expression);
}
    break;

  case 61:
/* Line 670 of lalr1.cc  */
#line 481 "parser.y"
    {
	(yyval.expression) = (yysemantic_stack_[(1) - (1)].expression);
	
}
    break;

  case 62:
/* Line 670 of lalr1.cc  */
#line 485 "parser.y"
    {
	(yyval.expression) = (yysemantic_stack_[(1) - (1)].expression);
}
    break;

  case 63:
/* Line 670 of lalr1.cc  */
#line 488 "parser.y"
    {
	(yyval.expression) = (yysemantic_stack_[(1) - (1)].expression);
}
    break;

  case 64:
/* Line 670 of lalr1.cc  */
#line 491 "parser.y"
    { 
	(yyval.expression) = new Addition_Expression((yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));
}
    break;

  case 65:
/* Line 670 of lalr1.cc  */
#line 494 "parser.y"
    { 
	(yyval.expression) = new Subtraction_Expression((yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));
	
	
}
    break;

  case 66:
/* Line 670 of lalr1.cc  */
#line 499 "parser.y"
    { 
	(yyval.expression) = new Multiplication_Expression((yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));
	
	
}
    break;

  case 67:
/* Line 670 of lalr1.cc  */
#line 504 "parser.y"
    { 
	(yyval.expression) = new Modulo_Expression((yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));
	
	
}
    break;

  case 68:
/* Line 670 of lalr1.cc  */
#line 509 "parser.y"
    { 
	(yyval.expression) = new Division_Expression((yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));
	
	
}
    break;

  case 69:
/* Line 670 of lalr1.cc  */
#line 515 "parser.y"
    {
	(yyval.expression) = new Relational_Binary_Expression((yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression), Operators::GREATER);
}
    break;

  case 70:
/* Line 670 of lalr1.cc  */
#line 518 "parser.y"
    {
	(yyval.expression) = new Relational_Binary_Expression((yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression), Operators::LESS);
}
    break;

  case 71:
/* Line 670 of lalr1.cc  */
#line 521 "parser.y"
    {
	(yyval.expression) = new Relational_Binary_Expression((yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression), Operators::GREATER_EQUAL);
}
    break;

  case 72:
/* Line 670 of lalr1.cc  */
#line 524 "parser.y"
    {
	(yyval.expression) = new Relational_Binary_Expression((yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression), Operators::LESS_EQUAL);
}
    break;

  case 73:
/* Line 670 of lalr1.cc  */
#line 527 "parser.y"
    {
	(yyval.expression) = new Relational_Binary_Expression((yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression), Operators::AND);
}
    break;

  case 74:
/* Line 670 of lalr1.cc  */
#line 530 "parser.y"
    {
	(yyval.expression) = new Relational_Binary_Expression((yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression), Operators::OR);
}
    break;

  case 75:
/* Line 670 of lalr1.cc  */
#line 533 "parser.y"
    {
	(yyval.expression) = new Relational_Binary_Expression((yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression), Operators::EQUAL);
}
    break;

  case 76:
/* Line 670 of lalr1.cc  */
#line 536 "parser.y"
    {
	(yyval.expression) = new Relational_Binary_Expression((yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression), Operators::NOT_EQUAL);
}
    break;

  case 77:
/* Line 670 of lalr1.cc  */
#line 540 "parser.y"
    {
	(yyval.expression) = new Unary_Not_Expression((yysemantic_stack_[(2) - (2)].expression));
}
    break;

  case 78:
/* Line 670 of lalr1.cc  */
#line 543 "parser.y"
    {
	(yyval.expression) = new Unary_Negate_Expression((yysemantic_stack_[(2) - (2)].expression));
}
    break;

  case 79:
/* Line 670 of lalr1.cc  */
#line 546 "parser.y"
    {
	(yyval.expression) = new Pre_Increment_Expression((yysemantic_stack_[(2) - (2)].expression));
}
    break;

  case 80:
/* Line 670 of lalr1.cc  */
#line 549 "parser.y"
    {
	(yyval.expression) = new Pre_Decrement_Expression((yysemantic_stack_[(2) - (2)].expression));
}
    break;

  case 81:
/* Line 670 of lalr1.cc  */
#line 552 "parser.y"
    {
	(yyval.expression) = (yysemantic_stack_[(3) - (2)].expression);
}
    break;

  case 82:
/* Line 670 of lalr1.cc  */
#line 560 "parser.y"
    {
	(yyval.expression) = new Assignment_Expression((yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));
	
}
    break;

  case 83:
/* Line 670 of lalr1.cc  */
#line 567 "parser.y"
    {
	(yyval.expression) = (yysemantic_stack_[(1) - (1)].expression);
}
    break;

  case 84:
/* Line 670 of lalr1.cc  */
#line 573 "parser.y"
    {
	(yyval.expression) = new Field_Access_Expression((yysemantic_stack_[(1) - (1)].identifier));
	
}
    break;

  case 85:
/* Line 670 of lalr1.cc  */
#line 577 "parser.y"
    {
	(yyval.expression) = new Field_Access_Expression((yysemantic_stack_[(1) - (1)].identifier));
}
    break;

  case 86:
/* Line 670 of lalr1.cc  */
#line 580 "parser.y"
    {
	(yyval.expression) = new Field_Access_Expression((yysemantic_stack_[(3) - (3)].identifier), (yysemantic_stack_[(3) - (1)].expression));
	(yysemantic_stack_[(3) - (3)].identifier).destroy();
}
    break;

  case 87:
/* Line 670 of lalr1.cc  */
#line 584 "parser.y"
    {
	(yyval.expression) = new Field_Access_Expression((yysemantic_stack_[(1) - (1)].identifier));
}
    break;

  case 88:
/* Line 670 of lalr1.cc  */
#line 590 "parser.y"
    {
	(yyval.expression) = new Call_Expression((yysemantic_stack_[(4) - (1)].identifier), (yysemantic_stack_[(4) - (3)].arguments));
}
    break;

  case 89:
/* Line 670 of lalr1.cc  */
#line 593 "parser.y"
    {
	(yyval.expression) = new Call_Expression((yysemantic_stack_[(7) - (1)].identifier), (yysemantic_stack_[(7) - (3)].state_id), (yysemantic_stack_[(7) - (6)].arguments));
}
    break;

  case 90:
/* Line 670 of lalr1.cc  */
#line 596 "parser.y"
    {
	(yyval.expression) = new System_Call_Expression((yysemantic_stack_[(4) - (1)].identifier), (yysemantic_stack_[(4) - (3)].arguments));
}
    break;

  case 91:
/* Line 670 of lalr1.cc  */
#line 599 "parser.y"
    {
	(yyval.expression) = new Filter_Call_Expression((yysemantic_stack_[(4) - (1)].identifier), (yysemantic_stack_[(4) - (3)].arguments));
}
    break;

  case 92:
/* Line 670 of lalr1.cc  */
#line 602 "parser.y"
    {
	(yyval.expression) = new Call_Expression((yysemantic_stack_[(6) - (1)].expression), (yysemantic_stack_[(6) - (3)].identifier), (yysemantic_stack_[(6) - (5)].arguments));
}
    break;

  case 93:
/* Line 670 of lalr1.cc  */
#line 609 "parser.y"
    {
	(yyval.expression) = new Aggregate_Value_Symbol(*(yysemantic_stack_[(3) - (2)].arguments));
	(yysemantic_stack_[(3) - (2)].arguments).destroy();
}
    break;

  case 94:
/* Line 670 of lalr1.cc  */
#line 619 "parser.y"
    {(yyval.arguments) = new Arguments;}
    break;

  case 95:
/* Line 670 of lalr1.cc  */
#line 620 "parser.y"
    {(yyval.arguments) = (yysemantic_stack_[(1) - (1)].arguments);}
    break;

  case 96:
/* Line 670 of lalr1.cc  */
#line 624 "parser.y"
    {
	(yyval.arguments) = (yysemantic_stack_[(1) - (1)].arguments);
	
}
    break;

  case 97:
/* Line 670 of lalr1.cc  */
#line 630 "parser.y"
    {
	(yyval.arguments) = new Arguments;
	(yyval.arguments)->push_back((yysemantic_stack_[(1) - (1)].expression));
	
}
    break;

  case 98:
/* Line 670 of lalr1.cc  */
#line 635 "parser.y"
    {
	(yyval.arguments) = (yysemantic_stack_[(3) - (1)].arguments);
	
	(yyval.arguments)->push_back((yysemantic_stack_[(3) - (3)].expression));
	
}
    break;

  case 99:
/* Line 670 of lalr1.cc  */
#line 644 "parser.y"
    {
	(yyval.constant_symbol) = (yysemantic_stack_[(1) - (1)].constant_symbol);
}
    break;

  case 100:
/* Line 670 of lalr1.cc  */
#line 647 "parser.y"
    {(yyval.constant_symbol) = (yysemantic_stack_[(1) - (1)].constant_symbol);}
    break;

  case 101:
/* Line 670 of lalr1.cc  */
#line 648 "parser.y"
    {(yyval.constant_symbol) = (yysemantic_stack_[(1) - (1)].constant_symbol);  }
    break;

  case 102:
/* Line 670 of lalr1.cc  */
#line 649 "parser.y"
    {(yyval.constant_symbol) = (yysemantic_stack_[(1) - (1)].string_constant); }
    break;

  case 103:
/* Line 670 of lalr1.cc  */
#line 650 "parser.y"
    {
	(yyval.constant_symbol) = new String_Constant_Symbol((yysemantic_stack_[(4) - (3)].identifier)->identifier_name(), (yyloc));
	(yysemantic_stack_[(4) - (3)].identifier).destroy();
}
    break;

  case 104:
/* Line 670 of lalr1.cc  */
#line 657 "parser.y"
    {
	(yyval.identifier) = (yysemantic_stack_[(1) - (1)].identifier);
}
    break;

  case 105:
/* Line 670 of lalr1.cc  */
#line 660 "parser.y"
    {
	(yyval.identifier) = (yysemantic_stack_[(1) - (1)].identifier);
}
    break;

  case 106:
/* Line 670 of lalr1.cc  */
#line 663 "parser.y"
    {
	(yyval.identifier) = (yysemantic_stack_[(1) - (1)].identifier);
}
    break;


/* Line 670 of lalr1.cc  */
#line 1326 "rule_parsing_unit.cc"
      default:
        break;
      }

    /* User semantic actions sometimes alter yychar, and that requires
       that yytoken be updated with the new translation.  We take the
       approach of translating immediately before every use of yytoken.
       One alternative is translating here after every semantic action,
       but that translation would be missed if the semantic action
       invokes YYABORT, YYACCEPT, or YYERROR immediately after altering
       yychar.  In the case of YYABORT or YYACCEPT, an incorrect
       destructor might then be invoked immediately.  In the case of
       YYERROR, subsequent parser actions might lead to an incorrect
       destructor call or verbose syntax error message before the
       lookahead is translated.  */
    YY_SYMBOL_PRINT ("-> $$ =", yyr1_[yyn], &yyval, &yyloc);

    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();

    yysemantic_stack_.push (yyval);
    yylocation_stack_.push (yyloc);

    /* Shift the result of the reduction.  */
    yyn = yyr1_[yyn];
    yystate = yypgoto_[yyn - yyntokens_] + yystate_stack_[0];
    if (0 <= yystate && yystate <= yylast_
	&& yycheck_[yystate] == yystate_stack_[0])
      yystate = yytable_[yystate];
    else
      yystate = yydefgoto_[yyn - yyntokens_];
    goto yynewstate;

  /*------------------------------------.
  | yyerrlab -- here on detecting error |
  `------------------------------------*/
  yyerrlab:
    /* Make sure we have latest lookahead translation.  See comments at
       user semantic actions for why this is necessary.  */
    yytoken = yytranslate_ (yychar);

    /* If not already recovering from an error, report this error.  */
    if (!yyerrstatus_)
      {
	++yynerrs_;
	if (yychar == yyempty_)
	  yytoken = yyempty_;
	error (yylloc, yysyntax_error_ (yystate, yytoken));
      }

    yyerror_range[1] = yylloc;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */
        if (yychar <= yyeof_)
          {
            /* Return failure if at end of input.  */
            if (yychar == yyeof_)
              YYABORT;
          }
        else
          {
            yydestruct_ ("Error: discarding", yytoken, &yylval, &yylloc);
            yychar = yyempty_;
          }
      }

    /* Else will try to reuse lookahead token after shifting the error
       token.  */
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;

    yyerror_range[1] = yylocation_stack_[yylen - 1];
    /* Do not reclaim the symbols of the rule which action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    yystate = yystate_stack_[0];
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;	/* Each real token shifted decrements this.  */

    for (;;)
      {
	yyn = yypact_[yystate];
	if (!yy_pact_value_is_default_ (yyn))
	{
	  yyn += yyterror_;
	  if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
	    {
	      yyn = yytable_[yyn];
	      if (0 < yyn)
		break;
	    }
	}

	/* Pop the current state because it cannot handle the error token.  */
	if (yystate_stack_.height () == 1)
	  YYABORT;

	yyerror_range[1] = yylocation_stack_[0];
	yydestruct_ ("Error: popping",
		     yystos_[yystate],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);
	yypop_ ();
	yystate = yystate_stack_[0];
	YY_STACK_PRINT ();
      }

    yyerror_range[2] = yylloc;
    // Using YYLLOC is tempting, but would change the location of
    // the lookahead.  YYLOC is available though.
    YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yyloc);

    /* Shift the error token.  */
    YY_SYMBOL_PRINT ("Shifting", yystos_[yyn],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);

    yystate = yyn;
    goto yynewstate;

    /* Accept.  */
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    /* Abort.  */
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (yychar != yyempty_)
      {
        /* Make sure we have latest lookahead translation.  See comments
           at user semantic actions for why this is necessary.  */
        yytoken = yytranslate_ (yychar);
        yydestruct_ ("Cleanup: discarding lookahead", yytoken, &yylval,
                     &yylloc);
      }

    /* Do not reclaim the symbols of the rule which action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystate_stack_.height ())
      {
        yydestruct_ ("Cleanup: popping",
                     yystos_[yystate_stack_[0]],
                     &yysemantic_stack_[0],
                     &yylocation_stack_[0]);
        yypop_ ();
      }

    return yyresult;
    }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (yychar != yyempty_)
          {
            /* Make sure we have latest lookahead translation.  See
               comments at user semantic actions for why this is
               necessary.  */
            yytoken = yytranslate_ (yychar);
            yydestruct_ (YY_NULL, yytoken, &yylval, &yylloc);
          }

        while (1 < yystate_stack_.height ())
          {
            yydestruct_ (YY_NULL,
                         yystos_[yystate_stack_[0]],
                         &yysemantic_stack_[0],
                         &yylocation_stack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  // Generate an error message.
  std::string
  Rule_Parsing_Unit::yysyntax_error_ (int, int)
  {
    return YY_("syntax error");
  }


  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
  const signed char Rule_Parsing_Unit::yypact_ninf_ = -99;
  const short int
  Rule_Parsing_Unit::yypact_[] =
  {
        19,     7,    80,    19,   -99,    61,   -99,   -99,    31,    45,
      35,   117,    21,   -99,   -99,   -99,   157,    87,   106,     5,
     -99,   -99,   -99,   -99,   -99,   -99,   -99,   -99,   157,    50,
     -99,   -99,   -99,    29,   -99,    28,   -99,   -99,    81,   -99,
       2,   -99,   157,    -9,    75,   -99,    28,    -3,    22,   157,
     -99,   157,   -99,   127,   127,   157,    88,    88,   -99,    91,
      -1,    28,   -99,    85,   -99,   127,    90,   -99,   102,   103,
     108,   -99,   -99,   -99,   -99,   127,   127,   127,   127,   157,
     127,   112,   -99,   279,   -99,   150,   -99,   -99,   -99,   -99,
     279,    33,   -99,   -99,   -99,   141,   -99,   -99,   279,   148,
     115,   127,   127,   127,     5,   124,   124,   124,   124,    27,
     163,    78,   127,   127,   127,   127,   127,   127,   127,   127,
     127,   127,   127,   127,   127,   155,   127,   -99,    89,   -99,
      69,   -99,   127,   121,   -99,   122,   123,   146,    88,   -99,
     -99,   -99,   -99,   128,   296,   312,   326,   326,   340,   340,
     340,   340,    79,    79,   124,   124,   124,   129,   279,   127,
     131,   -99,   -99,   -11,   -99,   132,   217,   -99,   161,   279,
     -99,   -99,   -99,   133,   -99,   -99,   127,   138,   279,   127,
     176,   261,   -99,   -99,   -99,   127,   135,   -99,   190,    -4,
     127,   151,   -99,   -99,   -99,   -99,   239,   -99,   -99
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned char
  Rule_Parsing_Unit::yydefact_[] =
  {
         0,     0,     0,    11,     3,     0,     1,     4,     0,     0,
       0,     0,     0,     7,    12,     5,    35,     0,     0,     0,
       2,     8,    50,    49,    48,    47,    51,    53,     0,     0,
      36,    39,    38,     0,     6,     0,    21,    22,     0,    54,
       0,    10,     0,    44,     0,    14,     0,     0,     0,    35,
      52,     0,    37,     0,     0,    35,     0,     0,    15,     0,
       0,     0,    13,     9,    55,     0,    84,    85,     0,    87,
       0,   102,    99,   100,   101,     0,     0,     0,     0,    35,
       0,     0,    63,    46,    58,    60,    83,    61,    62,    59,
      45,     0,    33,    40,    41,     0,    18,    17,    97,     0,
      96,    94,    94,    94,     0,    78,    77,    80,    79,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    43,     0,    19,
       0,    93,     0,     0,    95,     0,     0,     0,     0,    81,
     104,   105,   106,     0,    74,    73,    76,    75,    69,    70,
      71,    72,    64,    65,    66,    68,    67,    86,    82,    56,
       0,    32,    34,     0,    24,     0,     0,    16,     0,    98,
      88,    91,    90,     0,    42,   103,    94,     0,    57,     0,
      28,     0,    25,    23,    20,    94,     0,    26,     0,     0,
       0,     0,    92,    27,    30,    29,     0,    89,    31
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  Rule_Parsing_Unit::yypgoto_[] =
  {
       -99,   -99,   -99,   204,   -99,   197,   -99,   -99,   -99,    30,
     -99,   109,   -99,   -99,    23,   -55,   -99,   -23,   -39,   -99,
     -99,   166,   -99,    -8,   -99,   -99,   -53,   -99,   -99,   -99,
     -99,   -99,   -98,   149,   -99,   -99,   -99
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  Rule_Parsing_Unit::yydefgoto_[] =
  {
        -1,     2,     3,     4,    12,    13,    17,     8,    14,    48,
     130,    38,   162,   163,   164,    93,   128,    29,    30,    31,
      82,    56,    32,    33,    40,   177,    98,    84,    85,    86,
      87,    88,   133,   134,   100,    89,   143
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const signed char Rule_Parsing_Unit::yytable_ninf_ = -1;
  const short int
  Rule_Parsing_Unit::yytable_[] =
  {
        83,    90,    94,    52,   135,   136,    59,    53,    54,    65,
     160,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      39,    45,   105,   106,   107,   108,    63,   110,    36,    75,
       1,    61,    91,    76,    11,    77,    78,    50,    79,    10,
      20,    46,    92,    64,    11,    80,    37,    55,    81,    92,
      47,    43,    45,    96,    61,    44,   109,    51,     5,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,    46,   158,    62,   166,    58,    60,   186,   169,
       6,    47,    42,   174,     9,   138,    18,   191,    42,   165,
     127,    97,    22,    23,    24,    25,    26,    15,    16,   159,
     140,   141,   142,   160,    41,    42,   178,    27,   180,    65,
     181,    66,    67,    68,    69,    70,    71,    72,    73,    74,
     122,   123,   124,   167,   168,    28,   188,   125,    19,    75,
      35,    55,    49,    76,   195,    77,    78,   196,    79,    34,
      42,    92,    95,   161,   104,    80,   101,    65,    81,    66,
      67,    68,    69,    70,    71,    72,    73,    74,   102,   103,
      22,    23,    24,    25,    26,   111,   126,    75,   129,   131,
     132,    76,   125,    77,    78,    27,    79,   157,   170,   171,
     172,   173,   175,    80,   182,   176,    81,   179,   184,   185,
     187,   189,   192,    28,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,     7,   197,    21,
      57,   125,   194,   137,    99,     0,     0,     0,     0,     0,
     139,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,     0,     0,     0,     0,   125,     0,
       0,     0,     0,     0,     0,     0,     0,   193,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,     0,     0,     0,     0,   125,     0,     0,     0,   183,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,     0,     0,     0,     0,   125,     0,     0,
       0,   198,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   190,     0,     0,     0,   125,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,     0,     0,     0,     0,   125,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
       0,     0,     0,     0,   125,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,     0,     0,     0,     0,
     125,   116,   117,   118,   119,   120,   121,   122,   123,   124,
       0,     0,     0,     0,   125,    -1,    -1,    -1,    -1,   120,
     121,   122,   123,   124,     0,     0,     0,     0,   125
  };

  /* YYCHECK.  */
  const short int
  Rule_Parsing_Unit::yycheck_[] =
  {
        53,    54,    57,    42,   102,   103,     9,    16,    17,    20,
      14,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      28,    24,    75,    76,    77,    78,    49,    80,    23,    40,
      11,    32,    55,    44,    13,    46,    47,    35,    49,     8,
      19,    44,    53,    51,    13,    56,    41,    56,    59,    53,
      53,    22,    24,    54,    32,    26,    79,    55,    51,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,    44,   126,    52,   128,    46,    47,   176,   132,
       0,    53,    55,   138,    23,    58,    51,   185,    55,   128,
      57,    61,     3,     4,     5,     6,     7,    52,    53,    10,
      22,    23,    24,    14,    54,    55,   159,    18,   163,    20,
     163,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      41,    42,    43,    54,    55,    36,   179,    48,    11,    40,
      24,    56,    51,    44,   189,    46,    47,   190,    49,    52,
      55,    53,    51,    54,    36,    56,    56,    20,    59,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    56,    56,
       3,     4,     5,     6,     7,    53,    16,    40,    27,    21,
      55,    44,    48,    46,    47,    18,    49,    22,    57,    57,
      57,    35,    54,    56,    52,    56,    59,    56,    27,    56,
      52,    15,    57,    36,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,     3,    57,    12,
      44,    48,   189,   104,    65,    -1,    -1,    -1,    -1,    -1,
      57,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    -1,    -1,    -1,    -1,    48,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    -1,    -1,    -1,    -1,    48,    -1,    -1,    -1,    52,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    -1,    -1,    -1,    -1,    48,    -1,    -1,
      -1,    52,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    -1,    -1,    -1,    48,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    -1,    -1,    -1,    -1,    48,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      -1,    -1,    -1,    -1,    48,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,
      48,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      -1,    -1,    -1,    -1,    48,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    -1,    -1,    -1,    -1,    48
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  Rule_Parsing_Unit::yystos_[] =
  {
         0,    11,    61,    62,    63,    51,     0,    63,    67,    23,
       8,    13,    64,    65,    68,    52,    53,    66,    51,    11,
      19,    65,     3,     4,     5,     6,     7,    18,    36,    77,
      78,    79,    82,    83,    52,    24,    23,    41,    71,    83,
      84,    54,    55,    22,    26,    24,    44,    53,    69,    51,
      35,    55,    78,    16,    17,    56,    81,    81,    69,     9,
      69,    32,    52,    77,    83,    20,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    40,    44,    46,    47,    49,
      56,    59,    80,    86,    87,    88,    89,    90,    91,    95,
      86,    77,    53,    75,    75,    51,    54,    69,    86,    93,
      94,    56,    56,    56,    36,    86,    86,    86,    86,    77,
      86,    53,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    48,    16,    57,    76,    27,
      70,    21,    55,    92,    93,    92,    92,    71,    58,    57,
      22,    23,    24,    96,    86,    86,    86,    86,    86,    86,
      86,    86,    86,    86,    86,    86,    86,    22,    86,    10,
      14,    54,    72,    73,    74,    78,    86,    54,    55,    86,
      57,    57,    57,    35,    75,    54,    56,    85,    86,    56,
      75,    86,    52,    52,    27,    56,    92,    52,    86,    15,
      44,    92,    57,    57,    74,    75,    86,    57,    52
  };

#if YYDEBUG
  /* TOKEN_NUMBER_[YYLEX-NUM] -- Internal symbol number corresponding
     to YYLEX-NUM.  */
  const unsigned short int
  Rule_Parsing_Unit::yytoken_number_[] =
  {
         0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,    62,    60,   290,   291,    43,
      45,    42,    47,    37,    33,   292,   293,   294,    46,    91,
     295,    58,    59,   123,   125,    44,    40,    41,    93,    36
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  Rule_Parsing_Unit::yyr1_[] =
  {
         0,    60,    61,    62,    62,    63,    63,    64,    64,    65,
      66,    67,    67,    68,    69,    69,    69,    69,    69,    70,
      70,    71,    71,    72,    72,    72,    72,    73,    74,    74,
      74,    74,    75,    76,    76,    77,    77,    77,    78,    78,
      79,    79,    80,    81,    82,    82,    82,    83,    83,    83,
      83,    83,    83,    83,    84,    84,    85,    85,    86,    86,
      86,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      86,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      86,    86,    87,    88,    89,    89,    89,    89,    90,    90,
      90,    90,    90,    91,    92,    92,    93,    94,    94,    95,
      95,    95,    95,    95,    96,    96,    96
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  Rule_Parsing_Unit::yyr2_[] =
  {
         0,     2,     4,     1,     2,     4,     5,     1,     2,     5,
       3,     0,     2,     5,     1,     2,     5,     3,     3,     1,
       3,     1,     1,     2,     1,     2,     3,     4,     2,     4,
       4,     5,     3,     0,     2,     0,     1,     3,     1,     1,
       4,     4,     4,     3,     2,     4,     4,     1,     1,     1,
       1,     1,     3,     1,     1,     3,     0,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     2,
       2,     3,     3,     1,     1,     1,     3,     1,     4,     7,
       4,     4,     6,     3,     0,     1,     1,     1,     3,     1,
       1,     1,     1,     4,     1,     1,     1
  };

#if YYDEBUG
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const Rule_Parsing_Unit::yytname_[] =
  {
    "$end", "error", "$undefined", "T_VOID", "T_BOOL", "T_INT", "T_DOUBLE",
  "T_STRING", "T_FILTER", "T_HAS", "T_TRANSFER", "T_STATE", "T_NULL_PTR",
  "T_IN", "T_IF", "T_ELSE", "T_LEFT_ARROW", "T_RIGHT_ARROW",
  "T_EMPTY_TYPE_AGGREGATE", "T_END", "T_AGGREGATE_OPEN",
  "T_AGGREGATE_CLOSE", "T_IDENTIFIER", "T_UPPERCASE_IDENTIFIER",
  "T_FILTER_NAME", "T_SYSTEM_IDENTIFIER", "T_OVERRIDEN_FUNCTION",
  "T_STRING_CONSTANT", "T_INTEGER_CONSTANT", "T_DOUBLE_CONSTANT",
  "T_BOOL_CONSTANT", "T_OR", "T_AND", "T_NOT_EQUAL", "T_EQUAL", "'>'",
  "'<'", "T_GREATER_EQUAL", "T_LESS_EQUAL", "'+'", "'-'", "'*'", "'/'",
  "'%'", "'!'", "NEGATION", "T_DECREMENT", "T_INCREMENT", "'.'", "'['",
  "T_DIMENSIONS", "':'", "';'", "'{'", "'}'", "','", "'('", "')'", "']'",
  "'$'", "$accept", "Rule_Implementor", "State_Declaration_List",
  "State_Declaration", "State_Specification_List", "State_Specification",
  "State_Members", "Filter_List", "Filter", "Filter_Specification",
  "String_List", "State_ID", "Statement", "Test_Expression",
  "If_Statement", "Statement_Block", "Statement_List", "Declaration_List",
  "Declaration", "Routine_Definition", "Lambda_Expression",
  "Bracketed_Declaration_List", "Variable_Declaration", "Type",
  "Type_Syntax_List", "Expression_Wild", "Expression",
  "Assignment_Expression", "LValue", "Field_Access_Expression", "Call",
  "Aggregate_Value", "Expression_List_Wild", "Expression_List",
  "Expression_List_Helper", "Constant_Expression", "Identifier", YY_NULL
  };


  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const Rule_Parsing_Unit::rhs_number_type
  Rule_Parsing_Unit::yyrhs_[] =
  {
        61,     0,    -1,    62,    67,    64,    19,    -1,    63,    -1,
      62,    63,    -1,    11,    51,    23,    52,    -1,    11,    51,
      23,    66,    52,    -1,    65,    -1,    64,    65,    -1,    13,
      11,    71,    51,    77,    -1,    53,    77,    54,    -1,    -1,
      67,    68,    -1,     8,    51,    24,    69,    52,    -1,    24,
      -1,    44,    69,    -1,    53,     9,    51,    70,    54,    -1,
      69,    32,    69,    -1,    53,    69,    54,    -1,    27,    -1,
      70,    55,    27,    -1,    23,    -1,    41,    -1,    86,    52,
      -1,    74,    -1,    78,    52,    -1,    10,    85,    52,    -1,
      14,    56,    86,    57,    -1,    73,    75,    -1,    73,    75,
      15,    75,    -1,    73,    75,    15,    74,    -1,    73,    86,
      44,    86,    52,    -1,    53,    76,    54,    -1,    -1,    76,
      72,    -1,    -1,    78,    -1,    77,    55,    78,    -1,    82,
      -1,    79,    -1,    83,    22,    81,    75,    -1,    83,    26,
      81,    75,    -1,    49,    77,    58,    75,    -1,    56,    77,
      57,    -1,    83,    22,    -1,    83,    22,    17,    86,    -1,
      83,    22,    16,    86,    -1,     6,    -1,     5,    -1,     4,
      -1,     3,    -1,     7,    -1,    36,    84,    35,    -1,    18,
      -1,    83,    -1,    84,    55,    83,    -1,    -1,    86,    -1,
      87,    -1,    95,    -1,    88,    -1,    90,    -1,    91,    -1,
      80,    -1,    86,    39,    86,    -1,    86,    40,    86,    -1,
      86,    41,    86,    -1,    86,    43,    86,    -1,    86,    42,
      86,    -1,    86,    35,    86,    -1,    86,    36,    86,    -1,
      86,    37,    86,    -1,    86,    38,    86,    -1,    86,    32,
      86,    -1,    86,    31,    86,    -1,    86,    34,    86,    -1,
      86,    33,    86,    -1,    44,    86,    -1,    40,    86,    -1,
      47,    86,    -1,    46,    86,    -1,    56,    86,    57,    -1,
      88,    16,    86,    -1,    89,    -1,    22,    -1,    23,    -1,
      86,    48,    22,    -1,    25,    -1,    22,    56,    92,    57,
      -1,    26,    36,    71,    35,    56,    92,    57,    -1,    25,
      56,    92,    57,    -1,    24,    56,    92,    57,    -1,    86,
      48,    22,    56,    92,    57,    -1,    20,    93,    21,    -1,
      -1,    93,    -1,    94,    -1,    86,    -1,    94,    55,    86,
      -1,    28,    -1,    29,    -1,    30,    -1,    27,    -1,    59,
      53,    96,    54,    -1,    22,    -1,    23,    -1,    24,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  Rule_Parsing_Unit::yyprhs_[] =
  {
         0,     0,     3,     8,    10,    13,    18,    24,    26,    29,
      35,    39,    40,    43,    49,    51,    54,    60,    64,    68,
      70,    74,    76,    78,    81,    83,    86,    90,    95,    98,
     103,   108,   114,   118,   119,   122,   123,   125,   129,   131,
     133,   138,   143,   148,   152,   155,   160,   165,   167,   169,
     171,   173,   175,   179,   181,   183,   187,   188,   190,   192,
     194,   196,   198,   200,   202,   206,   210,   214,   218,   222,
     226,   230,   234,   238,   242,   246,   250,   254,   257,   260,
     263,   266,   270,   274,   276,   278,   280,   284,   286,   291,
     299,   304,   309,   316,   320,   321,   323,   325,   327,   331,
     333,   335,   337,   339,   344,   346,   348
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  Rule_Parsing_Unit::yyrline_[] =
  {
         0,   205,   205,   212,   216,   223,   226,   232,   236,   243,
     252,   258,   261,   267,   273,   276,   279,   283,   286,   293,
     297,   304,   307,   313,   316,   320,   323,   329,   334,   337,
     340,   343,   349,   354,   357,   363,   366,   370,   377,   378,
     384,   391,   401,   407,   414,   418,   424,   434,   435,   436,
     437,   438,   439,   442,   448,   452,   460,   463,   471,   475,
     478,   481,   485,   488,   491,   494,   499,   504,   509,   515,
     518,   521,   524,   527,   530,   533,   536,   540,   543,   546,
     549,   552,   560,   567,   573,   577,   580,   584,   590,   593,
     596,   599,   602,   609,   619,   620,   624,   630,   635,   644,
     647,   648,   649,   650,   657,   660,   663
  };

  // Print the state stack on the debug stream.
  void
  Rule_Parsing_Unit::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (state_stack_type::const_iterator i = yystate_stack_.begin ();
	 i != yystate_stack_.end (); ++i)
      *yycdebug_ << ' ' << *i;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  Rule_Parsing_Unit::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    /* Print the symbols being reduced, and their result.  */
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
	       << " (line " << yylno << "):" << std::endl;
    /* The symbols being reduced.  */
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
		       yyrhs_[yyprhs_[yyrule] + yyi],
		       &(yysemantic_stack_[(yynrhs) - (yyi + 1)]),
		       &(yylocation_stack_[(yynrhs) - (yyi + 1)]));
  }
#endif // YYDEBUG

  /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
  Rule_Parsing_Unit::token_number_type
  Rule_Parsing_Unit::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
    {
           0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    44,     2,     2,    59,    43,     2,     2,
      56,    57,    41,    39,    55,    40,    48,    42,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    51,    52,
      36,     2,    35,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    49,     2,    58,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    53,     2,    54,     2,     2,     2,     2,
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
      37,    38,    45,    46,    47,    50
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int Rule_Parsing_Unit::yyeof_ = 0;
  const int Rule_Parsing_Unit::yylast_ = 388;
  const int Rule_Parsing_Unit::yynnts_ = 37;
  const int Rule_Parsing_Unit::yyempty_ = -2;
  const int Rule_Parsing_Unit::yyfinal_ = 6;
  const int Rule_Parsing_Unit::yyterror_ = 1;
  const int Rule_Parsing_Unit::yyerrcode_ = 256;
  const int Rule_Parsing_Unit::yyntokens_ = 60;

  const unsigned int Rule_Parsing_Unit::yyuser_token_number_max_ = 295;
  const Rule_Parsing_Unit::token_number_type Rule_Parsing_Unit::yyundef_token_ = 2;


} // yy
/* Line 1141 of lalr1.cc  */
#line 1977 "rule_parsing_unit.cc"
/* Line 1142 of lalr1.cc  */
#line 667 "parser.y"


/* The closing %% above marks the end of the Rules section and the beginning
 * of the User Subroutines section. All text from here to the end of the
 * file is copied verbatim to the end of the generated y.tab.c file.
 * This section is where you put definitions of helper functions.
 */
 

