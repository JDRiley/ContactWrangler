#include <Wrangler_Rules_Parser.h>

//
#include <iostream>

using std::cerr; using std::cout; using std::endl;

//
#include <fstream>
//
#include <J_String.h>
using std::ifstream;

using namespace std;
int main(){

	string file_string(jtl::file_to_str("J:/Java Studio/AndroidMaster/ContactWrangler/default.cwr"));


	int implementor_handle = jtl::generate_rule_parser(file_string);
	(void)implementor_handle;


	cout << jtl::process_command(implementor_handle, "State: SENT :on_message_recieved(\"Hey Milly\");");


	return 0;


}