#include "Type_Aggregate.h"
//
#include "Specific_Symbol_List.h"

namespace jomike{



Type_Aggregate::Type_Aggregate(Type_Syntax_List* i_types_list)
	: Type_Syntax("Aggregate", Symbol_Types::AGGREGATE){
	M_types = i_types_list;
}

Type_Aggregate::Type_Aggregate(const Type_Aggregate& irk_src)
:Type_Syntax(irk_src){
	M_types = irk_src.M_types->get_copy();
}

Type_Aggregate::Type_Aggregate(Type_Aggregate&& irv_src)
	:Type_Syntax(std::move(irv_src)){
	M_types = irv_src.M_types->move_copy();
}

Type_Aggregate* Type_Aggregate::move_copy(){
	return  new Type_Aggregate(std::move(*this));
}

Type_Aggregate* Type_Aggregate::get_copy()const {
	return new Type_Aggregate(*this);
}



}



