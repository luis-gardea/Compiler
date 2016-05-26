# start of generated code
	.data
	.align	2
	.globl	class_nameTab
	.globl	Main_protObj
	.globl	Int_protObj
	.globl	String_protObj
	.globl	bool_const0
	.globl	bool_const1
	.globl	_int_tag
	.globl	_bool_tag
	.globl	_string_tag
_int_tag:
	.word	2
_bool_tag:
	.word	3
_string_tag:
	.word	4
	.globl	_MemMgr_INITIALIZER
_MemMgr_INITIALIZER:
	.word	_NoGC_Init
	.globl	_MemMgr_COLLECTOR
_MemMgr_COLLECTOR:
	.word	_NoGC_Collect
	.globl	_MemMgr_TEST
_MemMgr_TEST:
	.word	0
	.word	-1
str_const71:
	.word	4
	.word	5
	.word	String_dispTab
	.word	int_const10
	.byte	0	
	.align	2
	.word	-1
str_const70:
	.word	4
	.word	6
	.word	String_dispTab
	.word	int_const4
	.ascii	"Main"
	.byte	0	
	.align	2
	.word	-1
str_const69:
	.word	4
	.word	9
	.word	String_dispTab
	.word	int_const21
	.ascii	"CellularAutomaton"
	.byte	0	
	.align	2
	.word	-1
str_const68:
	.word	4
	.word	6
	.word	String_dispTab
	.word	int_const2
	.ascii	"Board"
	.byte	0	
	.align	2
	.word	-1
str_const67:
	.word	4
	.word	6
	.word	String_dispTab
	.word	int_const13
	.ascii	"String"
	.byte	0	
	.align	2
	.word	-1
str_const66:
	.word	4
	.word	6
	.word	String_dispTab
	.word	int_const4
	.ascii	"Bool"
	.byte	0	
	.align	2
	.word	-1
str_const65:
	.word	4
	.word	5
	.word	String_dispTab
	.word	int_const1
	.ascii	"Int"
	.byte	0	
	.align	2
	.word	-1
str_const64:
	.word	4
	.word	5
	.word	String_dispTab
	.word	int_const12
	.ascii	"IO"
	.byte	0	
	.align	2
	.word	-1
str_const63:
	.word	4
	.word	6
	.word	String_dispTab
	.word	int_const13
	.ascii	"Object"
	.byte	0	
	.align	2
	.word	-1
str_const62:
	.word	4
	.word	7
	.word	String_dispTab
	.word	int_const16
	.ascii	"_prim_slot"
	.byte	0	
	.align	2
	.word	-1
str_const61:
	.word	4
	.word	7
	.word	String_dispTab
	.word	int_const15
	.ascii	"SELF_TYPE"
	.byte	0	
	.align	2
	.word	-1
str_const60:
	.word	4
	.word	7
	.word	String_dispTab
	.word	int_const15
	.ascii	"_no_class"
	.byte	0	
	.align	2
	.word	-1
str_const59:
	.word	4
	.word	8
	.word	String_dispTab
	.word	int_const19
	.ascii	"<basic class>"
	.byte	0	
	.align	2
	.word	-1
str_const58:
	.word	4
	.word	16
	.word	String_dispTab
	.word	int_const24
	.ascii	"There are many initial states to choose from. \n"
	.byte	0	
	.align	2
	.word	-1
str_const57:
	.word	4
	.word	12
	.word	String_dispTab
	.word	int_const25
	.ascii	"Welcome to the Game of Life.\n"
	.byte	0	
	.align	2
	.word	-1
str_const56:
	.word	4
	.word	5
	.word	String_dispTab
	.word	int_const11
	.ascii	"y"
	.byte	0	
	.align	2
	.word	-1
str_const55:
	.word	4
	.word	17
	.word	String_dispTab
	.word	int_const26
	.ascii	"Please use lowercase y or n for your answer [n]: "
	.byte	0	
	.align	2
	.word	-1
str_const54:
	.word	4
	.word	17
	.word	String_dispTab
	.word	int_const27
	.ascii	"Would you like to choose a background pattern? \n"
	.byte	0	
	.align	2
	.word	-1
str_const53:
	.word	4
	.word	5
	.word	String_dispTab
	.word	int_const12
	.ascii	"\n\n"
	.byte	0	
	.align	2
	.word	-1
str_const52:
	.word	4
	.word	5
	.word	String_dispTab
	.word	int_const11
	.ascii	"n"
	.byte	0	
	.align	2
	.word	-1
str_const51:
	.word	4
	.word	17
	.word	String_dispTab
	.word	int_const26
	.ascii	"Please use lowercase y or n for your answer [y]: "
	.byte	0	
	.align	2
	.word	-1
str_const50:
	.word	4
	.word	18
	.word	String_dispTab
	.word	int_const28
	.ascii	"Would you like to continue with the next generation? \n"
	.byte	0	
	.align	2
	.word	-1
str_const49:
	.word	4
	.word	11
	.word	String_dispTab
	.word	int_const8
	.ascii	"                         "
	.byte	0	
	.align	2
	.word	-1
str_const48:
	.word	4
	.word	12
	.word	String_dispTab
	.word	int_const9
	.ascii	" XXXX   X    XX    X   XXXX "
	.byte	0	
	.align	2
	.word	-1
str_const47:
	.word	4
	.word	12
	.word	String_dispTab
	.word	int_const9
	.ascii	" XX X  XX  X XX X  XX  X XX "
	.byte	0	
	.align	2
	.word	-1
str_const46:
	.word	4
	.word	9
	.word	String_dispTab
	.word	int_const3
	.ascii	" XX X  XX  X XX "
	.byte	0	
	.align	2
	.word	-1
str_const45:
	.word	4
	.word	12
	.word	String_dispTab
	.word	int_const9
	.ascii	"XXX    X   X  X    X   XXXX "
	.byte	0	
	.align	2
	.word	-1
str_const44:
	.word	4
	.word	12
	.word	String_dispTab
	.word	int_const9
	.ascii	"XXXXX   X   XXXXX   X   XXXX"
	.byte	0	
	.align	2
	.word	-1
str_const43:
	.word	4
	.word	10
	.word	String_dispTab
	.word	int_const6
	.ascii	"  X X   X X X X     X"
	.byte	0	
	.align	2
	.word	-1
str_const42:
	.word	4
	.word	10
	.word	String_dispTab
	.word	int_const6
	.ascii	"X     X X X X   X X  "
	.byte	0	
	.align	2
	.word	-1
str_const41:
	.word	4
	.word	11
	.word	String_dispTab
	.word	int_const8
	.ascii	"  X    X  XXXXX  X    X  "
	.byte	0	
	.align	2
	.word	-1
str_const40:
	.word	4
	.word	11
	.word	String_dispTab
	.word	int_const8
	.ascii	"XXXXX  X    X    X    X  "
	.byte	0	
	.align	2
	.word	-1
str_const39:
	.word	4
	.word	11
	.word	String_dispTab
	.word	int_const8
	.ascii	"XXXXXXXXXXXXXXXXXXXXXXXXX"
	.byte	0	
	.align	2
	.word	-1
str_const38:
	.word	4
	.word	8
	.word	String_dispTab
	.word	int_const0
	.ascii	"X X X X X X X X"
	.byte	0	
	.align	2
	.word	-1
str_const37:
	.word	4
	.word	8
	.word	String_dispTab
	.word	int_const0
	.ascii	"  X   X X X   X"
	.byte	0	
	.align	2
	.word	-1
str_const36:
	.word	4
	.word	8
	.word	String_dispTab
	.word	int_const0
	.ascii	"X   X X X   X  "
	.byte	0	
	.align	2
	.word	-1
str_const35:
	.word	4
	.word	10
	.word	String_dispTab
	.word	int_const5
	.ascii	" X  XX  X  X  X     "
	.byte	0	
	.align	2
	.word	-1
str_const34:
	.word	4
	.word	10
	.word	String_dispTab
	.word	int_const5
	.ascii	"X  X  X  XX  X      "
	.byte	0	
	.align	2
	.word	-1
str_const33:
	.word	4
	.word	11
	.word	String_dispTab
	.word	int_const8
	.ascii	"    X   X   X     X     X"
	.byte	0	
	.align	2
	.word	-1
str_const32:
	.word	4
	.word	11
	.word	String_dispTab
	.word	int_const8
	.ascii	"X     X     X   X   X    "
	.byte	0	
	.align	2
	.word	-1
str_const31:
	.word	4
	.word	11
	.word	String_dispTab
	.word	int_const8
	.ascii	"X   X X X   X   X X X   X"
	.byte	0	
	.align	2
	.word	-1
str_const30:
	.word	4
	.word	11
	.word	String_dispTab
	.word	int_const8
	.ascii	"X     X     X     X     X"
	.byte	0	
	.align	2
	.word	-1
str_const29:
	.word	4
	.word	11
	.word	String_dispTab
	.word	int_const8
	.ascii	"    X   X   X   X   X    "
	.byte	0	
	.align	2
	.word	-1
str_const28:
	.word	4
	.word	10
	.word	String_dispTab
	.word	int_const5
	.ascii	" XX  XXXX XXXX  XX  "
	.byte	0	
	.align	2
	.word	-1
str_const27:
	.word	4
	.word	8
	.word	String_dispTab
	.word	int_const0
	.ascii	"Your choice => "
	.byte	0	
	.align	2
	.word	-1
str_const26:
	.word	4
	.word	8
	.word	String_dispTab
	.word	int_const18
	.ascii	"\t21: An 'S'\n"
	.byte	0	
	.align	2
	.word	-1
str_const25:
	.word	4
	.word	8
	.word	String_dispTab
	.word	int_const18
	.ascii	"\t20: An '8'\n"
	.byte	0	
	.align	2
	.word	-1
str_const24:
	.word	4
	.word	8
	.word	String_dispTab
	.word	int_const18
	.ascii	"\t19: An 'O'\n"
	.byte	0	
	.align	2
	.word	-1
str_const23:
	.word	4
	.word	7
	.word	String_dispTab
	.word	int_const17
	.ascii	"\t18: A '3'\n"
	.byte	0	
	.align	2
	.word	-1
str_const22:
	.word	4
	.word	8
	.word	String_dispTab
	.word	int_const18
	.ascii	"\t17: An 'E'\n"
	.byte	0	
	.align	2
	.word	-1
str_const21:
	.word	4
	.word	8
	.word	String_dispTab
	.word	int_const18
	.ascii	"\t16: An 'M'\n"
	.byte	0	
	.align	2
	.word	-1
str_const20:
	.word	4
	.word	7
	.word	String_dispTab
	.word	int_const17
	.ascii	"\t15: A 'W'\n"
	.byte	0	
	.align	2
	.word	-1
str_const19:
	.word	4
	.word	9
	.word	String_dispTab
	.word	int_const3
	.ascii	"\t14: A plus '+'\n"
	.byte	0	
	.align	2
	.word	-1
str_const18:
	.word	4
	.word	7
	.word	String_dispTab
	.word	int_const17
	.ascii	"\t13: A 'T'\n"
	.byte	0	
	.align	2
	.word	-1
str_const17:
	.word	4
	.word	9
	.word	String_dispTab
	.word	int_const21
	.ascii	"\t12: A full grid\n"
	.byte	0	
	.align	2
	.word	-1
str_const16:
	.word	4
	.word	12
	.word	String_dispTab
	.word	int_const29
	.ascii	"\t11: Numbers 9 and 10 combined\n"
	.byte	0	
	.align	2
	.word	-1
str_const15:
	.word	4
	.word	10
	.word	String_dispTab
	.word	int_const5
	.ascii	"\t10: An inverse 'V'\n"
	.byte	0	
	.align	2
	.word	-1
str_const14:
	.word	4
	.word	7
	.word	String_dispTab
	.word	int_const16
	.ascii	"\t9: A 'V'\n"
	.byte	0	
	.align	2
	.word	-1
str_const13:
	.word	4
	.word	11
	.word	String_dispTab
	.word	int_const30
	.ascii	"\t8: Two less than signs\n"
	.byte	0	
	.align	2
	.word	-1
str_const12:
	.word	4
	.word	11
	.word	String_dispTab
	.word	int_const31
	.ascii	"\t7: Two greater than signs\n"
	.byte	0	
	.align	2
	.word	-1
str_const11:
	.word	4
	.word	10
	.word	String_dispTab
	.word	int_const6
	.ascii	"\t6: A less than sign\n"
	.byte	0	
	.align	2
	.word	-1
str_const10:
	.word	4
	.word	11
	.word	String_dispTab
	.word	int_const8
	.ascii	"\t5: A greater than sign \n"
	.byte	0	
	.align	2
	.word	-1
str_const9:
	.word	4
	.word	7
	.word	String_dispTab
	.word	int_const15
	.ascii	"\t4: An X\n"
	.byte	0	
	.align	2
	.word	-1
str_const8:
	.word	4
	.word	16
	.word	String_dispTab
	.word	int_const24
	.ascii	"\t3: A slash from the upper right to lower left\n"
	.byte	0	
	.align	2
	.word	-1
str_const7:
	.word	4
	.word	16
	.word	String_dispTab
	.word	int_const24
	.ascii	"\t2: A slash from the upper left to lower right\n"
	.byte	0	
	.align	2
	.word	-1
str_const6:
	.word	4
	.word	8
	.word	String_dispTab
	.word	int_const18
	.ascii	"\t1: A cross\n"
	.byte	0	
	.align	2
	.word	-1
str_const5:
	.word	4
	.word	11
	.word	String_dispTab
	.word	int_const30
	.ascii	"\nPlease chose a number:\n"
	.byte	0	
	.align	2
	.word	-1
str_const4:
	.word	4
	.word	5
	.word	String_dispTab
	.word	int_const11
	.ascii	"-"
	.byte	0	
	.align	2
	.word	-1
str_const3:
	.word	4
	.word	5
	.word	String_dispTab
	.word	int_const11
	.ascii	"X"
	.byte	0	
	.align	2
	.word	-1
str_const2:
	.word	4
	.word	5
	.word	String_dispTab
	.word	int_const11
	.ascii	" "
	.byte	0	
	.align	2
	.word	-1
str_const1:
	.word	4
	.word	5
	.word	String_dispTab
	.word	int_const11
	.ascii	"\n"
	.byte	0	
	.align	2
	.word	-1
str_const0:
	.word	4
	.word	8
	.word	String_dispTab
	.word	int_const19
	.ascii	"tests/life.cl"
	.byte	0	
	.align	2
	.word	-1
int_const31:
	.word	2
	.word	4
	.word	Int_dispTab
	.word	27
	.word	-1
int_const30:
	.word	2
	.word	4
	.word	Int_dispTab
	.word	24
	.word	-1
int_const29:
	.word	2
	.word	4
	.word	Int_dispTab
	.word	31
	.word	-1
int_const28:
	.word	2
	.word	4
	.word	Int_dispTab
	.word	54
	.word	-1
int_const27:
	.word	2
	.word	4
	.word	Int_dispTab
	.word	48
	.word	-1
int_const26:
	.word	2
	.word	4
	.word	Int_dispTab
	.word	49
	.word	-1
int_const25:
	.word	2
	.word	4
	.word	Int_dispTab
	.word	29
	.word	-1
int_const24:
	.word	2
	.word	4
	.word	Int_dispTab
	.word	47
	.word	-1
int_const23:
	.word	2
	.word	4
	.word	Int_dispTab
	.word	19
	.word	-1
int_const22:
	.word	2
	.word	4
	.word	Int_dispTab
	.word	18
	.word	-1
int_const21:
	.word	2
	.word	4
	.word	Int_dispTab
	.word	17
	.word	-1
int_const20:
	.word	2
	.word	4
	.word	Int_dispTab
	.word	14
	.word	-1
int_const19:
	.word	2
	.word	4
	.word	Int_dispTab
	.word	13
	.word	-1
int_const18:
	.word	2
	.word	4
	.word	Int_dispTab
	.word	12
	.word	-1
int_const17:
	.word	2
	.word	4
	.word	Int_dispTab
	.word	11
	.word	-1
int_const16:
	.word	2
	.word	4
	.word	Int_dispTab
	.word	10
	.word	-1
int_const15:
	.word	2
	.word	4
	.word	Int_dispTab
	.word	9
	.word	-1
int_const14:
	.word	2
	.word	4
	.word	Int_dispTab
	.word	8
	.word	-1
int_const13:
	.word	2
	.word	4
	.word	Int_dispTab
	.word	6
	.word	-1
int_const12:
	.word	2
	.word	4
	.word	Int_dispTab
	.word	2
	.word	-1
int_const11:
	.word	2
	.word	4
	.word	Int_dispTab
	.word	1
	.word	-1
int_const10:
	.word	2
	.word	4
	.word	Int_dispTab
	.word	0
	.word	-1
int_const9:
	.word	2
	.word	4
	.word	Int_dispTab
	.word	28
	.word	-1
int_const8:
	.word	2
	.word	4
	.word	Int_dispTab
	.word	25
	.word	-1
int_const7:
	.word	2
	.word	4
	.word	Int_dispTab
	.word	7
	.word	-1
int_const6:
	.word	2
	.word	4
	.word	Int_dispTab
	.word	21
	.word	-1
int_const5:
	.word	2
	.word	4
	.word	Int_dispTab
	.word	20
	.word	-1
int_const4:
	.word	2
	.word	4
	.word	Int_dispTab
	.word	4
	.word	-1
int_const3:
	.word	2
	.word	4
	.word	Int_dispTab
	.word	16
	.word	-1
int_const2:
	.word	2
	.word	4
	.word	Int_dispTab
	.word	5
	.word	-1
int_const1:
	.word	2
	.word	4
	.word	Int_dispTab
	.word	3
	.word	-1
int_const0:
	.word	2
	.word	4
	.word	Int_dispTab
	.word	15
	.word	-1
bool_const0:
	.word	3
	.word	4
	.word	Bool_dispTab
	.word	0
	.word	-1
bool_const1:
	.word	3
	.word	4
	.word	Bool_dispTab
	.word	1
	.word	-1
Main_protObj:
	.word	4
	.word	8
	.word	Main_dispTab
	.word	int_const10
	.word	int_const10
	.word	int_const10
	.word	str_const71
	.word	0
	.word	-1
CellularAutomaton_protObj:
	.word	3
	.word	7
	.word	CellularAutomaton_dispTab
	.word	int_const10
	.word	int_const10
	.word	int_const10
	.word	str_const71
	.word	-1
Board_protObj:
	.word	2
	.word	6
	.word	Board_dispTab
	.word	int_const10
	.word	int_const10
	.word	int_const10
	.word	-1
IO_protObj:
	.word	1
	.word	3
	.word	IO_dispTab
	.word	-1
Int_protObj:
	.word	5
	.word	4
	.word	Int_dispTab
	.word	0
	.word	-1
Bool_protObj:
	.word	6
	.word	4
	.word	Bool_dispTab
	.word	0
	.word	-1
String_protObj:
	.word	7
	.word	5
	.word	String_dispTab
	.word	int_const10
	.word	0
	.word	-1
Object_protObj:
	.word	0
	.word	3
	.word	Object_dispTab
class_nameTab:
	.word	str_const63
	.word	str_const64
	.word	str_const68
	.word	str_const69
	.word	str_const70
	.word	str_const65
	.word	str_const66
	.word	str_const67
class_objTab:
	.word	Object_protObj
	.word	Object_init
	.word	IO_protObj
	.word	IO_init
	.word	Board_protObj
	.word	Board_init
	.word	CellularAutomaton_protObj
	.word	CellularAutomaton_init
	.word	Main_protObj
	.word	Main_init
	.word	Int_protObj
	.word	Int_init
	.word	Bool_protObj
	.word	Bool_init
	.word	String_protObj
	.word	String_init
Main_dispTab:
	.word	Object.abort
	.word	Object.type_name
	.word	Object.copy
	.word	IO.out_string
	.word	IO.out_int
	.word	IO.in_string
	.word	IO.in_int
	.word	Board.size_of_board
	.word	Board.board_init
	.word	CellularAutomaton.init
	.word	CellularAutomaton.print
	.word	CellularAutomaton.num_cells
	.word	CellularAutomaton.cell
	.word	CellularAutomaton.north
	.word	CellularAutomaton.south
	.word	CellularAutomaton.east
	.word	CellularAutomaton.west
	.word	CellularAutomaton.northwest
	.word	CellularAutomaton.northeast
	.word	CellularAutomaton.southeast
	.word	CellularAutomaton.southwest
	.word	CellularAutomaton.neighbors
	.word	CellularAutomaton.cell_at_next_evolution
	.word	CellularAutomaton.evolve
	.word	CellularAutomaton.option
	.word	CellularAutomaton.prompt
	.word	CellularAutomaton.prompt2
	.word	Main.main
CellularAutomaton_dispTab:
	.word	Object.abort
	.word	Object.type_name
	.word	Object.copy
	.word	IO.out_string
	.word	IO.out_int
	.word	IO.in_string
	.word	IO.in_int
	.word	Board.size_of_board
	.word	Board.board_init
	.word	CellularAutomaton.init
	.word	CellularAutomaton.print
	.word	CellularAutomaton.num_cells
	.word	CellularAutomaton.cell
	.word	CellularAutomaton.north
	.word	CellularAutomaton.south
	.word	CellularAutomaton.east
	.word	CellularAutomaton.west
	.word	CellularAutomaton.northwest
	.word	CellularAutomaton.northeast
	.word	CellularAutomaton.southeast
	.word	CellularAutomaton.southwest
	.word	CellularAutomaton.neighbors
	.word	CellularAutomaton.cell_at_next_evolution
	.word	CellularAutomaton.evolve
	.word	CellularAutomaton.option
	.word	CellularAutomaton.prompt
	.word	CellularAutomaton.prompt2
Board_dispTab:
	.word	Object.abort
	.word	Object.type_name
	.word	Object.copy
	.word	IO.out_string
	.word	IO.out_int
	.word	IO.in_string
	.word	IO.in_int
	.word	Board.size_of_board
	.word	Board.board_init
IO_dispTab:
	.word	Object.abort
	.word	Object.type_name
	.word	Object.copy
	.word	IO.out_string
	.word	IO.out_int
	.word	IO.in_string
	.word	IO.in_int
Int_dispTab:
	.word	Object.abort
	.word	Object.type_name
	.word	Object.copy
Bool_dispTab:
	.word	Object.abort
	.word	Object.type_name
	.word	Object.copy
String_dispTab:
	.word	Object.abort
	.word	Object.type_name
	.word	Object.copy
	.word	String.length
	.word	String.concat
	.word	String.substr
Object_dispTab:
	.word	Object.abort
	.word	Object.type_name
	.word	Object.copy
	.globl	heap_start
heap_start:
	.word	0
	.text
	.globl	Main_init
	.globl	Int_init
	.globl	String_init
	.globl	Bool_init
	.globl	Main.main
Object_init:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	move	$a0 $s0
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 12
	jr	$ra	
IO_init:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	jal	Object_init
	move	$a0 $s0
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 12
	jr	$ra	
Board_init:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	jal	IO_init
	move	$a0 $s0
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 12
	jr	$ra	
CellularAutomaton_init:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	jal	Board_init
	move	$a0 $s0
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 12
	jr	$ra	
Main_init:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	jal	CellularAutomaton_init
	move	$a0 $s0
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 12
	jr	$ra	
Int_init:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	jal	Object_init
	move	$a0 $s0
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 12
	jr	$ra	
Bool_init:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	jal	Object_init
	move	$a0 $s0
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 12
	jr	$ra	
String_init:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	jal	Object_init
	move	$a0 $s0
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 12
	jr	$ra	
Main.main:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	la	$a0 bool_const0
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 str_const71
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 str_const57
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label1
	la	$a0 str_const0
	li	$t1 412
	jal	_dispatch_abort
label1:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	la	$a0 str_const58
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label2
	la	$a0 str_const0
	li	$t1 413
	jal	_dispatch_abort
label2:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
label3:
	move	$a0 $s0
	bne	$a0 $zero label4
	la	$a0 str_const0
	li	$t1 414
	jal	_dispatch_abort
label4:
	lw	$t1 8($a0)
	lw	$t1 104($t1)
	jalr		$t1
	lw	$t1 12($a0)
	beq	$t1 $zero label5
	la	$a0 bool_const1
	sw	$a0 -4($fp)
	move	$a0 $s0
	bne	$a0 $zero label6
	la	$a0 str_const0
	li	$t1 417
	jal	_dispatch_abort
label6:
	lw	$t1 8($a0)
	lw	$t1 96($t1)
	jalr		$t1
	sw	$a0 -8($fp)
	lw	$a0 -8($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 CellularAutomaton_protObj
	jal	Object.copy
	jal	CellularAutomaton_init
	bne	$a0 $zero label7
	la	$a0 str_const0
	li	$t1 418
	jal	_dispatch_abort
label7:
	lw	$t1 8($a0)
	lw	$t1 36($t1)
	jalr		$t1
	sw	$a0 28($s0)
	lw	$a0 28($s0)
	bne	$a0 $zero label8
	la	$a0 str_const0
	li	$t1 419
	jal	_dispatch_abort
label8:
	lw	$t1 8($a0)
	lw	$t1 40($t1)
	jalr		$t1
label9:
	lw	$a0 -4($fp)
	lw	$t1 12($a0)
	beq	$t1 $zero label10
	move	$a0 $s0
	bne	$a0 $zero label11
	la	$a0 str_const0
	li	$t1 421
	jal	_dispatch_abort
label11:
	lw	$t1 8($a0)
	lw	$t1 100($t1)
	jalr		$t1
	la	$t1 bool_const0
	beq	$a0 $t1 label12
	lw	$a0 28($s0)
	bne	$a0 $zero label13
	la	$a0 str_const0
	li	$t1 423
	jal	_dispatch_abort
label13:
	lw	$t1 8($a0)
	lw	$t1 92($t1)
	jalr		$t1
	lw	$a0 28($s0)
	bne	$a0 $zero label14
	la	$a0 str_const0
	li	$t1 424
	jal	_dispatch_abort
label14:
	lw	$t1 8($a0)
	lw	$t1 40($t1)
	jalr		$t1
	b	label15
label12:
	la	$a0 bool_const0
	sw	$a0 -4($fp)
label15:
	b	label9
label10:
	move	$a0 $zero
	b	label3
label5:
	move	$a0 $zero
	move	$a0 $s0
	addiu	$sp $sp 4
	addiu	$sp $sp 4
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 12
	jr	$ra	
CellularAutomaton.init:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	lw	$a0 12($fp)
	sw	$a0 24($s0)
	lw	$a0 12($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label16
	la	$a0 str_const0
	li	$t1 116
	jal	_dispatch_abort
label16:
	lw	$t1 8($a0)
	lw	$t1 32($t1)
	jalr		$t1
	move	$a0 $s0
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 16
	jr	$ra	
CellularAutomaton.print:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	la	$a0 int_const10
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 20($s0)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 str_const1
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label17
	la	$a0 str_const0
	li	$t1 129
	jal	_dispatch_abort
label17:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
label18:
	lw	$a0 -4($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 -8($fp)
	lw	$a0 12($a0)
	lw	$t1 4($sp)
	lw	$t1 12($t1)
	addiu	$sp $sp 4
	blt	$t1 $a0 label19
	la	$a0 bool_const0
	b	label20
label19:
	la	$a0 bool_const1
label20:
	lw	$t1 12($a0)
	beq	$t1 $zero label21
	lw	$a0 -4($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 16($s0)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 24($s0)
	bne	$a0 $zero label22
	la	$a0 str_const0
	li	$t1 132
	jal	_dispatch_abort
label22:
	lw	$t1 8($a0)
	lw	$t1 20($t1)
	jalr		$t1
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label23
	la	$a0 str_const0
	li	$t1 132
	jal	_dispatch_abort
label23:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	la	$a0 str_const1
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label24
	la	$a0 str_const0
	li	$t1 133
	jal	_dispatch_abort
label24:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	lw	$a0 -4($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 16($s0)
	lw	$a0 12($a0)
	lw	$t1 4($sp)
	lw	$t1 12($t1)
	add	$t1 $t1 $a0
	sw	$t1 0($sp)
	addiu	$sp $sp -4
	lw	$a0 8($sp)
	jal	Object.copy
	lw	$t1 4($sp)
	sw	$t1 12($a0)
	addiu	$sp $sp 8
	sw	$a0 -4($fp)
	b	label18
label21:
	move	$a0 $zero
	la	$a0 str_const1
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label25
	la	$a0 str_const0
	li	$t1 137
	jal	_dispatch_abort
label25:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	move	$a0 $s0
	addiu	$sp $sp 4
	addiu	$sp $sp 4
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 12
	jr	$ra	
CellularAutomaton.num_cells:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	lw	$a0 24($s0)
	bne	$a0 $zero label26
	la	$a0 str_const0
	li	$t1 144
	jal	_dispatch_abort
label26:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 12
	jr	$ra	
CellularAutomaton.cell:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	lw	$a0 20($s0)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 int_const11
	lw	$a0 12($a0)
	lw	$t1 4($sp)
	lw	$t1 12($t1)
	sub	$t1 $t1 $a0
	sw	$t1 0($sp)
	addiu	$sp $sp -4
	lw	$a0 8($sp)
	jal	Object.copy
	lw	$t1 4($sp)
	sw	$t1 12($a0)
	addiu	$sp $sp 8
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 12($fp)
	lw	$a0 12($a0)
	lw	$t1 4($sp)
	lw	$t1 12($t1)
	addiu	$sp $sp 4
	blt	$t1 $a0 label27
	la	$a0 bool_const0
	b	label28
label27:
	la	$a0 bool_const1
label28:
	la	$t1 bool_const0
	beq	$a0 $t1 label29
	la	$a0 str_const2
	b	label30
label29:
	lw	$a0 12($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 int_const11
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 24($s0)
	bne	$a0 $zero label31
	la	$a0 str_const0
	li	$t1 151
	jal	_dispatch_abort
label31:
	lw	$t1 8($a0)
	lw	$t1 20($t1)
	jalr		$t1
label30:
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 16
	jr	$ra	
CellularAutomaton.north:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	lw	$a0 12($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 16($s0)
	lw	$a0 12($a0)
	lw	$t1 4($sp)
	lw	$t1 12($t1)
	sub	$t1 $t1 $a0
	sw	$t1 0($sp)
	addiu	$sp $sp -4
	lw	$a0 8($sp)
	jal	Object.copy
	lw	$t1 4($sp)
	sw	$t1 12($a0)
	addiu	$sp $sp 8
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 int_const10
	lw	$a0 12($a0)
	lw	$t1 4($sp)
	lw	$t1 12($t1)
	addiu	$sp $sp 4
	blt	$t1 $a0 label32
	la	$a0 bool_const0
	b	label33
label32:
	la	$a0 bool_const1
label33:
	la	$t1 bool_const0
	beq	$a0 $t1 label34
	la	$a0 str_const2
	b	label35
label34:
	lw	$a0 12($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 16($s0)
	lw	$a0 12($a0)
	lw	$t1 4($sp)
	lw	$t1 12($t1)
	sub	$t1 $t1 $a0
	sw	$t1 0($sp)
	addiu	$sp $sp -4
	lw	$a0 8($sp)
	jal	Object.copy
	lw	$t1 4($sp)
	sw	$t1 12($a0)
	addiu	$sp $sp 8
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label36
	la	$a0 str_const0
	li	$t1 159
	jal	_dispatch_abort
label36:
	lw	$t1 8($a0)
	lw	$t1 48($t1)
	jalr		$t1
label35:
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 16
	jr	$ra	
CellularAutomaton.south:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	lw	$a0 20($s0)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 12($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 16($s0)
	lw	$a0 12($a0)
	lw	$t1 4($sp)
	lw	$t1 12($t1)
	add	$t1 $t1 $a0
	sw	$t1 0($sp)
	addiu	$sp $sp -4
	lw	$a0 8($sp)
	jal	Object.copy
	lw	$t1 4($sp)
	sw	$t1 12($a0)
	addiu	$sp $sp 8
	lw	$a0 12($a0)
	lw	$t1 4($sp)
	lw	$t1 12($t1)
	addiu	$sp $sp 4
	blt	$t1 $a0 label37
	la	$a0 bool_const0
	b	label38
label37:
	la	$a0 bool_const1
label38:
	la	$t1 bool_const0
	beq	$a0 $t1 label39
	la	$a0 str_const2
	b	label40
label39:
	lw	$a0 12($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 16($s0)
	lw	$a0 12($a0)
	lw	$t1 4($sp)
	lw	$t1 12($t1)
	add	$t1 $t1 $a0
	sw	$t1 0($sp)
	addiu	$sp $sp -4
	lw	$a0 8($sp)
	jal	Object.copy
	lw	$t1 4($sp)
	sw	$t1 12($a0)
	addiu	$sp $sp 8
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label41
	la	$a0 str_const0
	li	$t1 167
	jal	_dispatch_abort
label41:
	lw	$t1 8($a0)
	lw	$t1 48($t1)
	jalr		$t1
label40:
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 16
	jr	$ra	
CellularAutomaton.east:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	lw	$a0 12($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 int_const11
	lw	$a0 12($a0)
	lw	$t1 4($sp)
	lw	$t1 12($t1)
	add	$t1 $t1 $a0
	sw	$t1 0($sp)
	addiu	$sp $sp -4
	lw	$a0 8($sp)
	jal	Object.copy
	lw	$t1 4($sp)
	sw	$t1 12($a0)
	addiu	$sp $sp 8
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 16($s0)
	lw	$a0 12($a0)
	lw	$t1 4($sp)
	lw	$t1 12($t1)
	div	$t1 $t1 $a0
	sw	$t1 0($sp)
	addiu	$sp $sp -4
	lw	$a0 8($sp)
	jal	Object.copy
	lw	$t1 4($sp)
	sw	$t1 12($a0)
	addiu	$sp $sp 8
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 16($s0)
	lw	$a0 12($a0)
	lw	$t1 4($sp)
	lw	$t1 12($t1)
	mul	$t1 $t1 $a0
	sw	$t1 0($sp)
	addiu	$sp $sp -4
	lw	$a0 8($sp)
	jal	Object.copy
	lw	$t1 4($sp)
	sw	$t1 12($a0)
	addiu	$sp $sp 8
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 12($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 int_const11
	lw	$a0 12($a0)
	lw	$t1 4($sp)
	lw	$t1 12($t1)
	add	$t1 $t1 $a0
	sw	$t1 0($sp)
	addiu	$sp $sp -4
	lw	$a0 8($sp)
	jal	Object.copy
	lw	$t1 4($sp)
	sw	$t1 12($a0)
	addiu	$sp $sp 8
	lw	$t1 4($sp)
	move	$t2 $a0
	la	$a0 bool_const1
	addiu	$sp $sp 4
	beq	$t1 $t2 label42
	la	$a1 bool_const0
	jal	equality_test
label42:
	la	$t1 bool_const0
	beq	$a0 $t1 label43
	la	$a0 str_const2
	b	label44
label43:
	lw	$a0 12($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 int_const11
	lw	$a0 12($a0)
	lw	$t1 4($sp)
	lw	$t1 12($t1)
	add	$t1 $t1 $a0
	sw	$t1 0($sp)
	addiu	$sp $sp -4
	lw	$a0 8($sp)
	jal	Object.copy
	lw	$t1 4($sp)
	sw	$t1 12($a0)
	addiu	$sp $sp 8
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label45
	la	$a0 str_const0
	li	$t1 175
	jal	_dispatch_abort
label45:
	lw	$t1 8($a0)
	lw	$t1 48($t1)
	jalr		$t1
label44:
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 16
	jr	$ra	
CellularAutomaton.west:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	lw	$a0 12($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 int_const10
	lw	$t1 4($sp)
	move	$t2 $a0
	la	$a0 bool_const1
	addiu	$sp $sp 4
	beq	$t1 $t2 label46
	la	$a1 bool_const0
	jal	equality_test
label46:
	la	$t1 bool_const0
	beq	$a0 $t1 label47
	la	$a0 str_const2
	b	label48
label47:
	lw	$a0 12($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 16($s0)
	lw	$a0 12($a0)
	lw	$t1 4($sp)
	lw	$t1 12($t1)
	div	$t1 $t1 $a0
	sw	$t1 0($sp)
	addiu	$sp $sp -4
	lw	$a0 8($sp)
	jal	Object.copy
	lw	$t1 4($sp)
	sw	$t1 12($a0)
	addiu	$sp $sp 8
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 16($s0)
	lw	$a0 12($a0)
	lw	$t1 4($sp)
	lw	$t1 12($t1)
	mul	$t1 $t1 $a0
	sw	$t1 0($sp)
	addiu	$sp $sp -4
	lw	$a0 8($sp)
	jal	Object.copy
	lw	$t1 4($sp)
	sw	$t1 12($a0)
	addiu	$sp $sp 8
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 12($fp)
	lw	$t1 4($sp)
	move	$t2 $a0
	la	$a0 bool_const1
	addiu	$sp $sp 4
	beq	$t1 $t2 label49
	la	$a1 bool_const0
	jal	equality_test
label49:
	la	$t1 bool_const0
	beq	$a0 $t1 label50
	la	$a0 str_const2
	b	label51
label50:
	lw	$a0 12($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 int_const11
	lw	$a0 12($a0)
	lw	$t1 4($sp)
	lw	$t1 12($t1)
	sub	$t1 $t1 $a0
	sw	$t1 0($sp)
	addiu	$sp $sp -4
	lw	$a0 8($sp)
	jal	Object.copy
	lw	$t1 4($sp)
	sw	$t1 12($a0)
	addiu	$sp $sp 8
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label52
	la	$a0 str_const0
	li	$t1 186
	jal	_dispatch_abort
label52:
	lw	$t1 8($a0)
	lw	$t1 48($t1)
	jalr		$t1
label51:
label48:
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 16
	jr	$ra	
CellularAutomaton.northwest:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	lw	$a0 12($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 16($s0)
	lw	$a0 12($a0)
	lw	$t1 4($sp)
	lw	$t1 12($t1)
	sub	$t1 $t1 $a0
	sw	$t1 0($sp)
	addiu	$sp $sp -4
	lw	$a0 8($sp)
	jal	Object.copy
	lw	$t1 4($sp)
	sw	$t1 12($a0)
	addiu	$sp $sp 8
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 int_const10
	lw	$a0 12($a0)
	lw	$t1 4($sp)
	lw	$t1 12($t1)
	addiu	$sp $sp 4
	blt	$t1 $a0 label53
	la	$a0 bool_const0
	b	label54
label53:
	la	$a0 bool_const1
label54:
	la	$t1 bool_const0
	beq	$a0 $t1 label55
	la	$a0 str_const2
	b	label56
label55:
	lw	$a0 12($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 16($s0)
	lw	$a0 12($a0)
	lw	$t1 4($sp)
	lw	$t1 12($t1)
	div	$t1 $t1 $a0
	sw	$t1 0($sp)
	addiu	$sp $sp -4
	lw	$a0 8($sp)
	jal	Object.copy
	lw	$t1 4($sp)
	sw	$t1 12($a0)
	addiu	$sp $sp 8
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 16($s0)
	lw	$a0 12($a0)
	lw	$t1 4($sp)
	lw	$t1 12($t1)
	mul	$t1 $t1 $a0
	sw	$t1 0($sp)
	addiu	$sp $sp -4
	lw	$a0 8($sp)
	jal	Object.copy
	lw	$t1 4($sp)
	sw	$t1 12($a0)
	addiu	$sp $sp 8
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 12($fp)
	lw	$t1 4($sp)
	move	$t2 $a0
	la	$a0 bool_const1
	addiu	$sp $sp 4
	beq	$t1 $t2 label57
	la	$a1 bool_const0
	jal	equality_test
label57:
	la	$t1 bool_const0
	beq	$a0 $t1 label58
	la	$a0 str_const2
	b	label59
label58:
	lw	$a0 12($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 int_const11
	lw	$a0 12($a0)
	lw	$t1 4($sp)
	lw	$t1 12($t1)
	sub	$t1 $t1 $a0
	sw	$t1 0($sp)
	addiu	$sp $sp -4
	lw	$a0 8($sp)
	jal	Object.copy
	lw	$t1 4($sp)
	sw	$t1 12($a0)
	addiu	$sp $sp 8
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label60
	la	$a0 str_const0
	li	$t1 196
	jal	_dispatch_abort
label60:
	lw	$t1 8($a0)
	lw	$t1 52($t1)
	jalr		$t1
label59:
label56:
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 16
	jr	$ra	
CellularAutomaton.northeast:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	lw	$a0 12($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 16($s0)
	lw	$a0 12($a0)
	lw	$t1 4($sp)
	lw	$t1 12($t1)
	sub	$t1 $t1 $a0
	sw	$t1 0($sp)
	addiu	$sp $sp -4
	lw	$a0 8($sp)
	jal	Object.copy
	lw	$t1 4($sp)
	sw	$t1 12($a0)
	addiu	$sp $sp 8
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 int_const10
	lw	$a0 12($a0)
	lw	$t1 4($sp)
	lw	$t1 12($t1)
	addiu	$sp $sp 4
	blt	$t1 $a0 label61
	la	$a0 bool_const0
	b	label62
label61:
	la	$a0 bool_const1
label62:
	la	$t1 bool_const0
	beq	$a0 $t1 label63
	la	$a0 str_const2
	b	label64
label63:
	lw	$a0 12($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 int_const11
	lw	$a0 12($a0)
	lw	$t1 4($sp)
	lw	$t1 12($t1)
	add	$t1 $t1 $a0
	sw	$t1 0($sp)
	addiu	$sp $sp -4
	lw	$a0 8($sp)
	jal	Object.copy
	lw	$t1 4($sp)
	sw	$t1 12($a0)
	addiu	$sp $sp 8
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 16($s0)
	lw	$a0 12($a0)
	lw	$t1 4($sp)
	lw	$t1 12($t1)
	div	$t1 $t1 $a0
	sw	$t1 0($sp)
	addiu	$sp $sp -4
	lw	$a0 8($sp)
	jal	Object.copy
	lw	$t1 4($sp)
	sw	$t1 12($a0)
	addiu	$sp $sp 8
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 16($s0)
	lw	$a0 12($a0)
	lw	$t1 4($sp)
	lw	$t1 12($t1)
	mul	$t1 $t1 $a0
	sw	$t1 0($sp)
	addiu	$sp $sp -4
	lw	$a0 8($sp)
	jal	Object.copy
	lw	$t1 4($sp)
	sw	$t1 12($a0)
	addiu	$sp $sp 8
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 12($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 int_const11
	lw	$a0 12($a0)
	lw	$t1 4($sp)
	lw	$t1 12($t1)
	add	$t1 $t1 $a0
	sw	$t1 0($sp)
	addiu	$sp $sp -4
	lw	$a0 8($sp)
	jal	Object.copy
	lw	$t1 4($sp)
	sw	$t1 12($a0)
	addiu	$sp $sp 8
	lw	$t1 4($sp)
	move	$t2 $a0
	la	$a0 bool_const1
	addiu	$sp $sp 4
	beq	$t1 $t2 label65
	la	$a1 bool_const0
	jal	equality_test
label65:
	la	$t1 bool_const0
	beq	$a0 $t1 label66
	la	$a0 str_const2
	b	label67
label66:
	lw	$a0 12($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 int_const11
	lw	$a0 12($a0)
	lw	$t1 4($sp)
	lw	$t1 12($t1)
	add	$t1 $t1 $a0
	sw	$t1 0($sp)
	addiu	$sp $sp -4
	lw	$a0 8($sp)
	jal	Object.copy
	lw	$t1 4($sp)
	sw	$t1 12($a0)
	addiu	$sp $sp 8
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label68
	la	$a0 str_const0
	li	$t1 206
	jal	_dispatch_abort
label68:
	lw	$t1 8($a0)
	lw	$t1 52($t1)
	jalr		$t1
label67:
label64:
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 16
	jr	$ra	
CellularAutomaton.southeast:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	lw	$a0 20($s0)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 12($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 16($s0)
	lw	$a0 12($a0)
	lw	$t1 4($sp)
	lw	$t1 12($t1)
	add	$t1 $t1 $a0
	sw	$t1 0($sp)
	addiu	$sp $sp -4
	lw	$a0 8($sp)
	jal	Object.copy
	lw	$t1 4($sp)
	sw	$t1 12($a0)
	addiu	$sp $sp 8
	lw	$a0 12($a0)
	lw	$t1 4($sp)
	lw	$t1 12($t1)
	addiu	$sp $sp 4
	blt	$t1 $a0 label69
	la	$a0 bool_const0
	b	label70
label69:
	la	$a0 bool_const1
label70:
	la	$t1 bool_const0
	beq	$a0 $t1 label71
	la	$a0 str_const2
	b	label72
label71:
	lw	$a0 12($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 int_const11
	lw	$a0 12($a0)
	lw	$t1 4($sp)
	lw	$t1 12($t1)
	add	$t1 $t1 $a0
	sw	$t1 0($sp)
	addiu	$sp $sp -4
	lw	$a0 8($sp)
	jal	Object.copy
	lw	$t1 4($sp)
	sw	$t1 12($a0)
	addiu	$sp $sp 8
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 16($s0)
	lw	$a0 12($a0)
	lw	$t1 4($sp)
	lw	$t1 12($t1)
	div	$t1 $t1 $a0
	sw	$t1 0($sp)
	addiu	$sp $sp -4
	lw	$a0 8($sp)
	jal	Object.copy
	lw	$t1 4($sp)
	sw	$t1 12($a0)
	addiu	$sp $sp 8
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 16($s0)
	lw	$a0 12($a0)
	lw	$t1 4($sp)
	lw	$t1 12($t1)
	mul	$t1 $t1 $a0
	sw	$t1 0($sp)
	addiu	$sp $sp -4
	lw	$a0 8($sp)
	jal	Object.copy
	lw	$t1 4($sp)
	sw	$t1 12($a0)
	addiu	$sp $sp 8
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 12($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 int_const11
	lw	$a0 12($a0)
	lw	$t1 4($sp)
	lw	$t1 12($t1)
	add	$t1 $t1 $a0
	sw	$t1 0($sp)
	addiu	$sp $sp -4
	lw	$a0 8($sp)
	jal	Object.copy
	lw	$t1 4($sp)
	sw	$t1 12($a0)
	addiu	$sp $sp 8
	lw	$t1 4($sp)
	move	$t2 $a0
	la	$a0 bool_const1
	addiu	$sp $sp 4
	beq	$t1 $t2 label73
	la	$a1 bool_const0
	jal	equality_test
label73:
	la	$t1 bool_const0
	beq	$a0 $t1 label74
	la	$a0 str_const2
	b	label75
label74:
	lw	$a0 12($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 int_const11
	lw	$a0 12($a0)
	lw	$t1 4($sp)
	lw	$t1 12($t1)
	add	$t1 $t1 $a0
	sw	$t1 0($sp)
	addiu	$sp $sp -4
	lw	$a0 8($sp)
	jal	Object.copy
	lw	$t1 4($sp)
	sw	$t1 12($a0)
	addiu	$sp $sp 8
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label76
	la	$a0 str_const0
	li	$t1 216
	jal	_dispatch_abort
label76:
	lw	$t1 8($a0)
	lw	$t1 56($t1)
	jalr		$t1
label75:
label72:
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 16
	jr	$ra	
CellularAutomaton.southwest:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	lw	$a0 20($s0)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 12($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 16($s0)
	lw	$a0 12($a0)
	lw	$t1 4($sp)
	lw	$t1 12($t1)
	add	$t1 $t1 $a0
	sw	$t1 0($sp)
	addiu	$sp $sp -4
	lw	$a0 8($sp)
	jal	Object.copy
	lw	$t1 4($sp)
	sw	$t1 12($a0)
	addiu	$sp $sp 8
	lw	$a0 12($a0)
	lw	$t1 4($sp)
	lw	$t1 12($t1)
	addiu	$sp $sp 4
	blt	$t1 $a0 label77
	la	$a0 bool_const0
	b	label78
label77:
	la	$a0 bool_const1
label78:
	la	$t1 bool_const0
	beq	$a0 $t1 label79
	la	$a0 str_const2
	b	label80
label79:
	lw	$a0 12($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 16($s0)
	lw	$a0 12($a0)
	lw	$t1 4($sp)
	lw	$t1 12($t1)
	div	$t1 $t1 $a0
	sw	$t1 0($sp)
	addiu	$sp $sp -4
	lw	$a0 8($sp)
	jal	Object.copy
	lw	$t1 4($sp)
	sw	$t1 12($a0)
	addiu	$sp $sp 8
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 16($s0)
	lw	$a0 12($a0)
	lw	$t1 4($sp)
	lw	$t1 12($t1)
	mul	$t1 $t1 $a0
	sw	$t1 0($sp)
	addiu	$sp $sp -4
	lw	$a0 8($sp)
	jal	Object.copy
	lw	$t1 4($sp)
	sw	$t1 12($a0)
	addiu	$sp $sp 8
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 12($fp)
	lw	$t1 4($sp)
	move	$t2 $a0
	la	$a0 bool_const1
	addiu	$sp $sp 4
	beq	$t1 $t2 label81
	la	$a1 bool_const0
	jal	equality_test
label81:
	la	$t1 bool_const0
	beq	$a0 $t1 label82
	la	$a0 str_const2
	b	label83
label82:
	lw	$a0 12($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 int_const11
	lw	$a0 12($a0)
	lw	$t1 4($sp)
	lw	$t1 12($t1)
	sub	$t1 $t1 $a0
	sw	$t1 0($sp)
	addiu	$sp $sp -4
	lw	$a0 8($sp)
	jal	Object.copy
	lw	$t1 4($sp)
	sw	$t1 12($a0)
	addiu	$sp $sp 8
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label84
	la	$a0 str_const0
	li	$t1 226
	jal	_dispatch_abort
label84:
	lw	$t1 8($a0)
	lw	$t1 56($t1)
	jalr		$t1
label83:
label80:
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 16
	jr	$ra	
CellularAutomaton.neighbors:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	lw	$a0 12($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label85
	la	$a0 str_const0
	li	$t1 232
	jal	_dispatch_abort
label85:
	lw	$t1 8($a0)
	lw	$t1 52($t1)
	jalr		$t1
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 str_const3
	lw	$t1 4($sp)
	move	$t2 $a0
	la	$a0 bool_const1
	addiu	$sp $sp 4
	beq	$t1 $t2 label86
	la	$a1 bool_const0
	jal	equality_test
label86:
	la	$t1 bool_const0
	beq	$a0 $t1 label87
	la	$a0 int_const11
	b	label88
label87:
	la	$a0 int_const10
label88:
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 12($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label89
	la	$a0 str_const0
	li	$t1 233
	jal	_dispatch_abort
label89:
	lw	$t1 8($a0)
	lw	$t1 56($t1)
	jalr		$t1
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 str_const3
	lw	$t1 4($sp)
	move	$t2 $a0
	la	$a0 bool_const1
	addiu	$sp $sp 4
	beq	$t1 $t2 label90
	la	$a1 bool_const0
	jal	equality_test
label90:
	la	$t1 bool_const0
	beq	$a0 $t1 label91
	la	$a0 int_const11
	b	label92
label91:
	la	$a0 int_const10
label92:
	lw	$a0 12($a0)
	lw	$t1 4($sp)
	lw	$t1 12($t1)
	add	$t1 $t1 $a0
	sw	$t1 0($sp)
	addiu	$sp $sp -4
	lw	$a0 8($sp)
	jal	Object.copy
	lw	$t1 4($sp)
	sw	$t1 12($a0)
	addiu	$sp $sp 8
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 12($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label93
	la	$a0 str_const0
	li	$t1 234
	jal	_dispatch_abort
label93:
	lw	$t1 8($a0)
	lw	$t1 60($t1)
	jalr		$t1
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 str_const3
	lw	$t1 4($sp)
	move	$t2 $a0
	la	$a0 bool_const1
	addiu	$sp $sp 4
	beq	$t1 $t2 label94
	la	$a1 bool_const0
	jal	equality_test
label94:
	la	$t1 bool_const0
	beq	$a0 $t1 label95
	la	$a0 int_const11
	b	label96
label95:
	la	$a0 int_const10
label96:
	lw	$a0 12($a0)
	lw	$t1 4($sp)
	lw	$t1 12($t1)
	add	$t1 $t1 $a0
	sw	$t1 0($sp)
	addiu	$sp $sp -4
	lw	$a0 8($sp)
	jal	Object.copy
	lw	$t1 4($sp)
	sw	$t1 12($a0)
	addiu	$sp $sp 8
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 12($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label97
	la	$a0 str_const0
	li	$t1 235
	jal	_dispatch_abort
label97:
	lw	$t1 8($a0)
	lw	$t1 64($t1)
	jalr		$t1
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 str_const3
	lw	$t1 4($sp)
	move	$t2 $a0
	la	$a0 bool_const1
	addiu	$sp $sp 4
	beq	$t1 $t2 label98
	la	$a1 bool_const0
	jal	equality_test
label98:
	la	$t1 bool_const0
	beq	$a0 $t1 label99
	la	$a0 int_const11
	b	label100
label99:
	la	$a0 int_const10
label100:
	lw	$a0 12($a0)
	lw	$t1 4($sp)
	lw	$t1 12($t1)
	add	$t1 $t1 $a0
	sw	$t1 0($sp)
	addiu	$sp $sp -4
	lw	$a0 8($sp)
	jal	Object.copy
	lw	$t1 4($sp)
	sw	$t1 12($a0)
	addiu	$sp $sp 8
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 12($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label101
	la	$a0 str_const0
	li	$t1 236
	jal	_dispatch_abort
label101:
	lw	$t1 8($a0)
	lw	$t1 72($t1)
	jalr		$t1
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 str_const3
	lw	$t1 4($sp)
	move	$t2 $a0
	la	$a0 bool_const1
	addiu	$sp $sp 4
	beq	$t1 $t2 label102
	la	$a1 bool_const0
	jal	equality_test
label102:
	la	$t1 bool_const0
	beq	$a0 $t1 label103
	la	$a0 int_const11
	b	label104
label103:
	la	$a0 int_const10
label104:
	lw	$a0 12($a0)
	lw	$t1 4($sp)
	lw	$t1 12($t1)
	add	$t1 $t1 $a0
	sw	$t1 0($sp)
	addiu	$sp $sp -4
	lw	$a0 8($sp)
	jal	Object.copy
	lw	$t1 4($sp)
	sw	$t1 12($a0)
	addiu	$sp $sp 8
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 12($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label105
	la	$a0 str_const0
	li	$t1 237
	jal	_dispatch_abort
label105:
	lw	$t1 8($a0)
	lw	$t1 68($t1)
	jalr		$t1
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 str_const3
	lw	$t1 4($sp)
	move	$t2 $a0
	la	$a0 bool_const1
	addiu	$sp $sp 4
	beq	$t1 $t2 label106
	la	$a1 bool_const0
	jal	equality_test
label106:
	la	$t1 bool_const0
	beq	$a0 $t1 label107
	la	$a0 int_const11
	b	label108
label107:
	la	$a0 int_const10
label108:
	lw	$a0 12($a0)
	lw	$t1 4($sp)
	lw	$t1 12($t1)
	add	$t1 $t1 $a0
	sw	$t1 0($sp)
	addiu	$sp $sp -4
	lw	$a0 8($sp)
	jal	Object.copy
	lw	$t1 4($sp)
	sw	$t1 12($a0)
	addiu	$sp $sp 8
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 12($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label109
	la	$a0 str_const0
	li	$t1 238
	jal	_dispatch_abort
label109:
	lw	$t1 8($a0)
	lw	$t1 76($t1)
	jalr		$t1
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 str_const3
	lw	$t1 4($sp)
	move	$t2 $a0
	la	$a0 bool_const1
	addiu	$sp $sp 4
	beq	$t1 $t2 label110
	la	$a1 bool_const0
	jal	equality_test
label110:
	la	$t1 bool_const0
	beq	$a0 $t1 label111
	la	$a0 int_const11
	b	label112
label111:
	la	$a0 int_const10
label112:
	lw	$a0 12($a0)
	lw	$t1 4($sp)
	lw	$t1 12($t1)
	add	$t1 $t1 $a0
	sw	$t1 0($sp)
	addiu	$sp $sp -4
	lw	$a0 8($sp)
	jal	Object.copy
	lw	$t1 4($sp)
	sw	$t1 12($a0)
	addiu	$sp $sp 8
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 12($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label113
	la	$a0 str_const0
	li	$t1 239
	jal	_dispatch_abort
label113:
	lw	$t1 8($a0)
	lw	$t1 80($t1)
	jalr		$t1
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 str_const3
	lw	$t1 4($sp)
	move	$t2 $a0
	la	$a0 bool_const1
	addiu	$sp $sp 4
	beq	$t1 $t2 label114
	la	$a1 bool_const0
	jal	equality_test
label114:
	la	$t1 bool_const0
	beq	$a0 $t1 label115
	la	$a0 int_const11
	b	label116
label115:
	la	$a0 int_const10
label116:
	lw	$a0 12($a0)
	lw	$t1 4($sp)
	lw	$t1 12($t1)
	add	$t1 $t1 $a0
	sw	$t1 0($sp)
	addiu	$sp $sp -4
	lw	$a0 8($sp)
	jal	Object.copy
	lw	$t1 4($sp)
	sw	$t1 12($a0)
	addiu	$sp $sp 8
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 16
	jr	$ra	
CellularAutomaton.cell_at_next_evolution:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	lw	$a0 12($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label117
	la	$a0 str_const0
	li	$t1 249
	jal	_dispatch_abort
label117:
	lw	$t1 8($a0)
	lw	$t1 84($t1)
	jalr		$t1
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 int_const1
	lw	$t1 4($sp)
	move	$t2 $a0
	la	$a0 bool_const1
	addiu	$sp $sp 4
	beq	$t1 $t2 label118
	la	$a1 bool_const0
	jal	equality_test
label118:
	la	$t1 bool_const0
	beq	$a0 $t1 label119
	la	$a0 str_const3
	b	label120
label119:
	lw	$a0 12($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label121
	la	$a0 str_const0
	li	$t1 252
	jal	_dispatch_abort
label121:
	lw	$t1 8($a0)
	lw	$t1 84($t1)
	jalr		$t1
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 int_const12
	lw	$t1 4($sp)
	move	$t2 $a0
	la	$a0 bool_const1
	addiu	$sp $sp 4
	beq	$t1 $t2 label122
	la	$a1 bool_const0
	jal	equality_test
label122:
	la	$t1 bool_const0
	beq	$a0 $t1 label123
	lw	$a0 12($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label124
	la	$a0 str_const0
	li	$t1 253
	jal	_dispatch_abort
label124:
	lw	$t1 8($a0)
	lw	$t1 48($t1)
	jalr		$t1
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 str_const3
	lw	$t1 4($sp)
	move	$t2 $a0
	la	$a0 bool_const1
	addiu	$sp $sp 4
	beq	$t1 $t2 label125
	la	$a1 bool_const0
	jal	equality_test
label125:
	la	$t1 bool_const0
	beq	$a0 $t1 label126
	la	$a0 str_const3
	b	label127
label126:
	la	$a0 str_const4
label127:
	b	label128
label123:
	la	$a0 str_const4
label128:
label120:
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 16
	jr	$ra	
CellularAutomaton.evolve:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	la	$a0 int_const10
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label129
	la	$a0 str_const0
	li	$t1 266
	jal	_dispatch_abort
label129:
	lw	$t1 8($a0)
	lw	$t1 44($t1)
	jalr		$t1
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 str_const71
	sw	$a0 0($sp)
	addiu	$sp $sp -4
label130:
	lw	$a0 -4($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 -8($fp)
	lw	$a0 12($a0)
	lw	$t1 4($sp)
	lw	$t1 12($t1)
	addiu	$sp $sp 4
	blt	$t1 $a0 label131
	la	$a0 bool_const0
	b	label132
label131:
	la	$a0 bool_const1
label132:
	lw	$t1 12($a0)
	beq	$t1 $zero label133
	lw	$a0 -4($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label134
	la	$a0 str_const0
	li	$t1 271
	jal	_dispatch_abort
label134:
	lw	$t1 8($a0)
	lw	$t1 88($t1)
	jalr		$t1
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 -12($fp)
	bne	$a0 $zero label135
	la	$a0 str_const0
	li	$t1 271
	jal	_dispatch_abort
label135:
	lw	$t1 8($a0)
	lw	$t1 16($t1)
	jalr		$t1
	sw	$a0 -12($fp)
	lw	$a0 -4($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 int_const11
	lw	$a0 12($a0)
	lw	$t1 4($sp)
	lw	$t1 12($t1)
	add	$t1 $t1 $a0
	sw	$t1 0($sp)
	addiu	$sp $sp -4
	lw	$a0 8($sp)
	jal	Object.copy
	lw	$t1 4($sp)
	sw	$t1 12($a0)
	addiu	$sp $sp 8
	sw	$a0 -4($fp)
	b	label130
label133:
	move	$a0 $zero
	lw	$a0 -12($fp)
	sw	$a0 24($s0)
	move	$a0 $s0
	addiu	$sp $sp 4
	addiu	$sp $sp 4
	addiu	$sp $sp 4
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 12
	jr	$ra	
CellularAutomaton.option:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	la	$a0 int_const10
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 str_const5
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label136
	la	$a0 str_const0
	li	$t1 288
	jal	_dispatch_abort
label136:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	la	$a0 str_const6
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label137
	la	$a0 str_const0
	li	$t1 289
	jal	_dispatch_abort
label137:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	la	$a0 str_const7
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label138
	la	$a0 str_const0
	li	$t1 290
	jal	_dispatch_abort
label138:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	la	$a0 str_const8
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label139
	la	$a0 str_const0
	li	$t1 291
	jal	_dispatch_abort
label139:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	la	$a0 str_const9
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label140
	la	$a0 str_const0
	li	$t1 292
	jal	_dispatch_abort
label140:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	la	$a0 str_const10
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label141
	la	$a0 str_const0
	li	$t1 293
	jal	_dispatch_abort
label141:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	la	$a0 str_const11
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label142
	la	$a0 str_const0
	li	$t1 294
	jal	_dispatch_abort
label142:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	la	$a0 str_const12
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label143
	la	$a0 str_const0
	li	$t1 295
	jal	_dispatch_abort
label143:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	la	$a0 str_const13
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label144
	la	$a0 str_const0
	li	$t1 296
	jal	_dispatch_abort
label144:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	la	$a0 str_const14
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label145
	la	$a0 str_const0
	li	$t1 297
	jal	_dispatch_abort
label145:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	la	$a0 str_const15
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label146
	la	$a0 str_const0
	li	$t1 298
	jal	_dispatch_abort
label146:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	la	$a0 str_const16
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label147
	la	$a0 str_const0
	li	$t1 299
	jal	_dispatch_abort
label147:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	la	$a0 str_const17
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label148
	la	$a0 str_const0
	li	$t1 300
	jal	_dispatch_abort
label148:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	la	$a0 str_const18
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label149
	la	$a0 str_const0
	li	$t1 301
	jal	_dispatch_abort
label149:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	la	$a0 str_const19
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label150
	la	$a0 str_const0
	li	$t1 302
	jal	_dispatch_abort
label150:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	la	$a0 str_const20
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label151
	la	$a0 str_const0
	li	$t1 303
	jal	_dispatch_abort
label151:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	la	$a0 str_const21
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label152
	la	$a0 str_const0
	li	$t1 304
	jal	_dispatch_abort
label152:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	la	$a0 str_const22
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label153
	la	$a0 str_const0
	li	$t1 305
	jal	_dispatch_abort
label153:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	la	$a0 str_const23
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label154
	la	$a0 str_const0
	li	$t1 306
	jal	_dispatch_abort
label154:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	la	$a0 str_const24
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label155
	la	$a0 str_const0
	li	$t1 307
	jal	_dispatch_abort
label155:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	la	$a0 str_const25
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label156
	la	$a0 str_const0
	li	$t1 308
	jal	_dispatch_abort
label156:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	la	$a0 str_const26
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label157
	la	$a0 str_const0
	li	$t1 309
	jal	_dispatch_abort
label157:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	la	$a0 str_const27
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label158
	la	$a0 str_const0
	li	$t1 310
	jal	_dispatch_abort
label158:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	move	$a0 $s0
	bne	$a0 $zero label159
	la	$a0 str_const0
	li	$t1 311
	jal	_dispatch_abort
label159:
	lw	$t1 8($a0)
	lw	$t1 24($t1)
	jalr		$t1
	sw	$a0 -4($fp)
	la	$a0 str_const1
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label160
	la	$a0 str_const0
	li	$t1 312
	jal	_dispatch_abort
label160:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	lw	$a0 -4($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 int_const11
	lw	$t1 4($sp)
	move	$t2 $a0
	la	$a0 bool_const1
	addiu	$sp $sp 4
	beq	$t1 $t2 label161
	la	$a1 bool_const0
	jal	equality_test
label161:
	la	$t1 bool_const0
	beq	$a0 $t1 label162
	la	$a0 str_const28
	b	label163
label162:
	lw	$a0 -4($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 int_const12
	lw	$t1 4($sp)
	move	$t2 $a0
	la	$a0 bool_const1
	addiu	$sp $sp 4
	beq	$t1 $t2 label164
	la	$a1 bool_const0
	jal	equality_test
label164:
	la	$t1 bool_const0
	beq	$a0 $t1 label165
	la	$a0 str_const29
	b	label166
label165:
	lw	$a0 -4($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 int_const1
	lw	$t1 4($sp)
	move	$t2 $a0
	la	$a0 bool_const1
	addiu	$sp $sp 4
	beq	$t1 $t2 label167
	la	$a1 bool_const0
	jal	equality_test
label167:
	la	$t1 bool_const0
	beq	$a0 $t1 label168
	la	$a0 str_const30
	b	label169
label168:
	lw	$a0 -4($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 int_const4
	lw	$t1 4($sp)
	move	$t2 $a0
	la	$a0 bool_const1
	addiu	$sp $sp 4
	beq	$t1 $t2 label170
	la	$a1 bool_const0
	jal	equality_test
label170:
	la	$t1 bool_const0
	beq	$a0 $t1 label171
	la	$a0 str_const31
	b	label172
label171:
	lw	$a0 -4($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 int_const2
	lw	$t1 4($sp)
	move	$t2 $a0
	la	$a0 bool_const1
	addiu	$sp $sp 4
	beq	$t1 $t2 label173
	la	$a1 bool_const0
	jal	equality_test
label173:
	la	$t1 bool_const0
	beq	$a0 $t1 label174
	la	$a0 str_const32
	b	label175
label174:
	lw	$a0 -4($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 int_const13
	lw	$t1 4($sp)
	move	$t2 $a0
	la	$a0 bool_const1
	addiu	$sp $sp 4
	beq	$t1 $t2 label176
	la	$a1 bool_const0
	jal	equality_test
label176:
	la	$t1 bool_const0
	beq	$a0 $t1 label177
	la	$a0 str_const33
	b	label178
label177:
	lw	$a0 -4($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 int_const7
	lw	$t1 4($sp)
	move	$t2 $a0
	la	$a0 bool_const1
	addiu	$sp $sp 4
	beq	$t1 $t2 label179
	la	$a1 bool_const0
	jal	equality_test
label179:
	la	$t1 bool_const0
	beq	$a0 $t1 label180
	la	$a0 str_const34
	b	label181
label180:
	lw	$a0 -4($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 int_const14
	lw	$t1 4($sp)
	move	$t2 $a0
	la	$a0 bool_const1
	addiu	$sp $sp 4
	beq	$t1 $t2 label182
	la	$a1 bool_const0
	jal	equality_test
label182:
	la	$t1 bool_const0
	beq	$a0 $t1 label183
	la	$a0 str_const35
	b	label184
label183:
	lw	$a0 -4($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 int_const15
	lw	$t1 4($sp)
	move	$t2 $a0
	la	$a0 bool_const1
	addiu	$sp $sp 4
	beq	$t1 $t2 label185
	la	$a1 bool_const0
	jal	equality_test
label185:
	la	$t1 bool_const0
	beq	$a0 $t1 label186
	la	$a0 str_const36
	b	label187
label186:
	lw	$a0 -4($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 int_const16
	lw	$t1 4($sp)
	move	$t2 $a0
	la	$a0 bool_const1
	addiu	$sp $sp 4
	beq	$t1 $t2 label188
	la	$a1 bool_const0
	jal	equality_test
label188:
	la	$t1 bool_const0
	beq	$a0 $t1 label189
	la	$a0 str_const37
	b	label190
label189:
	lw	$a0 -4($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 int_const17
	lw	$t1 4($sp)
	move	$t2 $a0
	la	$a0 bool_const1
	addiu	$sp $sp 4
	beq	$t1 $t2 label191
	la	$a1 bool_const0
	jal	equality_test
label191:
	la	$t1 bool_const0
	beq	$a0 $t1 label192
	la	$a0 str_const38
	b	label193
label192:
	lw	$a0 -4($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 int_const18
	lw	$t1 4($sp)
	move	$t2 $a0
	la	$a0 bool_const1
	addiu	$sp $sp 4
	beq	$t1 $t2 label194
	la	$a1 bool_const0
	jal	equality_test
label194:
	la	$t1 bool_const0
	beq	$a0 $t1 label195
	la	$a0 str_const39
	b	label196
label195:
	lw	$a0 -4($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 int_const19
	lw	$t1 4($sp)
	move	$t2 $a0
	la	$a0 bool_const1
	addiu	$sp $sp 4
	beq	$t1 $t2 label197
	la	$a1 bool_const0
	jal	equality_test
label197:
	la	$t1 bool_const0
	beq	$a0 $t1 label198
	la	$a0 str_const40
	b	label199
label198:
	lw	$a0 -4($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 int_const20
	lw	$t1 4($sp)
	move	$t2 $a0
	la	$a0 bool_const1
	addiu	$sp $sp 4
	beq	$t1 $t2 label200
	la	$a1 bool_const0
	jal	equality_test
label200:
	la	$t1 bool_const0
	beq	$a0 $t1 label201
	la	$a0 str_const41
	b	label202
label201:
	lw	$a0 -4($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 int_const0
	lw	$t1 4($sp)
	move	$t2 $a0
	la	$a0 bool_const1
	addiu	$sp $sp 4
	beq	$t1 $t2 label203
	la	$a1 bool_const0
	jal	equality_test
label203:
	la	$t1 bool_const0
	beq	$a0 $t1 label204
	la	$a0 str_const42
	b	label205
label204:
	lw	$a0 -4($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 int_const3
	lw	$t1 4($sp)
	move	$t2 $a0
	la	$a0 bool_const1
	addiu	$sp $sp 4
	beq	$t1 $t2 label206
	la	$a1 bool_const0
	jal	equality_test
label206:
	la	$t1 bool_const0
	beq	$a0 $t1 label207
	la	$a0 str_const43
	b	label208
label207:
	lw	$a0 -4($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 int_const21
	lw	$t1 4($sp)
	move	$t2 $a0
	la	$a0 bool_const1
	addiu	$sp $sp 4
	beq	$t1 $t2 label209
	la	$a1 bool_const0
	jal	equality_test
label209:
	la	$t1 bool_const0
	beq	$a0 $t1 label210
	la	$a0 str_const44
	b	label211
label210:
	lw	$a0 -4($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 int_const22
	lw	$t1 4($sp)
	move	$t2 $a0
	la	$a0 bool_const1
	addiu	$sp $sp 4
	beq	$t1 $t2 label212
	la	$a1 bool_const0
	jal	equality_test
label212:
	la	$t1 bool_const0
	beq	$a0 $t1 label213
	la	$a0 str_const45
	b	label214
label213:
	lw	$a0 -4($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 int_const23
	lw	$t1 4($sp)
	move	$t2 $a0
	la	$a0 bool_const1
	addiu	$sp $sp 4
	beq	$t1 $t2 label215
	la	$a1 bool_const0
	jal	equality_test
label215:
	la	$t1 bool_const0
	beq	$a0 $t1 label216
	la	$a0 str_const46
	b	label217
label216:
	lw	$a0 -4($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 int_const5
	lw	$t1 4($sp)
	move	$t2 $a0
	la	$a0 bool_const1
	addiu	$sp $sp 4
	beq	$t1 $t2 label218
	la	$a1 bool_const0
	jal	equality_test
label218:
	la	$t1 bool_const0
	beq	$a0 $t1 label219
	la	$a0 str_const47
	b	label220
label219:
	lw	$a0 -4($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 int_const6
	lw	$t1 4($sp)
	move	$t2 $a0
	la	$a0 bool_const1
	addiu	$sp $sp 4
	beq	$t1 $t2 label221
	la	$a1 bool_const0
	jal	equality_test
label221:
	la	$t1 bool_const0
	beq	$a0 $t1 label222
	la	$a0 str_const48
	b	label223
label222:
	la	$a0 str_const49
label223:
label220:
label217:
label214:
label211:
label208:
label205:
label202:
label199:
label196:
label193:
label190:
label187:
label184:
label181:
label178:
label175:
label172:
label169:
label166:
label163:
	addiu	$sp $sp 4
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 12
	jr	$ra	
CellularAutomaton.prompt:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	la	$a0 str_const71
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 str_const50
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label224
	la	$a0 str_const0
	li	$t1 370
	jal	_dispatch_abort
label224:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	la	$a0 str_const51
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label225
	la	$a0 str_const0
	li	$t1 371
	jal	_dispatch_abort
label225:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	move	$a0 $s0
	bne	$a0 $zero label226
	la	$a0 str_const0
	li	$t1 372
	jal	_dispatch_abort
label226:
	lw	$t1 8($a0)
	lw	$t1 20($t1)
	jalr		$t1
	sw	$a0 -4($fp)
	la	$a0 str_const1
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label227
	la	$a0 str_const0
	li	$t1 373
	jal	_dispatch_abort
label227:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	lw	$a0 -4($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 str_const52
	lw	$t1 4($sp)
	move	$t2 $a0
	la	$a0 bool_const1
	addiu	$sp $sp 4
	beq	$t1 $t2 label228
	la	$a1 bool_const0
	jal	equality_test
label228:
	la	$t1 bool_const0
	beq	$a0 $t1 label229
	la	$a0 bool_const0
	b	label230
label229:
	la	$a0 bool_const1
label230:
	addiu	$sp $sp 4
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 12
	jr	$ra	
CellularAutomaton.prompt2:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	la	$a0 str_const71
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 str_const53
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label231
	la	$a0 str_const0
	li	$t1 388
	jal	_dispatch_abort
label231:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	la	$a0 str_const54
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label232
	la	$a0 str_const0
	li	$t1 389
	jal	_dispatch_abort
label232:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	la	$a0 str_const55
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label233
	la	$a0 str_const0
	li	$t1 390
	jal	_dispatch_abort
label233:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	move	$a0 $s0
	bne	$a0 $zero label234
	la	$a0 str_const0
	li	$t1 391
	jal	_dispatch_abort
label234:
	lw	$t1 8($a0)
	lw	$t1 20($t1)
	jalr		$t1
	sw	$a0 -4($fp)
	lw	$a0 -4($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 str_const56
	lw	$t1 4($sp)
	move	$t2 $a0
	la	$a0 bool_const1
	addiu	$sp $sp 4
	beq	$t1 $t2 label235
	la	$a1 bool_const0
	jal	equality_test
label235:
	la	$t1 bool_const0
	beq	$a0 $t1 label236
	la	$a0 bool_const1
	b	label237
label236:
	la	$a0 bool_const0
label237:
	addiu	$sp $sp 4
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 12
	jr	$ra	
Board.size_of_board:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	lw	$a0 12($fp)
	bne	$a0 $zero label238
	la	$a0 str_const0
	li	$t1 52
	jal	_dispatch_abort
label238:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 16
	jr	$ra	
Board.board_init:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	lw	$a0 12($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label239
	la	$a0 str_const0
	li	$t1 56
	jal	_dispatch_abort
label239:
	lw	$t1 8($a0)
	lw	$t1 28($t1)
	jalr		$t1
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 -4($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 int_const0
	lw	$t1 4($sp)
	move	$t2 $a0
	la	$a0 bool_const1
	addiu	$sp $sp 4
	beq	$t1 $t2 label240
	la	$a1 bool_const0
	jal	equality_test
label240:
	la	$t1 bool_const0
	beq	$a0 $t1 label241
	la	$a0 int_const1
	sw	$a0 12($s0)
	la	$a0 int_const2
	sw	$a0 16($s0)
	lw	$a0 -4($fp)
	sw	$a0 20($s0)
	b	label242
label241:
	lw	$a0 -4($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 int_const3
	lw	$t1 4($sp)
	move	$t2 $a0
	la	$a0 bool_const1
	addiu	$sp $sp 4
	beq	$t1 $t2 label243
	la	$a1 bool_const0
	jal	equality_test
label243:
	la	$t1 bool_const0
	beq	$a0 $t1 label244
	la	$a0 int_const4
	sw	$a0 12($s0)
	la	$a0 int_const4
	sw	$a0 16($s0)
	lw	$a0 -4($fp)
	sw	$a0 20($s0)
	b	label245
label244:
	lw	$a0 -4($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 int_const5
	lw	$t1 4($sp)
	move	$t2 $a0
	la	$a0 bool_const1
	addiu	$sp $sp 4
	beq	$t1 $t2 label246
	la	$a1 bool_const0
	jal	equality_test
label246:
	la	$t1 bool_const0
	beq	$a0 $t1 label247
	la	$a0 int_const4
	sw	$a0 12($s0)
	la	$a0 int_const2
	sw	$a0 16($s0)
	lw	$a0 -4($fp)
	sw	$a0 20($s0)
	b	label248
label247:
	lw	$a0 -4($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 int_const6
	lw	$t1 4($sp)
	move	$t2 $a0
	la	$a0 bool_const1
	addiu	$sp $sp 4
	beq	$t1 $t2 label249
	la	$a1 bool_const0
	jal	equality_test
label249:
	la	$t1 bool_const0
	beq	$a0 $t1 label250
	la	$a0 int_const1
	sw	$a0 12($s0)
	la	$a0 int_const7
	sw	$a0 16($s0)
	lw	$a0 -4($fp)
	sw	$a0 20($s0)
	b	label251
label250:
	lw	$a0 -4($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 int_const8
	lw	$t1 4($sp)
	move	$t2 $a0
	la	$a0 bool_const1
	addiu	$sp $sp 4
	beq	$t1 $t2 label252
	la	$a1 bool_const0
	jal	equality_test
label252:
	la	$t1 bool_const0
	beq	$a0 $t1 label253
	la	$a0 int_const2
	sw	$a0 12($s0)
	la	$a0 int_const2
	sw	$a0 16($s0)
	lw	$a0 -4($fp)
	sw	$a0 20($s0)
	b	label254
label253:
	lw	$a0 -4($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 int_const9
	lw	$t1 4($sp)
	move	$t2 $a0
	la	$a0 bool_const1
	addiu	$sp $sp 4
	beq	$t1 $t2 label255
	la	$a1 bool_const0
	jal	equality_test
label255:
	la	$t1 bool_const0
	beq	$a0 $t1 label256
	la	$a0 int_const7
	sw	$a0 12($s0)
	la	$a0 int_const4
	sw	$a0 16($s0)
	lw	$a0 -4($fp)
	sw	$a0 20($s0)
	b	label257
label256:
	la	$a0 int_const2
	sw	$a0 12($s0)
	la	$a0 int_const2
	sw	$a0 16($s0)
	lw	$a0 -4($fp)
	sw	$a0 20($s0)
label257:
label254:
label251:
label248:
label245:
label242:
	move	$a0 $s0
	addiu	$sp $sp 4
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 16
	jr	$ra	

# end of generated code
