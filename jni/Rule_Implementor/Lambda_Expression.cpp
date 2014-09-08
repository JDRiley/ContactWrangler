#include "Lambda_Expression.h"
//
#include "Specific_Symbol_List.h"
//
#include "Statement_Block.h"
//
#include "j_declaration.h"
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
	assert(!"This has not been implemented. See custom routine symbol");
	return J_VALUE_FALSE_BOOLEAN;
}



}



