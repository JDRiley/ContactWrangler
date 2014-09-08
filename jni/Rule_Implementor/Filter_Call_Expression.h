#ifndef FILTER_CALL_EXPRESSION_H
#define FILTER_CALL_EXPRESSION_H

#include "Call_Expression.h"


namespace jomike{
class Filter_Call_Expression : public Call_Expression{
public:
	Filter_Call_Expression(J_Symbol_Identifier* i_identifier, Arguments* i_args_list);

	Filter_Call_Expression* get_copy()const override;
	
	Filter_Call_Expression* move_copy()override;
private:
};

}

#endif //FILTER_CALL_EXPRESSION_H


