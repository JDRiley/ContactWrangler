#include "System_Call_Expression.h"


namespace jomike{



System_Call_Expression::System_Call_Expression(J_Symbol_Identifier* i_identifier, Arguments* i_args_list)
	: Call_Expression(i_identifier, i_args_list){
	
}

System_Call_Expression* System_Call_Expression::move_copy(){
	return  new System_Call_Expression(std::move(*this));
}

System_Call_Expression* System_Call_Expression::get_copy()const {
	return new System_Call_Expression(*this);
}

}



