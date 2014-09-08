#ifndef STATE_SPECIFICATION_H
#define STATE_SPECIFICATION_H

#include "j_symbol_component.h"
//
#include <j_map.h>

namespace jomike{
class State_Specification : public j_symbol_component{
public:
	State_Specification(State_ID* i_state_id, const Declaration_List& i_declaration_list);

	State_Specification(const State_Specification& irk_source);

	State_Specification* get_copy()const override;

	State_Specification* move_copy()override;

	const State_ID& state_id()const;

	~State_Specification();


	typedef j_map<std::string, Custom_Routine_Symbol*> Routine_Cont_t;

	typedef Routine_Cont_t::iterator iterator;

	iterator begin();

	iterator end();

private:

	State_ID* M_state_id;

	Routine_Cont_t M_routines;
};

}

#endif //STATE_SPECIFICATION_H


