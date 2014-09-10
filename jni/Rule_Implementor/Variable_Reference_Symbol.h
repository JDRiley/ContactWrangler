#ifndef VARIABLE_REFERENCE_SYMBOL_H
#define VARIABLE_REFERENCE_SYMBOL_H

#include "j_declaration.h"


namespace jomike{
class Variable_Reference_Symbol : public j_declaration{
public:
	Variable_Reference_Symbol(
		Type_Syntax* i_syntax, J_Symbol_Identifier* i_identifier);

	Variable_Reference_Symbol(
		Type_Syntax* i_syntax, J_Symbol_Identifier* i_identifier, j_expression* i_expression);

	Variable_Reference_Symbol* move_copy()override;

	Variable_Reference_Symbol* get_copy()const override;

	std::string get_display_name()override;

	bool has_value()const override;

	void clear();

	void process(const Arguments& irk_args)override;

private:
	j_expression* M_expression = nullptr;
	j_value derived_get_value(const Arguments& i_args)const override;

	void alert_symbol_scope_set()override;
	
	std::string derived_get_wrangler_str_val(const Arguments& /*irk_args*/)override;
};

}

#endif //VARIABLE_REFERENCE_SYMBOL_H


