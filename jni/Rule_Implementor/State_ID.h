#ifndef STATE_ID_H
#define STATE_ID_H

#include "j_symbol_component.h"


namespace jomike{
class State_ID : public j_symbol_component{
public:
	State_ID(J_Symbol_Identifier* i_identifier);

	State_ID* get_copy()const override;


	State_ID* move_copy()override;

private:
	std::string M_state_id;
};

}

#endif //STATE_ID_H


