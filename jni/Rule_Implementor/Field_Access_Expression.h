#ifndef FIELD_ACCESS_EXPRESSION_H
#define FIELD_ACCESS_EXPRESSION_H

#include "j_expression.h"


namespace jomike{
class Field_Access_Expression : public j_expression{
public:
	Field_Access_Expression(
		J_Symbol_Identifier* i_name, j_expression* i_base_expression = nullptr);


	Field_Access_Expression(const Field_Access_Expression& irk_source);
	Field_Access_Expression(Field_Access_Expression&& irv_right);
	Field_Access_Expression* get_copy()const override;

	Field_Access_Expression* move_copy()override;

	void set_value(j_value i_value)override;

	std::string get_display_name()override;

	bool has_value()const;

	j_expression* make_non_referenced()const override;

	~Field_Access_Expression();

	void process(const Arguments& irk_args)override;
private:

	j_expression* M_base_expression;
	j_value derived_get_value(const Arguments& i_args)const override;

	void alert_symbol_scope_set()override;
	
	std::string derived_get_wrangler_str_val(const Arguments& /*irk_args*/)override;
};

}

#endif //FIELD_ACCESS_EXPRESSION_H


