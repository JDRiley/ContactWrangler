#ifndef RULE_MODEL_H
#define RULE_MODEL_H

#include "Rule_Implementor_Fwd_Decl.h"
//
#include <string>
//
#include <J_Utile.h>
//
#include <j_map.h>
namespace jomike{
class Rule_Data{
public:
	Rule_Data();

	//Deleting Constructors and Assignment Operators
	Rule_Data(const Rule_Data&);
	Rule_Data(Rule_Data&&) = delete;
	Rule_Data& operator=(const Rule_Data&) = delete;
	Rule_Data& operator=(Rule_Data&&) = delete;

	const Wrangler_Filter& get_filter(const std::string&)const;

	void add_filter(Wrangler_Filter* i_filter);
	void clear();

	~Rule_Data();
private:
	
	typedef j_map<std::string, Wrangler_Filter*> Wrangler_Filter_Cont_t; 
	Wrangler_Filter_Cont_t M_filters;

	
};

}

#endif //RULE_MODEL_H


