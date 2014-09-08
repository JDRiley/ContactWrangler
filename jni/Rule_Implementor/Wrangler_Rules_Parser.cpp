#include "Wrangler_Rules_Parser.h"
//
#include <J_Utile.h>
//
#include "Rule_Implementor.h"
//
#include "j_symbol.h"

//Algorithm
#include <algorithm>
//
#include <functional>
//
#include <J_String.h>
//
#include <type_traits>
//
#include "Rule_Parser.h"
//
#include "J_Symbol_Error.h"
using std::bind; using std::equal_to; using std::none_of;
using namespace std::placeholders; using std::to_string;

//Containers
#include <array>
using std::string;
using std::array;



//TODO:  also put in  "place" statement . place statement and default return values
//IO
#include <iostream>
using std::cerr; using std::endl;

using std::string;


//Utilities 
#include <cassert>
namespace jomike{



static j_map<int, Rule_Implementor_Unique_t> g_rule_implementors;
static int g_rule_implemnotr_id = 0;
int generate_rule_parser(const string& irk_string){
	
	Rule_Parser parser;

	Rule_Implementor* rule_implementor = parser.parse(irk_string);

	int new_id = ++g_rule_implemnotr_id;
	assert(!g_rule_implementors.count(new_id));

	g_rule_implementors[new_id] = Rule_Implementor_Unique_t(rule_implementor);

	return new_id;
}

}