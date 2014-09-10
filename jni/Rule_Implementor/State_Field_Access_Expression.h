#ifndef STATE_FIELD_ACCESS_EXPRESSION
#define STATE_FIELD_ACCESS_EXPRESSION

#include "Field_Access_Expression.h"


namespace jomike{
class State_Field_Access_Expression : public Field_Access_Expression{
public:
	
	State_Field_Access_Expression(J_Symbol_Identifier* i_identifier);
	State_Field_Access_Expression* get_copy()const override;
	
	State_Field_Access_Expression* move_copy()override;

	j_expression* make_non_referenced()const override;

	bool has_value()const;
private:
	j_value derived_get_value(const Arguments& i_args)const override;
};

}

#endif //STATE_FIELD_ACCESS_EXPRESSION


