#include "Custom_Routine_Symbol.h"
//
#include "Specific_Symbol_List.h"
//
#include "J_Symbol_Scope.h"
//
#include "Type_Routine.h"
//
#include "j_declaration.h"
//
#include "Arguments.h"
//
#include <algorithm>
//
#include "J_Symbol_Error.h"
//
#include "Statement_Block.h"
using std::transform;
using std::string;


//
#include <J_String.h>
namespace jomike{


static Type_Syntax_List* make_type_syntax_list(const Declaration_List& irk_list){
	auto syntax_list = new Type_Syntax_List;
	for(auto declaration : irk_list){
		syntax_list->add_symbol(declaration->type_syntax());
	}
	return syntax_list;
}


Custom_Routine_Symbol::Custom_Routine_Symbol(
	J_Symbol_Identifier* i_identifier, const Declaration_List& irk_static_declarations
	, const Declaration_List& irk_arg_declarations, Type_Syntax* i_return_type
	, Statement_Block* i_statement_list)
:j_routine_symbol(i_identifier, new Type_Routine(i_return_type, make_type_syntax_list(irk_arg_declarations))){
	M_statement_block = i_statement_list;
	M_running_scope = new J_Symbol_Scope(irk_static_declarations);

	M_running_scope->set_parent_scope(&symbol_scope());
	transform(irk_arg_declarations.begin(), irk_arg_declarations.end()
			 , back_inserter(M_arg_names), [](const j_declaration* y_decl){return y_decl->name(); });
}

Custom_Routine_Symbol::Custom_Routine_Symbol(const Custom_Routine_Symbol& irk_right)
:j_routine_symbol(irk_right), M_arg_names(irk_right.M_arg_names)
, M_statement_block(irk_right.M_statement_block->get_copy())
, M_running_scope(irk_right.M_running_scope->get_copy()){

}

Custom_Routine_Symbol::Custom_Routine_Symbol(Custom_Routine_Symbol&& irv_right)
:j_routine_symbol(std::move(irv_right)), M_arg_names(std::move(irv_right.M_arg_names))
, M_statement_block(irv_right.M_statement_block->move_copy())
, M_running_scope(irv_right.M_running_scope->move_copy()){

}

Custom_Routine_Symbol::~Custom_Routine_Symbol(){
	delete M_statement_block;
	delete M_running_scope;
}

Custom_Routine_Symbol* Custom_Routine_Symbol::move_copy(){
	return  new Custom_Routine_Symbol(std::move(*this));
}

Custom_Routine_Symbol* Custom_Routine_Symbol::get_copy()const{
	return new Custom_Routine_Symbol(*this);
}

j_value Custom_Routine_Symbol::derived_get_value(const Arguments& irk_args)const {
	if(irk_args.size() != M_arg_names.size()){
		throw J_Symbol_Error(
			"Improper number of Args to function: " + name()
			+ " expected: " + to_string(M_arg_names.size()) + " args. Given: " + to_string(irk_args.size()));
	}

	J_Symbol_Scope_Unique_t running_scope(make_new_running_scope(irk_args));
		


	M_statement_block->set_symbol_scope(running_scope.get());

	j_value return_val;

	try{
		M_statement_block->process(empty_arguments());
	} catch(J_Routine_Transfer_Exception& e){
		return_val = e.value();
	}

	if(return_type_syntax().is_void()){
		return j_value::void_type();
	}

	if(j_value::Value_Types::UNDEFINIED == return_val.type()){
		throw J_Symbol_Error("Function Did Not Return A Value");
	}
	return return_val;

}

string Custom_Routine_Symbol::derived_get_wrangler_str_val(const Arguments& irk_args) {
	if(irk_args.size() != M_arg_names.size()){
		throw J_Symbol_Error(
			"Improper number of Args to function: " + name()
			+ " expected: " + to_string(M_arg_names.size()) + " args. Given: " + to_string(irk_args.size()));
	}

	J_Symbol_Scope_Unique_t running_scope(make_new_running_scope(irk_args));



	M_statement_block->set_symbol_scope(running_scope.get());


	string wrangler_str;
	string return_val_str;
	try{
		for(auto f_statement : M_statement_block->symbol_list()){
			wrangler_str += f_statement->get_wrangler_str_val(empty_arguments());
		}
	} catch(J_Routine_Transfer_Exception& e){
		return_val_str = e.value().as_string();
	}


	return wrangler_str + " ~~ " + return_val_str;

	
}

void Custom_Routine_Symbol::alert_symbol_scope_set(){
	M_statement_block->set_symbol_scope(&symbol_scope());
}

J_Symbol_Scope* Custom_Routine_Symbol::make_new_running_scope(const Arguments& irk_args)const{
	J_Symbol_Scope* running_scope = new J_Symbol_Scope(M_running_scope);

	for(int i = 0; i < irk_args.size(); ++i){
		j_symbol_unique_t arg_symbol(irk_args[i].make_non_referenced());
		arg_symbol->set_name(M_arg_names[i]);
		if(arg_symbol->return_type_syntax() != argument_types_list()[i]){

			//arg_symbol = j_symbol_unique_t(arg_symbol->convert_to_type(argument_types_list()[i]));

		}

		running_scope->add_symbol(arg_symbol.release());

	}
	return running_scope;
}

void Custom_Routine_Symbol::process(const Arguments& /*irk_args*/){

}


const j_value& J_Routine_Transfer_Exception::value()const{
	return M_value;
}

J_Routine_Transfer_Exception::J_Routine_Transfer_Exception(j_value i_value): M_value(i_value){

}

}



