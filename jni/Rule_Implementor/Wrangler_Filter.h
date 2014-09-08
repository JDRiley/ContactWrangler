#ifndef WRANGLER_FILTER_H
#define WRANGLER_FILTER_H

#include "Filter_Specification.h"


namespace jomike{
class Wrangler_Filter : public Filter_Specification{
public:
	Wrangler_Filter(
		J_Symbol_Identifier* i_dentifier, Filter_Specification* i_specification);

	//Deleting Constructors and Assignment Operators
	Wrangler_Filter(const Wrangler_Filter& irk_source);
	Wrangler_Filter(Wrangler_Filter&&);
	Wrangler_Filter& operator=(const Wrangler_Filter&) = delete;
	Wrangler_Filter& operator=(Wrangler_Filter&&) = delete;

	Wrangler_Filter* get_copy()const override;

	Wrangler_Filter* move_copy()override;

	const std::string& name()const;

	~Wrangler_Filter();
private:

	J_Symbol_Identifier* M_identifier;
	Filter_Specification* M_specification;
};

}

#endif //WRANGLER_FILTER_H


