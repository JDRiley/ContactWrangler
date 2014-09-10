#include "Rule_Implementor.h"
//
#include "Specific_Symbol_List.h"
//
#include "State_Specification.h"
//
#include "Rule_Data.h"
//
#include "Custom_Routine_Symbol.h"
//
#include "Wrangler_Function.h"
//
#include "J_Symbol_Identifier.h"
//
#include "J_Symbol_Error.h"
//
#include <Stream_Checker.h>
//
#include <sstream>
//
#include "State_ID_Factory.h"

using std::string;

using std::istringstream;
//
#include "State_ID.h"
namespace jomike{



Rule_Implementor::Rule_Implementor(
	State_Specification_List* i_state_specifications, const Rule_Data& irk_rule_data){

	M_rule_data = Rule_Data_Unique_t(new Rule_Data(irk_rule_data));



	add_state_specifications(i_state_specifications);

	delete i_state_specifications;
}

Rule_Implementor::~Rule_Implementor(){
	for(auto f_wrangler_func : M_wrangler_functions){
		delete f_wrangler_func;
	}
}

void Rule_Implementor::add_state_specifications(
	State_Specification_List* i_state_specifications){
	
	for(auto f_specification : *i_state_specifications){
		const State_ID& state_id = f_specification->state_id();
		
		for(auto f_decl : *f_specification){
			Custom_Routine_Symbol*
				routine = dynamic_cast<Custom_Routine_Symbol*>(f_decl);

			assert(routine);


			Wrangler_Function* wrangler_func;
			if(!M_wrangler_functions.count(routine->name())){
				wrangler_func = M_wrangler_functions[routine->name()]
					= new Wrangler_Function(new J_Symbol_Identifier(routine->name()));
			} else{
				wrangler_func = M_wrangler_functions[routine->name()];
			}

			wrangler_func->add_implementation(state_id, *routine);

		}
	}

}

string Rule_Implementor::process_command(const string& irk_command){

	Stream_Checker checker(irk_command);

	checker.skip_string("State:", "State Data");

	string input_string;

	checker.getline_and_check(&input_string, ':',  "State ID");

	if(' ' == input_string.front()){
		input_string.erase(input_string.begin());
	}


	State_ID_Unique_t state_id(make_state_id(input_string));

	string function_name;
	checker.getline_and_check(&function_name, '(', "Function Name");

	if(!M_wrangler_functions.count(function_name)){
		return "Error: Function with name: " + function_name + " not found!";
	}

	Wrangler_Function* wrangler_func = *M_wrangler_functions.find(function_name);

	return wrangler_func->process(*state_id, &checker);

}

}



