#include "Wrangler_Function.h"
//
#include "State_ID.h"
//
#include "Custom_Routine_Symbol.h"
//
#include "J_Symbol_Identifier.h"
namespace jomike{



Wrangler_Function::Wrangler_Function(J_Symbol_Identifier* i_name){
	M_name = i_name;
}

class Wrangler_Function::Implementation_Data{
public:
	Implementation_Data(const State_ID& irk_state_id, const Custom_Routine_Symbol& irk_routine){
		M_state_id = irk_state_id.get_copy();
		M_routine = irk_routine.get_copy();
	}

	//Deleting Constructors and Assignment Operators
	Implementation_Data(const Implementation_Data&) = delete;
	Implementation_Data(Implementation_Data&&) = delete;
	Implementation_Data& operator=(const Implementation_Data&) = delete;
	Implementation_Data& operator=(Implementation_Data&&) = delete;

	~Implementation_Data(){
		delete M_state_id;
		delete M_routine;
	}
private:
	State_ID* M_state_id;
	Custom_Routine_Symbol* M_routine;
};

void Wrangler_Function::add_implementation(const State_ID& irk_state, const Custom_Routine_Symbol& irk_routine){
	M_implementations.push_back(new Implementation_Data(irk_state, irk_routine));
}

Wrangler_Function::~Wrangler_Function(){
	delete M_name;
	M_implementations.apply([](Implementation_Data* y_data){delete y_data; });

}


}



