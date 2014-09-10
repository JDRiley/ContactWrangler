#ifndef EXPRESSION_WILD_H
#define EXPRESSION_WILD_H

#include "j_expression.h"


namespace jomike{
class Void_Empty_Expression : public j_expression{
public:
	Void_Empty_Expression();


	bool has_value()const override;

	Void_Empty_Expression* get_copy()const override;
	Void_Empty_Expression* move_copy()override;
	void process(const Arguments& irk_args)override;
private:
	j_value derived_get_value(const Arguments& i_args)const override;

	void alert_symbol_scope_set()override;
	
	std::string derived_get_wrangler_str_val(const Arguments& /*irk_args*/)override;
};

}

#endif //EXPRESSION_WILD_H


