#include "Rule_Model.h"
//
#include "J_Symbol_Error.h"
//
#include "j_symbol.h"
//
#include "N_Ary_Function_Symbol.h"

using std::string;

namespace jomike{

static Instance_Pointer<Rule_Model> s_rule_model;

j_symbol* get_j_symbol_from_model(const string& irk_name){

	return s_rule_model->get_symbol(irk_name);
}

Rule_Model& Rule_Model::get_instance(){
	static Rule_Model model;
	return model;
}

j_symbol* Rule_Model::get_symbol(const std::string& irk_name){
	auto found_pos = M_symbols.find(irk_name);
	if(M_symbols.end() == found_pos){
		throw J_Symbol_Error("Could Not Find symbol with name: " + irk_name);
	}
	return *found_pos;
}

Rule_Model::~Rule_Model(){
	for(auto f_symbol : M_symbols){
		delete f_symbol;
	}
}

Rule_Model::Rule_Model(){
	init_built_in_functions();
}

void Rule_Model::init_built_in_functions(){
	const string between_inclusive_str = "between_inclusive";
	assert(!M_symbols.count(between_inclusive_str));

	M_symbols[between_inclusive_str]
		= new N_Ary_Function_Symbol<bool, j_dbl, j_dbl, j_dbl>(between_inclusive<j_dbl>, between_inclusive_str);

	const string days_str = "days";
	M_symbols[days_str]
		= new N_Ary_Function_Symbol<j_llint, j_llint>([](j_llint i_val){return i_val * 24 * 60 * 60; }, days_str);

	const string seconds_str = "seconds";
	M_symbols[seconds_str]
		= new N_Ary_Function_Symbol<j_llint, j_llint>([](j_llint i_val){return i_val;}, seconds_str);

}

}



