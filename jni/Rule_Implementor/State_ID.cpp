#include "State_ID.h"
//
#include "J_Symbol_Identifier.h"

namespace jomike{



State_ID* State_ID::move_copy(){
	return  new State_ID(std::move(*this));
}

State_ID* State_ID::get_copy()const {
	return new State_ID(*this);
}

State_ID::State_ID(J_Symbol_Identifier* i_identifier):j_symbol_component(Symbol_Types::STATE_ID){
	M_state_id = i_identifier->identifier_name();
}

}



