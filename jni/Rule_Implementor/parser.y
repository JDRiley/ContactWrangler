/* File: parser.y
 * --------------
 * Yacc input file to generate the parser for the compiler.
 *
 * pp2: your job is to write a parser that will construct the parse tree
 *      and if no parse errors were found, print it.  The parser should 
 *      accept the language as described in specification, and as augmented 
 *      in the pp2 handout.
 */
%debug
%{

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

%}
%skeleton "lalr1.cc"
%defines
%define parser_class_name "Rule_Parsing_Unit"
%parse-param{jtl::Rule_Implementor** i_rule_implementor}
%parse-param{jtl::Rule_Parser* i_parser}
%parse-param{jtl::Rule_Data i_rule_data}
%lex-param{jtl::Rule_Parser* i_parser}


%code requires{
#include "Wrangler_Rules_Parser.h"
#include "Rule_Implementor_Fwd_Decl.h"
#include "Expression_List.h"
#include "Call_Expression.h"
#include "J_Symbol_Identifier.h"
#include "Field_Access_Expression.h"
#include "Arguments.h"
#include "j_expression.h"
#include "j_yy_stack.h"
#include "Specific_Symbol_List.h"
#include "J_Symbol_Scope.h"
#include "Custom_Routine_Symbol.h"
#include "Assignment_Expression.h"
#include "Statement_Block.h"
#include "Expression_Statement.h"
#include "If_Statement.h"
#include "Relational_Binary_Expression.h"
#include "Pre_Increment_Expression.h"
#include "Pre_Decrement_Expression.h"
#include "Rule_Implementor.h"
#include "Rule_Data.h"
#include "State_Declaration.h"
#include "State_Specification.h"
#include "Wrangler_Filter.h"
#include "Transfer_Statement.h"
#include "Void_Empty_Expression.h"
#include "State_ID.h"
#include "Negated_Filter_Specification.h"
#include "Has_Filter_Specification.h"
#include "Combined_Filter_Specification.h"
#include "Type_Aggregate.h"
#include "Aggregate_Value_Symbol.h"
#include "System_Call_Expression.h"
#include "Unary_Not_Expression.h"
#include "Filter_Call_Expression.h"
#include "Lambda_Expression.h"
#include "Modulo_Expression.h"
#include "Wrangler_Directive.h"
#include "State_Field_Access_Expression.h"
}

/* The section before the first %% is the Definitions section of the yacc
 * input file. Here is where you declare tokens and types, add precedence
 * and associativity options, and so on.
 */
 
/* yylval 
 * ------
 * Here we define the type of the yylval global variable that is used by
 * the scanner to store attibute information about the token just scanned
 * and thus communicate that information to the parser. 
 *
 * pp2: You will need to add new fields to this union as you add different 
 *      attributes to your non-terminal symbols.
 */


//%destructor{delete $$;} <*>

/* Tokens
* ------
* Here we tell yacc about all the token types that we are using.
* Yacc will assign unique numbers to these and export the #define
* in the generated y.tab.h header file.
*/





%token							T_VOID T_BOOL T_INT T_DOUBLE T_STRING
%token							T_FILTER T_HAS T_TRANSFER T_STATE
%token							T_NULL_PTR T_IN T_IF T_ELSE
%token							T_LEFT_ARROW T_RIGHT_ARROW T_EMPTY_TYPE_AGGREGATE
%token							T_END T_AGGREGATE_OPEN T_AGGREGATE_CLOSE
%token	<identifier>			T_IDENTIFIER T_UPPERCASE_IDENTIFIER T_FILTER_NAME T_SYSTEM_IDENTIFIER
%token	<identifier>			T_OVERRIDEN_FUNCTION
%token	<string_constant>		T_STRING_CONSTANT  
%token	<constant_symbol>		T_INTEGER_CONSTANT 
%token	<constant_symbol>		T_DOUBLE_CONSTANT
%token	<constant_symbol>		T_BOOL_CONSTANT

//Operator Precedence
%right T_LEFT_ARROW
%left T_OR
%left   T_AND
%left T_EQUAL T_NOT_EQUAL
%nonassoc   T_LESS_EQUAL T_GREATER_EQUAL  '>' '<'

%left '+' '-'

%left '*' '/' '%'

%nonassoc '!' NEGATION 
%nonassoc T_INCREMENT T_DECREMENT

%left '.'
%nonassoc '[' 
%left T_DIMENSIONS

/* Non-terminal types
* ------------------
* In order for yacc to assign/access the correct field of $$, $1, we
* must to declare which field is appropriate for the non-terminal.
* As an example, this first type declaration establishes that the DeclList
* non-terminal uses the field named "declList" in the yylval union. This
* means that when we are setting $$ for a reduction for DeclList ore reading
* $n which corresponds to a DeclList nonterminal we are accessing the field
* of the union named "declList" which is of type List<Decl*>.
* pp2: You'll need to add many of these of your own.
*/

%type	<identifier>		Identifier
%type	<expression>		Assignment_Expression Expression Test_Expression
%type	<constant_symbol>	Constant_Expression
%type	<arguments>	Expression_List Expression_List_Helper Expression_List_Wild
%type	<expression>		Expression_Wild 
%type	<expression>		Call Lambda_Expression
%type	<expression>		LValue
%type	<expression>		Field_Access_Expression
%type	<expression>		Aggregate_Value 
%type	<declaration>		Declaration Variable_Declaration Routine_Definition
%type	<type_syntax>		Type
%type	<symbol_list>		Statement_List
%type	<declaration_list>	Declaration_List Bracketed_Declaration_List State_Members
%type	<statement_block>	Statement_Block
%type	<statement>			Statement
%type	<if_statement>		If_Statement
%type	<state_id>			State_ID
%type	<filter_spec>		Filter_Specification
%type	<filter>			Filter
%type	<state_decl_list>	State_Declaration_List
%type	<state_spec_list>	State_Specification_List
%type	<string_list>		String_List;
%type	<state_decl>		State_Declaration;
%type	<state_spec>		State_Specification;
%type	<type_syntax_list>	Type_Syntax_List;
%%
/* Rules
* -----
* All productions and actions should be placed between the start and stop
* %% markers which delimit the Rules section.
*/

//TODO: Have this Parse a .cwr rule file instead of J_Calc input
Rule_Implementor
: State_Declaration_List Filter_List State_Specification_List T_END{
	*i_rule_implementor = new Rule_Implementor($3, i_rule_data);
	return true;
}
;

State_Declaration_List
: State_Declaration {
	$$ = new State_Declaration_List;
	$$->add_symbol($1);
}
| State_Declaration_List State_Declaration{
	$$ = $1;
	$$->add_symbol($2);
	@$;
}
;
State_Declaration
: T_STATE ':' T_UPPERCASE_IDENTIFIER ';'{
	$$ = new State_Declaration($3);
}
| T_STATE ':' T_UPPERCASE_IDENTIFIER State_Members ';'{
	$$ = new State_Declaration($3, $4);
}
;

State_Specification_List
: State_Specification {
	$$ = new State_Specification_List;
	$$->add_symbol($1);
}
| State_Specification_List State_Specification{
	$$ = $1;
	$$->add_symbol($2);
}
;

State_Specification
: T_IN T_STATE State_ID ':' Declaration_List{
	$$ = new State_Specification($3, *$5);
}
;




State_Members
: '{' Declaration_List '}' {
	$$ = $2;
}
;

Filter_List
: /*empty*/ {

}
| Filter_List Filter {
	i_rule_data.add_filter($2);
}
;

Filter
: T_FILTER ':' T_FILTER_NAME Filter_Specification ';' {
	$$ = new Wrangler_Filter($3, $4);
}
;

Filter_Specification
: T_FILTER_NAME{
	$$ = i_rule_data.get_filter($1->identifier_name()).get_copy();
}
| '!' Filter_Specification{
	$$ = new Negated_Filter_Specification($2);
}
| '{' T_HAS ':' String_List '}' {
	$$ = new Has_Filter_Specification(*$4);
	$4.destroy();
}
| Filter_Specification T_AND Filter_Specification{
	$$ = new Combined_Filter_Specification($1, $3);
}
| '{' Filter_Specification '}' {
	$$ = $2;
}
;


String_List
: T_STRING_CONSTANT{
	$$ = new String_Constant_Symbol_List;
	$$->add_symbol($1);
}
| String_List ',' T_STRING_CONSTANT{
	$$ = $1;
	$$->add_symbol($3);
}
;

State_ID
: T_UPPERCASE_IDENTIFIER {
	$$ = new State_ID($1);
}
| '*'{
	$$ = new State_ID(new J_Symbol_Identifier("*"));
}
;

Statement
: Expression ';' {
	$$ = new Expression_Statement($1);
}
| If_Statement{
	$$ = $1;
}

| Declaration ';' {
	$$ = $1;
}
| T_TRANSFER Expression_Wild ';' {
	$$ = new Transfer_Statement($2);
}
;

Test_Expression
: T_IF '(' Expression ')' {
	$$ = $3;
}

If_Statement
:  Test_Expression Statement_Block{
	$$ = new If_Statement($1, $2);
}
| Test_Expression Statement_Block T_ELSE Statement_Block{
	$$ = new If_Statement($1, $2, $4);
}
| Test_Expression Statement_Block T_ELSE If_Statement{
	$$ = new If_Statement($1, $2, $4);
}
| Test_Expression Expression '!' Expression ';'{
	$$ = new If_Statement($1, $2, $4);
}
;

Statement_Block
: '{' Statement_List '}'{
	$$ = new Statement_Block($2);
}
;
Statement_List
: /*empty*/ {
$$ = new Specific_Symbol_List<j_symbol>();
}
| Statement_List Statement {
	$$ = $1;
	$$->add_symbol($2);
}
;
Declaration_List
: /*empty*/ {
	$$ = new Specific_Symbol_List<j_declaration>;
}
|Declaration {
	$$ = new Specific_Symbol_List<j_declaration>();
	$$->add_symbol($1);
}
| Declaration_List ',' Declaration{
	$$ = $1;
	$$->add_symbol($3);
}
;

Declaration
: Variable_Declaration {$$ = $1;}
| Routine_Definition{ 
	$$ = $1; 
}
;

Routine_Definition
: Type T_IDENTIFIER Bracketed_Declaration_List Statement_Block{
	std::unique_ptr<Declaration_List> decl_list(new Declaration_List);

	$$ = new Custom_Routine_Symbol($2, *decl_list, *$3, $1, $4);
	$1.destroy();
	$3.destroy();
}
| Type T_OVERRIDEN_FUNCTION Bracketed_Declaration_List Statement_Block{
	std::unique_ptr<Declaration_List> decl_list(new Declaration_List);

	$$ = new Custom_Routine_Symbol($2, *decl_list, *$3, $1, $4);
	$1.destroy();
	$3.destroy();
}
;

Lambda_Expression
: /*Nameless*/ '[' Declaration_List ']' Statement_Block{
	$$ = new Lambda_Expression($2, $4);
}
;

Bracketed_Declaration_List
: '(' Declaration_List ')' {
	$$ = $2;
}

;

Variable_Declaration
: Type T_IDENTIFIER{$$ =  new Variable_Symbol($1, $2);
	
	
}
| Type T_IDENTIFIER T_RIGHT_ARROW Expression {
	$$ = new Variable_Reference_Symbol($1, $2, $4); 
	
	
	
}
| Type T_IDENTIFIER T_LEFT_ARROW Expression {
	$$ = new Variable_Symbol($1, $2, *$4);
	
	
	$4.destroy();
	
}
;

Type 
: T_DOUBLE{$$ = make_double_type_syntax();}
| T_INT{$$ = make_int_type_syntax();}
| T_BOOL{$$ = make_bool_type_syntax();}
| T_VOID{$$ = make_void_type_syntax(); }
| T_STRING{$$ = make_string_type_syntax(); }
| '<' Type_Syntax_List '>' {
	$$ = new Type_Aggregate($2);
}
| T_EMPTY_TYPE_AGGREGATE{
	$$ = make_void_type_syntax();
}
;

Type_Syntax_List
: Type{
	$$ = new Type_Syntax_List;
	$$->add_symbol($1);
}
| Type_Syntax_List ',' Type{
	$$ = $1;
	$$->add_symbol($3);
}
;


Expression_Wild
: /*empty*/{
	$$ = new Void_Empty_Expression;
}
| Expression{
	$$ = $1;
}
;



Expression
: Assignment_Expression{
	$$ = $1;
	
}
| Constant_Expression{
	$$ = $1; 
}
| LValue {
	$$ = $1;
}
| Call{
	$$ = $1;
	
}
| Aggregate_Value{
	$$ = $1;
}
| Lambda_Expression{
	$$ = $1;
}
| Expression '+' Expression { 
	$$ = new Addition_Expression($1, $3);
}
| Expression '-' Expression { 
	$$ = new Subtraction_Expression($1, $3);
	
	
}
| Expression '*' Expression { 
	$$ = new Multiplication_Expression($1, $3);
	
	
}
| Expression '%' Expression { 
	$$ = new Modulo_Expression($1, $3);
	
	
}
| Expression '/' Expression { 
	$$ = new Division_Expression($1, $3);
	
	
}

| Expression '>' Expression{
	$$ = new Relational_Binary_Expression($1, $3, Operators::GREATER);
}
| Expression '<' Expression{
	$$ = new Relational_Binary_Expression($1, $3, Operators::LESS);
}
| Expression T_GREATER_EQUAL Expression{
	$$ = new Relational_Binary_Expression($1, $3, Operators::GREATER_EQUAL);
}
| Expression T_LESS_EQUAL Expression{
	$$ = new Relational_Binary_Expression($1, $3, Operators::LESS_EQUAL);
}
| Expression  T_AND Expression{
	$$ = new Relational_Binary_Expression($1, $3, Operators::AND);
}
| Expression T_OR Expression{
	$$ = new Relational_Binary_Expression($1, $3, Operators::OR);
}
| Expression T_EQUAL Expression{
	$$ = new Relational_Binary_Expression($1, $3, Operators::EQUAL);
}
| Expression T_NOT_EQUAL Expression{
	$$ = new Relational_Binary_Expression($1, $3, Operators::NOT_EQUAL);
}

| '!' Expression{
	$$ = new Unary_Not_Expression($2);
}
| '-' Expression %prec NEGATION{
	$$ = new Unary_Negate_Expression($2);
}
| T_INCREMENT Expression{
	$$ = new Pre_Increment_Expression($2);
}
| T_DECREMENT Expression{
	$$ = new Pre_Decrement_Expression($2);
}
| '(' Expression ')' {
	$$ = $2;
}

;


Assignment_Expression
: LValue T_LEFT_ARROW Expression {
	$$ = new Assignment_Expression($1, $3);
	
}
;

LValue
:  Field_Access_Expression {
	$$ = $1;
}
;

Field_Access_Expression
: T_IDENTIFIER {
	$$ = new Field_Access_Expression($1);
	
}
| T_UPPERCASE_IDENTIFIER{
	$$ = new State_Field_Access_Expression($1);
}
| Expression '.' T_IDENTIFIER %prec '.'{
	$$ = new Field_Access_Expression($3, $1);
	$3.destroy();
}
| T_SYSTEM_IDENTIFIER{
	$$ = new Field_Access_Expression($1);
}
;

Call
: T_IDENTIFIER '(' Expression_List_Wild ')' {
	$$ = new Call_Expression($1, $3);
}
| T_OVERRIDEN_FUNCTION '<' State_ID '>' '(' Expression_List_Wild ')'{
	$$ = new Call_Expression($1, $3, $6);
}
| T_SYSTEM_IDENTIFIER '(' Expression_List_Wild ')' {
	$$ = new Wrangler_Directive($1, $3);
}
| T_FILTER_NAME '(' Expression_List_Wild ')' {
	$$ = new Filter_Call_Expression($1, $3);
}
| Expression '.' T_IDENTIFIER '(' Expression_List_Wild ')' {
	$$ = new Call_Expression($1, $3, $5);
}
;


Aggregate_Value
: T_AGGREGATE_OPEN Expression_List T_AGGREGATE_CLOSE{
	$$ = new Aggregate_Value_Symbol(*$2);
	$2.destroy();
}
;




Expression_List_Wild
:	/*empty*/ {$$ = new Arguments;}
| Expression_List {$$ = $1;}
;

Expression_List
: Expression_List_Helper {
	$$ = $1;
	
}
;
Expression_List_Helper
: Expression {
	$$ = new Arguments;
	$$->push_back($1);
	
}
| Expression_List_Helper ',' Expression {
	$$ = $1;
	
	$$->push_back($3);
	
}
;

Constant_Expression
: T_INTEGER_CONSTANT {
	$$ = $1;
}
| T_DOUBLE_CONSTANT{$$ = $1;}
| T_BOOL_CONSTANT{$$ = $1;  }
| T_STRING_CONSTANT{$$ = $1; }
| '$' '{' Identifier '}' {
	$$ = new String_Constant_Symbol($3->identifier_name(), @$);
	$3.destroy();
}
;

Identifier
: T_IDENTIFIER{
	$$ = $1;
}
| T_UPPERCASE_IDENTIFIER{
	$$ = $1;
}
| T_FILTER_NAME{
	$$ = $1;
}
;
%%

/* The closing %% above marks the end of the Rules section and the beginning
 * of the User Subroutines section. All text from here to the end of the
 * file is copied verbatim to the end of the generated y.tab.c file.
 * This section is where you put definitions of helper functions.
 */
 

