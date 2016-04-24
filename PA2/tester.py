#!/usr/bin/python

import os, sys

# Open a file
path = "tests/"
dirs = os.listdir( path )

# This would print all the files and directories
for file in dirs:
	if file[0] != '.':
		command1 = "./myparser tests/" + file + " > tests/output/out" + file
		command2 = "/usr/class/cs143/bin/lexer tests/" + file + " | /usr/class/cs143/bin/parser > tests/output/ref" + file
		os.system(command1)
		os.system(command2)