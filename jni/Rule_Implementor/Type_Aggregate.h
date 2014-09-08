#ifndef TYPE_AGGREGATE_H
#define TYPE_AGGREGATE_H

#include "Type_Syntax.h"


namespace jomike{
class Type_Aggregate : public Type_Syntax{
public:
	Type_Aggregate(Type_Syntax_List* i_types_list);

	Type_Aggregate* get_copy()const override;
	
	Type_Aggregate* move_copy()override;

	//Deleting Constructors and Assignment Operators
	Type_Aggregate(const Type_Aggregate& irk_src);
	Type_Aggregate(Type_Aggregate&& irv_src);
	Type_Aggregate& operator=(const Type_Aggregate&) = delete;
	Type_Aggregate& operator=(Type_Aggregate&&) = delete;
private:

	Type_Syntax_List* M_types;
};

}

#endif //TYPE_AGGREGATE_H


