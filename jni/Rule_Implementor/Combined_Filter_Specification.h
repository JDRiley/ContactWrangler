#ifndef COMBINED_FILTER_SPECIFICATION_H
#define COMBINED_FILTER_SPECIFICATION_H

#include "Binary_Filter_Specification.h"


namespace jomike{
class Combined_Filter_Specification : public Binary_Filter_Specification{
public:
	Combined_Filter_Specification(
		Filter_Specification* i_left_filter, Filter_Specification* i_right_filter);

	Combined_Filter_Specification* get_copy()const override;
	
	Combined_Filter_Specification* move_copy()override;
private:
};

}

#endif //COMBINED_FILTER_SPECIFICATION_H


