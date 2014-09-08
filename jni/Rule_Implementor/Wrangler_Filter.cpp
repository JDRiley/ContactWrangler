#include "Wrangler_Filter.h"
//
#include "J_Symbol_Identifier.h"

namespace jomike{



Wrangler_Filter* Wrangler_Filter::move_copy(){
	return  new Wrangler_Filter(std::move(*this));
}

Wrangler_Filter* Wrangler_Filter::get_copy()const {
	return new Wrangler_Filter(*this);
}

const std::string& Wrangler_Filter::name()const{
	assert(M_identifier);
	return M_identifier->identifier_name();
}

Wrangler_Filter::Wrangler_Filter(
	J_Symbol_Identifier* i_dentifier, Filter_Specification* i_specification){
	M_identifier = i_dentifier;
	M_specification = i_specification;

}

Wrangler_Filter::Wrangler_Filter(const Wrangler_Filter& irk_source)
	: Filter_Specification(irk_source){
	M_identifier = irk_source.M_identifier->get_copy();
	M_specification = irk_source.M_specification->get_copy();
}

Wrangler_Filter::Wrangler_Filter(Wrangler_Filter&& irv_source)
	: Filter_Specification(std::move(irv_source)){
	M_identifier = irv_source.M_identifier->move_copy();
	M_specification = irv_source.M_specification->move_copy();
}

Wrangler_Filter::~Wrangler_Filter(){
	delete M_identifier;
	delete M_specification;
}

}



