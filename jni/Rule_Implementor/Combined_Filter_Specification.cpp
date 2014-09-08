#include "Combined_Filter_Specification.h"


namespace jomike{



Combined_Filter_Specification* Combined_Filter_Specification::move_copy(){
	return  new Combined_Filter_Specification(std::move(*this));
}

Combined_Filter_Specification* Combined_Filter_Specification::get_copy()const {
	return new Combined_Filter_Specification(*this);
}

Combined_Filter_Specification::Combined_Filter_Specification(
	Filter_Specification* i_left_filter, Filter_Specification* i_right_filter)
:Binary_Filter_Specification(i_left_filter, i_right_filter){

}

}



