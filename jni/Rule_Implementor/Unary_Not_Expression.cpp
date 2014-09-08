#include "Unary_Not_Expression.h"


namespace jomike{



Unary_Not_Expression* Unary_Not_Expression::move_copy(){
	return  new Unary_Not_Expression(std::move(*this));
}

Unary_Not_Expression* Unary_Not_Expression::get_copy()const {
	return new Unary_Not_Expression(*this);
}

Unary_Not_Expression::Unary_Not_Expression(j_expression* i_expression):Unary_Expression(i_expression){

}

j_value Unary_Not_Expression::derived_get_value(const Arguments& i_args)const {
	return j_value(!Unary_Expression::derived_get_value(i_args).as_bool(), J_Unit());
}



}



