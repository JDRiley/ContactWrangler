#ifndef N_ARY_FUNCTION_SYMBOL_H
#define N_ARY_FUNCTION_SYMBOL_H

#include "j_routine_symbol.h"
//
#include <string>
//
#include <functional>
//
#include "J_Symbol_Error.h"
//
#include "J_Symbol_Identifier.h"
//
#include "Arguments.h"
//
#include "Type_Factory.h"
//
#include "Type_Routine.h"
//
#include <tuple>
namespace jomike{



template<typename Num_t, Num_t... M_nums>
class integer_sequence; 


//This is essentially a j_routine_symbol wrapper around std::function. It allows you to give any callable 
//object to the constructor that corresponds to the signiture Ret_t(Args_t...) and have get_value(args)
//called and automatically converts the j_values to the appropriate types through templates.
template<typename Ret_t, typename... Args_t>
class N_Ary_Function_Symbol : public j_routine_symbol{
public:
	template<typename Func_t>
	N_Ary_Function_Symbol(Func_t i_function, const std::string& irk_string);

	N_Ary_Function_Symbol* move_copy()override{
		return  new N_Ary_Function_Symbol(std::move(*this));
	}

	N_Ary_Function_Symbol* get_copy()const override{
		return new N_Ary_Function_Symbol(*this);
	}


	void process(const Arguments& /* = empty_arguments() */)override{

	}

private:
	std::function<Ret_t(Args_t...)> M_function;
	std::string M_name;

	void alert_symbol_scope_set()override{}
	std::string derived_get_wrangler_str_val(const Arguments& /*irk_args*/)override{ return ""; }

	//template<typename Last_Arg>
	//void make_arg_list_helper(Type_Syntax_List* i_type_list){
	//	i_type_list->add_symbol(make_type_syntax(CPP_To_Symbol_Type<Last_Arg>::type()));
	//}
	
	template<typename Last_Arg_t>
	void make_arg_list_helper(Type_Syntax_List* i_type_list){
		i_type_list->add_symbol(make_type_syntax(CPP_To_Symbol_Type<Last_Arg_t>::type()));
	}

	template<typename Cur_Arg_t, typename... Remaining_Args_t>
	typename std::enable_if<0 != sizeof...(Remaining_Args_t), void>::type
		make_arg_list_helper(Type_Syntax_List* i_type_list){
		i_type_list->add_symbol(make_type_syntax(CPP_To_Symbol_Type<Cur_Arg_t>::type()));
		make_arg_list_helper<Remaining_Args_t...>(i_type_list);
	}

	Type_Syntax_List* make_arg_list(){
		Type_Syntax_List* type_list = new Type_Syntax_List;
		
		make_arg_list_helper<Args_t...>(type_list);
		return type_list;
	}

	typedef std::tuple<Args_t...> Args_Tuple_t;



	j_value derived_get_value(const Arguments& i_args)const override;

	template<int T_index = 0>
	typename std::enable_if < static_cast<bool>(T_index < sizeof...(Args_t)), void>::type
		set_tuple_helper(std::tuple<Args_t...>* i_arg_tuple, const Arguments& irk_args)const{
		i_arg_tuple->get<T_index>() = irk_args[T_index].get_value()
			.as_type<typename std::tuple_element<T_index, std::tuple<Args_t...>>::type>();

		set_tuple<T_index + 1, Args_t...>(i_arg_tuple, irk_args);
	}

	//template<int T_index = 0>
	//typename std::enable_if < T_index == sizeof...(Args_t), void>::type
	//	set_tuple_helper(std::tuple<Args_t...>* i_arg_tuple, const Arguments& irk_args)const{
	//	i_arg_tuple->get<T_index>() = irk_args[T_index].get_value()
	//		.as_type<typename std::tuple_element<T_index, std::tuple<Args_t...>>::type>();

	//	
	//}

	template<j_size_t... Indicis>
	j_value get_value_helper(const Arguments& irk_args, integer_sequence<j_size_t, Indicis...>)const;

	void
		set_tuple(std::tuple<Args_t...>* i_arg_tuple, const Arguments& irk_args)const{
			set_tuple_helper(i_arg_tuple, irk_args);
	}



};







template<typename Ret_t, typename... Args_t>
template<typename Func_t>
N_Ary_Function_Symbol<Ret_t, Args_t...>::N_Ary_Function_Symbol(
	Func_t i_function, const std::string& irk_name)
	:j_routine_symbol(new J_Symbol_Identifier(irk_name)
	, new Type_Routine(
	make_type_syntax(CPP_To_Symbol_Type<Ret_t>::type())
	,make_arg_list()))
	, M_function(i_function), M_name(irk_name){
	
	set_args(Arguments(sizeof...(Args_t)));
}

template<typename Iter_t>
class self_incrementing_iter{
public:
	self_incrementing_iter(Iter_t i_iter):M_iter(i_iter){}

	typedef typename Iter_t::pointer pointer;
	typedef typename Iter_t::reference reference;

	reference operator*(){
		return *M_iter++;
	}
	
	pointer operator->(){

		return M_iter++operator->();
	}

private:
	Iter_t M_iter;
};

template<typename Num_t, Num_t... M_nums>
class integer_sequence{};

//Helper classes for making integer sequences until Visual studio adds the integer sequence to the 
//stl
template<typename Num_t, Num_t Cur_Index
	, Num_t M_size, bool finished,  Num_t... M_nums>
struct make_sequence_helper;

//Partial Specialization for when M_size != Cur_Index and we are still adding indicis
template<typename Num_t, Num_t Cur_Index
	, Num_t M_size, Num_t... M_nums>
struct make_sequence_helper<Num_t, Cur_Index, M_size, false, M_nums...>{
	typedef typename make_sequence_helper<
		Num_t, Cur_Index + 1, M_size, (Cur_Index + 1) == M_size,  M_nums..., Cur_Index>::type type;
};

//Partial Specialization for when M_size == Cur_Index
template<typename Num_t, Num_t Cur_Index
	, Num_t M_size,Num_t...  M_nums>
struct make_sequence_helper<Num_t, Cur_Index, M_size, true, M_nums...>{
	typedef integer_sequence<Num_t, M_nums...> type;
};

template<typename Num_t, Num_t Size>
struct make_integer_sequence{
	typedef typename make_sequence_helper<j_size_t, 0, Size, 0 == Size>::type type;
};

template<typename Ret_t, typename... Args_t>
j_value N_Ary_Function_Symbol<Ret_t, Args_t...>
	::derived_get_value(const Arguments& i_args)const {
	if( arguments().size()!= i_args.size()){
		throw J_Sym_Argument_Error("Incorrect Number of Arguments to: " + name());
	}
	return get_value_helper(i_args, typename make_integer_sequence<j_size_t, sizeof...(Args_t) >::type{});
	
}
template<typename Ret_t, typename... Args_t>
template<j_size_t... Indicis>
j_value N_Ary_Function_Symbol<Ret_t, Args_t...>::get_value_helper(const Arguments& irk_args, integer_sequence<j_size_t, Indicis...>)const{
	//For Debugging purposes. to see the values
	/*std::tuple<Args_t...> tuple(irk_args[Indicis].get_value()
								.as_type<std::tuple_element<Indicis, std::tuple<Args_t...>>::type>()...);
	*/
	return j_value(M_function(
		//this next line is being parameter pack expanded over the integer_equence Indicis
		//We get the Indicis by template matching the unamed integer sequence argument
		irk_args[Indicis].get_value().as_type<std::tuple_element<Indicis, std::tuple<Args_t...>>::type>()...
		)
		, J_Unit());
}






}

#endif //N_ARY_FUNCTION_SYMBOL_H


