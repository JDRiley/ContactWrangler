#ifndef J_SYMBOL_FWD_DECL_H
#define J_SYMBOL_FWD_DECL_H

//
#include <J_Fwd_Decl.h>

#ifdef VSTUDIO
#pragma comment(lib, "Rule_Implementor"J_LIB_APPEND)
#endif // VSTUDIO
namespace jomike{



J_FWD_DECL(Rule_Implementor)
J_FWD_DECL(J_Symbol_Scope)
J_FWD_DECL_LOWER(j_symbol)
J_FWD_DECL(Rule_Data)
J_FWD_DECL(j_symbol)
J_FWD_DECL(j_value)
J_FWD_DECL_LOWER(j_composite_symbol)
J_FWD_DECL_LOWER(j_routine_symbol)
J_FWD_DECL_LOWER(j_symbol_component)
J_FWD_DECL_LOWER(j_expression)
J_FWD_DECL(Constant_Symbol)
J_FWD_DECL(Type_Syntax)
J_STRUCT_FWD_DECL(Lexer_Location)
J_FWD_DECL_LOWER(j_declaration)
J_FWD_DECL(Value_Expression)
J_FWD_DECL(Expression_List)
J_FWD_DECL(Call_Expression)
J_FWD_DECL(J_Symbol_Identifier)
J_FWD_DECL(Arguments)
J_FWD_DECL(Type_Routine)
J_FWD_DECL(Rule_Parser)
J_FWD_DECL(Rule_Lexer)
J_FWD_DECL(Statement_Block)
J_FWD_DECL(j_statement)
J_FWD_DECL(If_Statement)
J_FWD_DECL(Custom_Routine_Symbol)
J_FWD_DECL(Wrangler_Function)
J_FWD_DECL(Aggregate_Value_Symbol)
template<typename Symbol_t>
class Specific_Symbol_List;
#define RULE_IMPLEMENTOR_FWD_DECL(m_name) J_FWD_DECL(m_name) typedef Specific_Symbol_List<m_name> m_name##_List;
RULE_IMPLEMENTOR_FWD_DECL(Wrangler_Filter)
RULE_IMPLEMENTOR_FWD_DECL(Type_Syntax)
RULE_IMPLEMENTOR_FWD_DECL(State_Declaration)
RULE_IMPLEMENTOR_FWD_DECL(State_Specification)
RULE_IMPLEMENTOR_FWD_DECL(Filter_Specification)
J_FWD_DECL(State_ID)
RULE_IMPLEMENTOR_FWD_DECL(String_Constant_Symbol)
typedef Specific_Symbol_List<j_symbol> Symbol_List;
typedef Specific_Symbol_List<j_declaration> Declaration_List;


typedef j_symbol_Shared_t J_Symbol_Shared_t;
typedef j_value_Shared_t J_Value_Shared_t;
}

#endif //J_SYMBOL_FWD_DECL_H
