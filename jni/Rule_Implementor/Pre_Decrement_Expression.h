#ifndef PRE_DECREMENT_EXPRESSION_H
#define PRE_DECREMENT_EXPRESSION_H

#include "Unary_Expression.h"


namespace jomike{
class Pre_Decrement_Expression : public Unary_Expression{
public:
	Pre_Decrement_Expression(j_expression* i_expression);

	Pre_Decrement_Expression* get_copy()const override;

	Pre_Decrement_Expression* move_copy()override;

	~Pre_Decrement_Expression();
private:

	j_value derived_get_value(const Arguments& i_args)const override;
};

}

#endif //PRE_DECREMENT_EXPRESSION_H


