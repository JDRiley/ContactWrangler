#include "j_routine_symbol.h"
//
#include "J_Symbol_Error.h"
//
#include "Type_Routine.h"
//
#include <functional>


using std::function;
using std::bind; using std::for_each;
using std::string;

namespace jomike{

j_routine_symbol::j_routine_symbol(
	J_Symbol_Identifier* i_identifier, Type_Routine* i_routine_type) 
	: j_declaration(i_routine_type, i_identifier){

}

const Type_Syntax_List& j_routine_symbol::argument_types_list()const{
	
	return routine_type_syntax().argument_types_list();
}

bool j_routine_symbol::has_value()const {
	return false;
}

void j_routine_symbol::clear(){

}

const Type_Syntax& j_routine_symbol::return_type_syntax()const {
	return routine_type_syntax().return_type();
}

const Type_Routine& j_routine_symbol::routine_type_syntax()const{
	auto routine_type
		= dynamic_cast<Type_Routine*>(&type_syntax());
	assert(routine_type);
	return *routine_type;
}

string j_routine_symbol::get_display_name(){
	string return_string =  "Routine: " + name() + routine_type_syntax().arg_type_string()
	+"->" + return_type_syntax().type_name();

	
	return return_string;
}




}



