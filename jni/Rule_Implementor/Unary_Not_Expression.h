#ifndef UNARY_NOT_EXPRESSION_H
#define UNARY_NOT_EXPRESSION_H

#include "Unary_Expression.h"


namespace jomike{
class Unary_Not_Expression : public Unary_Expression{
public:
	
	Unary_Not_Expression(j_expression* i_expression);

	Unary_Not_Expression* get_copy()const override;
	
	Unary_Not_Expression* move_copy()override;

	
private:
	j_value derived_get_value(const Arguments& i_args)const override;

};

}

#endif //UNARY_NOT_EXPRESSION_H


