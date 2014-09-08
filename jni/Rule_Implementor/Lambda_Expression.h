#ifndef LAMBDA_EXPRESSION_H
#define LAMBDA_EXPRESSION_H

#include "j_expression.h"


namespace jomike{
class Lambda_Expression : public j_expression{
public:
	Lambda_Expression(
		Declaration_List* i_decl_list, Statement_Block* i_statement_block);

	//Deleting Constructors and Assignment Operators
	Lambda_Expression(const Lambda_Expression& irk_src);
	Lambda_Expression(Lambda_Expression&& irv_right);
	
	Lambda_Expression& operator=(const Lambda_Expression&) = delete;
	Lambda_Expression& operator=(Lambda_Expression&&) = delete;

	Lambda_Expression* get_copy()const override;
	
	Lambda_Expression* move_copy()override;

	bool has_value()const override;
private:

	Declaration_List* M_static_declarations;
	Statement_Block* M_statement_block;

	j_value derived_get_value(const Arguments& i_args)const override;
};

}

#endif //LAMBDA_EXPRESSION_H


