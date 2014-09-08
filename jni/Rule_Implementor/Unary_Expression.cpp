#include "Unary_Expression.h"


namespace jomike{


Unary_Expression::~Unary_Expression(){
	delete M_expression;
}

bool Unary_Expression::has_value()const {
	assert(M_expression);
	return M_expression->has_value();
}

Unary_Expression::Unary_Expression(Unary_Expression&& irv_right): j_expression(std::move(irv_right)){
	if(irv_right.M_expression){
		M_expression = irv_right.M_expression->move_copy();
	} else{
		M_expression = nullptr;
	}
}

Unary_Expression::Unary_Expression(const Unary_Expression& irk_src) : j_expression(irk_src){
	if(irk_src.M_expression){
		M_expression = irk_src.M_expression->get_copy();
	} else{
		M_expression = nullptr;
	}
}

Unary_Expression::Unary_Expression(j_expression* i_expression) 
: j_expression(i_expression->symbol_type()){
	M_expression = i_expression;
}

Unary_Expression::Unary_Expression():j_expression(Symbol_Types::VOID_TYPE){
	M_expression = nullptr;
}

j_expression& Unary_Expression::base_expression()const{
	assert(M_expression);
	return *M_expression;
}

j_expression& Unary_Expression::base_expression(){
	assert(M_expression);
	return *M_expression;
}

bool Unary_Expression::has_expression()const{
	return M_expression;
}

void Unary_Expression::set_symbol_scope(const J_Symbol_Scope* i_symbol_scope){
	j_expression::set_symbol_scope(i_symbol_scope);
	if(has_expression()){
		base_expression().set_symbol_scope(i_symbol_scope);
	}
}

j_value Unary_Expression::derived_get_value(const Arguments& i_args)const {
	return M_expression->get_value(i_args);
}

}