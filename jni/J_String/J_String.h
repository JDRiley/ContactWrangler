#ifndef J_STRING_H
#define J_STRING_H

#include <J_Fwd_Decl.h>

//Algorithm
#include <algorithm>

//Containers

//
#include <ex_array.h>
//
#include <string>
//
#include <sstream>

#ifdef VS_STUDIO
#pragma comment(lib, "J_String" J_LIB_APPEND)
#endif



#ifdef VS_STUDIO
#define STRING_CONVERSION_FUNCTIONS_ENABLED 1
#elif _GLIBCXX_USE_C99
#define STRING_CONVERSION_FUNCTIONS_ENABLED 1
#endif


#ifndef STRING_CONVERSION_FUNCTIONS_ENABLED
#include <sstream>
#endif

namespace jomike{


typedef std::basic_string<j_ulint> LU_String;

std::string file_to_str(const std::string& irk_filename);

template<typename St>
std::string to_string(St i_val){
#if STRING_CONVERSION_FUNCTIONS_ENABLED
	return std::to_string(i_val);
#else
	std::ostringstream o_str;
	o_str << i_val;
	return o_str.str();
#endif
}

j_dbl read_double_and_advance(LU_String::const_iterator*, int);




template<typename String, typename Iter>
Iter get_word(Iter i_pos, Iter i_end, String* ik_string
	, const ex_array<typename String::value_type>& i_delims){
	
	String& dest_string = *ik_string;
	dest_string.clear();
	while(i_pos != i_end){
		if(i_pos->is_space()){
			++i_pos;
		}else{
			break;
		}
	}
	auto found_pos = std::find_first_of(i_pos, i_end, i_delims.begin(), i_delims.end());
	dest_string = String(i_pos, found_pos);
	return ++found_pos;

}



template<typename Char_t>
std::string to_std_string(const std::basic_string<Char_t>& irk_string){
	std::string new_string;
	for(auto f_char : irk_string){
		new_string.push_back(safe_char_cast(f_char));
	}
	return new_string;
}

template<typename Num_t>
std::string number_to_string(Num_t i_val, int i_decimal_places){
	std::ostringstream o_str;
	o_str.precision(i_decimal_places);
	o_str << std::fixed;
	o_str << i_val;

	return o_str.str();

}

template<typename Ret_t>
Ret_t from_string(const std::string& irk_str); 

template<>
int from_string<int>(const std::string& irk_str);

template<>
j_dbl from_string<j_dbl>(const std::string& irk_str);

template<>
j_llint from_string<j_llint>(const std::string& irk_str);

template<>
bool from_string<bool>(const std::string& irk_str);
}


#endif