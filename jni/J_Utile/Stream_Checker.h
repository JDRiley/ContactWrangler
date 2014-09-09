#ifndef STREAM_CHECKER_H
#define STREAM_CHECKER_H

#include <J_Fwd_Decl.h>
//
#include <iosfwd>
//
#include <string>
//
#include <J_Error.h>
namespace jomike{
class Stream_Checker{
public:
	Stream_Checker(std::istream& ir_stream);
	Stream_Checker(const std::string& irk_string);
	void check(const std::string& irk_error_str);
	void consume_char(char i_char, const std::string& irk_str = std::string("Format Error"));
	
	template<typename St>
	void read_and_check(St* ir_val, const std::string& irk_val_name);
	
	template<typename St>
	int read_and_check(const std::string& = "");

	void getline_and_check(std::string* ir_string, const char ik_delim, const std::string& irk_val_name);
	void skip_string(const std::string& irk_string, const std::string& irk_error_str);
	~Stream_Checker();
private:
	int M_stream_id = 0;
	std::istream& M_stream;
};

class J_Stream_Error : public J_Error{
public:
	J_Stream_Error(const std::string& irk_error);
};
template<typename St>
void Stream_Checker::read_and_check(St* ir_val, const std::string& irk_val_name){
	M_stream >> *ir_val;
	check("Could Not Read " + irk_val_name);
}


template<typename St>
int Stream_Checker::read_and_check(const std::string& irk_error_string){
	St val;
	M_stream >> val;
	check("Could Not Read " + irk_error_string);
	return val;
}


}

#endif //STREAM_CHECKER_H


