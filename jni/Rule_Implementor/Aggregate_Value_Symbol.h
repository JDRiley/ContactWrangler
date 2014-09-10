#ifndef AGGREGATE_VALUE_SYMBOL_H
#define AGGREGATE_VALUE_SYMBOL_H

#include "j_expression.h"


namespace jomike{
class Aggregate_Value_Symbol : public j_expression{
public:
	Aggregate_Value_Symbol(const Arguments& i_expr);

	Aggregate_Value_Symbol* get_copy()const override;
	
	Aggregate_Value_Symbol* move_copy()override;

	//Deleting Constructors and Assignment Operators
	Aggregate_Value_Symbol(const Aggregate_Value_Symbol&);
	Aggregate_Value_Symbol(Aggregate_Value_Symbol&&);
	Aggregate_Value_Symbol& operator=(const Aggregate_Value_Symbol&) = delete;
	Aggregate_Value_Symbol& operator=(Aggregate_Value_Symbol&&) = delete;

	~Aggregate_Value_Symbol();

	void process(const Arguments& irk_args)override;

	bool has_value()const;
private:
	Expression_List* M_expressions;

	j_value derived_get_value(const Arguments& i_args)const override;

	void alert_symbol_scope_set()override;
	
	std::string derived_get_wrangler_str_val(const Arguments& /*irk_args*/)override;
};

}

#endif //AGGREGATE_VALUE_SYMBOL_H


