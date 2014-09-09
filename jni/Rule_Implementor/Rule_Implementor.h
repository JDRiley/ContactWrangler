#ifndef RULE_IMPLEMENTOR_H
#define RULE_IMPLEMENTOR_H

#include "Rule_Implementor_Fwd_Decl.h"
//
#include <j_map.h>

namespace jomike{
class Rule_Implementor{
public:
	Rule_Implementor(State_Specification_List* i_state_specifications
					 , const Rule_Data& irk_rule_data);

	//Deleting Constructors and Assignment Operators
	Rule_Implementor(const Rule_Implementor&) = delete;
	Rule_Implementor(Rule_Implementor&&) = delete;
	Rule_Implementor& operator=(const Rule_Implementor&) = delete;
	Rule_Implementor& operator=(Rule_Implementor&&) = delete;

	std::string process_command(const std::string& irk_command);
	~Rule_Implementor();
	
private:
	Rule_Data_Unique_t M_rule_data;
	void add_state_specifications(State_Specification_List* i_state_specifications);
	j_map<std::string, Wrangler_Function*> M_wrangler_functions;
};

}

#endif //RULE_IMPLEMENTOR_H


