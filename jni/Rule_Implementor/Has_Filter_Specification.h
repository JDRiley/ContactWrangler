#ifndef HAS_FILTER_SPECIFICATION_H
#define HAS_FILTER_SPECIFICATION_H

#include "Filter_Specification.h"
//
#include <ex_array.h>
//
#include <string>
namespace jomike{
class Has_Filter_Specification : public Filter_Specification{
public:
	Has_Filter_Specification(const String_Constant_Symbol_List& i_symbol_list);

	Has_Filter_Specification* get_copy()const override;
	
	Has_Filter_Specification* move_copy()override;
private:
	ex_array<std::string> M_string_list;
};

}

#endif //HAS_FILTER_SPECIFICATION_H


