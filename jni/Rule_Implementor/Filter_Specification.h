#ifndef FILTER_SPECIFICATION_H
#define FILTER_SPECIFICATION_H

#include "j_symbol_component.h"


namespace jomike{
class Filter_Specification : public j_symbol_component{
public:
	Filter_Specification();

	Filter_Specification* get_copy()const override = 0;

	Filter_Specification* move_copy()override = 0;
private:
};

}

#endif //FILTER_SPECIFICATION_H


