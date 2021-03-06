#ifndef CONSTANT_SYMBOL_FACTORY_H
#define CONSTANT_SYMBOL_FACTORY_H

#include "Rule_Implementor_Fwd_Decl.h"
//
#include <string>
//
#include "location.hh"

namespace jomike{
	
Constant_Symbol* make_bool_constant_symbol(bool i_val, const yy::location& i_loc);

Constant_Symbol* make_int_constant_symbol(int i_val, const yy::location& i_loc);

Constant_Symbol* make_double_constant_symbol(j_dbl i_val, const yy::location& i_loc);

String_Constant_Symbol* make_string_constant_symbol(
	const std::string& irk_string, const yy::location& i_loc);
}

#endif //CONSTANT_SYMBOL_FACTORY_H


