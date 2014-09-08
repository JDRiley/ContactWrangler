#include "Filter_Call_Expression.h"


namespace jomike{



Filter_Call_Expression* Filter_Call_Expression::move_copy(){
	return  new Filter_Call_Expression(std::move(*this));
}

Filter_Call_Expression* Filter_Call_Expression::get_copy()const {
	return new Filter_Call_Expression(*this);
}

Filter_Call_Expression::Filter_Call_Expression(J_Symbol_Identifier* i_identifier, Arguments* i_args_list):Call_Expression(i_identifier, i_args_list){

}

}



