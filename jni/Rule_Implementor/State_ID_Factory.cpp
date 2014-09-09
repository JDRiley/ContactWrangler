#include "State_ID_Factory.h"
//
#include "State_ID.h"
//
#include "J_Symbol_Identifier.h"
namespace jomike{



State_ID* make_state_id(const std::string& irk_string){
	return new State_ID(new J_Symbol_Identifier(irk_string));
}

}



