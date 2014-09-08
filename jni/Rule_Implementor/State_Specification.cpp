#include "State_Specification.h"
//
#include "State_ID.h"
//
#include "Specific_Symbol_List.h"
//
#include "Custom_Routine_Symbol.h"
//
#include "J_Symbol_Error.h"
namespace jomike{


State_Specification::State_Specification(
	State_ID* i_state_id, const Declaration_List& irk_decl_list)
	:j_symbol_component(Symbol_Types::STATE_SPECIFICATION){
	M_state_id = i_state_id;

	for(auto f_decl : irk_decl_list){
		const Custom_Routine_Symbol*
			routine = dynamic_cast<const Custom_Routine_Symbol*>(f_decl);

		if(M_routines.count(routine->name())){
			throw J_Symbol_Error("Routine with name: " + routine->name()
								 + " already exists in this state");
		} else{
			M_routines[routine->name()] = routine->get_copy();
		}

	}

	

}

State_Specification::State_Specification(
	const State_Specification& irk_source):j_symbol_component(irk_source){
	M_state_id = irk_source.state_id().get_copy();


}


State_Specification* State_Specification::move_copy(){
	return  new State_Specification(std::move(*this));
}

State_Specification* State_Specification::get_copy()const {
	return new State_Specification(*this);
}

const State_ID& State_Specification::state_id()const{
	return *M_state_id;
}

State_Specification::~State_Specification(){
	delete M_state_id;
}

State_Specification::iterator State_Specification::end(){
	return M_routines.end();
}

State_Specification::iterator State_Specification::begin(){
	return M_routines.begin();
}

}



