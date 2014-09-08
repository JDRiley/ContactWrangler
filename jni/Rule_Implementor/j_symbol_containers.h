#ifndef J_SYMBOL_ARRAY_H
#define J_SYMBOL_ARRAY_H

#include "Rule_Implementor_Fwd_Decl.h"
//
#include <ex_array.h>
//
#include <map>
//
#include <string>
//
#include <j_tree.h>

namespace jomike{



class j_symbol_allocator{
public:
	j_symbol** allocate(j_size_t);
	void deallocate(j_symbol**, ptrdiff_t);
	void construct(j_symbol** p, j_symbol*);
	void destroy(j_symbol**);
};


typedef j_tree<j_symbol*, std::string
	, std::less<j_symbol*>, j_symbol_allocator> j_symbol_tree;

typedef ex_array<j_symbol*, j_symbol_allocator> j_symbol_array;

typedef std::map<std::string, j_symbol*
	, std::less<std::string>, j_symbol_allocator> j_symbol_map;

}
#endif //J_SYMBOL_ARRAY_H

