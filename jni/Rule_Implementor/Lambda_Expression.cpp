#include "Lambda_Expression.h"
//
#include "Specific_Symbol_List.h"
//
#include "Statement_Block.h"
//
#include "j_declaration.h"
//
#include "Arguments.h"
//
#include "Aggregate_Value_Symbol.h"
namespace jomike{



Lambda_Expression::Lambda_Expression(
	Declaration_List* i_decl_list, Statement_Block* i_statement_block)
:j_expression(Symbol_Types::LAMBDA_EXPRESSION){

	M_static_declarations = i_decl_list;
	M_statement_block = i_statement_block;
}

Lambda_Expression::Lambda_Expression(const Lambda_Expression& irk_src)
:j_expression(irk_src){
	M_static_declarations = irk_src.M_static_declarations->get_copy();
	M_statement_block = irk_src.M_statement_block->get_copy();
}

Lambda_Expression::Lambda_Expression(Lambda_Expression&& irv_src)
	: j_expression(irv_src){
	M_static_declarations = irv_src.M_static_declarations->move_copy();
	M_statement_block = irv_src.M_statement_block->move_copy();
}



Lambda_Expression* Lambda_Expression::move_copy(){
	return  new Lambda_Expression(std::move(*this));
}

Lambda_Expression* Lambda_Expression::get_copy()const {
	return new Lambda_Expression(*this);
}

bool Lambda_Expression::has_value()const {
	return M_statement_block->has_value();
}

j_value Lambda_Expression::derived_get_value(const Arguments& /*i_args*/)const {

	Arguments args;
	args.push_back(get_copy());
	return j_value(Aggregate_Value_Symbol(args), J_Unit());


}

std::string Lambda_Expression::derived_get_wrangler_str_val(const Arguments& irk_args){
	std::string return_string = "Lambda: @";
	//@ is a sentinal character declaring the bounds of a lambda. 
	//NOTE: this means currently you cannot have nested lambda expressions!

	return_string += M_statement_block->get_wrangler_str_val(irk_args);
	return_string.push_back('@');
	return return_string;
}

void Lambda_Expression::alert_symbol_scope_set(){
	M_statement_block->set_symbol_scope(&symbol_scope());
}

void Lambda_Expression::process(const Arguments& irk_args){
	M_static_declarations->process(irk_args);
	M_statement_block->process(irk_args);
}



}



