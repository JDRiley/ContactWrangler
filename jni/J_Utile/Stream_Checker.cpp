#include "Stream_Checker.h"
//
#include <cstring>
//
#include <iostream>
//
#include <j_map.h>
//
#include <sstream>
using std::stringstream;
using std::istream;
using std::string;
namespace jomike{


typedef std::unique_ptr<stringstream> stringstream_unique_t;
class Stream_Manager{
public:
	
	static int make_stream(const string& irk_string){
		assert(!Ms_streams.count(Ms_stream_ids + 1));
		Ms_streams.insert(std::move(++Ms_stream_ids), stringstream_unique_t(new stringstream(irk_string)));

		return Ms_stream_ids;
	}

	static istream& get_stream(int i_stream_id){
		auto found_pos = Ms_streams.find(i_stream_id);
		assert(Ms_streams.end() != found_pos);
		return **found_pos;
	}

	static void remove_stream(int i_stream_id){
		auto found_pos = Ms_streams.find(i_stream_id);
		assert(Ms_streams.end() != found_pos);
		Ms_streams.erase(found_pos);

	}
private:
	static j_map<int, stringstream_unique_t> Ms_streams;
	static int Ms_stream_ids;
};

int Stream_Manager::Ms_stream_ids = 0;
j_map<int, std::unique_ptr<stringstream>> Stream_Manager::Ms_streams;


Stream_Checker::Stream_Checker(std::istream& ir_stream): M_stream(ir_stream){

}

Stream_Checker::Stream_Checker(const std::string& irk_string)
	: M_stream_id(Stream_Manager::make_stream(irk_string)), M_stream(Stream_Manager::get_stream(M_stream_id)){

}

void Stream_Checker::check(const std::string& irk_error_str){
	if(!M_stream){
		throw J_Stream_Error(irk_error_str);
	}
}

void Stream_Checker::consume_char(
	char i_char, const std::string& irk_error_str /*= std::string("Format Error")*/){
	char test_char;
	if(!(M_stream >> test_char)){
		throw J_Stream_Error(irk_error_str);
	}

	if(i_char != test_char){
		throw J_Stream_Error(irk_error_str);
	}
}

void Stream_Checker::getline_and_check(
	std::string* ir_string, const char ik_delim, const std::string& irk_val_name){

	std::getline(M_stream, *ir_string, ik_delim);

	check("Could Not Read " + irk_val_name);
	while(!ir_string->empty() && isspace(ir_string->back())){
		ir_string->pop_back();
	}
}

Stream_Checker::~Stream_Checker(){
	if (M_stream_id){
		Stream_Manager::remove_stream(M_stream_id);
	}
}

void Stream_Checker::skip_string(const std::string& irk_string, const std::string& irk_error){
	for (auto f_char : irk_string){
		consume_char(f_char, irk_error);
	}
}


J_Stream_Error::J_Stream_Error(const std::string& irk_error)
	:J_Error(irk_error){

}

}



