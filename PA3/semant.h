#ifndef SEMANT_H_
#define SEMANT_H_

#include <map>
#include <vector>
#include <set>
#include <assert.h>
#include <iostream>  
#include "cool-tree.h"
#include "stringtab.h"
#include "symtab.h"
#include "list.h"
#include <utility>

#define TRUE 1
#define FALSE 0

class ClassTable;
typedef ClassTable *ClassTableP;
typedef std::pair<Symbol, Symbol> Method;

void static_error_exit();

// This is a structure that may be used to contain the semantic
// information such as the inheritance graph.  You may use it or not as
// you like: it is only here to provide a container for the supplied
// methods.

class ClassTable {
private:
  int semant_errors;
  void install_basic_classes();
  ostream& error_stream;
  std::map<Symbol,Class_> class_map;
  std::map<Symbol,Symbol> child_to_parent;
  std::map<Symbol,std::vector<Symbol>> parent_to_children;
  std::map<Symbol,bool> has_cycle;
  bool CheckForCycles(Symbol child, std::set<Symbol> visited);
  void CheckInheritanceTree();

public:
  ClassTable(Classes);
  int errors() { return semant_errors; }
  ostream& semant_error();
  ostream& semant_error(Class_ c);
  ostream& semant_error(Symbol filename, tree_node *t);
  ostream& semant_error1(Symbol name, tree_node *t);
  int get_semant_errors() const { return semant_errors; }
  bool conforms(Symbol c1, Symbol c2);
  Symbol lub(Symbol c1, Symbol c2);
  std::map<Symbol,std::vector<Symbol>> get_parent_to_children() { return parent_to_children; }
  std::map<Symbol,Class_> get_class_map() { return class_map; }
  std::map<Symbol,Symbol> get_child_to_parent() { return child_to_parent; }
  bool compare(Symbol class_name, Method m, Method parent_m, tree_node *t);

};

// Method {
//   Symbol name_;
//   Symbol type_;
//   Method::Method(Symbol name, Symbol type) {
//     name_ = name;
//     type_ = type;
//   };
// };


#endif

