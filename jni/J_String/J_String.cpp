#include "J_String.h"
#include <ex_array.h>

#include <j_type.h>
//
#include <J_Utile.h>
//Algorithm
#include <algorithm>

using std::find_first_of; using std::for_each;

//Containers
using std::string;

//IO Facilities

#include <fstream>


using std::ifstream;

//Utilities
#include <iterator>

using std::istreambuf_iterator;

namespace jomike{
string file_to_str(const string& irk_filename){

	
	ifstream file(irk_filename);
	assert(file);
	return string(istreambuf_iterator<char>(file), istreambuf_iterator<char>());
}



template<>
int from_string<int>(const std::string& irk_str){
	return std::stoi(irk_str);
}

template<>
j_dbl from_string<j_dbl>(const std::string& irk_str){
	return std::stod(irk_str);
}

template<>
j_llint from_string<j_llint>(const std::string& irk_str){
	return std::stoll(irk_str);
}

template<>
bool from_string<bool>(const std::string& irk_str){
	return !irk_str.empty();
}




}