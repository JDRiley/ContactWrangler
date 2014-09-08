#include "Expression_List.h"
//
#include "j_expression.h"

namespace jomike{



void Expression_List::add_expression(const j_expression& irk_declaration){
	add_syntax_component(irk_declaration);
}

Expression_List* Expression_List::move_copy(){
	return  new Expression_List(std::move(*this));
}

Expression_List* Expression_List::get_copy()const {
	return new Expression_List(*this);
}

Expression_List::Expression_List(){

}

jomike::Expression_List::iterator Expression_List::end()const{
	return j_symbol_component_list::end();
}

jomike::Expression_List::iterator Expression_List::begin()const{
	return j_symbol_component_list::begin();
}

}



