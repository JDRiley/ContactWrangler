#include "Binary_Filter_Specification.h"


namespace jomike{



Binary_Filter_Specification::Binary_Filter_Specification(
	Filter_Specification* i_left_filter, Filter_Specification* i_right_filter){
	M_left_filter = i_left_filter;
	M_right_filter = i_right_filter;
}

Binary_Filter_Specification::Binary_Filter_Specification(
	const Binary_Filter_Specification& irk_src):Filter_Specification(irk_src){
	M_left_filter = irk_src.M_left_filter->get_copy();
	M_right_filter = irk_src.M_right_filter->get_copy();
}

Binary_Filter_Specification::Binary_Filter_Specification(Binary_Filter_Specification&& irv_src)
:Filter_Specification(std::move(irv_src)){
	M_left_filter = irv_src.M_left_filter->move_copy();
	M_right_filter = irv_src.M_right_filter->move_copy();
}

const Filter_Specification& Binary_Filter_Specification::right_filter()const{
	assert(M_right_filter);
	return *M_right_filter;
}

Filter_Specification& Binary_Filter_Specification::right_filter(){
	assert(M_right_filter);
	return *M_right_filter;
}

const Filter_Specification& Binary_Filter_Specification::left_filter()const{
	assert(M_left_filter);
	return *M_left_filter;
}

Filter_Specification& Binary_Filter_Specification::left_filter(){
	assert(M_left_filter);
	return *M_left_filter;
}

}



