#ifndef MATH_LEXER_H
#define MATH_LEXER_H

#include "J_Fwd_Decl.h"
//
#include <FlexLexer.h>
//
#include "Rule_Implementor_Fwd_Decl.h"
//
#include "Rule_Parser.h"
//
#include "Lexer_Location.h"
//
#include <ex_array.h>



typedef yy::Rule_Parsing_Unit::token_type token_t;
typedef yy::Rule_Parsing_Unit::semantic_type semantic_t;

#define YY_DECL		\
	token_t\
	Rule_Lexer::yylex(semantic_t* yylval, yy::location* i_loc)





namespace jomike{
class Rule_Parser;
struct Lexer_Location;
class Rule_Lexer : public yyFlexLexer{
public:
	Rule_Lexer();
	token_t yylex(semantic_t* yylval, yy::location* i_loc);
	void init_scanner();
	void pre_action_set_up();
	const std::string& get_line(j_size_t i_line)const;
private:
	yy::location M_location;
	yy_buffer_state* yy_current_buffer;

	ex_array<std::string> M_lines;

	int M_current_line;
	int M_current_collumn;


};

}

#endif //MATH_LEXER_H


