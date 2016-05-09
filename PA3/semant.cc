

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "semant.h"
#include "utilities.h"
#include <symtab.h>


extern int semant_debug;
extern char *curr_filename;
static SymbolTable<Symbol,Symbol> *sym_tab = new SymbolTable<Symbol, Symbol>();
static std::map<stp, std::vector<stp> > method_map;

//////////////////////////////////////////////////////////////////////
//
// Symbols
//
// For convenience, a large number of symbols are predefined here.
// These symbols include the primitive type and method names, as well
// as fixed names used by the runtime system.
//
//////////////////////////////////////////////////////////////////////
static Symbol 
    arg,
    arg2,
    Bool,
    concat,
    cool_abort,
    copy,
    Int,
    in_int,
    in_string,
    IO,
    length,
    Main,
    main_meth,
    No_class,
    No_type,
    Object,
    out_int,
    out_string,
    prim_slot,
    self,
    SELF_TYPE,
    Str,
    str_field,
    substr,
    type_name,
    val;
//
// Initializing the predefined symbols.
//
static void initialize_constants(void)
{
    arg         = idtable.add_string("arg");
    arg2        = idtable.add_string("arg2");
    Bool        = idtable.add_string("Bool");
    concat      = idtable.add_string("concat");
    cool_abort  = idtable.add_string("abort");
    copy        = idtable.add_string("copy");
    Int         = idtable.add_string("Int");
    in_int      = idtable.add_string("in_int");
    in_string   = idtable.add_string("in_string");
    IO          = idtable.add_string("IO");
    length      = idtable.add_string("length");
    Main        = idtable.add_string("Main");
    main_meth   = idtable.add_string("main");
    //   _no_class is a symbol that can't be the name of any 
    //   user-defined class.
    No_class    = idtable.add_string("_no_class");
    No_type     = idtable.add_string("_no_type");
    Object      = idtable.add_string("Object");
    out_int     = idtable.add_string("out_int");
    out_string  = idtable.add_string("out_string");
    prim_slot   = idtable.add_string("_prim_slot");
    self        = idtable.add_string("self");
    SELF_TYPE   = idtable.add_string("SELF_TYPE");
    Str         = idtable.add_string("String");
    str_field   = idtable.add_string("_str_field");
    substr      = idtable.add_string("substr");
    type_name   = idtable.add_string("type_name");
    val         = idtable.add_string("_val");
}

void static_error_exit(){
    cerr << "Compilation halted due to static semantic errors." << endl;
    exit(1);
}


ClassTable::ClassTable(Classes classes) : semant_errors(0) , error_stream(cerr) {

    /* Fill this in */

    install_basic_classes();

    // Here we are adding all of the class that are defined to a map called class_map
    // We are also adding all of the child,parent pairs to another map
    for (int i = classes->first(); classes->more(i); i = classes->next(i)){
        if (class_map.find(classes->nth(i)->get_name()) != class_map.end()){
            Symbol name = classes->nth(i)->get_name();
            if (name == Object || name == Str || name == IO || name == Int || name == Bool) {
                semant_error(classes->nth(i)) << "Redefinition of basic class " << name << "." << endl;
            } else {
                semant_error(classes->nth(i)) << "Class " << name << " was previously defined." << endl;
            }
        } else {
            class_map[classes->nth(i)->get_name()] = classes->nth(i);
            child_to_parent[classes->nth(i)->get_name()] = classes->nth(i)->get_parent();
            parent_to_children[classes->nth(i)->get_parent()].push_back(classes->nth(i)->get_name());
        }
    }

    if (semant_debug) {
        for (auto it=parent_to_children.begin(); it!=parent_to_children.end(); ++it){
            cout << it->first << endl;
            for (size_t i = 0; i < it->second.size(); i++){
                cout << "\t" << it->second[i];
            }
            cout << endl;
        }
    }   

    
    CheckInheritanceTree();

    // if (semant_debug) {
    //     cout << lub(Object, IO) << endl;
    //     cout << lub(IO, Object) << endl;
    //     cout << lub(Object, Object) << endl;
    //     cout << lub(IO, IO) << endl;
    //     cout << lub(Int, IO) << endl;
    // }
    for (int i = classes->first(); classes->more(i); i = classes->next(i)){
        for (int j = classes->first(); classes->more(j); j = classes->next(j)){
            if (semant_debug)
                cout << classes->nth(i)->get_name() << "," << classes->nth(j)->get_name() << ":" << lub(classes->nth(i)->get_name(),classes->nth(j)->get_name()) << endl;
        }
    }

}


bool ClassTable::CheckForCycles(Symbol child, std::set<Symbol> visited){
    Symbol parent = child_to_parent[child];
    // If the child is object then we reach the root of our inheritance tree, there are no cycles
    if (child == Object)
        return false;
    // If the full path of this child has been visited before, then we document if it has a cycle in its path or not, return that bool
    if (has_cycle.find(child) != has_cycle.end()){
        return has_cycle[child];
    }
    // If we have visited this child in our current path, then there is a cycle, we add this child to has_cycle and set value to true
    // We raise error and then return true
    if (visited.find(child) != visited.end()){
        has_cycle[child] = true;
        return true;
    }

    //We insert child to our current path and then call CheckForCycles on the parent
    visited.insert(child);
    bool cycle = CheckForCycles(parent,visited);
    //When cycle returns, we have visited the entire path of child so we can set has_cycle to value returned by recursive call on parent
    if (cycle) {
        semant_error(class_map[child]) << "Class " << child << ", or an ancestor of " << child << ", is involved in an inheritance cycle." << endl;
    }
    has_cycle[child] = cycle;

    return cycle;

}

void ClassTable::CheckInheritanceTree(){
    // Here we check to make sure all parent classes are defined
    for (std::map<Symbol,Symbol>::iterator it=child_to_parent.begin(); it!=child_to_parent.end(); ++it){
        // std::cout << it->first << " => " << it->second << '\n';
        if (it->first == Object)
            continue;
        if (class_map.find(it->second) == class_map.end())
            semant_error(class_map[it->first]) << "Class " << it->first << " inherits from an undefined class." << it->second << endl;
        if (it->second == Str || it->second == IO || it->second == Int || it->second == Bool) {
            semant_error(class_map[it->first]) << "Class " << it->first << " cannot inherit class " << it->second << "." << endl;
        }
    }
    if (get_semant_errors() > 0){
        static_error_exit();
    }

    // Here we are checking for cycles
    for (std::map<Symbol,Symbol>::iterator it=child_to_parent.begin(); it!=child_to_parent.end(); ++it){
        std::set<Symbol> visited;
        CheckForCycles(it->first, visited);
    }
    if (get_semant_errors() > 0){
        static_error_exit();
    }
}

// Checks if c1 <= c2, i.e. that class c1 conforms to class c2
bool ClassTable::conforms(Symbol c1, Symbol c2) {
    if (c1 == NULL || c2 == NULL) return false;
    Symbol class_ = c1;
    while (true) {
        if (class_ == c2) {
            if (semant_debug)
                cout << c1 << " conforms to " << c2 << endl;
            return true;
        } else if (class_ == Object) {
            if (semant_debug)
                cout << c1 << " does not conform to " << c2 << endl;
            break;
        }
        class_ = child_to_parent[class_];
    }
    return false;
}

// (least upper bound) 
// Finds the least common ancestor of class c1 and c2. Will always return a Symbol, as all classes have Object as common ancestor
Symbol ClassTable::lub(Symbol c1, Symbol c2) {
    if (c1 == NULL || c2 == NULL) return Object;
    std::set<Symbol> c2_ancestors;
    Symbol class_ = c2;
    while (true) {
        c2_ancestors.insert(class_);
        cout << class_ << endl;
        if (class_ == Object) break;
        class_ = child_to_parent[class_];
    }

    class_ = c1;
    while (true) {
        if (c2_ancestors.find(class_) != c2_ancestors.end()) break;
        class_ = child_to_parent[class_];
    }

    return class_;
}

void ClassTable::install_basic_classes() {

    // The tree package uses these globals to annotate the classes built below.
   // curr_lineno  = 0;
    Symbol filename = stringtable.add_string("<basic class>");
    
    // The following demonstrates how to create dummy parse trees to
    // refer to basic Cool classes.  There's no need for method
    // bodies -- these are already built into the runtime system.
    
    // IMPORTANT: The results of the following expressions are
    // stored in local variables.  You will want to do something
    // with those variables at the end of this method to make this
    // code meaningful.

    // 
    // The Object class has no parent class. Its methods are
    //        abort() : Object    aborts the program
    //        type_name() : Str   returns a string representation of class name
    //        copy() : SELF_TYPE  returns a copy of the object
    //
    // There is no need for method bodies in the basic classes---these
    // are already built in to the runtime system.

    Class_ Object_class =
	class_(Object, 
	       No_class,
	       append_Features(
			       append_Features(
					       single_Features(method(cool_abort, nil_Formals(), Object, no_expr())),
					       single_Features(method(type_name, nil_Formals(), Str, no_expr()))),
			       single_Features(method(copy, nil_Formals(), SELF_TYPE, no_expr()))),
	       filename);

    // 
    // The IO class inherits from Object. Its methods are
    //        out_string(Str) : SELF_TYPE       writes a string to the output
    //        out_int(Int) : SELF_TYPE            "    an int    "  "     "
    //        in_string() : Str                 reads a string from the input
    //        in_int() : Int                      "   an int     "  "     "
    //
    Class_ IO_class = 
	class_(IO, 
	       Object,
	       append_Features(
			       append_Features(
					       append_Features(
							       single_Features(method(out_string, single_Formals(formal(arg, Str)),
										      SELF_TYPE, no_expr())),
							       single_Features(method(out_int, single_Formals(formal(arg, Int)),
										      SELF_TYPE, no_expr()))),
					       single_Features(method(in_string, nil_Formals(), Str, no_expr()))),
			       single_Features(method(in_int, nil_Formals(), Int, no_expr()))),
	       filename);  

    //
    // The Int class has no methods and only a single attribute, the
    // "val" for the integer. 
    //
    Class_ Int_class =
	class_(Int, 
	       Object,
	       single_Features(attr(val, prim_slot, no_expr())),
	       filename);

    //
    // Bool also has only the "val" slot.
    //
    Class_ Bool_class =
	class_(Bool, Object, single_Features(attr(val, prim_slot, no_expr())),filename);

    //
    // The class Str has a number of slots and operations:
    //       val                                  the length of the string
    //       str_field                            the string itself
    //       length() : Int                       returns length of the string
    //       concat(arg: Str) : Str               performs string concatenation
    //       substr(arg: Int, arg2: Int): Str     substring selection
    //       
    Class_ Str_class =
	class_(Str, 
	       Object,
	       append_Features(
			       append_Features(
					       append_Features(
							       append_Features(
									       single_Features(attr(val, Int, no_expr())),
									       single_Features(attr(str_field, prim_slot, no_expr()))),
							       single_Features(method(length, nil_Formals(), Int, no_expr()))),
					       single_Features(method(concat, 
								      single_Formals(formal(arg, Str)),
								      Str, 
								      no_expr()))),
			       single_Features(method(substr, 
						      append_Formals(single_Formals(formal(arg, Int)), 
								     single_Formals(formal(arg2, Int))),
						      Str, 
						      no_expr()))),
	       filename);

    Class_ basic_class[] = {Object_class,IO_class,Int_class,Bool_class,Str_class};

    for (int i = 0; i < 5; i++) {
        class_map[basic_class[i]->get_name()] = basic_class[i];
        child_to_parent[basic_class[i]->get_name()] = basic_class[i]->get_parent();
    }
}

////////////////////////////////////////////////////////////////////
//
// semant_error is an overloaded function for reporting errors
// during semantic analysis.  There are three versions:
//
//    ostream& ClassTable::semant_error()                
//
//    ostream& ClassTable::semant_error(Class_ c)
//       print line number and filename for `c'
//
//    ostream& ClassTable::semant_error(Symbol filename, tree_node *t)  
//       print a line number and filename
//
///////////////////////////////////////////////////////////////////

ostream& ClassTable::semant_error(Class_ c)
{                                                             
    return semant_error(c->get_filename(),c);
}    

ostream& ClassTable::semant_error(Symbol filename, tree_node *t)
{
    error_stream << filename << ":" << t->get_line_number() << ": ";
    return semant_error();
}

ostream& ClassTable::semant_error()                  
{                                                 
    semant_errors++;                            
    return error_stream;
} 

ostream& ClassTable::semant_error1(Symbol name, tree_node *t)
{
    return semant_error(class_map[name]->get_filename(), t);
}

///////
//
///////

void program_class::recurse(ClassTable* classtable) {
    bool main_method_defined = false;
    sym_tab->enterscope();
    //Do we need to loop over all classes (ie type symbols) and add them to sym_tab before recursing?

    auto children = classtable->get_tree_map()[Object];
    for(size_t i = 0; i < children.size(); i++){
        classtable->get_class_map()[children[i]]->recurse(classtable, main_method_defined);
    }
    sym_tab->exitscope();
    if (!main_method_defined)
        classtable->semant_error() << "Class Main is not defined." << endl;

}

void class__class::recurse(ClassTable* classtable, bool& main_method_defined) {
    // Enter a new scope since we just entered a new Class. All features defined here
    // are added to this Class's scope upfront. 
    //
    // Add all method declarations to the global method_map data structure,
    // which defines the method environment for the program.
    //
    // Add all attribute declarations to the global sym_tab data structure,
    // which defines the type environment for the program.
    sym_tab->enterscope();
    Symbol feature_name;
    Symbol feature_type;
    for(int i = features->first(); features->more(i); i = features->next(i)) {
        feature_name = features->nth(i)->get_name(); 
        feature_type = features->nth(i)->get_type();
        // Do we need this next line of checking?
        //if (feature_name == NULL || feature_type == NULL) continue;

        if (features->nth(i)->get_feature_type() == "Method") {
            stp m(feature_name, feature_type);
            if (method_map.find(m) != method_map.end()) {
                classtable->semant_error1(name, features->nth(i)) << "Method " << feature_name << " is multiply defined in class." << endl;
            } else {
                    method_map[m] = std::vector<stp>();
            }
        } else {
            if(sym_tab->probe(feature_name) != NULL) {
                classtable->semant_error1(name, features->nth(i)) << "Attribute " << feature_name << " is multiply defined in class." << endl;
            } else {
                Symbol feature_type = features->nth(i)->get_type();
                if (feature_type != NULL) {
                    sym_tab->addid(feature_name, &feature_type);
                }
            }
        }   
    }

    if (name == Main) {
        main_method_defined = true;
        if (sym_tab->probe(main_meth) == NULL) {
            classtable->semant_error1(name, this) << "main method not defined in class Main." << endl;
        }
    }

    auto children = classtable->get_tree_map()[name];
    for(size_t i = 0; i < children.size(); i++){
        classtable->get_class_map()[children[i]]->recurse(classtable, main_method_defined);
    }

    for(int i = features->first(); features->more(i); i = features->next(i)) {
        features->nth(i)->recurse(classtable, name);
    }

    sym_tab->exitscope();
}

void method_class::recurse(ClassTable* classtable, Symbol class_name)
{
    sym_tab->enterscope();
    for(int i = formals->first(); formals->more(i); i = formals->next(i)) {
        stp m(name, return_type);
        stp f(formals->nth(i)->get_name(), formals->nth(i)->get_type());
        method_map[m].push_back(f);
    }

    for(int i = formals->first(); formals->more(i); i = formals->next(i))
        formals->nth(i)->recurse(classtable, class_name);

    expr->recurse(classtable, class_name);
    sym_tab->exitscope();
}

void attr_class::recurse(ClassTable* classtable, Symbol class_name)
{
    init->recurse(classtable, class_name);
    Symbol type = init->get_type();
    //Probably want to do some type cheking with this type
}

//
// formal_class::dump_with_types dumps the name and type declaration
// of a formal parameter.
//
void formal_class::recurse(ClassTable* classtable, Symbol class_name)
{
    sym_tab->addid(name, &type_decl);
    return;
}

//
// branch_class::dump_with_types dumps the name, type declaration,
// and body of any case branch.
//
void branch_class::recurse(ClassTable* classtable, Symbol class_name)
{
    return;
}

//
// assign_class::dump_with_types prints "assign" and then (indented)
// the variable being assigned, the expression, and finally the type
// of the result.  Note the call to dump_type (see above) at the
// end of the method.
//
void assign_class::recurse(ClassTable* classtable, Symbol class_name)
{
    expr->recurse(classtable, class_name);

    if (sym_tab->probe(name) == NULL) {
        classtable->semant_error1(class_name, this) << "Assignment to undeclared variable " << name << "." << endl;
        type = Object;
    } else {
        type = expr->get_type();
    }

    
    // Probably want to do some typechecking here.
    //sym_tab->addid(name, &type);
}

//
// static_dispatch_class::dump_with_types prints the expression,
// static dispatch class, function name, and actual arguments
// of any static dispatch.  
//
void static_dispatch_class::recurse(ClassTable* classtable, Symbol class_name)
{
    type = Object;
}

//
//   dispatch_class::dump_with_types is similar to 
//   static_dispatch_class::dump_with_types 
//
void dispatch_class::recurse(ClassTable* classtable, Symbol class_name)
{
    type = Object;
}

//
// cond_class::dump_with_types dumps each of the three expressions
// in the conditional and then the type of the entire expression.
//
void cond_class::recurse(ClassTable* classtable, Symbol class_name)
{   
    pred->recurse(classtable, class_name);
    Symbol pred_type = pred->get_type();
    if (pred_type != Bool) {
        classtable->semant_error1(class_name, this) << "Predicate of \'if\' does not have type Bool." << endl; 
    }

    then_exp->recurse(classtable, class_name);
    Symbol then_type = then_exp->get_type();
    
    else_exp->recurse(classtable, class_name);
    Symbol else_type = else_exp->get_type();

    type = classtable->lub(then_type,else_type);
}

//
// loop_class::dump_with_types dumps the predicate and then the
// body of the loop, and finally the type of the entire expression.
//
void loop_class::recurse(ClassTable* classtable, Symbol class_name)
{
    pred->recurse(classtable,class_name);
    Symbol pred_type = pred->get_type();
    if (pred_type != Bool) {
        classtable->semant_error1(class_name,this) << "Loop condition does not have type Bool." << endl;
    }

    body->recurse(classtable, class_name);

    type = Object;
}

//
//  typcase_class::dump_with_types dumps each branch of the
//  the Case_ one at a time.  The type of the entire expression
//  is dumped at the end.
//
void typcase_class::recurse(ClassTable* classtable, Symbol class_name)
{
   return;
}

//
//  The rest of the cases for Expression are very straightforward
//  and introduce nothing that isn't already in the code discussed
//  above.
//
void block_class::recurse(ClassTable* classtable, Symbol class_name)
{
    for (int i = body->first(); body->more(i); i = body->next(i)) {
        body->nth(i)->recurse(classtable, class_name);
        type = body->nth(i)->get_type();
    }
}

void let_class::recurse(ClassTable* classtable, Symbol class_name)
{
   return;
}

void plus_class::recurse(ClassTable* classtable, Symbol class_name)
{
    e1->recurse(classtable, class_name);
    e2->recurse(classtable, class_name);

    if (e1->get_type() != Int || e2->get_type() != Int) {
        classtable->semant_error1(class_name,this) << "Non-Int arguments: " << e1->get_type() << " + " << e2->get_type() << endl;
    }

    type = Int;
}

void sub_class::recurse(ClassTable* classtable, Symbol class_name)
{
    e1->recurse(classtable, class_name);
    e2->recurse(classtable, class_name);

    if (e1->get_type() != Int || e2->get_type() != Int) {
        classtable->semant_error1(class_name,this) << "Non-Int arguments: " << e1->get_type() << " - " << e2->get_type() << endl;
    }

    type = Int;
}

void mul_class::recurse(ClassTable* classtable, Symbol class_name)
{
    e1->recurse(classtable, class_name);
    e2->recurse(classtable, class_name);

    if (e1->get_type() != Int || e2->get_type() != Int) {
        classtable->semant_error1(class_name,this) << "Non-Int arguments: " << e1->get_type() << " * " << e2->get_type() << endl;
    }

    type = Int;
}

void divide_class::recurse(ClassTable* classtable, Symbol class_name)
{
    e1->recurse(classtable, class_name);
    e2->recurse(classtable, class_name);

    if (e1->get_type() != Int || e2->get_type() != Int) {
        classtable->semant_error1(class_name,this) << "Non-Int arguments: " << e1->get_type() << " / " << e2->get_type() << endl;
    }

    type = Int;
}

void neg_class::recurse(ClassTable* classtable, Symbol class_name)
{
    e1->recurse(classtable, class_name);

    if (e1->get_type() != Int) {
        classtable->semant_error1(class_name,this) << "Non-Int argument: " << e1->get_type() << endl;
    }

    type = Int;
}

void lt_class::recurse(ClassTable* classtable, Symbol class_name)
{
    e1->recurse(classtable, class_name);
    e2->recurse(classtable, class_name);

    if (e1->get_type() != Bool || e2->get_type() != Bool) {
        classtable->semant_error1(class_name,this) << "Non-Bool arguments: " << e1->get_type() << " < " << e2->get_type() << endl;
    }

    type = Bool;
}


void eq_class::recurse(ClassTable* classtable, Symbol class_name)
{
    e1->recurse(classtable, class_name);
    e2->recurse(classtable, class_name);

    if (e1->get_type() !=  e2->get_type()) {
        classtable->semant_error1(class_name,this) << "Non-mathcing arguments: " << e1->get_type() << " = " << e2->get_type() << endl;
    }

    type = Bool;
}

void leq_class::recurse(ClassTable* classtable, Symbol class_name)
{
    e1->recurse(classtable, class_name);
    e2->recurse(classtable, class_name);

    if (e1->get_type() != Bool || e2->get_type() != Bool) {
        classtable->semant_error1(class_name,this) << "Non-Bool arguments: " << e1->get_type() << " <= " << e2->get_type() << endl;
    }

    type = Bool;
}

void comp_class::recurse(ClassTable* classtable, Symbol class_name)
{
    e1->recurse(classtable, class_name);

    if (e1->get_type() !=  Bool) {
        classtable->semant_error1(class_name,this) << "Non-Bool argument: " << e1->get_type() << endl;
    }

    type = Bool;
}

void int_const_class::recurse(ClassTable* classtable, Symbol class_name)
{
    type = Int;
}

void bool_const_class::recurse(ClassTable* classtable, Symbol class_name)
{
    type = Bool;
}

void string_const_class::recurse(ClassTable* classtable, Symbol class_name)
{
    type = Str;
}

void new__class::recurse(ClassTable* classtable, Symbol class_name)
{
    //type check
    type = type_name;
}

void isvoid_class::recurse(ClassTable* classtable, Symbol class_name)
{
    e1->recurse(classtable, class_name);
    //do some sort of type check here with No_class ?
    type = Bool;
}

void no_expr_class::recurse(ClassTable* classtable, Symbol class_name)
{
    type = No_type;
}

void object_class::recurse(ClassTable* classtable, Symbol class_name)
{
    if (sym_tab->probe(name) == NULL) {
        classtable->semant_error1(class_name,this) << "undeclared identifier " << name << endl;
    }
    type = Object;
    //this is just place holder for now-- should get type from sym_tab
}

/*   This is the entry point to the semantic checker.

     Your checker should do the following two things:

     1) Check that the program is semantically correct
     2) Decorate the abstract syntax tree with type information
        by setting the `type' field in each Expression node.
        (see `tree.h')

     You are free to first do 1), make sure you catch all semantic
     errors. Part 2) can be done in a second stage, when you want
     to build mycoolc.
 */
void program_class::semant()
{
    initialize_constants();

    /* ClassTable constructor may do some semantic analysis */
    ClassTable *classtable = new ClassTable(classes);

    recurse(classtable);

    /* some semantic analysis code may go here */

    if (classtable->errors()) {
	   cerr << "Compilation halted due to static semantic errors." << endl;
	   exit(1);
    }
}


