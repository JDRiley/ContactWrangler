#ifndef WRANGLER_FUNCTION_H
#define WRANGLER_FUNCTION_H

#include "Rule_Implementor.h"
//
#include <ex_array.h>
//
#include <Stream_Checker.h>
namespace jomike{
class Wrangler_Function{

public:
	Wrangler_Function(J_Symbol_Identifier* i_name);


	class Implementation_Data;

	//Deleting Constructors and Assignment Operators
	Wrangler_Function(const Wrangler_Function&) = delete;
	Wrangler_Function(Wrangler_Function&&) = delete;
	Wrangler_Function& operator=(const Wrangler_Function&) = delete;
	Wrangler_Function& operator=(Wrangler_Function&&) = delete;
	void add_implementation(
		const State_ID& irk_state, const Custom_Routine_Symbol& irk_routine);


	~Wrangler_Function();


	std::string process(const State_ID& ir_state, Stream_Checker* ir_checker)const;
private:
	J_Symbol_Identifier* M_name;


	


	ex_array<Implementation_Data*> M_implementations;
	
};

}

#endif //WRANGLER_FUNCTION_H


