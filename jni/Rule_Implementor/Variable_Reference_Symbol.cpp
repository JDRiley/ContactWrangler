#include "Variable_Reference_Symbol.h"
//
#include "j_expression.h"
using std::string;

namespace jomike{



string Variable_Reference_Symbol::get_display_name(){
	if(has_value()){
		return get_value().to_str();
	}
	return name();
}

Variable_Reference_Symbol* Variable_Reference_Symbol::get_copy()const {
	return new Variable_Reference_Symbol(*this);
}

Variable_Reference_Symbol* Variable_Reference_Symbol::move_copy(){
	return  new Variable_Reference_Symbol(std::move(*this));
}

j_value Variable_Reference_Symbol::derived_get_value(const Arguments& )const {
	assert(0);
	return j_value(0ll, J_Unit());
}

bool Variable_Reference_Symbol::has_value()const {
	assert(0);
	return false;
}

void Variable_Reference_Symbol::clear(){
	assert(0);
}

Variable_Reference_Symbol::Variable_Reference_Symbol(
	Type_Syntax* i_syntax, J_Symbol_Identifier* i_identifier)
	:j_declaration(i_syntax,  i_identifier){
	assert(0);
}

Variable_Reference_Symbol::Variable_Reference_Symbol(
	Type_Syntax* i_syntax, J_Symbol_Identifier* i_identifier, j_expression* i_expression)
	: j_declaration(i_syntax, i_identifier){
	M_expression = i_expression;
}

std::string Variable_Reference_Symbol::derived_get_wrangler_str_val(const Arguments& /*irk_args*/){
	return "";
}

void Variable_Reference_Symbol::alert_symbol_scope_set(){

}

void Variable_Reference_Symbol::process(const Arguments& irk_args){
	if(M_expression){
		M_expression->process(irk_args);
	}
}

}



