#ifndef SYSTEM_CALL_EXPRESSION_H
#define SYSTEM_CALL_EXPRESSION_H

#include "Call_Expression.h"

namespace jomike{
class System_Call_Expression : public Call_Expression{
public:
	System_Call_Expression(J_Symbol_Identifier* i_identifier, Arguments* i_args_list);

	System_Call_Expression* get_copy()const override;
	
	System_Call_Expression* move_copy()override;
private:
};

}

#endif //SYSTEM_CALL_EXPRESSION_H


