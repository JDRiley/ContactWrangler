#ifndef STATE_ID_FACTORY_H
#define STATE_ID_FACTORY_H

#include "Rule_Implementor_Fwd_Decl.h"
//
#include <string>

namespace jomike{


State_ID* make_state_id(const std::string& irk_string);

}

#endif //STATE_ID_FACTORY_H


