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
using std::string;

namespace jomike{


j_symbol* get_j_symbol_from_model(const string& irk_name){
	throw J_Symbol_Error("No Global Symbols in Rule Wrangler. Symbol: " + irk_name + " not found!");
}

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

}



