#ifndef RULE_MODEL_H
#define RULE_DATA_H

#include "Rule_Implementor_Fwd_Decl.h"

//
#include <J_Utile.h>
//
#include <string>
//
#include <j_map.h>
namespace jomike{
class Rule_Model{
public:
	j_symbol* get_symbol(const std::string& irk_name);


	~Rule_Model();
private:
	friend class Instance_Pointer<Rule_Model>;
	Rule_Model();
	static Rule_Model& get_instance();

	j_map<std::string, j_symbol*> M_symbols;

	void init_built_in_functions();
};

}

#endif //RULE_MODEL_H


