#include "j_symbol_component_list.h"
//
#include <cassert>

namespace jomike{





j_symbol_component_list::j_symbol_component_list()
:j_symbol_component(Symbol_Types::LIST){

}

void j_symbol_component_list::add_syntax_component(const j_symbol_component& i_component){
	M_components.push_back(i_component.get_copy());
}

}



