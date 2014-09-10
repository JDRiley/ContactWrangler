#include "Call_Expression.h"
//
#include <cassert>
//
#include "J_Symbol_Identifier.h"
//
#include "Arguments.h"
//
#include "State_ID.h"
namespace jomike{



bool Call_Expression::has_value()const{
	return true;
}

j_value Call_Expression::derived_get_value(const Arguments& i_args)const {
	assert(i_args.empty());
	(void)i_args;
	return get_symbol()->get_value(*M_args_list);
}


std::string Call_Expression::derived_get_wrangler_str_val(const Arguments& irk_args){
	assert(irk_args.empty());
	(void)irk_args;
	return get_symbol()->get_wrangler_str_val(irk_args);
}


Call_Expression::Call_Expression(
	J_Symbol_Identifier* i_identifier, Arguments* i_args_list)
	:j_expression(Symbol_Types::EXPRESSION_TYPE_UNINITIALIZED){
	M_identifier = i_identifier;
	M_args_list = i_args_list;

	
}

Call_Expression::Call_Expression(const Call_Expression& irk_source)
:j_expression(irk_source){
	if(irk_source.M_base_expression){
		M_base_expression = irk_source.M_base_expression->get_copy();
	}

	M_identifier = irk_source.M_identifier->get_copy();

	M_args_list = irk_source.M_args_list->get_copy();

	if(irk_source.M_state_id){
		M_state_id = irk_source.M_state_id->get_copy();
	}
}

Call_Expression::Call_Expression(Call_Expression&& irv_src)
	:j_expression(std::move(irv_src)){
	if(irv_src.M_base_expression){
		M_base_expression = irv_src.M_base_expression->move_copy();
	}

	M_identifier = irv_src.M_identifier->move_copy();

	M_args_list = irv_src.M_args_list->move_copy();

	if(irv_src.M_state_id){
		M_state_id = irv_src.M_state_id->move_copy();
	}
}

Call_Expression::Call_Expression(
	J_Symbol_Identifier* i_identifier, State_ID* i_state_id, Arguments* i_args_list)
: j_expression(Symbol_Types::EXPRESSION_TYPE_UNINITIALIZED){
	M_identifier = i_identifier;
	M_state_id = i_state_id;
	M_args_list = i_args_list;

}

Call_Expression::Call_Expression(
	j_expression* irk_base_expression, J_Symbol_Identifier* i_identifier, Arguments* i_args_list)
:j_expression(Symbol_Types::EXPRESSION_TYPE_UNINITIALIZED){
	M_base_expression = irk_base_expression;
	M_identifier = i_identifier;
	M_args_list = i_args_list;

}

Call_Expression::~Call_Expression(){
	delete M_identifier;
	delete M_args_list;
}

j_symbol* Call_Expression::get_symbol()const{
	return get_symbol_from_scope(M_identifier->identifier_name());
}

const Type_Syntax& Call_Expression::return_type_syntax()const {
	return get_symbol_from_scope(M_identifier->identifier_name())->return_type_syntax();
}

void Call_Expression::alert_symbol_scope_set(){
	if(M_base_expression){
		M_base_expression->set_symbol_scope(&symbol_scope());
	}
}

void Call_Expression::process(const Arguments& irk_args){
	if(M_base_expression){
		M_base_expression->process(irk_args);
	}

	M_args_list->process(irk_args);
}

}



