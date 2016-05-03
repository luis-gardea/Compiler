#ifndef SEMANT_H_
#define SEMANT_H_

#include <stdlib.h>
#include <map>
#include <vector>
#include <assert.h>
#include <iostream>  
#include "cool-tree.h"
#include "stringtab.h"
#include "symtab.h"
#include "list.h"

#define TRUE 1
#define FALSE 0

class ClassTable;
class ClassTree;
typedef ClassTable *ClassTableP;
typedef struct Node{
  Symbol name;
  Node* parent;
  std::vector<Node *> children;

  Node(Symbol n) {
    name = n;
  }
} Node;

std::map<Symbol, Class_> class_table;

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
  ClassTree* classtree;
  

public:
  ClassTable(Classes);
  int errors() { return semant_errors; }
  Symbol get_parent_symbol(Symbol child) { 
    Symbol parent = class_table[child]->get_parent(); 
    // If not found in class_table, then parent is not defined. Return NULL.
    if (class_table.find(parent) == class_table.end()) return NULL;
    return parent;
  }
  ostream& semant_error();
  ostream& semant_error(Class_ c);
  ostream& semant_error(Symbol filename, tree_node *t);
};

class ClassTree {
private:
	Node* root;
  std::map<Symbol, Node*> added_to_tree; 

public:
	ClassTree();
	void add_root(Symbol object) { root = new Node(object); }
	void add_node(Symbol name, Symbol parent);
	void check_for_cycles();
};



#endif

