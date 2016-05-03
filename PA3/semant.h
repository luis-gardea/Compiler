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
  void install_tree();
  void install_basic_classes();
  ostream& error_stream;
  std::map<Symbol, Class_> class_table;
  ClassTree* = classtree;

public:
  ClassTable(Classes);
  int errors() { return semant_errors; }
  Class_ get_parent_class(Symbol class_) { return class_table[class_]; }
  ostream& semant_error();
  ostream& semant_error(Class_ c);
  ostream& semant_error(Symbol filename, tree_node *t);
};

class ClassTree {
private:
	Class_ root;

public:
	ClassTree();
	void add_root(Class_ Object) { root = Object; }
	void add_node(Class_ name, Class_ parent);
	bool check_for_cycles();
};

#endif

