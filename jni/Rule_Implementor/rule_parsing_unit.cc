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
#line 196 "parser.y"
    {
	*i_rule_implementor = new Rule_Implementor((yysemantic_stack_[(4) - (3)].state_spec_list), i_rule_data);
	return true;
}
    break;

  case 3:
/* Line 670 of lalr1.cc  */
#line 203 "parser.y"
    {
	(yyval.state_decl_list) = new State_Declaration_List;
	(yyval.state_decl_list)->add_symbol((yysemantic_stack_[(1) - (1)].state_decl));
}
    break;

  case 4:
/* Line 670 of lalr1.cc  */
#line 207 "parser.y"
    {
	(yyval.state_decl_list) = (yysemantic_stack_[(2) - (1)].state_decl_list);
	(yyval.state_decl_list)->add_symbol((yysemantic_stack_[(2) - (2)].state_decl));
	(yyloc);
}
    break;

  case 5:
/* Line 670 of lalr1.cc  */
#line 214 "parser.y"
    {
	(yyval.state_decl) = new State_Declaration((yysemantic_stack_[(4) - (3)].identifier));
}
    break;

  case 6:
/* Line 670 of lalr1.cc  */
#line 217 "parser.y"
    {
	(yyval.state_decl) = new State_Declaration((yysemantic_stack_[(5) - (3)].identifier), (yysemantic_stack_[(5) - (4)].declaration_list));
}
    break;

  case 7:
/* Line 670 of lalr1.cc  */
#line 223 "parser.y"
    {
	(yyval.state_spec_list) = new State_Specification_List;
	(yyval.state_spec_list)->add_symbol((yysemantic_stack_[(1) - (1)].state_spec));
}
    break;

  case 8:
/* Line 670 of lalr1.cc  */
#line 227 "parser.y"
    {
	(yyval.state_spec_list) = (yysemantic_stack_[(2) - (1)].state_spec_list);
	(yyval.state_spec_list)->add_symbol((yysemantic_stack_[(2) - (2)].state_spec));
}
    break;

  case 9:
/* Line 670 of lalr1.cc  */
#line 234 "parser.y"
    {
	(yyval.state_spec) = new State_Specification((yysemantic_stack_[(5) - (3)].state_id), *(yysemantic_stack_[(5) - (5)].declaration_list));
}
    break;

  case 10:
/* Line 670 of lalr1.cc  */
#line 243 "parser.y"
    {
	(yyval.declaration_list) = (yysemantic_stack_[(3) - (2)].declaration_list);
}
    break;

  case 11:
/* Line 670 of lalr1.cc  */
#line 249 "parser.y"
    {

}
    break;

  case 12:
/* Line 670 of lalr1.cc  */
#line 252 "parser.y"
    {
	i_rule_data.add_filter((yysemantic_stack_[(2) - (2)].filter));
}
    break;

  case 13:
/* Line 670 of lalr1.cc  */
#line 258 "parser.y"
    {
	(yyval.filter) = new Wrangler_Filter((yysemantic_stack_[(5) - (3)].identifier), (yysemantic_stack_[(5) - (4)].filter_spec));
}
    break;

  case 14:
/* Line 670 of lalr1.cc  */
#line 264 "parser.y"
    {
	(yyval.filter_spec) = i_rule_data.get_filter((yysemantic_stack_[(1) - (1)].identifier)->identifier_name()).get_copy();
}
    break;

  case 15:
/* Line 670 of lalr1.cc  */
#line 267 "parser.y"
    {
	(yyval.filter_spec) = new Negated_Filter_Specification((yysemantic_stack_[(2) - (2)].filter_spec));
}
    break;

  case 16:
/* Line 670 of lalr1.cc  */
#line 270 "parser.y"
    {
	(yyval.filter_spec) = new Has_Filter_Specification(*(yysemantic_stack_[(5) - (4)].string_list));
	(yysemantic_stack_[(5) - (4)].string_list).destroy();
}
    break;

  case 17:
/* Line 670 of lalr1.cc  */
#line 274 "parser.y"
    {
	(yyval.filter_spec) = new Combined_Filter_Specification((yysemantic_stack_[(3) - (1)].filter_spec), (yysemantic_stack_[(3) - (3)].filter_spec));
}
    break;

  case 18:
/* Line 670 of lalr1.cc  */
#line 277 "parser.y"
    {
	(yyval.filter_spec) = (yysemantic_stack_[(3) - (2)].filter_spec);
}
    break;

  case 19:
/* Line 670 of lalr1.cc  */
#line 284 "parser.y"
    {
	(yyval.string_list) = new String_Constant_Symbol_List;
	(yyval.string_list)->add_symbol((yysemantic_stack_[(1) - (1)].string_constant));
}
    break;

  case 20:
/* Line 670 of lalr1.cc  */
#line 288 "parser.y"
    {
	(yyval.string_list) = (yysemantic_stack_[(3) - (1)].string_list);
	(yyval.string_list)->add_symbol((yysemantic_stack_[(3) - (3)].string_constant));
}
    break;

  case 21:
/* Line 670 of lalr1.cc  */
#line 295 "parser.y"
    {
	(yyval.state_id) = new State_ID((yysemantic_stack_[(1) - (1)].identifier));
}
    break;

  case 22:
/* Line 670 of lalr1.cc  */
#line 298 "parser.y"
    {
	(yyval.state_id) = new State_ID(new J_Symbol_Identifier("*"));
}
    break;

  case 23:
/* Line 670 of lalr1.cc  */
#line 302 "parser.y"
    {
	(yyval.statement) = new Expression_Statement((yysemantic_stack_[(2) - (1)].expression));
}
    break;

  case 24:
/* Line 670 of lalr1.cc  */
#line 305 "parser.y"
    {
	(yyval.statement) = (yysemantic_stack_[(1) - (1)].if_statement);
}
    break;

  case 25:
/* Line 670 of lalr1.cc  */
#line 309 "parser.y"
    {
	(yyval.statement) = (yysemantic_stack_[(2) - (1)].declaration);
}
    break;

  case 26:
/* Line 670 of lalr1.cc  */
#line 312 "parser.y"
    {
	(yyval.statement) = new Transfer_Statement((yysemantic_stack_[(3) - (2)].expression));
}
    break;

  case 27:
/* Line 670 of lalr1.cc  */
#line 318 "parser.y"
    {
	(yyval.expression) = (yysemantic_stack_[(4) - (3)].expression);
}
    break;

  case 28:
/* Line 670 of lalr1.cc  */
#line 323 "parser.y"
    {
	(yyval.if_statement) = new If_Statement((yysemantic_stack_[(2) - (1)].expression), (yysemantic_stack_[(2) - (2)].statement_block));
}
    break;

  case 29:
/* Line 670 of lalr1.cc  */
#line 326 "parser.y"
    {
	(yyval.if_statement) = new If_Statement((yysemantic_stack_[(4) - (1)].expression), (yysemantic_stack_[(4) - (2)].statement_block), (yysemantic_stack_[(4) - (4)].statement_block));
}
    break;

  case 30:
/* Line 670 of lalr1.cc  */
#line 329 "parser.y"
    {
	(yyval.if_statement) = new If_Statement((yysemantic_stack_[(4) - (1)].expression), (yysemantic_stack_[(4) - (2)].statement_block), (yysemantic_stack_[(4) - (4)].if_statement));
}
    break;

  case 31:
/* Line 670 of lalr1.cc  */
#line 332 "parser.y"
    {
	(yyval.if_statement) = new If_Statement((yysemantic_stack_[(5) - (1)].expression), (yysemantic_stack_[(5) - (2)].expression), (yysemantic_stack_[(5) - (4)].expression));
}
    break;

  case 32:
/* Line 670 of lalr1.cc  */
#line 338 "parser.y"
    {
	(yyval.statement_block) = new Statement_Block((yysemantic_stack_[(3) - (2)].symbol_list));
}
    break;

  case 33:
/* Line 670 of lalr1.cc  */
#line 343 "parser.y"
    {
(yyval.symbol_list) = new Specific_Symbol_List<j_symbol>();
}
    break;

  case 34:
/* Line 670 of lalr1.cc  */
#line 346 "parser.y"
    {
	(yyval.symbol_list) = (yysemantic_stack_[(2) - (1)].symbol_list);
	(yyval.symbol_list)->add_symbol((yysemantic_stack_[(2) - (2)].statement));
}
    break;

  case 35:
/* Line 670 of lalr1.cc  */
#line 352 "parser.y"
    {
	(yyval.declaration_list) = new Specific_Symbol_List<j_declaration>;
}
    break;

  case 36:
/* Line 670 of lalr1.cc  */
#line 355 "parser.y"
    {
	(yyval.declaration_list) = new Specific_Symbol_List<j_declaration>();
	(yyval.declaration_list)->add_symbol((yysemantic_stack_[(1) - (1)].declaration));
}
    break;

  case 37:
/* Line 670 of lalr1.cc  */
#line 359 "parser.y"
    {
	(yyval.declaration_list) = (yysemantic_stack_[(3) - (1)].declaration_list);
	(yyval.declaration_list)->add_symbol((yysemantic_stack_[(3) - (3)].declaration));
}
    break;

  case 38:
/* Line 670 of lalr1.cc  */
#line 366 "parser.y"
    {(yyval.declaration) = (yysemantic_stack_[(1) - (1)].declaration);}
    break;

  case 39:
/* Line 670 of lalr1.cc  */
#line 367 "parser.y"
    { 
	(yyval.declaration) = (yysemantic_stack_[(1) - (1)].declaration); 
}
    break;

  case 40:
/* Line 670 of lalr1.cc  */
#line 373 "parser.y"
    {
	std::unique_ptr<Declaration_List> decl_list(new Declaration_List);

	(yyval.declaration) = new Custom_Routine_Symbol((yysemantic_stack_[(4) - (2)].identifier), *decl_list, *(yysemantic_stack_[(4) - (3)].declaration_list), (yysemantic_stack_[(4) - (1)].type_syntax), (yysemantic_stack_[(4) - (4)].statement_block));
	(yysemantic_stack_[(4) - (1)].type_syntax).destroy();
	(yysemantic_stack_[(4) - (3)].declaration_list).destroy();
}
    break;

  case 41:
/* Line 670 of lalr1.cc  */
#line 385 "parser.y"
    {
	(yyval.declaration_list) = (yysemantic_stack_[(3) - (2)].declaration_list);
}
    break;

  case 42:
/* Line 670 of lalr1.cc  */
#line 392 "parser.y"
    {(yyval.declaration) =  new Variable_Symbol((yysemantic_stack_[(2) - (1)].type_syntax), (yysemantic_stack_[(2) - (2)].identifier));
	
	
}
    break;

  case 43:
/* Line 670 of lalr1.cc  */
#line 396 "parser.y"
    {
	(yyval.declaration) = new Variable_Reference_Symbol((yysemantic_stack_[(4) - (1)].type_syntax), (yysemantic_stack_[(4) - (2)].identifier), (yysemantic_stack_[(4) - (4)].expression)); 
	
	
	
}
    break;

  case 44:
/* Line 670 of lalr1.cc  */
#line 402 "parser.y"
    {
	(yyval.declaration) = new Variable_Symbol((yysemantic_stack_[(4) - (1)].type_syntax), (yysemantic_stack_[(4) - (2)].identifier), *(yysemantic_stack_[(4) - (4)].expression));
	
	
	(yysemantic_stack_[(4) - (4)].expression).destroy();
	
}
    break;

  case 45:
/* Line 670 of lalr1.cc  */
#line 412 "parser.y"
    {(yyval.type_syntax) = make_double_type_syntax();}
    break;

  case 46:
/* Line 670 of lalr1.cc  */
#line 413 "parser.y"
    {(yyval.type_syntax) = make_int_type_syntax();}
    break;

  case 47:
/* Line 670 of lalr1.cc  */
#line 414 "parser.y"
    {(yyval.type_syntax) = make_bool_type_syntax();}
    break;

  case 48:
/* Line 670 of lalr1.cc  */
#line 415 "parser.y"
    {(yyval.type_syntax) = make_void_type_syntax(); }
    break;

  case 49:
/* Line 670 of lalr1.cc  */
#line 416 "parser.y"
    {(yyval.type_syntax) = make_string_type_syntax(); }
    break;

  case 50:
/* Line 670 of lalr1.cc  */
#line 417 "parser.y"
    {
	(yyval.type_syntax) = new Type_Aggregate((yysemantic_stack_[(3) - (2)].type_syntax_list));
}
    break;

  case 51:
/* Line 670 of lalr1.cc  */
#line 423 "parser.y"
    {
	(yyval.type_syntax_list) = new Type_Syntax_List;
}
    break;

  case 52:
/* Line 670 of lalr1.cc  */
#line 426 "parser.y"
    {
	(yyval.type_syntax_list) = new Type_Syntax_List;
	(yyval.type_syntax_list)->add_symbol((yysemantic_stack_[(1) - (1)].type_syntax));
}
    break;

  case 53:
/* Line 670 of lalr1.cc  */
#line 430 "parser.y"
    {
	(yyval.type_syntax_list) = (yysemantic_stack_[(3) - (1)].type_syntax_list);
	(yyval.type_syntax_list)->add_symbol((yysemantic_stack_[(3) - (3)].type_syntax));
}
    break;

  case 54:
/* Line 670 of lalr1.cc  */
#line 436 "parser.y"
    {
	(yyval.expression) = (yysemantic_stack_[(1) - (1)].expression);
	
}
    break;

  case 55:
/* Line 670 of lalr1.cc  */
#line 440 "parser.y"
    {
	(yyval.expression) = (yysemantic_stack_[(1) - (1)].expression);
	
}
    break;

  case 56:
/* Line 670 of lalr1.cc  */
#line 444 "parser.y"
    {
	(yyval.expression) = (yysemantic_stack_[(1) - (1)].constant_symbol); 
}
    break;

  case 57:
/* Line 670 of lalr1.cc  */
#line 447 "parser.y"
    {
	(yyval.expression) = (yysemantic_stack_[(1) - (1)].expression);
	
}
    break;

  case 58:
/* Line 670 of lalr1.cc  */
#line 451 "parser.y"
    {
	(yyval.expression) = (yysemantic_stack_[(1) - (1)].expression);
}
    break;

  case 59:
/* Line 670 of lalr1.cc  */
#line 454 "parser.y"
    { 
	(yyval.expression) = new Addition_Expression((yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));
}
    break;

  case 60:
/* Line 670 of lalr1.cc  */
#line 457 "parser.y"
    { 
	(yyval.expression) = new Subtraction_Expression((yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));
	
	
}
    break;

  case 61:
/* Line 670 of lalr1.cc  */
#line 462 "parser.y"
    { 
	(yyval.expression) = new Multiplication_Expression((yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));
	
	
}
    break;

  case 62:
/* Line 670 of lalr1.cc  */
#line 467 "parser.y"
    { 
	(yyval.expression) = new Division_Expression((yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));
	
	
}
    break;

  case 63:
/* Line 670 of lalr1.cc  */
#line 472 "parser.y"
    {
	(yyval.expression) = new Pre_Increment_Expression((yysemantic_stack_[(2) - (2)].expression));
}
    break;

  case 64:
/* Line 670 of lalr1.cc  */
#line 475 "parser.y"
    {
	(yyval.expression) = new Pre_Decrement_Expression((yysemantic_stack_[(2) - (2)].expression));
}
    break;

  case 65:
/* Line 670 of lalr1.cc  */
#line 478 "parser.y"
    {
	(yyval.expression) = new Relational_Binary_Expression((yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression), Operators::GREATER);
}
    break;

  case 66:
/* Line 670 of lalr1.cc  */
#line 481 "parser.y"
    {
	(yyval.expression) = new Relational_Binary_Expression((yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression), Operators::LESS);
}
    break;

  case 67:
/* Line 670 of lalr1.cc  */
#line 484 "parser.y"
    {
	(yyval.expression) = new Relational_Binary_Expression((yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression), Operators::GREATER_EQUAL);
}
    break;

  case 68:
/* Line 670 of lalr1.cc  */
#line 487 "parser.y"
    {
	(yyval.expression) = new Relational_Binary_Expression((yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression), Operators::LESS_EQUAL);
}
    break;

  case 69:
/* Line 670 of lalr1.cc  */
#line 490 "parser.y"
    {
	(yyval.expression) = new Relational_Binary_Expression((yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression), Operators::AND);
}
    break;

  case 70:
/* Line 670 of lalr1.cc  */
#line 493 "parser.y"
    {
	(yyval.expression) = new Relational_Binary_Expression((yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression), Operators::OR);
}
    break;

  case 71:
/* Line 670 of lalr1.cc  */
#line 496 "parser.y"
    {
	(yyval.expression) = new Relational_Binary_Expression((yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression), Operators::EQUAL);
}
    break;

  case 72:
/* Line 670 of lalr1.cc  */
#line 499 "parser.y"
    {
	(yyval.expression) = new Relational_Binary_Expression((yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression), Operators::NOT_EQUAL);
}
    break;

  case 73:
/* Line 670 of lalr1.cc  */
#line 502 "parser.y"
    {(yyval.expression) = (yysemantic_stack_[(3) - (2)].expression);  }
    break;

  case 74:
/* Line 670 of lalr1.cc  */
#line 503 "parser.y"
    {
	(yyval.expression) = new Unary_Negate_Expression((yysemantic_stack_[(2) - (2)].expression));
}
    break;

  case 75:
/* Line 670 of lalr1.cc  */
#line 506 "parser.y"
    {
	(yyval.expression) = new Unary_Not_Expression((yysemantic_stack_[(2) - (2)].expression));
}
    break;

  case 76:
/* Line 670 of lalr1.cc  */
#line 512 "parser.y"
    {
	(yyval.expression) = new Void_Empty_Expression;
}
    break;

  case 77:
/* Line 670 of lalr1.cc  */
#line 515 "parser.y"
    {
	(yyval.expression) = (yysemantic_stack_[(1) - (1)].expression);
}
    break;

  case 78:
/* Line 670 of lalr1.cc  */
#line 520 "parser.y"
    {
	(yyval.expression) = new Assignment_Expression((yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression));
	
}
    break;

  case 79:
/* Line 670 of lalr1.cc  */
#line 527 "parser.y"
    {
	(yyval.expression) = new Aggregate_Value_Symbol(*(yysemantic_stack_[(3) - (2)].arguments));
	(yysemantic_stack_[(3) - (2)].arguments).destroy();
}
    break;

  case 80:
/* Line 670 of lalr1.cc  */
#line 536 "parser.y"
    {(yyval.expression) = (yysemantic_stack_[(1) - (1)].expression); }
    break;

  case 81:
/* Line 670 of lalr1.cc  */
#line 539 "parser.y"
    {
	(yyval.expression) = new Field_Access_Expression((yysemantic_stack_[(1) - (1)].identifier));
	
}
    break;

  case 82:
/* Line 670 of lalr1.cc  */
#line 550 "parser.y"
    {
	(yyval.expression) = new Call_Expression((yysemantic_stack_[(4) - (1)].identifier), (yysemantic_stack_[(4) - (3)].arguments));
}
    break;

  case 83:
/* Line 670 of lalr1.cc  */
#line 553 "parser.y"
    {
	(yyval.expression) = new Call_Expression((yysemantic_stack_[(7) - (1)].identifier), (yysemantic_stack_[(7) - (3)].state_id), (yysemantic_stack_[(7) - (6)].arguments));
}
    break;

  case 84:
/* Line 670 of lalr1.cc  */
#line 556 "parser.y"
    {
	(yyval.expression) = new System_Call_Expression((yysemantic_stack_[(4) - (1)].identifier), (yysemantic_stack_[(4) - (3)].arguments));
}
    break;

  case 85:
/* Line 670 of lalr1.cc  */
#line 559 "parser.y"
    {
	(yyval.expression) = new Filter_Call_Expression((yysemantic_stack_[(4) - (1)].identifier), (yysemantic_stack_[(4) - (3)].arguments));
}
    break;

  case 86:
/* Line 670 of lalr1.cc  */
#line 572 "parser.y"
    {(yyval.arguments) = new Arguments;}
    break;

  case 87:
/* Line 670 of lalr1.cc  */
#line 573 "parser.y"
    {(yyval.arguments) = (yysemantic_stack_[(1) - (1)].arguments);}
    break;

  case 88:
/* Line 670 of lalr1.cc  */
#line 577 "parser.y"
    {
	(yyval.arguments) = (yysemantic_stack_[(1) - (1)].arguments);
	
}
    break;

  case 89:
/* Line 670 of lalr1.cc  */
#line 583 "parser.y"
    {
	(yyval.arguments) = new Arguments;
	(yyval.arguments)->push_back((yysemantic_stack_[(1) - (1)].expression));
	
}
    break;

  case 90:
/* Line 670 of lalr1.cc  */
#line 588 "parser.y"
    {
	(yyval.arguments) = (yysemantic_stack_[(3) - (1)].arguments);
	
	(yyval.arguments)->push_back((yysemantic_stack_[(3) - (3)].expression));
	
}
    break;

  case 91:
/* Line 670 of lalr1.cc  */
#line 597 "parser.y"
    {
	(yyval.constant_symbol) = (yysemantic_stack_[(1) - (1)].constant_symbol);
}
    break;

  case 92:
/* Line 670 of lalr1.cc  */
#line 600 "parser.y"
    {(yyval.constant_symbol) = (yysemantic_stack_[(1) - (1)].constant_symbol);}
    break;

  case 93:
/* Line 670 of lalr1.cc  */
#line 601 "parser.y"
    {(yyval.constant_symbol) = (yysemantic_stack_[(1) - (1)].constant_symbol);  }
    break;

  case 94:
/* Line 670 of lalr1.cc  */
#line 602 "parser.y"
    {(yyval.constant_symbol) = (yysemantic_stack_[(1) - (1)].string_constant); }
    break;


/* Line 670 of lalr1.cc  */
#line 1219 "rule_parsing_unit.cc"
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
  const signed char Rule_Parsing_Unit::yypact_ninf_ = -92;
  const short int
  Rule_Parsing_Unit::yypact_[] =
  {
         1,   -24,    75,     1,   -92,     8,   -92,   -92,   104,    36,
      -3,    80,    58,   -92,   -92,   -92,    32,    33,    71,     2,
     -92,   -92,   -92,   -92,   -92,   -92,   -92,    32,    73,   -92,
     -92,   -92,    77,   -92,    26,   -92,   -92,    55,   -92,   -23,
     -92,    32,   -11,   -92,    26,    -2,    -8,    32,   -92,    32,
     -92,   109,   109,    32,    57,   -92,    61,    -5,    26,   -92,
      59,   -92,   109,    30,    60,    91,   -92,   -92,   -92,   -92,
     109,   109,   127,   127,   109,   236,   -92,   -92,   173,   -92,
     -92,   -92,   236,   -27,   -92,   -92,   194,   -92,   -92,   236,
     200,   167,     2,   109,   109,   109,   110,   -92,   -92,   -92,
     -92,   136,   109,   109,   109,   109,   109,   109,   109,   109,
     109,   109,   109,   109,   109,   -92,    76,   -92,   137,   -92,
     109,   189,   168,   -92,   169,   170,   -92,   163,   123,   105,
     105,    85,    85,    85,    85,   110,   110,   -92,   -92,   236,
     109,   185,   -92,   -92,   -10,   -92,   172,   176,   -92,   216,
     236,   187,   -92,   -92,   -92,   236,   192,   109,   229,   222,
     -92,   -92,   -92,   109,   -92,   148,    -6,   109,   190,   -92,
     -92,   -92,   199,   -92,   -92
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned char
  Rule_Parsing_Unit::yydefact_[] =
  {
         0,     0,     0,    11,     3,     0,     1,     4,     0,     0,
       0,     0,     0,     7,    12,     5,    35,     0,     0,     0,
       2,     8,    48,    47,    46,    45,    49,    51,     0,    36,
      39,    38,     0,     6,     0,    21,    22,     0,    52,     0,
      10,     0,    42,    14,     0,     0,     0,    35,    50,     0,
      37,     0,     0,    35,     0,    15,     0,     0,     0,    13,
       9,    53,     0,    81,     0,     0,    94,    91,    92,    93,
       0,     0,     0,     0,     0,    44,    54,    58,    57,    80,
      55,    56,    43,     0,    33,    40,     0,    18,    17,    89,
       0,    88,     0,    86,    86,    86,    74,    75,    81,    64,
      63,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    41,     0,    19,     0,    79,
       0,     0,     0,    87,     0,     0,    73,    70,    69,    72,
      71,    65,    66,    67,    68,    59,    60,    61,    62,    78,
      76,     0,    32,    34,     0,    24,     0,     0,    16,     0,
      90,     0,    82,    85,    84,    77,     0,     0,    28,     0,
      25,    23,    20,    86,    26,     0,     0,     0,     0,    27,
      30,    29,     0,    83,    31
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  Rule_Parsing_Unit::yypgoto_[] =
  {
       -92,   -92,   -92,   242,   -92,   235,   -92,   -92,   -92,    63,
     -92,   156,   -92,   -92,    83,   -74,   -92,    20,   -39,   -92,
     -92,   -92,    47,   -92,   -51,   -92,   -92,   -92,   145,   -92,
     -92,   -91,   201,   -92,   -92
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  Rule_Parsing_Unit::yydefgoto_[] =
  {
        -1,     2,     3,     4,    12,    13,    17,     8,    14,    46,
     118,    37,   143,   144,   145,    85,   116,    28,    29,    30,
      54,    31,    32,    39,    89,   156,    76,    77,    78,    79,
      80,   122,   123,    91,    81
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const signed char Rule_Parsing_Unit::yytable_ninf_ = -1;
  const unsigned char
  Rule_Parsing_Unit::yytable_[] =
  {
        75,    82,    50,   124,   125,    51,    52,    56,   141,    62,
      48,    63,     1,    64,    65,    66,    67,    68,    69,    96,
      97,    43,    58,   101,    35,    58,     5,    41,    70,   115,
       9,    49,    71,    72,    73,    22,    23,    24,    25,    26,
      44,    36,    84,    59,    53,    74,    84,    18,    87,    43,
      45,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,    92,   147,    27,    60,    44,   150,
     158,    11,   168,    83,    38,     6,    20,   146,    45,    22,
      23,    24,    25,    26,    33,    93,   140,    15,    16,   155,
     141,    19,   171,   159,    34,    62,    61,    63,    42,    64,
      65,    66,    67,    68,    69,    47,   165,    55,    57,    84,
      27,    86,    10,    41,    70,    94,   172,    11,    71,    72,
      73,    88,   110,   111,   112,   113,    40,    41,    62,   142,
      63,    74,    64,    65,    66,    67,    68,    69,   106,   107,
     108,   109,   110,   111,   112,   113,    95,    70,    98,   112,
     113,    71,    72,    73,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,    74,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     148,   149,   126,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   169,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,    99,   100,   117,
     119,   120,   151,   160,   152,   153,   154,   161,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     157,   162,   163,   164,   166,     7,   173,    21,   121,   170,
     174,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,    90,   167,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113
  };

  /* YYCHECK.  */
  const unsigned char
  Rule_Parsing_Unit::yycheck_[] =
  {
        51,    52,    41,    94,    95,    16,    17,     9,    14,    19,
      33,    21,    11,    23,    24,    25,    26,    27,    28,    70,
      71,    23,    30,    74,    22,    30,    50,    54,    38,    56,
      22,    54,    42,    43,    44,     3,     4,     5,     6,     7,
      42,    39,    52,    51,    55,    55,    52,    50,    53,    23,
      52,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,    34,   116,    34,    47,    42,   120,
     144,    13,   163,    53,    27,     0,    18,   116,    52,     3,
       4,     5,     6,     7,    51,    55,    10,    51,    52,   140,
      14,    11,   166,   144,    23,    19,    49,    21,    21,    23,
      24,    25,    26,    27,    28,    50,   157,    44,    45,    52,
      34,    50,     8,    54,    38,    55,   167,    13,    42,    43,
      44,    58,    37,    38,    39,    40,    53,    54,    19,    53,
      21,    55,    23,    24,    25,    26,    27,    28,    33,    34,
      35,    36,    37,    38,    39,    40,    55,    38,    21,    39,
      40,    42,    43,    44,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    55,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    16,
      53,    54,    56,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    56,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    72,    73,    25,
      20,    54,    33,    51,    56,    56,    56,    51,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      55,    25,    55,    51,    15,     3,    56,    12,    92,   166,
      51,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    62,    42,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  Rule_Parsing_Unit::yystos_[] =
  {
         0,    11,    58,    59,    60,    50,     0,    60,    64,    22,
       8,    13,    61,    62,    65,    51,    52,    63,    50,    11,
      18,    62,     3,     4,     5,     6,     7,    34,    74,    75,
      76,    78,    79,    51,    23,    22,    39,    68,    79,    80,
      53,    54,    21,    23,    42,    52,    66,    50,    33,    54,
      75,    16,    17,    55,    77,    66,     9,    66,    30,    51,
      74,    79,    19,    21,    23,    24,    25,    26,    27,    28,
      38,    42,    43,    44,    55,    81,    83,    84,    85,    86,
      87,    91,    81,    74,    52,    72,    50,    53,    66,    81,
      89,    90,    34,    55,    55,    55,    81,    81,    21,    85,
      85,    81,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    16,    56,    73,    25,    67,    20,
      54,    68,    88,    89,    88,    88,    56,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      10,    14,    53,    69,    70,    71,    75,    81,    53,    54,
      81,    33,    56,    56,    56,    81,    82,    55,    72,    81,
      51,    51,    25,    55,    51,    81,    15,    42,    88,    56,
      71,    72,    81,    56,    51
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
     285,   286,   287,    62,    60,   288,   289,    43,    45,    42,
      47,    37,    33,   290,   291,   292,    46,    91,    93,   293,
      58,    59,   123,   125,    44,    40,    41
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  Rule_Parsing_Unit::yyr1_[] =
  {
         0,    57,    58,    59,    59,    60,    60,    61,    61,    62,
      63,    64,    64,    65,    66,    66,    66,    66,    66,    67,
      67,    68,    68,    69,    69,    69,    69,    70,    71,    71,
      71,    71,    72,    73,    73,    74,    74,    74,    75,    75,
      76,    77,    78,    78,    78,    79,    79,    79,    79,    79,
      79,    80,    80,    80,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    82,    82,    83,    84,
      85,    86,    87,    87,    87,    87,    88,    88,    89,    90,
      90,    91,    91,    91,    91
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  Rule_Parsing_Unit::yyr2_[] =
  {
         0,     2,     4,     1,     2,     4,     5,     1,     2,     5,
       3,     0,     2,     5,     1,     2,     5,     3,     3,     1,
       3,     1,     1,     2,     1,     2,     3,     4,     2,     4,
       4,     5,     3,     0,     2,     0,     1,     3,     1,     1,
       4,     3,     2,     4,     4,     1,     1,     1,     1,     1,
       3,     0,     1,     3,     1,     1,     1,     1,     1,     3,
       3,     3,     3,     2,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     2,     0,     1,     3,     3,
       1,     1,     4,     7,     4,     4,     0,     1,     1,     1,
       3,     1,     1,     1,     1
  };

#if YYDEBUG
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const Rule_Parsing_Unit::yytname_[] =
  {
    "$end", "error", "$undefined", "T_VOID", "T_BOOL", "T_INT", "T_DOUBLE",
  "T_STRING", "T_FILTER", "T_HAS", "T_TRANSFER", "T_STATE", "T_NULL_PTR",
  "T_IN", "T_IF", "T_ELSE", "T_LEFT_ARROW", "T_RIGHT_ARROW", "T_END",
  "T_AGGREGATE_OPEN", "T_AGGREGATE_CLOSE", "T_IDENTIFIER",
  "T_UPPERCASE_IDENTIFIER", "T_FILTER_NAME", "T_SYSTEM_IDENTIFIER",
  "T_STRING_CONSTANT", "T_INTEGER_CONSTANT", "T_DOUBLE_CONSTANT",
  "T_BOOL_CONSTANT", "T_OR", "T_AND", "T_NOT_EQUAL", "T_EQUAL", "'>'",
  "'<'", "T_GREATER_EQUAL", "T_LESS_EQUAL", "'+'", "'-'", "'*'", "'/'",
  "'%'", "'!'", "T_DECREMENT", "T_INCREMENT", "NEGATION", "'.'", "'['",
  "']'", "T_DIMENSIONS", "':'", "';'", "'{'", "'}'", "','", "'('", "')'",
  "$accept", "Rule_Implementor", "State_Declaration_List",
  "State_Declaration", "State_Specification_List", "State_Specification",
  "State_Members", "Filter_List", "Filter", "Filter_Specification",
  "String_List", "State_ID", "Statement", "Test_Expression",
  "If_Statement", "Statement_Block", "Statement_List", "Declaration_List",
  "Declaration", "Routine_Definition", "Bracketed_Declaration_List",
  "Variable_Declaration", "Type", "Type_Syntax_List", "Expression",
  "Expression_Wild", "Assignment_Expression", "Aggregate_Value", "LValue",
  "Field_Access_Expression", "Call", "Expression_List_Wild",
  "Expression_List", "Expression_List_Helper", "Constant_Expression", YY_NULL
  };


  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const Rule_Parsing_Unit::rhs_number_type
  Rule_Parsing_Unit::yyrhs_[] =
  {
        58,     0,    -1,    59,    64,    61,    18,    -1,    60,    -1,
      59,    60,    -1,    11,    50,    22,    51,    -1,    11,    50,
      22,    63,    51,    -1,    62,    -1,    61,    62,    -1,    13,
      11,    68,    50,    74,    -1,    52,    74,    53,    -1,    -1,
      64,    65,    -1,     8,    50,    23,    66,    51,    -1,    23,
      -1,    42,    66,    -1,    52,     9,    50,    67,    53,    -1,
      66,    30,    66,    -1,    52,    66,    53,    -1,    25,    -1,
      67,    54,    25,    -1,    22,    -1,    39,    -1,    81,    51,
      -1,    71,    -1,    75,    51,    -1,    10,    82,    51,    -1,
      14,    55,    81,    56,    -1,    70,    72,    -1,    70,    72,
      15,    72,    -1,    70,    72,    15,    71,    -1,    70,    81,
      42,    81,    51,    -1,    52,    73,    53,    -1,    -1,    73,
      69,    -1,    -1,    75,    -1,    74,    54,    75,    -1,    78,
      -1,    76,    -1,    79,    21,    77,    72,    -1,    55,    74,
      56,    -1,    79,    21,    -1,    79,    21,    17,    81,    -1,
      79,    21,    16,    81,    -1,     6,    -1,     5,    -1,     4,
      -1,     3,    -1,     7,    -1,    34,    80,    33,    -1,    -1,
      79,    -1,    80,    54,    79,    -1,    83,    -1,    87,    -1,
      91,    -1,    85,    -1,    84,    -1,    81,    37,    81,    -1,
      81,    38,    81,    -1,    81,    39,    81,    -1,    81,    40,
      81,    -1,    44,    85,    -1,    43,    85,    -1,    81,    33,
      81,    -1,    81,    34,    81,    -1,    81,    35,    81,    -1,
      81,    36,    81,    -1,    81,    30,    81,    -1,    81,    29,
      81,    -1,    81,    32,    81,    -1,    81,    31,    81,    -1,
      55,    81,    56,    -1,    38,    81,    -1,    42,    81,    -1,
      -1,    81,    -1,    85,    16,    81,    -1,    19,    89,    20,
      -1,    86,    -1,    21,    -1,    21,    55,    88,    56,    -1,
      21,    34,    68,    33,    55,    88,    56,    -1,    24,    55,
      88,    56,    -1,    23,    55,    88,    56,    -1,    -1,    89,
      -1,    90,    -1,    81,    -1,    90,    54,    81,    -1,    26,
      -1,    27,    -1,    28,    -1,    25,    -1
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
     133,   138,   142,   145,   150,   155,   157,   159,   161,   163,
     165,   169,   170,   172,   176,   178,   180,   182,   184,   186,
     190,   194,   198,   202,   205,   208,   212,   216,   220,   224,
     228,   232,   236,   240,   244,   247,   250,   251,   253,   257,
     261,   263,   265,   270,   278,   283,   288,   289,   291,   293,
     295,   299,   301,   303,   305
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  Rule_Parsing_Unit::yyrline_[] =
  {
         0,   196,   196,   203,   207,   214,   217,   223,   227,   234,
     243,   249,   252,   258,   264,   267,   270,   274,   277,   284,
     288,   295,   298,   302,   305,   309,   312,   318,   323,   326,
     329,   332,   338,   343,   346,   352,   355,   359,   366,   367,
     373,   385,   392,   396,   402,   412,   413,   414,   415,   416,
     417,   423,   426,   430,   436,   440,   444,   447,   451,   454,
     457,   462,   467,   472,   475,   478,   481,   484,   487,   490,
     493,   496,   499,   502,   503,   506,   512,   515,   520,   527,
     536,   539,   550,   553,   556,   559,   572,   573,   577,   583,
     588,   597,   600,   601,   602
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
       2,     2,     2,    42,     2,     2,     2,    41,     2,     2,
      55,    56,    39,    37,    54,    38,    46,    40,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    50,    51,
      34,     2,    33,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    47,     2,    48,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    52,     2,    53,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    35,    36,
      43,    44,    45,    49
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int Rule_Parsing_Unit::yyeof_ = 0;
  const int Rule_Parsing_Unit::yylast_ = 276;
  const int Rule_Parsing_Unit::yynnts_ = 35;
  const int Rule_Parsing_Unit::yyempty_ = -2;
  const int Rule_Parsing_Unit::yyfinal_ = 6;
  const int Rule_Parsing_Unit::yyterror_ = 1;
  const int Rule_Parsing_Unit::yyerrcode_ = 256;
  const int Rule_Parsing_Unit::yyntokens_ = 57;

  const unsigned int Rule_Parsing_Unit::yyuser_token_number_max_ = 293;
  const Rule_Parsing_Unit::token_number_type Rule_Parsing_Unit::yyundef_token_ = 2;


} // yy
/* Line 1141 of lalr1.cc  */
#line 1832 "rule_parsing_unit.cc"
/* Line 1142 of lalr1.cc  */
#line 606 "parser.y"


/* The closing %% above marks the end of the Rules section and the beginning
 * of the User Subroutines section. All text from here to the end of the
 * file is copied verbatim to the end of the generated y.tab.c file.
 * This section is where you put definitions of helper functions.
 */
 

