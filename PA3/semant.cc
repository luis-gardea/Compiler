

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "semant.h"
#include "utilities.h"
#include <symtab.h>


extern int semant_debug;
extern char *curr_filename;

//This serves as the Object Environment
static SymbolTable<Symbol,Symbol> *sym_tab = new SymbolTable<Symbol, Symbol>();

//This serves as the method environment
static std::map<Method, std::vector<std::pair<Symbol,Symbol>>> method_map;

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

// Error helper function called when checking the inheritance graph
void static_error_exit(){
    cerr << "Compilation halted due to static semantic errors." << endl;
    exit(1);
}

//ClassTable contructor-
// Sets up the classtable and does inheritance graph semantic error checking
ClassTable::ClassTable(Classes classes) : semant_errors(0) , error_stream(cerr) {
    install_basic_classes();

    // Here we are adding all of the class that are defined to a map called class_map
    // We are also adding all of the child,parent pairs to another map
    // We also create a map from a class to all of its child classes
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

    // Here we check the inheritance tree for correctness and to check the existence of cycles
    CheckInheritanceTree();
}

//Recursively searches for any and all cycles within the inheritance graph
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

//
void ClassTable::CheckInheritanceTree(){
    // Here we check to make sure all parent classes are defined
    for (std::map<Symbol,Symbol>::iterator it=child_to_parent.begin(); it!=child_to_parent.end(); ++it){
        if (it->first == Object)
            continue;

        // Checking for a redefintion of SELF_TYPE
        if (it->first == SELF_TYPE)
            semant_error(class_map[it->first]) << "Redefinition of basic class SELF_TYPE." << endl;
        // Checking inheritance of SELF_TYPE
        else if (it->second == SELF_TYPE)
            semant_error(class_map[it->first]) << "Class " << it->first << " cannot inherit class SELF_TYPE." << endl;
        // Checking to see if parent class is defined
        else if (class_map.find(it->second) == class_map.end())
            semant_error(class_map[it->first]) << "Class " << it->first << " inherits from an undefined class " << it->second << "." << endl;
        // Checking to see if parent class is one of basic classes besides object
        else if (it->second == Str || it->second == Int || it->second == Bool) {
            semant_error(class_map[it->first]) << "Class " << it->first << " cannot inherit class " << it->second << "." << endl;
        }
    }
    // If our inheritance tree is wrong, we must exit
    if (get_semant_errors() > 0){
        static_error_exit();
    }

    // Here we are checking for cycles
    for (std::map<Symbol,Symbol>::iterator it=child_to_parent.begin(); it!=child_to_parent.end(); ++it){
        std::set<Symbol> visited;
        CheckForCycles(it->first, visited);
    }
    // If we have cycles, we must exit
    if (get_semant_errors() > 0){
        static_error_exit();
    }
}

// Checks if c1 <= c2, i.e. that class c1 conforms to class c2
bool ClassTable::conforms(Symbol c1, Symbol c2) {
    if (sym_tab->lookup(c1) == NULL || sym_tab->lookup(c2) == NULL) return false;
    if (c1 == SELF_TYPE && c2 == SELF_TYPE) return true;
    if (c1 == SELF_TYPE) {        
        // sets c1 to the class that SELF_TYPE refers to
        c1 = *(sym_tab->lookup(SELF_TYPE));
        return conforms(c1,c2);
    }
    // If c2 is SELF_TYPE but c1 isn't, automatically doesn't conform
    if (c2 == SELF_TYPE) return false;

    Symbol class_ = c1;
    // Here we climb up the tree of c1 and keep setting it to its parent
    // If c1 conforms to c2, then when traversing upwards, we will find it
    // If we reach Object first, then c1 cannot conform to c2 because it was not found
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
    // If both are SELF_TYPE, then we return SELF_TYPE
    if (c1 == SELF_TYPE && c2 == SELF_TYPE) return SELF_TYPE;
    // If either c1 or c2 are SELF_TYPE, then we replace with their class type
    if (c1 == SELF_TYPE) {
        c1 = *(sym_tab->lookup(c1));
    } else if (c2 == SELF_TYPE) {
        c2 = *(sym_tab->lookup(c2));
    } 

    std::set<Symbol> c2_ancestors;
    Symbol class_ = c2;
    // We add all ancestors of c2 to a set and then traverse the ancestors of 
    // c1, when the first ancestor of c1 is found in the set of c2, then that ancestor is the lub
    while (true) {
        c2_ancestors.insert(class_);
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
    Symbol symbols[] = {Object,  IO, Int, Bool, Str};

    // Add the basic classes to the ClassTable data structures.
    for (int i = 0; i < 5; i++) {
        class_map[basic_class[i]->get_name()] = basic_class[i];
        child_to_parent[basic_class[i]->get_name()] = basic_class[i]->get_parent();
        if (basic_class[i] == Object_class)
            parent_to_children[Object].push_back(IO);
    }

    // Initialize 3 things for the basic classes: Add attributes of Object to sym_tab, add methods to method_map, add basic types to sym_tab
    sym_tab->enterscope();
    for (int i = 0; i < 5; i++) {
        sym_tab->addid(basic_class[i]->get_name(), new Symbol(basic_class[i]->get_name()));
        if (symbols[i] == IO) continue;

        Features features = basic_class[i]->get_features();
        for(int j = features->first(); features->more(j); j = features->next(j)) {
            Symbol name = features->nth(j)->get_name();
            Symbol type = features->nth(j)->get_type();

            if (features->nth(j)->get_feature_type() == "Method") {
                Method m(symbols[i], name);
                Formals formals = features->nth(j)->get_formals();
                auto new_vec = new std::vector<std::pair<Symbol,Symbol>>();
                method_map[m] = *(new_vec);
                for(int k = formals->first(); formals->more(k); k = formals->next(k)) {
                    method_map[m].push_back(std::make_pair(formals->nth(k)->get_type(),formals->nth(k)->get_name()));
                }
                method_map[m].push_back(std::make_pair(type,type));
                // Because all other basic types inherit from object, we must add the methods of object to their method map
                if (basic_class[i] == Object_class) {
                    for(int k = 0; k < 5; k++) {
                        if (symbols[k] != Object) {
                            Method child_m(symbols[k], name);
                            method_map[child_m] = method_map[m];
                        }
                    }
                }
            } else if(basic_class[i] == Object_class) {
                sym_tab->addid(name, new Symbol(type));             
            }
        }
    }
    // Adding self and SELF_TYPE to symbol table because self always refers to SELF_TYPE
    sym_tab->addid(SELF_TYPE, new Symbol(Object));
    sym_tab->addid(self, new Symbol(SELF_TYPE));
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
// This next set of methods do an initial pass over the AST, initializing the classes defined in the program
// -This includes adding the declared types to the sym_tab
// -This includes adding all methods to the method environment
//      - makes sure that methods are inherited 
//      - Makes sure that the signatures of redefined methods are not in conflict with previous definition
///////

bool ClassTable::compare(Symbol class_name, Method m, Method parent_m, tree_node *t){
    auto formals = method_map[m];
    auto parent_formals = method_map[parent_m];

    // If number of parent args and child args don't match then raise error
    if (formals.size() != parent_formals.size()) {
        semant_error1(class_name,t) << "Incompatible number of formal parameters in redefined method " << m.second << "." << endl;
        return false;
    }
    // If the last element does not match, then return type is wrong
    if (formals.back().first != parent_formals.back().first) {
        semant_error1(class_name,t) << "In redefined method " << m.second << ", return type " << formals.back().first << " is different from original return type " << parent_formals.back().first << "." << endl;
        return false;
    }
    // If any element does not match that isnt the last, then parameter type is wrong
    for (size_t i = 0; i < formals.size(); i++){
        if (formals[i].first != parent_formals[i].first) {
            semant_error1(class_name,t) << "In redefined method " << m.second << ", parameter type " << formals[i].first << " is different from original type " << parent_formals[i].first << "." << endl;
            return false;
        }
    }

    return true;
}

// Go to the method_map and return a set of all the methods (including inherited methods) in the parent class
std::set<Symbol> class__class::get_parent_method_names(ClassTable* classtable){
    std::set<Symbol> parent_set;
    for (auto it : method_map){
        if (it.first.first == parent)
            parent_set.insert(it.first.second);
    }
    return parent_set;
}

// Add the current method to the method_map and make sure it is the same as its parent class
void method_class::check_methods(ClassTable* classtable, Symbol class_name){
    Method m(class_name, name);
    // Here we are adding the types of the arguments in a method
    for(int i = formals->first(); formals->more(i); i = formals->next(i)) {
        if (formals->nth(i)->get_type() == SELF_TYPE)
            classtable->semant_error1(class_name,this) << "Formal parameter " << formals->nth(i)->get_name() <<" cannot have type SELF_TYPE." << endl;
        if (sym_tab->lookup(formals->nth(i)->get_type()) == NULL) {
            classtable->semant_error1(class_name,this) << "Class " << formals->nth(i)->get_type() << " of formal parameter " << formals->nth(i)->get_name() << " is undefined." << endl;
        }
        method_map[m].push_back( std::make_pair(formals->nth(i)->get_type(), formals->nth(i)->get_name()) );
    }
    method_map[m].push_back( std::make_pair(return_type,return_type) );

    // Here we are checking to make sure that the method arguments and return type for a method defined
    // in a parent class matches the one of the child
    Symbol parent_name = classtable->get_child_to_parent()[class_name];
    Method parent_m(parent_name,name);
    if (method_map.find(parent_m) != method_map.end()){
        if (!classtable->compare(class_name, m, parent_m, this)) {
            method_map[m] = method_map[parent_m];
        }
    }

}

// Initialize the class (i.e. put methods and type into their repective environments)
void class__class::method_make(ClassTable *classtable, bool& main_class_defined){
    // A variable used if this class is named Main
    bool main_method_defined = false;

    // Iterate over the methods in this class, add them to the method_map, and check against their parent signature if valid
    std::set<Symbol> parent_method_names = get_parent_method_names(classtable);
    Symbol feature_name;
    for(int i = features->first(); features->more(i); i = features->next(i)) {
        feature_name = features->nth(i)->get_name(); 
        if (features->nth(i)->get_feature_type() == "Method") {
            if (name == Main && feature_name == main_meth)
                main_method_defined = true;

            // Create a key for the method_map, defined as (current_class_type, method_name)
            Method m(name, feature_name);
            if (method_map.find(m) != method_map.end()) {
                // Check if method was already defined was defined in CURRENT class, raise error 
                classtable->semant_error1(name, features->nth(i)) << "Method " << feature_name << " is multiply defined." << endl;
            } else if (parent_method_names.find(feature_name) != parent_method_names.end()) {
                // Check if method was defined in PARENT class 
                // Remove from set, add new method to map for THIS class
                auto new_vec = new std::vector<std::pair<Symbol,Symbol>>();
                method_map[m] = *(new_vec);
                features->nth(i)->check_methods(classtable, name);
                parent_method_names.erase(feature_name);
            } else {
                auto new_vec = new std::vector<std::pair<Symbol,Symbol>>();
                method_map[m] = *(new_vec);
                features->nth(i)->check_methods(classtable, name);
            }
        }
    }

    // Add the rest of the inherited methods that weren't redefined in this class to method_map as part of this class
    for (auto it = parent_method_names.begin(); it != parent_method_names.end(); it++){
        Method parent_m(parent,*it);
        Method m(name,*it);
        method_map[m] = method_map[parent_m];
    }

    // Extra book-keeping- Error handling for Main class and main method
    if (name == Main) {
        main_class_defined = true;
        if (!main_method_defined) {
            classtable->semant_error1(name, this) << "No \'main\' method in class Main." << endl;
        }
    }

    // Finally, recurse into children, adding and checking their methods and types.
    auto children = classtable->get_parent_to_children()[name];
    for(size_t i = 0; i < children.size(); i++){
        classtable->get_class_map()[children[i]]->method_make(classtable, main_class_defined);
    }
}

// We are adding all of the classes to the symbol table
void program_class::add_class_types() {
    for (int i = classes->first(); classes->more(i); i = classes->next(i)) {
        sym_tab->addid(classes->nth(i)->get_name(), new Symbol(classes->nth(i)->get_name()));
    }
}

///////
// All of the ASt traversal happens here. 
// Recurse is a member of every phyla and takes a pointer to the class table and the class which the node is part of
///////

void program_class::recurse(ClassTable* classtable) {
    bool main_class_defined = false;

    // Add the declared type to the type environment
    add_class_types();
    // First initiliaze all globals
    auto children = classtable->get_parent_to_children()[Object];
    for(size_t i = 0; i < children.size(); i++){
        classtable->get_class_map()[children[i]]->method_make(classtable, main_class_defined);
    }
    if (!main_class_defined)
        classtable->semant_error() << "Class Main is not defined." << endl;

    // sym_tab->dump();
    // for (auto it : method_map){
    //     Method m = it.first;
    //     cout << m.first << " " << m.second << endl;
    // }
    // This is the next pass of the AST, where we do all the scope and type checking. At this point, the Inheritcance graph and all global 
    // instances have been added to their respective environements.
    for(size_t i = 0; i < children.size(); i++){
        classtable->get_class_map()[children[i]]->recurse(classtable);
    }
    sym_tab->exitscope();
}

void class__class::recurse(ClassTable* classtable) {
    // Enter a new scope since we just entered a new Class. All features defined here
    // are added to this Class's scope upfront. 
    sym_tab->enterscope();

    // Push SELF_TYPE with value class_name
    sym_tab->addid(SELF_TYPE, new Symbol(name));
    
    // Add all attribute declarations to the global sym_tab data structure,
    // which defines the type environment for the program.
    Symbol feature_name;
    for(int i = features->first(); features->more(i); i = features->next(i)) {
        feature_name = features->nth(i)->get_name(); 
        if (features->nth(i)->get_feature_type() == "Attribute") {
            if(sym_tab->probe(feature_name) != NULL) {
                classtable->semant_error1(name, features->nth(i)) << "Attribute " << feature_name << " is multiply defined in class." << endl;
            } else if (feature_name != self && sym_tab->lookup(feature_name) != NULL) {
                classtable->semant_error1(name, features->nth(i)) << "Attribute " << feature_name << " is an attribute of an inherited class." << endl;
            }else {
                sym_tab->addid(feature_name, new Symbol(features->nth(i)->get_type()));
            }
        }   
    }

    // Recurse into all features to traverse the AST
    for(int i = features->first(); features->more(i); i = features->next(i)) {
        features->nth(i)->recurse(classtable, name);
    }

    // Walk down the inheritance graph, adding scope as we go down
    auto children = classtable->get_parent_to_children()[name];
    for(size_t i = 0; i < children.size(); i++){
        classtable->get_class_map()[children[i]]->recurse(classtable);
    }
    sym_tab->exitscope();
}

void method_class::recurse(ClassTable* classtable, Symbol class_name)
{
    // Enter new scope since we are introducing variables
    sym_tab->enterscope();

    // Add formal variables to scope and make sure there are no multiples
    std::set<Symbol> formal_names;
    for(int i = formals->first(); formals->more(i); i = formals->next(i)) {
        if (formals->nth(i)->get_name() == self) {
            classtable->semant_error1(class_name,this) << "\'self\' cannot be the name of a formal parameter." << endl;
        }

        if (formal_names.find(formals->nth(i)->get_name()) != formal_names.end()) {
            classtable->semant_error1(class_name,this) << "Formal parameter "<< formals->nth(i)->get_name() << " is multiply defined." << endl;
        }
        formal_names.insert(formals->nth(i)->get_name());
        formals->nth(i)->recurse(classtable, class_name);
    }

    // Recurse into the body of the method and check that the type of the expression conforms to the declared type
    expr->recurse(classtable, class_name);

    if (expr->get_type() != No_type && !classtable->conforms(expr->get_type(), return_type)){
        classtable->semant_error1(class_name,this) << "Inferred return type " << expr->get_type() << " of method " << name << " does not conform to declared return type " << return_type << "." << endl;
    }

    sym_tab->exitscope();
}

void attr_class::recurse(ClassTable* classtable, Symbol class_name)
{
    if (name == self) {
        classtable->semant_error1(class_name,this) << "\'self\' cannot be the name of an attribute." << endl;
    }

    // First check if the declared type is a valid type in the program
    // cout << name << " " << type_decl <<  endl;
    if (sym_tab->lookup(type_decl) == NULL){
        classtable->semant_error1(class_name,this) << "Class " << type_decl << " of attribute " << name << " is undefined." << endl;
        return;
    }

    init->recurse(classtable, class_name);

    // If initilization is omitted, we don't do the conformity check
    Symbol init_type = init->get_type();
    if (init_type == No_type) return;
    if (sym_tab->lookup(init_type) == NULL) return;
    
    // Check that the expression type conforms to the declared type
    if (!classtable->conforms(init_type, type_decl)){
        classtable->semant_error1(class_name,this) << "Inferred type " << init_type << " of initialization of attribute " << name << " does not conform to declared type " << type_decl << "." << endl;
    }
}

void formal_class::recurse(ClassTable* classtable, Symbol class_name)
{
    // Just add the varibale to the symbol table since we are already in a method scope
    sym_tab->addid(name, new Symbol(type_decl));
}

void branch_class::recurse(ClassTable* classtable, Symbol class_name, std::set<Symbol>& case_types)
{
    // Enterscope since we are pushing a new variable
    sym_tab->enterscope();

    if (name == self) 
        classtable->semant_error1(class_name,this) << "\'self\' bound in \'case\'." << endl;

    // If the declared type is SELF_TYPE, we raise an error
    if (type_decl == SELF_TYPE) {
        classtable->semant_error1(class_name,this) << "Identifier " << name << " declared with type SELF_TYPE in case branch." << endl;        
    }
    // Check that the declared type is valid
    if (sym_tab->lookup(type_decl) == NULL){
        classtable->semant_error1(class_name,this) << "Class " << type_decl << " of case branch is undefined." << endl;
    }

    // Check that the type of this branch has not been seen yet, if not seen then insert
    if (case_types.find(type_decl) != case_types.end()){
        classtable->semant_error1(class_name, this) << "Duplicate branch " << type_decl << " in case statement." << endl;
    } else {
        case_types.insert(type_decl);
    }
    
    // Add the variable to the scope
    sym_tab->addid(name, new Symbol(type_decl));

    expr->recurse(classtable,class_name); 
    // exit(1);
    sym_tab->exitscope();

}

void assign_class::recurse(ClassTable* classtable, Symbol class_name)
{
    if (name == self) {
        classtable->semant_error1(class_name,this) << "Cannot assign to \'self\'." << endl;
    }

    // Assign always takes on the type of the expression, so we recurse first
    expr->recurse(classtable, class_name);
    type = expr->get_type();

    // Raise error and don't check conformity if variable is undeclared
    if (sym_tab->lookup(name) == NULL) {
        classtable->semant_error1(class_name, this) << "Assignment to undeclared variable " << name << "." << endl;
        return;
    } 

    // Check that the expression type conforms to the declared type of the variable
    Symbol type_decl = *(sym_tab->lookup(name));
    if (!classtable->conforms(type, type_decl) && sym_tab->lookup(type_decl) != NULL)
        classtable->semant_error1(class_name,this) << "Type " << type << " of assigned expression does not conform to declared type " << type_decl << " of identifier " << name << "." << endl;
}

void static_dispatch_class::recurse(ClassTable* classtable, Symbol class_name)
{
    type = No_type;
    expr->recurse(classtable, class_name);
    // Cannot dispatch to self type
    if (type_name == SELF_TYPE) {
        classtable->semant_error1(class_name,this) << "Static dispatch to SELF_TYPE." << endl;
        type = Object;
        return;
    }
    // Raise error if type_name not in symbol table
    if (sym_tab->lookup(type_name) == NULL){
        classtable->semant_error1(class_name,this) << "Static dispatch to undefined class " << type_name << "." << endl;
        type = Object;
        return;
    // else raise error if expression type does not comform to dispatch type
    } else if (!classtable->conforms(expr->get_type(),type_name)) {
        type = Object;
        classtable->semant_error1(class_name,this) << "Expression type " << expr->get_type() << " does not conform to declared static dispatch type "  << type_name << "." << endl;
        return;
    }
    
    Method m(type_name, name);
    std::vector<std::pair<Symbol,Symbol>> args;
    if(method_map.find(m) == method_map.end()) {
        type = type_name;
        // If method is undefined, then raise error and return
        classtable->semant_error1(class_name,this) << "Static dispatch to undefined method " << name << "." << endl;
        return;
    } else {
        args = method_map[m];
    }

    std::vector<Symbol> expr_types;
    // Here we are adding all of the arguments to an array
    for(int i = actual->first(); actual->more(i); i = actual->next(i)) {
        actual->nth(i)->recurse(classtable, class_name);
        if (sym_tab->lookup(actual->nth(i)->get_type()) == NULL)
            classtable->semant_error1(class_name,this) << "Class " << actual->nth(i)->get_type() << " of formal parameter "<< args[i].second << " is undefined." << endl;
        expr_types.push_back(actual->nth(i)->get_type());
    }

    if (args.size() != expr_types.size() + 1) {
        classtable->semant_error1(class_name,this) << "Method " << name << " called with wrong number of arguments." << endl;
        type = (args.back().first == SELF_TYPE) ? expr->get_type(): args.back().first;
        return;
    }

    size_t min_size = (expr_types.size() < args.size()) ? expr_types.size() : args.size();
    for (size_t i = 0; i < min_size; i++) {
        if (!classtable->conforms(expr_types[i], args[i].first)) {
            classtable->semant_error1(class_name,this) << "In call of method " << name << ", type " << expr_types[i] << " of parameter " << args[i].second << " does not conform to declared type " << args[i].first << "." << endl;
        }
    }

    if (args.size() != 0) 
        type = (args.back().first == SELF_TYPE) ? expr->get_type(): args.back().first;
    else
        type = Object;
}

void dispatch_class::recurse(ClassTable* classtable, Symbol class_name)
{
    type = No_type;
    expr->recurse(classtable, class_name);
    Symbol class_type = expr->get_type();
    // If expression type is SELF_TYPE, then we change the class_type to be the class_name
    if (expr->get_type() == SELF_TYPE)
        class_type = class_name;
    if (sym_tab->lookup(class_type) == NULL) {
        classtable->semant_error1(class_name,this) << "Dispatch on undefined class " << class_type << "." << endl; 
        type = Object;
        return;
    }
    Method m(class_type, name);
    std::vector<std::pair<Symbol,Symbol>> args;   
    // cout << class_type << " " << name << " " << *(sym_tab->lookup(SELF_TYPE)) <<  endl;
    // sym_tab->dump(); 
    if(method_map.find(m) == method_map.end()) {
        classtable->semant_error1(class_name,this) << "Dispatch to undefined method " << name << "." << endl; 
        return;
    } else {
        args = method_map[m];
    }
   
    std::vector<Symbol> expr_types;
    for(int i = actual->first(); actual->more(i); i = actual->next(i)) {
        actual->nth(i)->recurse(classtable, class_name);
        if (sym_tab->lookup(actual->nth(i)->get_type()) == NULL)
            classtable->semant_error1(class_name,this) << "Class " << actual->nth(i)->get_type() << " of formal parameter "<< args[i].second << " is undefined." << endl;
        expr_types.push_back(actual->nth(i)->get_type());
    }

    if (args.size() != expr_types.size() + 1) {
        classtable->semant_error1(class_name,this) << "Method " << name << " called with wrong number of arguments." << endl;
        type = (args.back().first == SELF_TYPE) ? expr->get_type(): args.back().first;
        return;
    }
    
    size_t min_size = (expr_types.size() < args.size()) ? expr_types.size() : args.size();
    for (size_t i = 0; i < min_size; i++) {
        if (!classtable->conforms(expr_types[i], args[i].first)) {
            classtable->semant_error1(class_name,this) << "In call of method " << name << ", type " << expr_types[i] << " of parameter " << args[i].second << " does not conform to declared type " << args[i].first << "." << endl;
        }
    }

    if (args.size() != 0) 
        type = (args.back().first == SELF_TYPE) ? expr->get_type(): args.back().first;
    else
        type = Object;

}

void cond_class::recurse(ClassTable* classtable, Symbol class_name)
{   
    // make sure predicate expr is type Bool
    pred->recurse(classtable, class_name);
    Symbol pred_type = pred->get_type();
    if (pred_type != Bool) {
        classtable->semant_error1(class_name, this) << "Predicate of \'if\' does not have type Bool." << endl; 
    }

    // Evaluate branches
    then_exp->recurse(classtable, class_name);
    Symbol then_type = then_exp->get_type();
    
    else_exp->recurse(classtable, class_name);
    Symbol else_type = else_exp->get_type();

    // The type of if expression is lub of branch expressions
    if (sym_tab->lookup(then_type) == NULL || sym_tab->lookup(else_type) == NULL)
        type = Object;
    else
        type = classtable->lub(then_type,else_type);
}

void loop_class::recurse(ClassTable* classtable, Symbol class_name)
{
    // make sure predicate expr is type Bool    
    pred->recurse(classtable,class_name);
    Symbol pred_type = pred->get_type();
    if (pred_type != Bool) {
        classtable->semant_error1(class_name,this) << "Loop condition does not have type Bool." << endl;
    }

    body->recurse(classtable, class_name);
    type = Object;
}

void typcase_class::recurse(ClassTable* classtable, Symbol class_name)
{
    // Evaluate first expression
    expr->recurse(classtable,class_name);

    // Loop over the branches and evaluate them, keep track of the variables defined
    std::set<Symbol> case_types;
    for (int i = cases->first(); cases->more(i); i = cases->next(i)){
        cases->nth(i)->recurse(classtable, class_name, case_types);
        
        // After recursing on the first branch, type is still no_type so we just set type to the branch type
        // otherwise the type is a running lub of all the branch types
        if (i == cases->first()){
            type = cases->nth(i)->get_expr_type();
            if (type == No_type)
                type = Object;
        } else {
            if (cases->nth(i)->get_expr_type() == No_type){
                type = Object;
                continue;
            }
            type = classtable->lub(type,cases->nth(i)->get_expr_type());
        }
    }
}

void block_class::recurse(ClassTable* classtable, Symbol class_name)
{
    // Evaluate all expressions and set tyep to the type of the last expression 
    for (int i = body->first(); body->more(i); i = body->next(i)) {
        body->nth(i)->recurse(classtable, class_name);
        type = body->nth(i)->get_type();
    }
}

void let_class::recurse(ClassTable* classtable, Symbol class_name)
{
    // Evaluate the init expression
    // cout << identifier << endl;

    init->recurse(classtable, class_name);
    Symbol init_type = init->get_type();
    // If there is no initilization, we don't do a conformity check
    // Otherwise raise error if init expression does not conform to declared type;
    if (sym_tab->lookup(type_decl) == NULL) {
        classtable->semant_error1(class_name, this) << "Class " << type_decl << " of let-bound identifier " << identifier << " is undefined." << endl;
    } else if (init_type != No_type) {
        if(!classtable->conforms(init_type, type_decl)) {
            classtable->semant_error1(class_name, this) << "Inferred type " <<  init_type << " of initialization of " << identifier << " does not conform to identifier's declared type " << type_decl << "." << endl;
        }
    }


    // Enter scope since we push a new variable
    sym_tab->enterscope();
    
    if (identifier == self){
        // cout << "were here"<< endl;
        classtable->semant_error1(class_name,this) << "\'self\' cannot be bound in a \'let\' expression." << endl;
        // type = No_type;
    } else {
        sym_tab->addid(identifier, new Symbol(type_decl));
    }
    body->recurse(classtable, class_name);
    sym_tab->exitscope();
    

    type = body->get_type();
    if (sym_tab->lookup(type) == NULL){
        type = Object;
    }
}

void plus_class::recurse(ClassTable* classtable, Symbol class_name)
{
    // Evaluate both expressions
    e1->recurse(classtable, class_name);
    e2->recurse(classtable, class_name);

    // Make sure that both expressions are Int
    if (e1->get_type() != Int || e2->get_type() != Int) {
        classtable->semant_error1(class_name,this) << "non-Int arguments: " << e1->get_type() << " + " << e2->get_type() << endl;
    }

    // We know the type of this expression will be Int
    type = Int;
}

void sub_class::recurse(ClassTable* classtable, Symbol class_name)
{
    e1->recurse(classtable, class_name);
    e2->recurse(classtable, class_name);

    if (e1->get_type() != Int || e2->get_type() != Int) {
        classtable->semant_error1(class_name,this) << "non-Int arguments: " << e1->get_type() << " - " << e2->get_type() << endl;
    }

    type = Int;
}

void mul_class::recurse(ClassTable* classtable, Symbol class_name)
{
    e1->recurse(classtable, class_name);
    e2->recurse(classtable, class_name);

    if (e1->get_type() != Int || e2->get_type() != Int) {
        classtable->semant_error1(class_name,this) << "non-Int arguments: " << e1->get_type() << " * " << e2->get_type() << endl;
    }

    type = Int;
}

void divide_class::recurse(ClassTable* classtable, Symbol class_name)
{
    e1->recurse(classtable, class_name);
    e2->recurse(classtable, class_name);

    if (e1->get_type() != Int || e2->get_type() != Int) {
        classtable->semant_error1(class_name,this) << "non-Int arguments: " << e1->get_type() << " / " << e2->get_type() << endl;
    }

    type = Int;
}

void neg_class::recurse(ClassTable* classtable, Symbol class_name)
{
    e1->recurse(classtable, class_name);

    if (e1->get_type() != Int) {
        classtable->semant_error1(class_name,this) << "Argument of \'~\' has type " << e1->get_type() << " instead of Int." << endl;
    }

    type = Int;
}

void lt_class::recurse(ClassTable* classtable, Symbol class_name)
{
    e1->recurse(classtable, class_name);
    e2->recurse(classtable, class_name);

    if (e1->get_type() != Int || e2->get_type() != Int) {
        classtable->semant_error1(class_name,this) << "non-Int arguments: " << e1->get_type() << " < " << e2->get_type() << endl;
    }

    type = Bool;
}


void eq_class::recurse(ClassTable* classtable, Symbol class_name)
{
    e1->recurse(classtable, class_name);
    e2->recurse(classtable, class_name);
    type = Bool;

    std::set<Symbol> basic_types = {Int, Bool, Str};
    if (basic_types.find(e1->get_type()) !=  basic_types.end()) {
        // if (basic_types.find(e2->get_type()) !=  basic_types.end()) {
            if (e1->get_type() != e2->get_type()) {
                classtable->semant_error1(class_name,this) << "Illegal comparison with a basic type." << endl;
                return;
            }
        // }
    }

    if (basic_types.find(e2->get_type()) !=  basic_types.end()) {
        // if (basic_types.find(e1->get_type()) !=  basic_types.end()) {
            if (e1->get_type() != e2->get_type()) {
                classtable->semant_error1(class_name,this) << "Illegal comparison with a basic type." << endl;
                return;
            }
        // }
    }
}

void leq_class::recurse(ClassTable* classtable, Symbol class_name)
{
    e1->recurse(classtable, class_name);
    e2->recurse(classtable, class_name);

    if (e1->get_type() != Int || e2->get_type() != Int) {
        classtable->semant_error1(class_name,this) << "non-Int arguments: " << e1->get_type() << " <= " << e2->get_type() << endl;
    }

    type = Bool;
}

void comp_class::recurse(ClassTable* classtable, Symbol class_name)
{
    e1->recurse(classtable, class_name);

    if (e1->get_type() !=  Bool) {
        classtable->semant_error1(class_name,this) << "Argument of \'not\' has type " << e1->get_type() << " instead of Bool." << endl;
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
    type = type_name;

    if (sym_tab->lookup(type_name) == NULL) {
        classtable->semant_error1(class_name,this) << "\'new\' used with undefined class " << type_name << "." << endl;
        type = Object;
    }
}

void isvoid_class::recurse(ClassTable* classtable, Symbol class_name)
{
    e1->recurse(classtable, class_name);
    type = Bool;
}

void no_expr_class::recurse(ClassTable* classtable, Symbol class_name)
{
    type = No_type;
}

void object_class::recurse(ClassTable* classtable, Symbol class_name)
{
    if (sym_tab->lookup(name) == NULL) {
        classtable->semant_error1(class_name,this) << "Undeclared identifier " << name << "." << endl;
        type = Object;
        return;
    }
    type = *(sym_tab->lookup(name));
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
    ClassTable *classtable = new ClassTable(classes);
    recurse(classtable);

    if (classtable->errors()) {
       cerr << "Compilation halted due to static semantic errors." << endl;
       exit(1);
    }
}
