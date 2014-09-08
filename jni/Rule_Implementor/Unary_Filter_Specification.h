#ifndef UNARY_FILTER_SPECIFICATION_H
#define UNARY_FILTER_SPECIFICATION_H

#include "Filter_Specification.h"


namespace jomike{
class Unary_Filter_Specification : public Filter_Specification{
public:
	Unary_Filter_Specification(Filter_Specification* i_filter);

	//Deleting Constructors and Assignment Operators
	Unary_Filter_Specification(const Unary_Filter_Specification& irk_source);
	Unary_Filter_Specification(Unary_Filter_Specification&&);
	Unary_Filter_Specification& operator=(const Unary_Filter_Specification&) = delete;
	Unary_Filter_Specification& operator=(Unary_Filter_Specification&&) = delete;



	Unary_Filter_Specification* get_copy()const override = 0;
	
	Unary_Filter_Specification* move_copy()override = 0;
protected:
	
	Filter_Specification& base_specification(){
		assert(M_base_specification);
		return *M_base_specification;
	}
	
	const Filter_Specification& base_specification()const{
		assert(M_base_specification);
		return *M_base_specification;
	}
private:
	Filter_Specification* M_base_specification;
};

}

#endif //UNARY_FILTER_SPECIFICATION_H


