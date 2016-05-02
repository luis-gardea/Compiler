#ifndef SEMANT_H_
#define SEMANT_H_

#include <assert.h>
#include <iostream>  
#include "cool-tree.h"
#include "stringtab.h"
#include "symtab.h"
#include "list.h"

#define TRUE 1
#define FALSE 0

class ClassTable;
typedef ClassTable *ClassTableP;

// This is a structure that may be used to contain the semantic
// information such as the inheritance graph.  You may use it or not as
// you like: it is only here to provide a container for the supplied
// methods.

class ClassTable {
private:
  int semant_errors;
  void install_basic_classes();
  ostream& error_stream;
  map<Symbol, Class_> class_table;

public:
  ClassTable(Classes);
  int errors() { return semant_errors; }
  ostream& semant_error();
  ostream& semant_error(Class_ c);
  ostream& semant_error(Symbol filename, tree_node *t);
};

class ClassTree {
private:
	Symbol root;
	Vector<Symbol> visited;
	map<Symbol, Class_> tree_table;

public:
	ClassTree(map<Symbol, Class_> class_table){
		tree_table = class_table;
	}
	void add_root();
	void add_node(Symbol name, Symbol* parent) {new Node();}
	Symbol* find_node(Symbol* )
	void check_for_cycle();
};

struct Node {
	Symbol name;
	Symbol* parent;
	Symbol* children;
};

#endif

