#include "Modulo_Expression.h"


namespace jomike{



Modulo_Expression::Modulo_Expression(j_expression* i_left_expr, j_expression* i_right_expr)
	:Binary_Expression(i_left_expr, i_right_expr, Operators::MODULO){

}

Modulo_Expression* Modulo_Expression::move_copy(){
	return  new Modulo_Expression(std::move(*this));
}

Modulo_Expression* Modulo_Expression::get_copy()const {
	return new Modulo_Expression(*this);
}

j_value Modulo_Expression::derived_get_value(const Arguments& i_args)const{
	return left_expression().get_value(i_args) % right_expression().get_value(i_args);
}

}



