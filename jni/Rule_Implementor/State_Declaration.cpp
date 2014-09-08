#include "State_Declaration.h"
//
#include "J_Symbol_Identifier.h"
//
#include "Specific_Symbol_List.h"
//
#include "Variable_Symbol.h"
namespace jomike{

State_Declaration* State_Declaration::move_copy(){
	return  new State_Declaration(std::move(*this));
}

State_Declaration* State_Declaration::get_copy()const {
	return new State_Declaration(*this);
}

State_Declaration::State_Declaration(J_Symbol_Identifier* i_identifier)
	:j_symbol_component(Symbol_Types::STATE_DECLARATION){
	M_identifier = i_identifier;
	assert(M_identifier);
}

State_Declaration::State_Declaration(State_Declaration&& irk_source)
	:j_symbol_component(std::move(irk_source)){
	M_identifier = irk_source.M_identifier->move_copy();
}

State_Declaration::State_Declaration(const State_Declaration& irv_right)
	: j_symbol_component(irv_right){
	M_identifier = irv_right.M_identifier->get_copy();
}

State_Declaration::State_Declaration(
	J_Symbol_Identifier* i_identifier, Declaration_List* i_members)
	: j_symbol_component(Symbol_Types::STATE_DECLARATION), M_identifier(i_identifier){
	M_routine_list = i_members;

	for(j_declaration* f_routine : *M_routine_list){
		assert(dynamic_cast<Variable_Symbol*>(f_routine));
	}
}

State_Declaration::~State_Declaration(){
	delete M_identifier;
}

}



