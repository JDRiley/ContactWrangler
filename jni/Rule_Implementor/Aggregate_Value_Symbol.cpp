#include "Aggregate_Value_Symbol.h"
//
#include "Expression_List.h"
//
#include "Arguments.h"
namespace jomike{



Aggregate_Value_Symbol::Aggregate_Value_Symbol(const Arguments& irk_expr)
: j_expression(Symbol_Types::AGGREGATE){
	M_expressions = new Expression_List;
	for(auto& f_symbol : irk_expr){
		M_expressions->add_expression(*f_symbol);
	}
}

Aggregate_Value_Symbol::Aggregate_Value_Symbol(const Aggregate_Value_Symbol& irk_src)
:j_expression(irk_src){
	M_expressions = irk_src.M_expressions->get_copy();
}

Aggregate_Value_Symbol::Aggregate_Value_Symbol(Aggregate_Value_Symbol&& irv_src)
:j_expression(std::move(irv_src)){
	M_expressions = irv_src.M_expressions->move_copy();
}



Aggregate_Value_Symbol* Aggregate_Value_Symbol::move_copy(){
	return  new Aggregate_Value_Symbol(std::move(*this));
}

Aggregate_Value_Symbol* Aggregate_Value_Symbol::get_copy()const {
	return new Aggregate_Value_Symbol(*this);
}

Aggregate_Value_Symbol::~Aggregate_Value_Symbol(){
	delete M_expressions;
}

bool Aggregate_Value_Symbol::has_value()const{
	for(auto f_expr : *M_expressions){
		if(!f_expr->has_value()){
			return false;
		}

	}

	return true;
}

j_value Aggregate_Value_Symbol::derived_get_value(const Arguments& /*i_args*/)const {
	return j_value(*this, J_Unit());
}

}



