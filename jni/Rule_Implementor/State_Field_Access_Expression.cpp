#include "State_Field_Access_Expression.h"
//
#include "Constant_Symbol.h"

namespace jomike{



jomike::j_value State_Field_Access_Expression::derived_get_value(const Arguments& /*i_args*/)const {
	return j_value(name(), J_Unit());
}

bool State_Field_Access_Expression::has_value()const{
	return true;
}

State_Field_Access_Expression* State_Field_Access_Expression::move_copy(){
	return  new State_Field_Access_Expression(std::move(*this));
}

State_Field_Access_Expression* State_Field_Access_Expression::get_copy()const {
	return new State_Field_Access_Expression(*this);
}

State_Field_Access_Expression::State_Field_Access_Expression(J_Symbol_Identifier* i_identifier)
	:Field_Access_Expression(i_identifier){

}

j_expression* State_Field_Access_Expression::make_non_referenced()const{
	return new String_Constant_Symbol(name(), yy::location());
}

}



