#ifndef J_PLACEHOLDER_SYMBOL_H
#define J_PLACEHOLDER_SYMBOL_H

#include "j_expression.h"


namespace jomike{


class j_placeholder_symbol : public j_expression{
public:
	j_placeholder_symbol* get_copy()const override;

	j_placeholder_symbol* move_copy()override;
	bool has_value()const override;
	void clear()override;
	j_placeholder_symbol(j_size_t i_index);
	bool is_placeholder()const override;
	j_size_t placeholder_index()const;

	std::string get_display_name()override;

	void process(const Arguments& /*irk_args*/)override;
protected:
	j_value derived_get_value(const Arguments& i_args)const override;
private:
	j_size_t M_Placeholder_index;

	void alert_symbol_scope_set()override;
	
	std::string derived_get_wrangler_str_val(const Arguments& /*irk_args*/)override;
};

}

#endif //J_PLACEHOLDER_SYMBOL_H

