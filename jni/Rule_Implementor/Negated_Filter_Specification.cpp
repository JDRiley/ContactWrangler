#include "Negated_Filter_Specification.h"


namespace jomike{



Negated_Filter_Specification* Negated_Filter_Specification::move_copy(){
	return  new Negated_Filter_Specification(std::move(*this));
}

Negated_Filter_Specification* Negated_Filter_Specification::get_copy()const {
	return new Negated_Filter_Specification(*this);
}

Negated_Filter_Specification::Negated_Filter_Specification(Filter_Specification* i_spec)
	:Unary_Filter_Specification(i_spec){

}

}



