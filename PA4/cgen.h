#include <assert.h>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <stdio.h>
#include "emit.h"
#include "cool-tree.h"
#include "symtab.h"

enum Basicness     {Basic, NotBasic};
#define TRUE 1
#define FALSE 0

class CgenClassTable;
typedef CgenClassTable *CgenClassTableP;

class CgenNode;
typedef CgenNode *CgenNodeP;

typedef std::pair<Symbol, Symbol> Method;

class CgenClassTable : public SymbolTable<Symbol,CgenNode> {
private:
   List<CgenNode> *nds;
   ostream& str;
   int stringclasstag;
   int intclasstag;
   int boolclasstag;
   int label_counter;


// The following methods emit code for
// constants and global declarations.

   void code_global_data();
   void code_global_text();
   void code_bools(int);
   void code_select_gc();
   void code_constants();

// The following creates an inheritance graph from
// a list of classes.  The graph is implemented as
// a tree of `CgenNode', and class names are placed
// in the base class symbol table.

   void install_basic_classes();
   void install_class(CgenNodeP nd);
   void install_classes(Classes cs);
   void build_inheritance_tree();
   void set_relations(CgenNodeP nd);
   void set_class_tags(CgenNodeP p, int& counter);
   void create_implementation_map(CgenNodeP p, std::vector<Method> methods);
   void create_class_map(CgenNodeP p, std::vector<Symbol> attributes);

// Helper functions to code the tables and object initializations of all methods.

   void code_protObjs(CgenNodeP p, std::vector<Feature> attributes);
   void code_class_nameTab();
   void code_class_objTab();
   void code_dispTabs(CgenNodeP p, std::vector<std::pair<Symbol, Symbol>> methods);
   void code_object_inits(CgenNodeP p, int num_inherited_attributes, CgenClassTableP table);
   void code_class_methods();

public:
   CgenClassTable(Classes, ostream& str);
   void code();
   CgenNodeP root();
   int new_label() { label_counter++; return label_counter; };
   Symbol filename;
   Symbol current_method;
   int var_count;
   std::map<Symbol, std::vector<Symbol>> disp_tables;
   std::map<Method, std::vector<Symbol>> implementation_map;
   std::map<Symbol, std::vector<Symbol>> class_map;
   std::map<Symbol, int> classTag_map;
   List<CgenNode>* get_classes() { return nds; }
   std::map<Symbol, std::vector<int>>* var_table;
   void new_env() { var_table = new std::map<Symbol, std::vector<int>>(); }

};


class CgenNode : public class__class {
private: 
   CgenNodeP parentnd;                        // Parent of class
   List<CgenNode> *children;                  // Children of class
   Basicness basic_status;                    // `Basic' if class is basic
                                              // `NotBasic' otherwise

public:
   CgenNode(Class_ c,
            Basicness bstatus,
            CgenClassTableP class_table);

   void add_child(CgenNodeP child);
   List<CgenNode> *get_children() { return children; }
   void set_parentnd(CgenNodeP p);
   CgenNodeP get_parentnd() { return parentnd; }
   Symbol get_parent_name() { return parentnd->get_name(); }
   int basic() { return (basic_status == Basic); }
   void code_protObj(ostream& s, std::vector<Feature> attributes, int classTag);
   Features get_features() { return features; }
   void code_class_nameTab(ostream& s);
   void code_class_objTab(ostream& s);
   void code_dispTab(ostream& s, std::vector<std::pair<Symbol, Symbol>> methods);
   Symbol get_name() { return name; }
   void code_object_init(ostream& s, int num_inherited_attributes, int& num_self_attributes, CgenClassTableP table);
   void code_class_method(CgenClassTableP table, ostream& s);
   Symbol get_filename() {return filename; }
   int closest_ancestor(std::vector<Symbol> types);
};

class BoolConst 
{
 private: 
  int val;
 public:
  BoolConst(int);
  void code_def(ostream&, int boolclasstag);
  void code_ref(ostream&) const;
};

