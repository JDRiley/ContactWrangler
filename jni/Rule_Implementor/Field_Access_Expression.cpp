#include "Field_Access_Expression.h"
//
#include "J_Symbol_Identifier.h"
using std::string;

namespace jomike{

J_FWD_DECL(J_Symbol_Identifier)

Field_Access_Expression::Field_Access_Expression(
J_Symbol_Identifier* i_name, j_expression* i_base_expression)
:j_expression(Symbol_Types::EXPRESSION_TYPE_UNINITIALIZED, i_name){

	assert(i_name);

	M_base_expression = i_base_expression;
}

Field_Access_Expression::Field_Access_Expression(const Field_Access_Expression& irk_source) : j_expression(irk_source){

	if(irk_source.M_base_expression){
		M_base_expression = irk_source.M_base_expression->get_copy();
	}
}

Field_Access_Expression::Field_Access_Expression(Field_Access_Expression&& irv_src)
	: j_expression(std::move(irv_src)){

	if(irv_src.M_base_expression){
		M_base_expression = irv_src.M_base_expression->move_copy();
	}
}

j_value Field_Access_Expression::derived_get_value(const Arguments& i_args)const {
	return get_symbol_from_scope(name())
		->get_value(i_args);
}

bool Field_Access_Expression::has_value()const{
	try{
		return get_symbol_from_scope(name())->has_value();
	} catch(...){
		return false;
	}
}

Field_Access_Expression* Field_Access_Expression::move_copy(){
	return  new Field_Access_Expression(std::move(*this));
}

Field_Access_Expression* Field_Access_Expression::get_copy()const {
	return new Field_Access_Expression(*this);
}

void Field_Access_Expression::set_value(j_value i_value){
	get_symbol_from_scope(name())->set_value(i_value);
}

string Field_Access_Expression::get_display_name(){
	return get_symbol_from_scope(name())->get_display_name();
}

Field_Access_Expression::~Field_Access_Expression(){
	delete M_base_expression;
}

j_expression* Field_Access_Expression::make_non_referenced()const{
	auto symbol = static_cast<j_expression*>(get_symbol_from_scope(name()));
	assert(symbol);

	return symbol->get_copy();
}

std::string Field_Access_Expression::derived_get_wrangler_str_val(const Arguments& /*irk_args*/){
	return "";
}

void Field_Access_Expression::alert_symbol_scope_set(){
	if(M_base_expression){
		M_base_expression->set_symbol_scope(&symbol_scope());
	}
}

void Field_Access_Expression::process(const Arguments& irk_args){
	if(M_base_expression){
		M_base_expression->process(irk_args);
	}
}

}



