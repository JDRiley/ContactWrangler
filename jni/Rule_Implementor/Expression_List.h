#ifndef EXPRESSION_LIST_H
#define EXPRESSION_LIST_H

#include "Specific_Symbol_List.h"


namespace jomike{
class Expression_List : public Specific_Symbol_List<j_expression>{
public:
	Expression_List();
	
	
	Expression_List* get_copy()const override;

	Expression_List* move_copy()override;


	void add_expression(const j_expression& irk_declaration);
private:

};
}

#endif //EXPRESSION_LIST_H


