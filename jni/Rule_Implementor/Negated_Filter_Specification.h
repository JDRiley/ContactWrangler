#ifndef NEGATED_FILTER_SPECIFICATION_H
#define NEGATED_FILTER_SPECIFICATION_H

#include "Unary_Filter_Specification.h"


namespace jomike{
class Negated_Filter_Specification : public Unary_Filter_Specification{
public:
	Negated_Filter_Specification(Filter_Specification* i_spec);


	Negated_Filter_Specification* get_copy()const override;
	Negated_Filter_Specification* move_copy()override;

private:

};

}

#endif //NEGATED_FILTER_SPECIFICATION_H


