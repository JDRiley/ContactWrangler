#include "j_expression.h"

using std::string;

namespace jomike{



j_expression::j_expression(Symbol_Types i_type):j_symbol(i_type){
	
}

j_expression::j_expression(
	Symbol_Types i_symbol_type, J_Symbol_Identifier* i_identifier) 
	: j_symbol(i_identifier, i_symbol_type){

}

j_expression::j_expression(const j_expression& irk_right) : j_symbol(irk_right){

}

j_expression::j_expression(j_expression&& irv_src) : j_symbol(std::move(irv_src)){}

j_expression* j_expression::as_expression(){
	return get_copy();
}

string j_expression::get_display_name(){
	if(has_value()){
		return get_value().to_str();
	}
	return name();
}

j_expression::~j_expression(){

}

j_expression* j_expression::make_non_referenced()const {
	j_expression* new_ptr = dynamic_cast<j_expression*>(j_symbol::make_non_referenced());
	assert(new_ptr);
	return new_ptr;
}



}



