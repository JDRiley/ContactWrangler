//
#include "Rule_Parser.h"
//
#include "Rule_Lexer.h"
//
#include <sstream>
//
#include <iostream>
//
#include "J_Symbol_Error.h"
//
#include "Arguments.h"
//
#include "Constant_Symbol.h"
//
#include "j_declaration.h"
//
#include "Type_Syntax.h"
//
#include <algorithm>
//
#include <functional>
//
#include <utility>
//
#include "Specific_Symbol_List.h"
//
#include "j_statement.h"
//
#include "Rule_Data.h"
//
#include "State_ID.h"
//
#include <algorithm>
//
#include <ex_array.h>
using std::mem_fn; using std::bind; using std::for_each; using std::transform;
using namespace std::placeholders;
using std::stringstream; using std::ostringstream;
using std::string;

int j_semantic_type::base_restrictive_ptr::Ms_restrictive_ptr_ID = 0;
using yy::location;
namespace jomike{

static Instance_Pointer<Rule_Data> s_rule_model;

token_t Rule_Parser::lex(semantic_t* yylval, yy::location* i_loc){
	return M_lexer->yylex(yylval, i_loc);
}

Rule_Implementor* Rule_Parser::parse(const std::string& irk_string){
	Rule_Implementor* new_implementor = nullptr;

	Rule_Data rule_data;
	yy::Rule_Parsing_Unit parsing_unit(&new_implementor, this, rule_data);

	

	//parsing_unit.set_debug_level(1);
	stringstream str_stream(irk_string);
	M_lexer->yyrestart(&str_stream);

	parsing_unit.parse();
	
	
	return new_implementor;

}

Rule_Parser::Rule_Parser(){
	
	M_lexer = new Rule_Lexer;
}

Rule_Parser::~Rule_Parser(){
	delete M_lexer;
}

std::string Rule_Parser::get_lines(const yy::location& irk_loc){
	string lines;

	auto underline_error = [](const std::string& irk_string, const location& irk_loc, unsigned y_line_index){
		assert(y_line_index <= irk_loc.end.line);
		unsigned end_pos;
		if(y_line_index == irk_loc.end.line){
			end_pos = irk_loc.end.column;
		} else{
			end_pos = safe_uns_cast(irk_string.size());
		}
		std::string input_line;
		const unsigned k_string_size = safe_uns_cast(irk_string.size());
		for(unsigned i = 0, str_pos = 1; i < k_string_size; ++i){
			
			if(between_inclusive(str_pos, irk_loc.begin.column, end_pos)){
				input_line.push_back('^');
			} else{
				input_line.push_back(' ');
			}
			const unsigned TAB_SIZE = 8;

			if(irk_string[i] == '\t'){
				unsigned original_str_pos = str_pos;
				str_pos += (TAB_SIZE - (str_pos ) % TAB_SIZE) % TAB_SIZE;
				int diff = str_pos - original_str_pos;
				for(int b = 0; b < diff; ++b){
					input_line.push_back(' ');
				}
			}

			++str_pos;
		}

		return input_line;
	};
	

	for(unsigned i = irk_loc.begin.line; i < irk_loc.end.line +1; ++i){
		lines += (M_lexer->get_line(i) + '\n');
		lines += underline_error(M_lexer->get_line(i), irk_loc, i);
		lines.push_back('\n');
	}


	return lines;
}

std::string Rule_Parser::get_line(unsigned i_line){
	return M_lexer->get_line(i_line);
}

}

yy::Rule_Parsing_Unit::token_type yylex(
	yy::Rule_Parsing_Unit::semantic_type* yylval, yy::location* yylloc, jtl::Rule_Parser* i_parser){
	
	return i_parser->lex(yylval, yylloc);
}


void yy::Rule_Parsing_Unit::error(const location_type& irk_loc, const std::string& irk_string){

	ostringstream o_str;

	int start_pos = std::max(irk_loc.begin.line - 4, 1u);
	for(unsigned i = start_pos; i < irk_loc.begin.line; ++i){
		o_str << i_parser->get_line(i) << '\n';
	}

	o_str << '(' << irk_string << ')' << "[Syntax_Error : " << irk_loc << ']'
		<< '\n' << i_parser->get_lines(irk_loc);
	
	std::cerr << "Error Encountered: " << o_str.str();

	jtl::ex_array<string> tokens;
	for(const char* const * f_token = yytname_; *f_token; ++f_token){
		tokens.push_back(*f_token);
	}
	throw jtl::J_Syntax_Error(o_str.str());
}

//#define MEMBER_INITIALIZATION \
//	identifier(this)\
//, symbol_component(this)\
//, constant_symbol(this)\
//, declaration(this)\
//, type_syntax(this)\
//, expression(this)\
//, arguments(this)\
//, symbol(this)\
//, symbol_list(this)\
//, symbol_scope(this)\
//, declaration_list(this)\
//, statement_block(this)\
//, statement(this)

#define COMMA ,
#define SEMI_COLON ;
#define FOR_ALL(m_macro, seperator)\
	m_macro(identifier) seperator\
	m_macro(symbol_component) seperator\
	m_macro(constant_symbol) seperator\
	m_macro(declaration) seperator\
	m_macro(type_syntax) seperator\
	m_macro(expression) seperator\
	m_macro(arguments) seperator\
	m_macro(symbol) seperator\
	m_macro(symbol_list) seperator\
	m_macro(symbol_scope) seperator\
	m_macro(declaration_list) seperator\
	m_macro(statement) seperator\
	m_macro(statement_block) seperator\
	m_macro(if_statement) seperator\
	m_macro(string_constant) seperator\
	m_macro(state_id) seperator\
	m_macro(state_decl_list) seperator\
	m_macro(state_spec_list) seperator\
	m_macro(state_decl) seperator\
	m_macro(state_spec) seperator\
	m_macro(filter) seperator\
	m_macro(filter_spec) seperator\
	m_macro(string_list) seperator\
	m_macro(type_syntax_list)

#define INITIALIZE_MEMBER(name) name(this)

#define MEMBER_INITIALIZATION FOR_ALL(INITIALIZE_MEMBER, COMMA)

j_semantic_type::j_semantic_type()
:MEMBER_INITIALIZATION {
	set_pointer_map();
	
	 
	
}
j_semantic_type::j_semantic_type(const j_semantic_type& irk_right)
:MEMBER_INITIALIZATION{
	set_pointer_map();


	copy_data(irk_right);

}

j_semantic_type::j_semantic_type(j_semantic_type&& irr_right)
: MEMBER_INITIALIZATION{
	set_pointer_map();
	swap(irr_right);
}

#undef MEMBER_INITIALIZATION


void j_semantic_type::set_pointer_map(){
#define SET_ID_TO_PTR(ptr) {ptr.ID(), &ptr}

	M_ptrs = {
		FOR_ALL(SET_ID_TO_PTR, COMMA)
		//SET_ID_TO_PTR(identifier)
		//, SET_ID_TO_PTR(symbol_component)
		//, SET_ID_TO_PTR(constant_symbol)
		//, SET_ID_TO_PTR(declaration)
		//, SET_ID_TO_PTR(type_syntax)
		//, SET_ID_TO_PTR(expression)
		//, SET_ID_TO_PTR(arguments)
		//, SET_ID_TO_PTR(symbol)
		//, SET_ID_TO_PTR(symbol_list)
		//, SET_ID_TO_PTR(symbol_scope)
		//, SET_ID_TO_PTR(declaration_list)
		//, SET_ID_TO_PTR(statement_block)
		//, SET_ID_TO_PTR(statement)
	};
#undef SET_ID_TO_PTR
}


template<typename St>
j_semantic_type::restrictive_ptr<St>::~restrictive_ptr(){
	destroy();
}


template<typename St>
void j_semantic_type::restrictive_ptr<St>::destroy(){
	delete M_ptr;
	M_ptr = nullptr;
}

j_semantic_type::~j_semantic_type(){

}

j_semantic_type& j_semantic_type::operator=(const j_semantic_type& irk_right){
	j_semantic_type temp(irk_right);
	swap(temp);
	return *this;
}

class Move_Ptr{
public:
	template<typename St>
	St* operator()(j_semantic_type::restrictive_ptr<St>& irk_src)const{
		return irk_src.take();
	}
};

void j_semantic_type::move_data(j_semantic_type& ir_right){

	get_data(ir_right, Move_Ptr());
}



template<typename St, typename Ptr_Retrieval_t>
static void assign_ptr(
	int& i_num_set, j_semantic_type::restrictive_ptr<St>& i_left
	, j_semantic_type::restrictive_ptr<St>& i_right, Ptr_Retrieval_t& i_func){
	if(auto ptr = i_func(i_right)){
		++i_num_set;
		i_left = ptr;
	}
}

template<typename St, typename Ptr_Retrieval_t>
static void assign_ptr(
	int& i_num_set, j_semantic_type::restrictive_ptr<St>& i_left
	, const j_semantic_type::restrictive_ptr<St>& irk_right, Ptr_Retrieval_t& i_func){
	if(auto ptr = i_func(irk_right)){
		++i_num_set;
		i_left = ptr;
	}
}

template<typename Semantic_t, typename Ptr_Retrieval_t>
typename jtl::enable_if_same_non_qualified_type<
	Semantic_t, j_semantic_type, void>::type  j_semantic_type::get_data(
	Semantic_t& irk_right, Ptr_Retrieval_t i_func){

	int num_set = 0;



#define PTR_ASSIGN(i_ptr) assign_ptr(num_set, i_ptr, irk_right.i_ptr, i_func);
	FOR_ALL(PTR_ASSIGN, SEMI_COLON);
	//PTR_ASSIGN(identifier);
	//PTR_ASSIGN(symbol_component);
	//PTR_ASSIGN(constant_symbol);
	//PTR_ASSIGN(declaration);
	//PTR_ASSIGN(type_syntax);
	//PTR_ASSIGN(expression);
	//PTR_ASSIGN(arguments);
	//PTR_ASSIGN(symbol);
	//PTR_ASSIGN(symbol_list);
	//PTR_ASSIGN(symbol_scope);
	//PTR_ASSIGN(declaration_list);
	//PTR_ASSIGN(statement_block);
	//PTR_ASSIGN(statement);

#undef PTR_ASSIGN

	

	assert((num_set < 2) || "Num Set Should Be only 1 max");
}

j_semantic_type& j_semantic_type::operator==(j_semantic_type&& irr_right){
	set_all_null();
	swap(irr_right);
	return *this;
}
class Copy_Ptr{
public:
	template<typename St>
	St* operator()(const j_semantic_type::restrictive_ptr<St>& irk_src)const{
		return irk_src.copy_ptr();
	}
};

void j_semantic_type::copy_data(const j_semantic_type &irk_right){

	get_data(irk_right, Copy_Ptr());
}

void j_semantic_type::swap(j_semantic_type& ir_right){
	assert(M_ptrs.size() == ir_right.M_ptrs.size());
	auto src_pos = ir_right.M_ptrs.begin();
	for(auto f_res_ptr : M_ptrs){
		f_res_ptr->swap(**src_pos++);
	}
}

template<typename St>
St* j_semantic_type::restrictive_ptr<St>::copy_ptr()const{
	return M_ptr ? M_ptr->get_copy() : nullptr;
}

template<typename St>
void j_semantic_type::restrictive_ptr<St>::swap(base_restrictive_ptr& ir_right){
	restrictive_ptr<St>* src_ptr = dynamic_cast<restrictive_ptr<St>*>(&ir_right);

	assert(src_ptr);
	swap(*src_ptr);
}


template<typename St>
void j_semantic_type::restrictive_ptr<St>::swap(
	j_semantic_type::restrictive_ptr<St>& ir_right){
	std::swap(M_ptr, ir_right.M_ptr);
}
