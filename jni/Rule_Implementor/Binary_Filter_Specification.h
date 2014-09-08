#ifndef BINARY_FILTER_SPECIFICATION_H
#define BINARY_FILTER_SPECIFICATION_H

#include "Filter_Specification.h"


namespace jomike{

class Binary_Filter_Specification : public Filter_Specification{
public:
	Binary_Filter_Specification(
		Filter_Specification* i_left_filter, Filter_Specification* i_right_filter);

	//Deleting Constructors and Assignment Operators
	Binary_Filter_Specification(const Binary_Filter_Specification& irk_src);
	Binary_Filter_Specification(Binary_Filter_Specification&& irv_src);
	Binary_Filter_Specification& operator=(const Binary_Filter_Specification&) = delete;
	Binary_Filter_Specification& operator=(Binary_Filter_Specification&&) = delete;

	Binary_Filter_Specification* get_copy()const override = 0;
	
	Binary_Filter_Specification* move_copy()override = 0;
protected:
	Filter_Specification& left_filter();

	const Filter_Specification& left_filter()const;

	Filter_Specification& right_filter();

	const Filter_Specification& right_filter()const;
private:
	Filter_Specification* M_left_filter;
	Filter_Specification* M_right_filter;
};

}

#endif //BINARY_FILTER_SPECIFICATION_H


