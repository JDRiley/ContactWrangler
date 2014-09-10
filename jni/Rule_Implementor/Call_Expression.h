#ifndef CALL_EXPRESSION_H
#define CALL_EXPRESSION_H

#include "j_expression.h"


namespace jomike{
class Call_Expression : public j_expression{
public:

	Call_Expression(
		J_Symbol_Identifier* i_identifier, Arguments* i_args_list);


	Call_Expression(
		j_expression* irk_base_expression
		, J_Symbol_Identifier* i_identifier, Arguments* i_args_list);

	Call_Expression(
		J_Symbol_Identifier* i_identifier, State_ID* i_state_id, Arguments* i_args_list);

	Call_Expression(Call_Expression&& irv_right);

	Call_Expression* get_copy()const override{
		return new Call_Expression(*this);
	}

	Call_Expression* move_copy()override{
		return  new Call_Expression(std::move(*this));
	}

	std::string get_display_name()override{
			return name();
	}

	bool has_value()const override;

	Call_Expression(const Call_Expression& irk_source);

	const Type_Syntax& return_type_syntax()const override;

	void process(const Arguments& irk_args)override;
	~Call_Expression();
protected:
	j_symbol* get_symbol()const;
private:
	mutable j_expression* M_base_expression = nullptr;
	J_Symbol_Identifier* M_identifier;
	Arguments* M_args_list;
	State_ID* M_state_id = nullptr;

	j_value derived_get_value(const Arguments& i_args)const override;

	void alert_symbol_scope_set()override;

	std::string derived_get_wrangler_str_val(const Arguments& irk_args)override;
};

}

#endif //CALL_EXPRESSION_H


