#ifndef STATE_DECLARATION_H
#define STATE_DECLARATION_H

#include "j_symbol_component.h"


namespace jomike{
class State_Declaration : public j_symbol_component{
public:
	State_Declaration(
		J_Symbol_Identifier* i_identifier);


	State_Declaration(
		J_Symbol_Identifier* i_identifier, Declaration_List* i_members);

	//Deleting Constructors and Assignment Operators
	State_Declaration(const State_Declaration& irk_source);
	State_Declaration(State_Declaration&&);
	State_Declaration& operator=(const State_Declaration&) = delete;
	State_Declaration& operator=(State_Declaration&&) = delete;

	State_Declaration* get_copy()const override;

	State_Declaration* move_copy()override;

	~State_Declaration();
private:
	J_Symbol_Identifier* M_identifier;
	Declaration_List* M_routine_list;
};

}

#endif //STATE_DECLARATION_H


