#ifndef MODULO_EXPRESSION_H
#define MODULO_EXPRESSION_H

#include "Binary_Expression.h"


namespace jomike{
class Modulo_Expression : public Binary_Expression{
public:
	Modulo_Expression(
		j_expression* i_left_expr, j_expression* i_right_expr);

	Modulo_Expression* get_copy()const override;
	
	Modulo_Expression* move_copy()override;
private:
	j_value derived_get_value(const Arguments& i_args)const override;

};

}

#endif //MODULO_EXPRESSION_H


