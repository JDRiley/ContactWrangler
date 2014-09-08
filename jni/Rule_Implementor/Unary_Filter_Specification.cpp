#include "Unary_Filter_Specification.h"


namespace jomike{



Unary_Filter_Specification::Unary_Filter_Specification(
	const Unary_Filter_Specification& irk_source):Filter_Specification(irk_source){
	M_base_specification = irk_source.M_base_specification->get_copy();

}

Unary_Filter_Specification::Unary_Filter_Specification(
	Unary_Filter_Specification&& irv_source) : Filter_Specification(std::move(irv_source)){
	M_base_specification = irv_source.M_base_specification->move_copy();

}

Unary_Filter_Specification::Unary_Filter_Specification(Filter_Specification* i_filter){
	M_base_specification = i_filter;
}

}



