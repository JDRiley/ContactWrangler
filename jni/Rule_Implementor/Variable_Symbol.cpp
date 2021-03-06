#include "Variable_Symbol.h"
//
#include "j_expression.h"
//
#include "Type_Syntax.h"
//
#include "Value_Expression.h"
using std::string;

namespace jomike{



void Variable_Symbol::clear(){
	assert(0);
}

string Variable_Symbol::get_display_name(){
	if(has_value()){
		return get_value().to_str();
	}
	return name();
}

j_value Variable_Symbol::derived_get_value(const Arguments& )const{
	return M_value;
}

Variable_Symbol::Variable_Symbol(Type_Syntax* i_syntax, J_Symbol_Identifier* i_identifier)
	:j_declaration(i_syntax, i_identifier){
	
}

Variable_Symbol::Variable_Symbol(
	Type_Syntax* i_syntax, J_Symbol_Identifier* i_identifier, const j_expression& i_expression)
	:j_declaration(i_syntax, i_identifier){
	if(!i_expression.has_value()){
		throw J_Value_Error("Cannot Declare variable and assign it to expression with no value");
	}
	M_value = type_syntax().convert_value(i_expression.get_value());

}

bool Variable_Symbol::has_value()const {
	return M_value.value_status();
}

j_expression* Variable_Symbol::as_expression(){
	return new Value_Expression(M_value);
}

void Variable_Symbol::set_value(j_value i_value){
	M_value = type_syntax().convert_value(i_value);
}

Variable_Symbol* Variable_Symbol::get_copy()const {
	return new Variable_Symbol(*this);
}

Variable_Symbol* Variable_Symbol::move_copy(){
	return  new Variable_Symbol(std::move(*this));
}

std::string Variable_Symbol::derived_get_wrangler_str_val(const Arguments& /*irk_args*/){
	return "";
}

void Variable_Symbol::alert_symbol_scope_set(){

}

void Variable_Symbol::process(const Arguments& /*irk_args*/){

}

}



