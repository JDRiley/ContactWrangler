#include "Rule_Data.h"
//
#include "Wrangler_Filter.h"
//
#include "J_Symbol_Error.h"
using std::string;

namespace jomike{





void Rule_Data::add_filter(Wrangler_Filter* i_filter){
	string filter_name = i_filter->name();
	if(M_filters.count(filter_name)){
		delete i_filter;
		throw J_Symbol_Error(
			"Filter with name: " + filter_name + " already exists.");
	}
	M_filters[filter_name] = i_filter;
}

Rule_Data::~Rule_Data(){
	clear();
}

void Rule_Data::clear(){
	for(auto f_filter : M_filters){
		delete f_filter;
	}
}

Rule_Data::Rule_Data(const Rule_Data& irk_src){

	M_filters = irk_src.M_filters;

	for(auto& f_filter : M_filters){
		f_filter = f_filter->get_copy();
	}

}

Rule_Data::Rule_Data(){

}


const Wrangler_Filter& Rule_Data::get_filter(const std::string& irk_name)const{
	if(!M_filters.count(irk_name)){
		throw J_Symbol_Error("No Filter with name: " + irk_name);
	}

	return **M_filters.find(irk_name);
}

}



