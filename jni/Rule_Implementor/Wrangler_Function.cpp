#include "Wrangler_Function.h"
//
#include "State_ID.h"
//
#include "Custom_Routine_Symbol.h"
//
#include "J_Symbol_Identifier.h"
//
#include <Stream_Checker.h>
//
#include "Arguments.h"
//
#include "Constant_Symbol.h"
using std::string;

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

	std::string process(Stream_Checker* ir_checker)const{
		string arg_string;
		ir_checker->consume_char('"');
		ir_checker->getline_and_check(&arg_string, '"', "Arguments");
		Arguments args;
		args.push_back(new String_Constant_Symbol(arg_string, yy::location()));

		return M_routine->get_wrangler_str_val(args);
	}

	const State_ID& state_id()const{
		assert(M_state_id);
		return *M_state_id;
	}

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

std::string Wrangler_Function::process(const State_ID& ir_state, Stream_Checker* ir_checker)const{
	for(auto f_impl : M_implementations){
		if(!f_impl->state_id().matches(ir_state)){
			continue;
		}


		return f_impl->process(ir_checker);
	}

	return "Error: Could Not find state for function: " + M_name->identifier_name();
}


}



