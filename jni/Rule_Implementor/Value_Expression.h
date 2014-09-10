#ifndef VALUE_EXPRESSION_H
#define VALUE_EXPRESSION_H

#include "j_expression.h"


namespace jomike{
class Value_Expression : public j_expression{
public:
	Value_Expression(j_value i_value);



	Value_Expression* get_copy()const override;
	Value_Expression* move_copy()override;
	bool has_value()const override;

	void process(const Arguments& /*irk_args*/)override;
private:
	j_value M_value;
	j_value derived_get_value(const Arguments& i_args)const override;

	void alert_symbol_scope_set()override;
	
	std::string derived_get_wrangler_str_val(const Arguments& /*irk_args*/)override;
};

}

#endif //VALUE_EXPRESSION_H


