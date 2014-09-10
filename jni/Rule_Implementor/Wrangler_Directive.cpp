#include "Wrangler_Directive.h"
//
#include "Arguments.h"
//
#include "J_Symbol_Identifier.h"
using std::string;
//
#include <j_map.h>
//
#include <iostream>

//
#include <sstream>
//
#include "J_Symbol_Scope.h"
using std::ostringstream;
using std::cerr; using std::cout; using std::endl;
namespace jomike{




Wrangler_Directive::Wrangler_Directive(J_Symbol_Identifier* i_identifier, Arguments* i_args)
	:j_expression(Symbol_Types::EXPRESSION_TYPE_UNINITIALIZED, i_identifier){
	M_args_list = i_args;
	
}

Wrangler_Directive::Wrangler_Directive(const Wrangler_Directive& irk_src) : j_expression(irk_src){
	M_args_list = irk_src.M_args_list->get_copy();

}

Wrangler_Directive::Wrangler_Directive(Wrangler_Directive&& irv_src) : j_expression(std::move(irv_src)){
	M_args_list = irv_src.M_args_list->move_copy();

}
Wrangler_Directive* Wrangler_Directive::move_copy(){
	return  new Wrangler_Directive(std::move(*this));
}

Wrangler_Directive* Wrangler_Directive::get_copy()const {
	return new Wrangler_Directive(*this);
}

std::string Wrangler_Directive::derived_get_wrangler_str_val(const Arguments& irk_args){

	ostringstream o_str;

	o_str << name() << ',' << M_args_list->size() << " ";

	auto arg_pos = M_args_list->begin();
	if(M_args_list->size()){
		o_str << (*arg_pos++)->get_value(irk_args).as_string();


		while(arg_pos != M_args_list->end()){
			o_str << ", " << (*arg_pos++)->get_value(irk_args).as_string();
		}
		
	}
	o_str << ";";
	return o_str.str();
}

jomike::j_value Wrangler_Directive::derived_get_value(const Arguments& /*i_args*/)const {
	return j_value::void_type();
}

bool Wrangler_Directive::has_value()const {
	for(auto f_arg : *M_args_list){
		if(!f_arg->has_value()){
			return false;
		}
	}
	return true;
}

Wrangler_Directive::~Wrangler_Directive(){
	delete M_args_list;


}

void Wrangler_Directive::alert_symbol_scope_set(){
	for(auto f_arg : *M_args_list){
		f_arg->set_symbol_scope(&symbol_scope());
	}
}

void Wrangler_Directive::process(const Arguments& /* = empty_arguments() */){





	for(auto& f_arg : *M_args_list){
		j_expression* symbol = f_arg->make_non_referenced();
		delete f_arg;
		f_arg = symbol;
	}
}



}



