
//**************************************************************
//
// Code generator SKELETON
//
// Read the comments carefully. Make sure to
//    initialize the base class tags in
//       `CgenClassTable::CgenClassTable'
//
//    Add the label for the dispatch tables to
//       `IntEntry::code_def'
//       `StringEntry::code_def'
//       `BoolConst::code_def'
//
//    Add code to emit everyting else that is needed
//       in `CgenClassTable::code'
//
//
// The files as provided will produce code to begin the code
// segments, declare globals, and emit constants.  You must
// fill in the rest.
//
//**************************************************************

#include "cgen.h"
#include "cgen_gc.h"

extern void emit_string_constant(ostream& str, char *s);
extern int cgen_debug;

//static std::map<Symbol, std::vector<int>>* var_table = new SymbolTable<Symbol, std::vector<int>>();
//
// Three symbols from the semantic analyzer (semant.cc) are used.
// If e : No_type, then no code is generated for e.
// Special code is generated for new SELF_TYPE.
// The name "self" also generates code different from other references.
//
//////////////////////////////////////////////////////////////////////
//
// Symbols
//
// For convenience, a large number of symbols are predefined here.
// These symbols include the primitive type and method names, as well
// as fixed names used by the runtime system.
//
//////////////////////////////////////////////////////////////////////
Symbol 
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

static char *gc_init_names[] =
  { "_NoGC_Init", "_GenGC_Init", "_ScnGC_Init" };
static char *gc_collect_names[] =
  { "_NoGC_Collect", "_GenGC_Collect", "_ScnGC_Collect" };


//  BoolConst is a class that implements code generation for operations
//  on the two booleans, which are given global names here.
BoolConst falsebool(FALSE);
BoolConst truebool(TRUE);

//*********************************************************
//
// Define method for code generation
//
// This is the method called by the compiler driver
// `cgtest.cc'. cgen takes an `ostream' to which the assembly will be
// emmitted, and it passes this and the class list of the
// code generator tree to the constructor for `CgenClassTable'.
// That constructor performs all of the work of the code
// generator.
//
//*********************************************************

void program_class::cgen(ostream &os) 
{
  // spim wants comments to start with '#'
  os << "# start of generated code\n";

  initialize_constants();
  CgenClassTable *codegen_classtable = new CgenClassTable(classes,os);

  os << "\n# end of generated code\n";
}


//////////////////////////////////////////////////////////////////////////////
//
//  emit_* procedures
//
//  emit_X  writes code for operation "X" to the output stream.
//  There is an emit_X for each opcode X, as well as emit_ functions
//  for generating names according to the naming conventions (see emit.h)
//  and calls to support functions defined in the trap handler.
//
//  Register names and addresses are passed as strings.  See `emit.h'
//  for symbolic names you can use to refer to the strings.
//
//////////////////////////////////////////////////////////////////////////////

static void emit_load(char *dest_reg, int offset, char *source_reg, ostream& s)
{
  s << LW << dest_reg << " " << offset * WORD_SIZE << "(" << source_reg << ")" 
    << endl;
}

static void emit_store(char *source_reg, int offset, char *dest_reg, ostream& s)
{
  s << SW << source_reg << " " << offset * WORD_SIZE << "(" << dest_reg << ")"
      << endl;
}

static void emit_load_imm(char *dest_reg, int val, ostream& s)
{ s << LI << dest_reg << " " << val << endl; }

static void emit_load_address(char *dest_reg, char *address, ostream& s)
{ s << LA << dest_reg << " " << address << endl; }

static void emit_partial_load_address(char *dest_reg, ostream& s)
{ s << LA << dest_reg << " "; }

static void emit_load_bool(char *dest, const BoolConst& b, ostream& s)
{
  emit_partial_load_address(dest,s);
  b.code_ref(s);
  s << endl;
}

static void emit_load_string(char *dest, StringEntry *str, ostream& s)
{
  emit_partial_load_address(dest,s);
  str->code_ref(s);
  s << endl;
}

static void emit_load_int(char *dest, IntEntry *i, ostream& s)
{
  emit_partial_load_address(dest,s);
  i->code_ref(s);
  s << endl;
}

static void emit_move(char *dest_reg, char *source_reg, ostream& s)
{ s << MOVE << dest_reg << " " << source_reg << endl; }

static void emit_neg(char *dest, char *src1, ostream& s)
{ s << NEG << dest << " " << src1 << endl; }

static void emit_add(char *dest, char *src1, char *src2, ostream& s)
{ s << ADD << dest << " " << src1 << " " << src2 << endl; }

static void emit_addu(char *dest, char *src1, char *src2, ostream& s)
{ s << ADDU << dest << " " << src1 << " " << src2 << endl; }

static void emit_addiu(char *dest, char *src1, int imm, ostream& s)
{ s << ADDIU << dest << " " << src1 << " " << imm << endl; }

static void emit_div(char *dest, char *src1, char *src2, ostream& s)
{ s << DIV << dest << " " << src1 << " " << src2 << endl; }

static void emit_mul(char *dest, char *src1, char *src2, ostream& s)
{ s << MUL << dest << " " << src1 << " " << src2 << endl; }

static void emit_sub(char *dest, char *src1, char *src2, ostream& s)
{ s << SUB << dest << " " << src1 << " " << src2 << endl; }

static void emit_sll(char *dest, char *src1, int num, ostream& s)
{ s << SLL << dest << " " << src1 << " " << num << endl; }

static void emit_jalr(char *dest, ostream& s)
{ s << JALR << "\t" << dest << endl; }

static void emit_jal(char *address,ostream &s)
{ s << JAL << address << endl; }

static void emit_partial_jal(ostream &s)
{ s << JAL; }

static void emit_return(ostream& s)
{ s << RET << endl; }

static void emit_gc_assign(ostream& s)
{ s << JAL << "_GenGC_Assign" << endl; }

static void emit_disptable_ref(Symbol sym, ostream& s)
{  s << sym << DISPTAB_SUFFIX; }

static void emit_init_ref(Symbol sym, ostream& s)
{ s << sym << CLASSINIT_SUFFIX; }

static void emit_init_def(Symbol sym, ostream& s)
{ 
  emit_init_ref(sym, s);
  s << ":" << endl;
}

static void emit_label_ref(int l, ostream &s)
{ s << "label" << l; }

static void emit_protobj_ref(Symbol sym, ostream& s)
{ s << sym << PROTOBJ_SUFFIX; }

static void emit_method_ref(Symbol classname, Symbol methodname, ostream& s)
{ s << classname << METHOD_SEP << methodname; }

static void emit_method_def(Symbol classname, Symbol methodname, ostream& s)
{ 
  emit_method_ref(classname, methodname, s);
  s << ":" << endl;
}

static void emit_jal_method(Symbol classname, Symbol methodname, ostream& s)
{ s << JAL << classname << METHOD_SEP << methodname << endl; }

static void emit_label_def(int l, ostream &s)
{
  emit_label_ref(l,s);
  s << ":" << endl;
}

static void emit_beqz(char *source, int label, ostream &s)
{
  s << BEQZ << source << " ";
  emit_label_ref(label,s);
  s << endl;
}

static void emit_beq(char *src1, char *src2, int label, ostream &s)
{
  s << BEQ << src1 << " " << src2 << " ";
  emit_label_ref(label,s);
  s << endl;
}

static void emit_bne(char *src1, char *src2, int label, ostream &s)
{
  s << BNE << src1 << " " << src2 << " ";
  emit_label_ref(label,s);
  s << endl;
}

static void emit_bleq(char *src1, char *src2, int label, ostream &s)
{
  s << BLEQ << src1 << " " << src2 << " ";
  emit_label_ref(label,s);
  s << endl;
}

static void emit_blt(char *src1, char *src2, int label, ostream &s)
{
  s << BLT << src1 << " " << src2 << " ";
  emit_label_ref(label,s);
  s << endl;
}

static void emit_blti(char *src1, int imm, int label, ostream &s)
{
  s << BLT << src1 << " " << imm << " ";
  emit_label_ref(label,s);
  s << endl;
}

static void emit_bgti(char *src1, int imm, int label, ostream &s)
{
  s << BGT << src1 << " " << imm << " ";
  emit_label_ref(label,s);
  s << endl;
}

static void emit_branch(int l, ostream& s)
{
  s << BRANCH;
  emit_label_ref(l,s);
  s << endl;
}

//
// Push a register on the stack. The stack grows towards smaller addresses.
//
static void emit_push(char *reg, ostream& str)
{
  emit_store(reg,0,SP,str);
  emit_addiu(SP,SP,-4,str);
}

//
// Fetch the integer value in an Int object.
// Emits code to fetch the integer value of the Integer object pointed
// to by register source into the register dest
//
static void emit_fetch_int(char *dest, char *source, ostream& s)
{ emit_load(dest, DEFAULT_OBJFIELDS, source, s); }

//
// Emits code to store the integer value contained in register source
// into the Integer object pointed to by dest.
//
static void emit_store_int(char *source, char *dest, ostream& s)
{ emit_store(source, DEFAULT_OBJFIELDS, dest, s); }


static void emit_test_collector(ostream &s)
{
  emit_push(ACC, s);
  emit_move(ACC, SP, s); // stack end
  emit_move(A1, ZERO, s); // allocate nothing
  s << JAL << gc_collect_names[cgen_Memmgr] << endl;
  emit_addiu(SP,SP,4,s);
  emit_load(ACC,0,SP,s);
}

static void emit_gc_check(char *source, ostream &s)
{
  if (source != (char*)A1) emit_move(A1, source, s);
  s << JAL << "_gc_check" << endl;
}


///////////////////////////////////////////////////////////////////////////////
//
// coding strings, ints, and booleans
//
// Cool has three kinds of constants: strings, ints, and booleans.
// This section defines code generation for each type.
//
// All string constants are listed in the global "stringtable" and have
// type StringEntry.  StringEntry methods are defined both for String
// constant definitions and references.
//
// All integer constants are listed in the global "inttable" and have
// type IntEntry.  IntEntry methods are defined for Int
// constant definitions and references.
//
// Since there are only two Bool values, there is no need for a table.
// The two booleans are represented by instances of the class BoolConst,
// which defines the definition and reference methods for Bools.
//
///////////////////////////////////////////////////////////////////////////////

//
// Strings
//
void StringEntry::code_ref(ostream& s)
{
  s << STRCONST_PREFIX << index;
  //cout << str << " " << index << endl;
}

//
// Emit code for a constant String.
// You should fill in the code naming the dispatch table.
//

void StringEntry::code_def(ostream& s, int stringclasstag)
{
  IntEntryP lensym = inttable.add_int(len);

  // Add -1 eye catcher
  s << WORD << "-1" << endl;

  code_ref(s);  s  << LABEL                                             // label
      << WORD << stringclasstag << endl                                 // tag
      << WORD << (DEFAULT_OBJFIELDS + STRING_SLOTS + (len+4)/4) << endl // size
      << WORD;
      emit_disptable_ref(Str, s);
      s << endl;                                              // dispatch table
      s << WORD;  lensym->code_ref(s);  s << endl;            // string length
  emit_string_constant(s,str);                                // ascii string
  s << ALIGN;                                                 // align to word
}

//
// StrTable::code_string
// Generate a string object definition for every string constant in the 
// stringtable.
//
void StrTable::code_string_table(ostream& s, int stringclasstag)
{  
  for (List<StringEntry> *l = tbl; l; l = l->tl())
    l->hd()->code_def(s,stringclasstag);
}

//
// Ints
//
void IntEntry::code_ref(ostream &s)
{
  s << INTCONST_PREFIX << index;
}

//
// Emit code for a constant Integer.
// You should fill in the code naming the dispatch table.
//

void IntEntry::code_def(ostream &s, int intclasstag)
{
  // Add -1 eye catcher
  s << WORD << "-1" << endl;

  code_ref(s);  s << LABEL                                // label
      << WORD << intclasstag << endl                      // class tag
      << WORD << (DEFAULT_OBJFIELDS + INT_SLOTS) << endl  // object size
      << WORD; 
      emit_disptable_ref(Int, s);
      s << endl;                                          // dispatch table
      s << WORD << str << endl;                           // integer value
}


//
// IntTable::code_string_table
// Generate an Int object definition for every Int constant in the
// inttable.
//
void IntTable::code_string_table(ostream &s, int intclasstag)
{
  for (List<IntEntry> *l = tbl; l; l = l->tl())
    l->hd()->code_def(s,intclasstag);
}


//
// Bools
//
BoolConst::BoolConst(int i) : val(i) { assert(i == 0 || i == 1); }

void BoolConst::code_ref(ostream& s) const
{
  s << BOOLCONST_PREFIX << val;
}
  
//
// Emit code for a constant Bool.
// You should fill in the code naming the dispatch table.
//

void BoolConst::code_def(ostream& s, int boolclasstag)
{
  // Add -1 eye catcher
  s << WORD << "-1" << endl;

  code_ref(s);  s << LABEL                                  // label
      << WORD << boolclasstag << endl                       // class tag
      << WORD << (DEFAULT_OBJFIELDS + BOOL_SLOTS) << endl   // object size
      << WORD;
      emit_disptable_ref(Bool, s);
      s << endl;                                            // dispatch table
      s << WORD << val << endl;                             // value (0 or 1)
}

//////////////////////////////////////////////////////////////////////////////
//
//  CgenClassTable methods
//
//////////////////////////////////////////////////////////////////////////////

//***************************************************
//
//  Emit code to start the .data segment and to
//  declare the global names.
//
//***************************************************

void CgenClassTable::code_global_data()
{
  Symbol main    = idtable.lookup_string(MAINNAME);
  Symbol string  = idtable.lookup_string(STRINGNAME);
  Symbol integer = idtable.lookup_string(INTNAME);
  Symbol boolc   = idtable.lookup_string(BOOLNAME);

  str << "\t.data\n" << ALIGN;
  //
  // The following global names must be defined first.
  //
  str << GLOBAL << CLASSNAMETAB << endl;
  str << GLOBAL; emit_protobj_ref(main,str);    str << endl;
  str << GLOBAL; emit_protobj_ref(integer,str); str << endl;
  str << GLOBAL; emit_protobj_ref(string,str);  str << endl;
  str << GLOBAL; falsebool.code_ref(str);  str << endl;
  str << GLOBAL; truebool.code_ref(str);   str << endl;
  str << GLOBAL << INTTAG << endl;
  str << GLOBAL << BOOLTAG << endl;
  str << GLOBAL << STRINGTAG << endl;

  //
  // We also need to know the tag of the Int, String, and Bool classes
  // during code generation.
  //
  str << INTTAG << LABEL
      << WORD << intclasstag << endl;
  str << BOOLTAG << LABEL 
      << WORD << boolclasstag << endl;
  str << STRINGTAG << LABEL 
      << WORD << stringclasstag << endl;    
}


//***************************************************
//
//  Emit code to start the .text segment and to
//  declare the global names.
//
//***************************************************

void CgenClassTable::code_global_text()
{
  str << GLOBAL << HEAP_START << endl
      << HEAP_START << LABEL 
      << WORD << 0 << endl
      << "\t.text" << endl
      << GLOBAL;
  emit_init_ref(idtable.add_string("Main"), str);
  str << endl << GLOBAL;
  emit_init_ref(idtable.add_string("Int"),str);
  str << endl << GLOBAL;
  emit_init_ref(idtable.add_string("String"),str);
  str << endl << GLOBAL;
  emit_init_ref(idtable.add_string("Bool"),str);
  str << endl << GLOBAL;
  emit_method_ref(idtable.add_string("Main"), idtable.add_string("main"), str);
  str << endl;
}

void CgenClassTable::code_bools(int boolclasstag)
{
  falsebool.code_def(str,boolclasstag);
  truebool.code_def(str,boolclasstag);
}

void CgenClassTable::code_select_gc()
{
  //
  // Generate GC choice constants (pointers to GC functions)
  //
  str << GLOBAL << "_MemMgr_INITIALIZER" << endl;
  str << "_MemMgr_INITIALIZER:" << endl;
  str << WORD << gc_init_names[cgen_Memmgr] << endl;
  str << GLOBAL << "_MemMgr_COLLECTOR" << endl;
  str << "_MemMgr_COLLECTOR:" << endl;
  str << WORD << gc_collect_names[cgen_Memmgr] << endl;
  str << GLOBAL << "_MemMgr_TEST" << endl;
  str << "_MemMgr_TEST:" << endl;
  str << WORD << (cgen_Memmgr_Test == GC_TEST) << endl;
}


//********************************************************
//
// Emit code to reserve space for and initialize all of
// the constants.  Class names should have been added to
// the string table (in the supplied code, is is done
// during the construction of the inheritance graph), and
// code for emitting string constants as a side effect adds
// the string's length to the integer table.  The constants
// are emmitted by running through the stringtable and inttable
// and producing code for each entry.
//
//********************************************************

void CgenClassTable::code_constants()
{
  //
  // Add constants that are required by the code generator.
  //
  stringtable.add_string("");
  inttable.add_string("0");

  stringtable.code_string_table(str,stringclasstag);
  inttable.code_string_table(str,intclasstag);
  code_bools(boolclasstag);
}

void CgenClassTable::set_class_tags(CgenNodeP p, int& counter) {
  if (classTag_map.find(p->get_name()) == classTag_map.end()) {
    classTag_map[p->get_name()] = counter;
    counter++;
  }

  List<CgenNode> *children = p->get_children(); 
  for(List<CgenNode> *l = children; l; l = l->tl()) {
    set_class_tags(l->hd(), counter);
  }
}

void CgenClassTable::create_implementation_map(CgenNodeP p, std::vector<Method> methods)
{
  Symbol class_name = p->get_name();
  if (class_name == Object) {
    for(List<CgenNode> *l = nds; l; l = l->tl()) {
      Method m(l->hd()->get_name(), l->hd()->get_name());
      implementation_map[m] = std::vector<Symbol>();
    }
  }

  for (auto parent_method : methods) {
    Symbol parent_method_name = parent_method.second;
    Method m(class_name, parent_method_name);
    implementation_map[m] = implementation_map[parent_method];
  }

  int num_methods = 0;
  Features features = p->get_features();
  for(int i = features->first(); features->more(i); i = features->next(i)) {
    if (features->nth(i)->get_feature_type() == "Method") {
      num_methods++;
      Method m(class_name, features->nth(i)->get_name());
      methods.push_back(m);

      Formals formals = features->nth(i)->get_formals();
      std::vector<Symbol> formal_names;
      for(int i = formals->first(); formals->more(i); i = formals->next(i)) {
        formal_names.push_back(formals->nth(i)->get_name());
      }
      implementation_map[m] = formal_names;
    }
  }

  List<CgenNode> *children = p->get_children(); 
  for(List<CgenNode> *l = children; l; l = l->tl()) {
    create_implementation_map(l->hd(), methods);
  }

  for(int i = 0; i < num_methods; i++) {
    methods.pop_back();
  }
}

void CgenClassTable::create_class_map(CgenNodeP p, std::vector<Symbol> attributes) 
{
  int num_attributes = 0;

  Features features = p->get_features();
  for(int i = features->first(); features->more(i); i = features->next(i)) {
    if (features->nth(i)->get_feature_type() == "Attribute") {
      num_attributes++;
      attributes.push_back(features->nth(i)->get_name());
    }
  }

  std::vector<Symbol>* class_attributesP = new std::vector<Symbol>(attributes);
  std::vector<Symbol> class_attributes = *class_attributesP;
  // class_attributes = attributes;
  class_map[p->get_name()] = class_attributes;

  List<CgenNode> *children = p->get_children(); 
  for(List<CgenNode> *l = children; l; l = l->tl()) {
    create_class_map(l->hd(), attributes);
  }

  for(int i = 0; i < num_attributes; i++) {
    attributes.pop_back();
  }
}

CgenClassTable::CgenClassTable(Classes classes, ostream& s) : nds(NULL) , str(s)
{
   

   enterscope();
   if (cgen_debug) cout << "Building CgenClassTable" << endl;
   install_basic_classes();
   install_classes(classes);
   build_inheritance_tree();

   // stringclasstag = 1;
   // intclasstag =    2;
   // boolclasstag =   3;


  if (cgen_debug) cout << "building maps" << endl;
  int classTag = 0;
  set_class_tags(root(), classTag);

  // classTag_map[Object] = 0;
  stringclasstag = classTag_map[Str];
  intclasstag = classTag_map[Int];
  boolclasstag = classTag_map[Bool];

  
  create_implementation_map(root(), std::vector<Method>());
  create_class_map(root(), std::vector<Symbol>());

  addid(SELF_TYPE, lookup(Main));

   code();
   exitscope();
}

void CgenClassTable::install_basic_classes()
{

// The tree package uses these globals to annotate the classes built below.
  //curr_lineno  = 0;
  Symbol filename = stringtable.add_string("<basic class>");

//
// A few special class names are installed in the lookup table but not
// the class list.  Thus, these classes exist, but are not part of the
// inheritance hierarchy.
// No_class serves as the parent of Object and the other special classes.
// SELF_TYPE is the self class; it cannot be redefined or inherited.
// prim_slot is a class known to the code generator.
//
  addid(No_class,
	new CgenNode(class_(No_class,No_class,nil_Features(),filename),
			    Basic,this));
  addid(SELF_TYPE,
	new CgenNode(class_(SELF_TYPE,No_class,nil_Features(),filename),
			    Basic,this));
  addid(prim_slot,
	new CgenNode(class_(prim_slot,No_class,nil_Features(),filename),
			    Basic,this));

// 
// The Object class has no parent class. Its methods are
//        cool_abort() : Object    aborts the program
//        type_name() : Str        returns a string representation of class name
//        copy() : SELF_TYPE       returns a copy of the object
//
// There is no need for method bodies in the basic classes---these
// are already built in to the runtime system.
//
  install_class(
   new CgenNode(
    class_(Object, 
	   No_class,
	   append_Features(
           append_Features(
           single_Features(method(cool_abort, nil_Formals(), Object, no_expr())),
           single_Features(method(type_name, nil_Formals(), Str, no_expr()))),
           single_Features(method(copy, nil_Formals(), SELF_TYPE, no_expr()))),
	   filename),
    Basic,this));

// 
// The IO class inherits from Object. Its methods are
//        out_string(Str) : SELF_TYPE          writes a string to the output
//        out_int(Int) : SELF_TYPE               "    an int    "  "     "
//        in_string() : Str                    reads a string from the input
//        in_int() : Int                         "   an int     "  "     "
//
   install_class(
    new CgenNode(
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
	   filename),	    
    Basic,this));

//
// The Int class has no methods and only a single attribute, the
// "val" for the integer. 
//
   install_class(
    new CgenNode(
     class_(Int, 
	    Object,
            single_Features(attr(val, prim_slot, no_expr())),
	    filename),
     Basic,this));

//
// Bool also has only the "val" slot.
//
    install_class(
     new CgenNode(
      class_(Bool, Object, single_Features(attr(val, prim_slot, no_expr())),filename),
      Basic,this));

//
// The class Str has a number of slots and operations:
//       val                                  ???
//       str_field                            the string itself
//       length() : Int                       length of the string
//       concat(arg: Str) : Str               string concatenation
//       substr(arg: Int, arg2: Int): Str     substring
//       
   install_class(
    new CgenNode(
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
	     filename),
        Basic,this));

}

// CgenClassTable::install_class
// CgenClassTable::install_classes
//
// install_classes enters a list of classes in the symbol table.
//
void CgenClassTable::install_class(CgenNodeP nd)
{
  Symbol name = nd->get_name();

  if (probe(name))
    {
      return;
    }

  // The class name is legal, so add it to the list of classes
  // and the symbol table.
  nds = new List<CgenNode>(nd,nds);
  addid(name,nd);
}

void CgenClassTable::install_classes(Classes cs)
{
  for(int i = cs->first(); cs->more(i); i = cs->next(i))
    install_class(new CgenNode(cs->nth(i),NotBasic,this));
}

//
// CgenClassTable::build_inheritance_tree
//
void CgenClassTable::build_inheritance_tree()
{
  for(List<CgenNode> *l = nds; l; l = l->tl())
      set_relations(l->hd());
}

//
// CgenClassTable::set_relations
//
// Takes a CgenNode and locates its, and its parent's, inheritance nodes
// via the class table.  Parent and child pointers are added as appropriate.
//
void CgenClassTable::set_relations(CgenNodeP nd)
{
  CgenNode *parent_node = probe(nd->get_parent());
  nd->set_parentnd(parent_node);
  parent_node->add_child(nd);
}

void CgenNode::add_child(CgenNodeP n)
{
  children = new List<CgenNode>(n,children);
}

void CgenNode::set_parentnd(CgenNodeP p)
{
  assert(parentnd == NULL);
  assert(p != NULL);
  parentnd = p;
}

void CgenClassTable::code_protObjs(CgenNodeP p, std::vector<Feature> attributes) 
{
  int num_attributes = 0;
  Features features = p->get_features();
  for(int i = features->first(); features->more(i); i = features->next(i)) {
    if (features->nth(i)->get_feature_type() == "Attribute") {
      num_attributes++;
      attributes.push_back(features->nth(i));
    }
  }

  List<CgenNode> *children = p->get_children(); 
  for(List<CgenNode> *l = children; l; l = l->tl()) {
    code_protObjs(l->hd(), attributes);
  }

  int classTag = classTag_map[p->get_name()];
  p->code_protObj(str, attributes, classTag);

  for(int i = 0; i < num_attributes; i++) {
    attributes.pop_back();
  }
}

static void emit_default_const_ref(Symbol type, ostream &s)
{ 
    if (type == Str)
      stringtable.lookup_string("")->code_ref(s);
    else if (type == Int)
      inttable.lookup_string("0")->code_ref(s);
    else if (type == Bool) 
      BoolConst(0).code_ref(s);
    else
      s << "0"; 
}

static void emit_default_init(Symbol type, ostream &s) {
  if (type == Str)
    emit_load_string(ACC,stringtable.lookup_string(""),s);
  else if (type == Int)
    emit_load_int(ACC,inttable.lookup_string("0"),s);
  else if (type == Bool) 
    emit_load_bool(ACC, BoolConst(0), s);
  else
    emit_move(ACC, ZERO, s); 
}

void CgenNode::code_protObj(ostream& s, std::vector<Feature> attributes, int classTag) 
{
  int CLASS_SLOTS = attributes.size();

  // Add -1 eye catcher
  s << WORD << "-1" << endl;
  emit_protobj_ref(name, s);
  s << ":" << endl;          // label
  s << WORD << classTag << endl                     // class tag
  << WORD << (DEFAULT_OBJFIELDS + CLASS_SLOTS) << endl;  // object size
  s << WORD;
  emit_disptable_ref(name, s);
  s << endl; // dispatch table 
  for(Feature attr : attributes) { // attributes
    s << WORD; 
    Symbol type = attr->get_type();
    emit_default_const_ref(type, s);
    s << endl;
  }                                        
}

void CgenClassTable::code_class_nameTab() {
  str << "class_nameTab:" << endl;
  root()->code_class_nameTab(str);
}

void CgenNode::code_class_nameTab(ostream& s) { 
  s << WORD;
  stringtable.lookup_string(name->get_string())->code_ref(s);
  s << endl;
  for(List<CgenNode> *l = children; l; l = l->tl()) {
    l->hd()->code_class_nameTab(s);
  }
}

void CgenClassTable::code_class_objTab() {
  str << "class_objTab:" << endl;
  root()->code_class_objTab(str);
}

void CgenNode::code_class_objTab(ostream& s) { 
  s << WORD;
  emit_protobj_ref(name, s);
  s << endl;

  s << WORD;
  emit_init_ref(name, s);
  s << endl;

  for(List<CgenNode> *l = children; l; l = l->tl()) {
    l->hd()->code_class_objTab(s);
  }
}

void CgenClassTable::code_dispTabs(CgenNodeP p, std::vector<std::pair<Symbol, Symbol>> methods) 
{
  int num_methods = 0;
  Features features = p->get_features();
  for(int i = features->first(); features->more(i); i = features->next(i)) {
    if (features->nth(i)->get_feature_type() == "Method") {
      num_methods++;
      bool inherited = false;
      for (size_t j = 0; j<methods.size(); j++){
        if (methods[j] == std::make_pair(p->get_parent_name(), features->nth(i)->get_name())){
          methods[j] = std::make_pair(p->get_name(), features->nth(i)->get_name());
          inherited = true;
          break;
        }
      }
      if (!inherited)
        methods.push_back(std::make_pair(p->get_name(), features->nth(i)->get_name()));
    }
  }

  std::vector<Symbol>* method_names_p = new std::vector<Symbol>();
  auto method_names = *(method_names_p);
  for (auto method : methods) {
    Symbol *method_name = new Symbol(method.second);
    method_names.push_back(*method_name);
    // cerr << "HERE " << method.first << " " << *(method_name) << endl;
  }

  List<CgenNode> *children = p->get_children(); 
  // cerr << p->get_name() << endl;
  disp_tables[p->get_name()] = method_names;
  // for (auto i : method_names){
  //   cerr << i << endl;
  // }
  for(List<CgenNode> *l = children; l; l = l->tl()) {
    // cerr << l->hd()->get_name() << endl;
    // disp_tables[l->hd()->get_name()] = method_names;

    code_dispTabs(l->hd(), methods);
  }

  p->code_dispTab(str, methods);

  for(int i = 0; i < num_methods; i++) {
    methods.pop_back();
  }
}

void CgenNode::code_dispTab(ostream& s, std::vector<std::pair<Symbol, Symbol>> methods) 
{
  emit_disptable_ref(name, s);  //label
  s << ":" << endl;
  for(auto method : methods) { // method
    s << WORD;
    emit_method_ref(method.first, method.second, s);
    s << endl;
  }                                        
}

void CgenClassTable::code_object_inits(CgenNodeP p, int num_inherited_attributes, CgenClassTableP table) {
  filename = p->get_filename();
  int num_self_attributes = 0;
  p->code_object_init(str, num_inherited_attributes, num_self_attributes, table);

  List<CgenNode> *children = p->get_children(); 
  for(List<CgenNode> *l = children; l; l = l->tl()) {
    code_object_inits(l->hd(), (num_inherited_attributes + num_self_attributes), table);
  }
}

static void emit_jal_init(Symbol name, ostream &s)
{ s << JAL << name << CLASSINIT_SUFFIX << endl; }

void emit_method_setup(ostream& s) 
{
  // Move stack pointer down predefined 3 spaces
  emit_addiu(SP, SP, -12, s);
  // Don't let FP get clobbered
  emit_store(FP, 3, SP, s);
  // Don't let SELF get clobbered
  emit_store(SELF, 2, SP, s);
  // Store RA for when we return
  emit_store(RA, 1, SP, s);

  // Move FP down- we are starting a new frame
  // **Note: args are 12 + 4*n up from FP
  emit_addiu(FP, SP, 4, s);

  // Move self into SELF
  emit_move(SELF, ACC ,s);
}

void emit_method_cleanup(int n, ostream& s) 
{
  //re-load, RA, SELF, and FP
  emit_load(FP, 3, SP, s);
  emit_load(SELF, 2, SP, s);
  emit_load(RA, 1, SP, s);


  //calculate size of activation
  int z = 4*n + 12;

  //move stack pointer up past space that calle used, plus the arguments to the
  // that are right above where FP was stored
  emit_addiu(SP, SP, z, s);
  emit_return(s);

}

// Init methods are called after an object of type *name* is created on heap. Pointer o that object is in ACC
// We want to initilize all atttributes of the object with values from the init expressions
void CgenNode::code_object_init(ostream& s, int num_inherited_attributes, int& num_self_attributes, CgenClassTableP table) 
{
  //var_table->enterscope();
  table->new_env();
  table->var_count = 0;
  table->addid(SELF_TYPE, table->lookup(name));
  table->current_method = name;

  // Treat this like any other method call, no parameters
  emit_init_def(name, s);
  emit_method_setup(s);

  // Object is the root
  if (parentnd->get_name() != No_class)
    emit_jal_init(parentnd->get_name(), s);
 
  // Initialize all attributes of object
  if (basic_status == NotBasic) {
    for(int i = features->first(); features->more(i); i = features->next(i)) {
      Feature attribute = features->nth(i);
      if (attribute->get_feature_type() == "Attribute") {
        num_self_attributes++;
        attribute->code(table, s);

        // if (name == String && attribute->get_name() == _val) {
        //   emit
        // }

        // Return value of attribute is left in a0 (ACC). We want to store this value (which is always a reference to an object)
        // in the correct position in the object we are initializing. Initialization object reference is s0 (SELF).
        if (attribute->get_expr_type() != NULL) {
          emit_store(ACC, 2 + num_inherited_attributes + num_self_attributes, SELF, s);

          if (cgen_Memmgr == 1) {
            emit_addiu(A1, SELF, 4*(2 + num_inherited_attributes + num_self_attributes),s);
            emit_jal("_GenGC_Assign", s);
          }
        }
      }
    }
  }

  // When we leave this method, we want ACC to point to the object in the heap
  // We stored the object in SELF, so we put self back in AC because self is the return value of the init method
  emit_move(ACC, SELF, s);
  emit_method_cleanup(0, s);

  //var_table->exitscope();
}

void CgenClassTable::code_class_methods() {
  for(List<CgenNode> *l = nds; l; l = l->tl()) {
    filename = l->hd()->get_filename();
    l->hd()->code_class_method(this, str);
  }
}

void CgenNode::code_class_method(CgenClassTableP table, ostream& s) 
{
  if (basic_status == NotBasic) {
    for(int i = features->first(); features->more(i); i = features->next(i)) {
      Feature method = features->nth(i);
      if (method->get_feature_type() == "Method") {
        //var_table->enterscope();
        table->new_env();
        table->var_count = 0;
        table->addid(SELF_TYPE, table->lookup(name));
        table->current_method = method->get_name();

        // Emit label and method setup
        emit_method_def(name, method->get_name(), s);
        emit_method_setup(s);

        // Evaluate the expression of the method
        method->code(table, s);

        // Make sure to clean up parameters placed on stack by caller before we return
        int n = method->get_formals()->len();
        //cerr << name << " " << method->get_name() << " " << n << endl;
        emit_method_cleanup(n, s);

        //var_table->exitscope();
      }
    }
  } 
}


void CgenClassTable::code()
{
  if (cgen_debug) cout << "coding global data" << endl;
  code_global_data();

  if (cgen_debug) cout << "choosing gc" << endl;
  code_select_gc();

  if (cgen_debug) cout << "coding constants" << endl;
  code_constants();

  if (cgen_debug) cout << "coding prototype objects" << endl;
  code_protObjs(root(), std::vector<Feature>());

  if (cgen_debug) cout << "coding class name table" << endl;
  code_class_nameTab();

  if (cgen_debug) cout << "coding class object table" << endl;
  code_class_objTab();

  if (cgen_debug) cout << "coding dispatch tables" << endl;
  code_dispTabs(root(), std::vector<std::pair<Symbol, Symbol>>());

//                 Add your code to emit
//                   - prototype objects --check
//                   - class_nameTab --check
//                   - dispatch tables --check
//

  if (cgen_debug) cout << "coding global text" << endl;
  code_global_text();

  if (cgen_debug) cout << "coding object initializers" << endl;
  code_object_inits(root(), 0, this);

  if (cgen_debug) cout << "coding class methods" << endl;
  code_class_methods();

//                 Add your code to emit
//                   - object initializer --check
//                   - the class methods
//                   - etc...

}

CgenNodeP CgenClassTable::root()
{
   return probe(Object);
}


///////////////////////////////////////////////////////////////////////
//
// CgenNode methods
//
///////////////////////////////////////////////////////////////////////

CgenNode::CgenNode(Class_ nd, Basicness bstatus, CgenClassTableP ct) :
   class__class((const class__class &) *nd),
   parentnd(NULL),
   children(NULL),
   basic_status(bstatus)
{ 
   stringtable.add_string(name->get_string());          // Add class name to string table
}

int CgenNode::closest_ancestor(std::vector<Symbol> types) 
{
  for (size_t i = 0; i < types.size(); i++) {
    if (types[i] == name) {
      return i; 
    }
  }

  if (get_parent_name() != No_class) {
    return get_parentnd()->closest_ancestor(types);
  } else {
    return -1;
  }
  
  // CgenNode closest_ancestor = get_parentnd();

  // while (closest_ancestor->get_parent_name() != No_class) {
  //   closest_ancestor = closest_ancestor->get_parentnd();
  //   for (size_t i = 0; i < types.size(); i++) {
  //     if (types[i] == closest_ancestor->get_name()) {
  //       return i; 
  //     }
  //   }
  // }

  // return -1;
}

//******************************************************************
//
//   Fill in the following methods to produce code for the
//   appropriate expression.  You may add or remove parameters
//   as you wish, but if you do, remember to change the parameters
//   of the declarations in `cool-tree.h'  Sample code for
//   constant integers, strings, and booleans are provided.
//
//*****************************************************************

void assign_class::code(CgenClassTableP table, ostream &s) 
{
  // evaluate expression, 
  expr->code(table, s);

  // Next we lookup to see if this object is a variable in scope,
  // since variables in scope shadow everything else
  //if (var_table->probe(name) != NULL){
  if (table->var_table->find(name) != table->var_table->end() && (*table->var_table)[name].size() != 0){
    //int offset = *(var_table->probe(name));
    int offset = (*table->var_table)[name].back();
    emit_store(ACC,-offset,FP,s);
    return;
  }

  auto class_ = table->lookup(SELF_TYPE);
  Symbol type_name = class_->get_name();
    
  // Next we see if this object is a parameter,
  // since parameters shadow atrributes
  Method m(type_name, table->current_method);
  std::vector<Symbol> implementation = table->implementation_map[m];
  for (size_t i = 0; i < implementation.size(); i++) {
    if (name == implementation[i]){
      int pos = implementation.size() - 1 - i;
      emit_load(ACC,3 + pos,FP,s);
      return;
    }
  }

  // Finally, if the object is not a variable or formal, it must be an attribute
  if (table->class_map.find(type_name) != table->class_map.end()){
    std::vector<Symbol> v = table->class_map[type_name];
    for (size_t i = 0; i < v.size(); i++){
      if (name == v[i]){
        emit_store(ACC,3+i,SELF,s);
        if (cgen_Memmgr == 1) {
          emit_addiu(A1, SELF, 4*(3+i),s);
          emit_jal("_GenGC_Assign", s);
        }
        return;
      }
    }
  }
}

void static_dispatch_class::code(CgenClassTableP table, ostream &s) 
{
  //Push parameters onto stack, first is highest, last is lowest
  for (int i = actual->first(); actual->more(i); i = actual->next(i)) {
    //evaluate expr
    actual->nth(i)->code(table, s);

    // push object onto stack in preparation for method call
    emit_push(ACC, s);
  }

  // Evaluate e0 to get object we are dispatching on.
  // This object becomes self
  expr->code(table, s);

  // create label to dipatch to the method
  int dispatch = table->new_label();
  emit_bne(ACC, ZERO, dispatch, s);

  // Dispatch on a void, raise error
  emit_load_string(ACC, stringtable.lookup_string(table->filename->get_string()), s);
  emit_load_imm(T1, get_line_number(), s);
  emit_jal("_dispatch_abort", s);

  //Define label for dispatch code
  emit_label_def(dispatch, s);

  // load pointer to dispatch table
  // emit_load(T1, 2, ACC, s);
  emit_partial_load_address(T1, s);
  emit_disptable_ref(type_name,s);
  s << endl;

  // Find method offset in dipatch table
  Symbol expr_type = expr->get_type();
  if (expr_type == SELF_TYPE) {
    expr_type = (table->lookup(SELF_TYPE))->get_name();
  }
  auto method_names = table->disp_tables[type_name];
  // cerr << name << " "<< type_name << " " << expr_type << endl;
  size_t i;
  for (i = 0; i < method_names.size(); i++) {
    if (method_names[i] == name){
      // cerr << i << endl;
      break;
    }
  }

  // Load address of method code and jump there
  emit_load(T1, i, T1, s);
  emit_jalr(T1, s);
}

void dispatch_class::code(CgenClassTableP table, ostream &s) 
{
  //Push parameters onto stack, first is highest, last is lowest
  for (int i = actual->first(); actual->more(i); i = actual->next(i)) {
    //evaluate expr
    actual->nth(i)->code(table, s);

    // push object onto stack in preparation for method call
    emit_push(ACC, s);
  }

  // Evaluate e0 to get object we are dispatching on.
  // This object becomes self
  expr->code(table, s);

  // create label to dipatch to the method
  int dispatch = table->new_label();
  emit_bne(ACC, ZERO, dispatch, s);

  // Dispatch on a void, raise error
  emit_load_string(ACC, stringtable.lookup_string(table->filename->get_string()), s);
  emit_load_imm(T1, get_line_number(), s);
  emit_jal("_dispatch_abort", s);

  //Define label for dispatch code
  emit_label_def(dispatch, s);

  // load pointer to dispatch table
  emit_load(T1, 2, ACC, s);

  // Find method offset in dipatch table
  Symbol expr_type = expr->get_type();
  if (expr_type == SELF_TYPE) {
    expr_type = (table->lookup(SELF_TYPE))->get_name();
  }
  auto method_names = table->disp_tables[expr_type];

  //if (table->current_method == idtable.lookup_string("head")) {
  // cerr << table->current_method << " " << expr_type << endl;
  // for (auto method: method_names)
  //    cerr << method << endl;
  //    cerr << endl;
   //}

  size_t i;
  for (i = 0; i < method_names.size(); i++) {
    if (method_names[i] == name)
      break;
  }

  // Load address of method code and jump there
  emit_load(T1, i, T1, s);
  emit_jalr(T1, s);
}

void cond_class::code(CgenClassTableP table, ostream &s) 
{
  pred->code(table,s);

  emit_fetch_int(ACC, ACC, s);
  int label = table->new_label();
  emit_beqz(ACC, label, s );
  then_exp->code(table,s);

  int end = table->new_label();
  emit_branch(end,s);

  emit_label_def(label, s);
  else_exp->code(table,s);
  emit_label_def(end,s);

  // emit_(T1, BoolConst(0), s);
  // int false_branch = table->new_label();

  // emit_beq(ACC, T1, false_branch, s);

  // then_exp->code(table,s);

  // int end = table->new_label();
  // emit_branch(end,s);

  // emit_label_def(false_branch,s);
  // else_exp->code(table,s);

  // emit_label_def(end,s);
}

void loop_class::code(CgenClassTableP table, ostream &s) {
  int current_loop = table->new_label();
  emit_label_def(current_loop,s);

  pred->code(table,s);

  emit_load(ACC,3,ACC,s);
  int end_loop = table->new_label();
  emit_beq(ACC,ZERO,end_loop,s);

  body->code(table,s);

  emit_branch(current_loop,s);

  emit_label_def(end_loop,s);

  emit_move(ACC,ZERO,s);
}

void typcase_class::code(CgenClassTableP table, ostream &s) 
{
  // Evaluate expression
  expr->code(table, s);

  // create label to case statement
  int case_start = table->new_label();
  emit_bne(ACC, ZERO, case_start, s);

  // case on a void, raise error
  emit_load_string(ACC, stringtable.lookup_string(table->filename->get_string()), s);
  emit_load_imm(T1, get_line_number(), s);
  emit_jal("_case_abort2", s);

  emit_label_def(case_start, s);
  // Push object and Load class tag into ACC
  emit_push(ACC, s);
  table->var_count++;
  emit_load(ACC, 0, ACC, s);

  // label0 corresponds to the 1st branch, label1 to branch 2nd, etc.
  int label = 0;
  std::vector<int> labels;
  std::vector<Symbol> types;
  for(int i = cases->first(); cases->more(i); i = cases->next(i)) {
    types.push_back(cases->nth(i)->get_type());

    label = table->new_label();
    labels.push_back(label);
  }

  // we can build a table that has the closest 
  // ancestor for every class in the program
  // in the case statement. 
  // We will compare the classtag of dynamic type of expression 
  // to all possible classes and do a predetermined jump
  // to that class' branch
  for(List<CgenNode> *l = table->get_classes(); l; l = l->tl()) {

    // This returns the index of the closest ancenstor for class l
    // so we can get its label to jump to
    int idx = l->hd()->closest_ancestor(types);
    // cerr << l->hd()->get_name() << " " << idx << endl;
    // If we didnt find a closest ancestor in the case statement for class l,
    // then if the dynamic type is l we should raise an error
    if (idx != -1) {
      // compare the dynamic tag in ACC to all class tags
      int compare_tag = table->classTag_map[l->hd()->get_name()];
      // cerr << compare_tag << endl;

      emit_load_imm(T1, compare_tag, s);

      // emit_addiu(SP, SP, 4, s);
      // table->var_count--;
      // If we find a match, jump to that class' closest ancestor branch
      emit_beq(ACC, T1, labels[idx], s);

    }
  }

  // If we fall through all the class comparisons,
  // there is no match in the case statement so we throw a 
  // runtime error
  emit_load(ACC, 1, SP, s);
  emit_jal("_case_abort", s);


  // Code the branchz
  int j = 0;
  int end_case = table->new_label();
  for(int i = cases->first(); cases->more(i); i = cases->next(i)) {
    emit_label_def(labels[j], s);
    emit_load(ACC, 1, SP, s);
    j++;
    cases->nth(i)->code(table, s);
    emit_branch(end_case, s);
  }

  //cleanup this expression
  emit_label_def(end_case, s);
  emit_addiu(SP, SP, 4, s);
  table->var_count--;
}

void branch_class::code(CgenClassTableP table, ostream &s)
{
  // We are introducing a variable with init value ACC on the stack
  // We need to keep track of the offset from fp
  // the variable is placed, as well as which method 
  // has access to this variable
  table->var_count++;
  //int *offset = new int(table->var_count);
  //var_table->addid(name, offset);
  (*table->var_table)[name].push_back(table->var_count);
  emit_push(ACC, s);

  // Evaluate the expression of the branch
  expr->code(table, s);

  // Move SP back up since the variable is now out of scope
  emit_addiu(SP, SP, 4, s);
  (*table->var_table)[name].pop_back();
  table->var_count--;
}

void block_class::code(CgenClassTableP table, ostream &s) {
  for (int i = body->first(); body->more(i); i = body->next(i)) {
    body->nth(i)->code(table, s);
  }
}

void let_class::code(CgenClassTableP table, ostream &s) 
{

  // Evaluate init expression
  init->code(table, s);
  Symbol init_type = init->get_type();

  if(init_type == NULL) {
    emit_default_init(type_decl, s);
  }

  // We are introducing a variable on the stack
  // We need to keep track of the offset from fp
  // the variable is placed, as well as which method 
  // has access to this variable
  table->var_count++;
  //int *offset = new int(table->var_count);
  //var_table->addid(identifier, offset);
  (*table->var_table)[identifier].push_back(table->var_count);
  emit_push(ACC, s);

  // Evaluate the body
  body->code(table, s);

  // Move SP back up since the variable is now out of scope
  emit_addiu(SP, SP, 4, s);
  (*table->var_table)[identifier].pop_back();
  table->var_count--;
}

void plus_class::code(CgenClassTableP table, ostream &s) {
  //eval e1 and push result to stack
  e1->code(table, s);
  emit_push(ACC, s);
  table->var_count++;

  //eval e2 
  e2->code(table, s);

  // Get value within e2 int object
  emit_fetch_int(ACC, ACC, s);

  // Get value within e1 int object
  emit_load(T1, 1, SP, s);
  emit_fetch_int(T1, T1, s);

  //perform computation, push onto stack
  emit_add(T1, T1, ACC, s);
  emit_push(T1, s);
  table->var_count++;

  //load ACC with int object and create new int object on heap
  emit_load(ACC, 2, SP, s);
  emit_jal_method(Object, idtable.lookup_string("copy"), s);

  // Store sum in new int object
  emit_load(T1, 1, SP, s);
  emit_store_int(T1, ACC, s);

  //Return stack pointer to orginal location
  emit_addiu(SP, SP, 8, s);
  table->var_count--;
  table->var_count--;
  //ACC contains pointer to new object on heap
}

void sub_class::code(CgenClassTableP table, ostream &s) {
  //eval e1 and push result to stack
  e1->code(table, s);
  emit_push(ACC, s);
  table->var_count++;

  //eval e2 
  e2->code(table, s);

  // Get value within e2 int object
  emit_fetch_int(ACC, ACC, s);

  // Get value within e1 int object
  emit_load(T1, 1, SP, s);
  emit_fetch_int(T1, T1, s);

  //perform computation, push onto stack
  emit_sub(T1, T1, ACC, s);
  emit_push(T1, s);
  table->var_count++;

  //load ACC with int object and create new int object on heap
  emit_load(ACC, 2, SP, s);
  emit_jal_method(Object, idtable.lookup_string("copy"), s);

  // Store sum in new int object
  emit_load(T1, 1, SP, s);
  emit_store_int(T1, ACC, s);

  //Return stack pointer to orginal location
  emit_addiu(SP, SP, 8, s);
  table->var_count--;
  table->var_count--;

  //ACC contains pointer to new object on heap
}

void mul_class::code(CgenClassTableP table, ostream &s) {
  //eval e1 and push result to stack
  e1->code(table, s);
  emit_push(ACC, s);
  table->var_count++;

  //eval e2 
  e2->code(table, s);

  // Get value within e2 int object
  emit_fetch_int(ACC, ACC, s);

  // Get value within e1 int object
  emit_load(T1, 1, SP, s);
  emit_fetch_int(T1, T1, s);

  //perform computation, push onto stack
  emit_mul(T1, T1, ACC, s);
  emit_push(T1, s);
  table->var_count++;

  //load ACC with int object and create new int object on heap
  emit_load(ACC, 2, SP, s);
  emit_jal_method(Object, idtable.lookup_string("copy"), s);

  // Store sum in new int object
  emit_load(T1, 1, SP, s);
  emit_store_int(T1, ACC, s);

  //Return stack pointer to orginal location
  emit_addiu(SP, SP, 8, s);
  table->var_count--;
  table->var_count--;

  //ACC contains pointer to new object on heap
}

void divide_class::code(CgenClassTableP table, ostream &s) {
  //eval e1 and push result to stack
  e1->code(table, s);
  emit_push(ACC, s);
  table->var_count++;

  //eval e2 
  e2->code(table, s);

  // Get value within e2 int object
  emit_fetch_int(ACC, ACC, s);

  // Get value within e1 int object
  emit_load(T1, 1, SP, s);
  emit_fetch_int(T1, T1, s);

  //perform computation, push onto stack
  emit_div(T1, T1, ACC, s);
  emit_push(T1, s);
  table->var_count++;

  //load ACC with int object and create new int object on heap
  emit_load(ACC, 2, SP, s);
  emit_jal_method(Object, idtable.lookup_string("copy"), s);

  // Store sum in new int object
  emit_load(T1, 1, SP, s);
  emit_store_int(T1, ACC, s);

  //Return stack pointer to orginal location
  emit_addiu(SP, SP, 8, s);
  table->var_count--;
  table->var_count--;

  //ACC contains pointer to new object on heap
}

void neg_class::code(CgenClassTableP table, ostream &s) {
  e1->code(table, s);

  emit_jal_method(Object, idtable.lookup_string("copy"), s);
  emit_fetch_int(T1, ACC, s);
  emit_neg(T1, T1, s);
  emit_store_int(T1, ACC, s);
}

void lt_class::code(CgenClassTableP table, ostream &s) {
  e1->code(table,s);
  emit_push(ACC,s);
  table->var_count++;
  e2->code(table,s);

  emit_fetch_int(ACC, ACC, s);
  emit_load(T1,1,SP,s);
  emit_fetch_int(T1,T1,s);
  int true_label = table->new_label();
  emit_addiu(SP,SP,4,s);
  table->var_count--;
  emit_blt(T1,ACC,true_label,s);
  emit_load_bool(ACC, BoolConst(0), s);

  int end_lt = table->new_label();
  emit_branch(end_lt,s);

  emit_label_def(true_label,s);
  emit_load_bool(ACC, BoolConst(1), s);
  emit_label_def(end_lt,s);
}

void eq_class::code(CgenClassTableP table, ostream &s) {
  e1->code(table,s);
  //emit_move(T1, ACC, s);

  emit_push(ACC,s);
  table->var_count++;
  e2->code(table,s);

  emit_move(T2, ACC, s);
  emit_load(T1, 1, SP, s);


  emit_load_bool(ACC, BoolConst(1), s);

  int end_eq = table->new_label();  
  emit_beq(T1, T2, end_eq, s);

  // emit_fetch_int(T2, T2, s);
  // emit_fetch_int(T1, T1, s);

  emit_load_bool(A1, BoolConst(0), s);
  emit_jal("equality_test", s);
  emit_label_def(end_eq, s);
  emit_addiu(SP,SP,4,s);
  table->var_count--;
}

void leq_class::code(CgenClassTableP table, ostream &s) {
  e1->code(table,s);
  emit_push(ACC,s);
  table->var_count++;
  e2->code(table,s);

  emit_fetch_int(ACC, ACC, s);
  emit_load(T1,1,SP,s);
  emit_fetch_int(T1,T1,s);
  int true_label = table->new_label();
  emit_addiu(SP,SP,4,s);
  table->var_count--;
  emit_bleq(T1,ACC,true_label,s);
  emit_load_bool(ACC, BoolConst(0), s);

  int end_lt = table->new_label();
  emit_branch(end_lt,s);

  emit_label_def(true_label,s);
  emit_load_bool(ACC, BoolConst(1), s);
  emit_label_def(end_lt,s);
}

void comp_class::code(CgenClassTableP table, ostream &s) {
  e1->code(table, s);

  emit_fetch_int(T1,ACC,s);
  emit_load_bool(ACC, BoolConst(1), s);

  int end_comp = table->new_label();
  emit_beqz(T1, end_comp, s);

  emit_load_bool(ACC, BoolConst(0), s);
  emit_label_def(end_comp, s);
}

void int_const_class::code(CgenClassTableP table, ostream& s)  
{
  //
  // Need to be sure we have an IntEntry *, not an arbitrary Symbol
  //
  if (true)
    emit_load_int(ACC,inttable.lookup_string(token->get_string()),s);
}

void string_const_class::code(CgenClassTableP table, ostream& s)
{
  if (true)
    emit_load_string(ACC,stringtable.lookup_string(token->get_string()),s);
}

void bool_const_class::code(CgenClassTableP table, ostream& s)
{
  emit_load_bool(ACC, BoolConst(val), s);
}

void new__class::code(CgenClassTableP table, ostream &s) 
{
  Symbol new_type = table->lookup(type_name)->get_name(); 

  emit_partial_load_address(ACC, s);
  emit_protobj_ref(new_type, s);
  s << endl;
  emit_jal_method(Object, idtable.lookup_string("copy"), s);
  emit_partial_jal(s);
  emit_init_ref(new_type, s);
  s << endl;
}

void isvoid_class::code(CgenClassTableP table, ostream &s) {
  e1->code(table, s);
  
  emit_move(T1, ACC, s);
  emit_load_bool(ACC, BoolConst(1), s);

  int end_isvoid = table->new_label();
  emit_beqz(T1, end_isvoid, s);

  emit_load_bool(ACC, BoolConst(0), s);
  emit_label_def(end_isvoid, s);
}

void no_expr_class::code(CgenClassTableP table, ostream &s) {
}

void object_class::code(CgenClassTableP table, ostream &s) 
{
  // If the object is self, just move SELF into ACC
  if (name == self) {
    emit_move(ACC, SELF, s);
    return;
  }

  // Next we lookup to see if this object is a variable in scope,
  // since variables in scope shadow everything else
  //if (var_table->probe(name) != NULL){
  if (table->var_table->find(name) != table->var_table->end() && (*table->var_table)[name].size() != 0){
    //int offset = *(var_table->probe(name));
    int offset = (*table->var_table)[name].back();
    emit_load(ACC,-offset,FP,s);
    return;
  }

  auto class_ = table->lookup(SELF_TYPE);
  Symbol type_name = class_->get_name();
    
  // Next we see if this object is a parameter,
  // since parameters shadow atrributes
  Method m(type_name, table->current_method);
  std::vector<Symbol> implementation = table->implementation_map[m];
  for (size_t i = 0; i < implementation.size(); i++) {
    if (name == implementation[i]){
      int pos = implementation.size() - 1 - i;
      emit_load(ACC,3 + pos,FP,s);
      return;
    }
  }

  // Finally, if the object is not a variable or formal, it must be an attribute
  if (table->class_map.find(type_name) != table->class_map.end()){
    std::vector<Symbol> v = table->class_map[type_name];
    for (size_t i = 0; i < v.size(); i++){
      if (name == v[i]){
        emit_load(ACC,3+i,SELF,s);
        return;
      }
    }
  }
}


