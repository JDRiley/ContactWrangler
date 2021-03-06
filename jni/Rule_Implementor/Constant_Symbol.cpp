#include "Constant_Symbol.h"

//
#include "j_value.h"
//
#include "Arguments.h"
//
#include "Type_Syntax.h"
//
#include "J_Symbol_Error.h"

//
#include "Type_Factory.h"
using std::string;

namespace jomike{

Constant_Symbol::Constant_Symbol(
	Symbol_Types i_symbol_type, const yy::location& /*i_loc*/):j_expression(i_symbol_type){
	set_type_syntax(make_type_syntax(i_symbol_type));
}

std::string Constant_Symbol::derived_get_wrangler_str_val(const Arguments& /*irk_args*/){
	return "";
}

void Constant_Symbol::alert_symbol_scope_set(){

}

void Constant_Symbol::process(const Arguments& /* = empty_arguments() */){

}




jomike::j_value Int_Constant_Symbol::derived_get_value(const Arguments& i_args)const {
	assert(i_args.empty());
	(void)i_args;
	return j_value(safe_long_long_cast(M_value), M_unit);
}

bool Int_Constant_Symbol::has_value()const {
	return true;
}

void Int_Constant_Symbol::clear(){
	M_value = 0;
}

Int_Constant_Symbol* Int_Constant_Symbol::move_copy(){
	return  new Int_Constant_Symbol(std::move(*this));
}

Int_Constant_Symbol* Int_Constant_Symbol::get_copy()const {
	return new Int_Constant_Symbol(*this);
}

Int_Constant_Symbol::Int_Constant_Symbol(int i_val, const yy::location& i_loc)
	:Constant_Symbol(Symbol_Types::INT, i_loc){
	M_value = i_val;
}

string Int_Constant_Symbol::get_display_name(){
	return derived_get_value(Arguments()).to_str();
}

j_symbol* Int_Constant_Symbol::convert_to_type(const Type_Syntax& irk_type)const {
	switch(irk_type.symbol_type()){
	case Symbol_Types::DOUBLE:{
		auto dbl_symbol = new Dbl_Constant_Symbol(static_cast<j_dbl>(M_value), yy::location());
		dbl_symbol->set_name(name());
		return dbl_symbol;
	}
	default:
		throw J_Symbol_Error("Cannot Convert Int Constant to Type: " + irk_type.type_name() + " implicitly.");
	}
}




Bool_Constant_Symbol::Bool_Constant_Symbol(bool i_val, const yy::location& i_loc)
:Constant_Symbol(Symbol_Types::BOOL, i_loc){
	M_value = i_val;
}





jomike::j_value Bool_Constant_Symbol::derived_get_value(const Arguments& i_args)const {
	assert(i_args.empty());
	(void)i_args;
	return j_value(M_value, M_unit);
}

bool Bool_Constant_Symbol::has_value()const {
	return true;
}

void Bool_Constant_Symbol::clear(){
	M_value = false;
}

Bool_Constant_Symbol* Bool_Constant_Symbol::move_copy(){
	return  new Bool_Constant_Symbol(std::move(*this));
}

Bool_Constant_Symbol* Bool_Constant_Symbol::get_copy()const {
	return new Bool_Constant_Symbol(*this);
}

string Bool_Constant_Symbol::get_display_name(){
	return derived_get_value(Arguments()).to_str();
}


jomike::j_value Dbl_Constant_Symbol::derived_get_value(const Arguments& i_args)const {
	assert(i_args.empty());
	(void)i_args;
	return j_value(M_value, M_unit);
}

bool Dbl_Constant_Symbol::has_value()const {
	return true;
}

void Dbl_Constant_Symbol::clear(){
	M_value = 0.0;
}

Dbl_Constant_Symbol* Dbl_Constant_Symbol::move_copy(){
	return  new Dbl_Constant_Symbol(std::move(*this));
}

Dbl_Constant_Symbol* Dbl_Constant_Symbol::get_copy()const {
	return new Dbl_Constant_Symbol(*this);
}

Dbl_Constant_Symbol::Dbl_Constant_Symbol(j_dbl i_val, const yy::location& i_loc)
	:Constant_Symbol(Symbol_Types::DOUBLE, i_loc){
	M_value = i_val;
}

string Dbl_Constant_Symbol::get_display_name(){
	return get_value().to_str();
}


j_value String_Constant_Symbol::derived_get_value(const Arguments& i_args)const {
	assert(i_args.empty());
	(void)i_args;
	return j_value(M_value, M_unit);
}

bool String_Constant_Symbol::has_value()const {
	return true;
}

void String_Constant_Symbol::clear(){
	M_value.clear();
}

String_Constant_Symbol* String_Constant_Symbol::move_copy(){
	return  new String_Constant_Symbol(std::move(*this));
}

String_Constant_Symbol* String_Constant_Symbol::get_copy()const {
	return new String_Constant_Symbol(*this);
}

String_Constant_Symbol::String_Constant_Symbol(
	const std::string& irk_val, const yy::location& i_loc)
	:Constant_Symbol(Symbol_Types::STRING, i_loc){
	M_value = irk_val;
}

string String_Constant_Symbol::get_display_name(){
	assert(M_value == derived_get_value(Arguments()).to_str());
	return M_value;
}

const std::string& String_Constant_Symbol::str()const{
	return M_value;
}

}


