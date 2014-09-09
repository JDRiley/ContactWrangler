#ifndef J_CALC_PARSER_H
#define J_CALC_PARSER_H

#include "Rule_Implementor_Fwd_Decl.h"
//
#include <J_Utile.h>
//
#include <string>




namespace jomike{

j_symbol* get_symbol(const std::string& irk_string);

void add_user_symbol(j_symbol*);

//returns an int identifier to the generated rule parser
int generate_rule_parser(const std::string& irk_string);

std::string process_command(int implementation_handle, const std::string& irk_command);

}
#endif