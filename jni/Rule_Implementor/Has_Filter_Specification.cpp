#include "Has_Filter_Specification.h"
//
#include "Specific_Symbol_List.h"
//
#include "Constant_Symbol.h"
namespace jomike{



Has_Filter_Specification* Has_Filter_Specification::move_copy(){
	return  new Has_Filter_Specification(std::move(*this));
}

Has_Filter_Specification* Has_Filter_Specification::get_copy()const {
	return new Has_Filter_Specification(*this);
}

Has_Filter_Specification::Has_Filter_Specification(
	const String_Constant_Symbol_List& irk_symbol_list){

	for(auto string_constant : irk_symbol_list){
		M_string_list.push_back(string_constant->str());
	}

	
}

}



