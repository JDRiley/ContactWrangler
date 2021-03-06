#ifndef VARIABLE_SYMBOL_H
#define VARIABLE_SYMBOL_H

#include "j_declaration.h"


namespace jomike{
class Variable_Symbol : public j_declaration{
public:
	Variable_Symbol(
		Type_Syntax* i_syntax, J_Symbol_Identifier* i_identifier);

	Variable_Symbol(
		Type_Syntax* i_syntax, J_Symbol_Identifier* i_identifier, const j_expression& i_expression);

	Variable_Symbol* get_copy()const override;

	Variable_Symbol* move_copy()override;

	void clear()override;

	bool has_value()const override;

	void set_value(j_value i_value)override;

	std::string get_display_name()override;

	j_expression* as_expression()override;
	void process(const Arguments& irk_args)override;
private:
	j_value derived_get_value(const Arguments& i_args)const override;
	j_value M_value;

	void alert_symbol_scope_set()override;
	
	std::string derived_get_wrangler_str_val(const Arguments& /*irk_args*/)override;
	
};

}

#endif //VARIABLE_SYMBOL_H


