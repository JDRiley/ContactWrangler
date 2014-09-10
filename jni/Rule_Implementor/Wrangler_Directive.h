#ifndef WRAGNLER_DIRECTIVE_H
#define WRAGNLER_DIRECTIVE_H

#include "j_expression.h"


namespace jomike{
class Wrangler_Directive : public j_expression{
public:
	Wrangler_Directive(J_Symbol_Identifier* i_identifier, Arguments* i_args);

	//Deleting Constructors and Assignment Operators
	Wrangler_Directive(const Wrangler_Directive& irk_src);
	Wrangler_Directive(Wrangler_Directive&& irv_src);
	Wrangler_Directive& operator=(const Wrangler_Directive&) = delete;
	Wrangler_Directive& operator=(Wrangler_Directive&&) = delete;

	Wrangler_Directive* get_copy()const override;
	
	Wrangler_Directive* move_copy()override;

	bool has_value()const override;

	~Wrangler_Directive();

	void process(const Arguments& /* = empty_arguments() */)override;
private:

	Arguments* M_args_list;
	j_value derived_get_value(const Arguments& i_args)const override;
	std::string derived_get_wrangler_str_val(const Arguments& irk_args)override;

	void alert_symbol_scope_set()override;
};

}

#endif //WRAGNLER_DIRECTIVE_H


