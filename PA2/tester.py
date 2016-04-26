#!/usr/bin/python

import os, sys

# Open a file
path = "tests/"
dirs = os.listdir( path )

if len(sys.argv) == 2:
	command1 = "./myparser tests/" + str(sys.argv[1]) + " >& tests/output/" + str(sys.argv[1]) + "out"
	command2 = "/usr/class/cs143/bin/lexer tests/" + str(sys.argv[1]) + " | /usr/class/cs143/bin/parser >& tests/output/" + str(sys.argv[1]) + "ref"
	os.system(command1)
	os.system(command2)
	print str(sys.argv[1])
	diff_cmd = "diff tests/output/" + str(sys.argv[1]) + "out" + " tests/output/" + str(sys.argv[1]) + "ref"
	os.system(diff_cmd)
else:
	# This would print all the files and directories
	for file in dirs:
		if file[0] != '.' and file != 'output' and file == '2':
			command1 = "./myparser tests/" + file + " >& tests/output/" + file + "out"
			command2 = "/usr/class/cs143/bin/lexer tests/" + file + " | /usr/class/cs143/bin/parser >& tests/output/" + file + "ref"
			os.system(command1)
			os.system(command2)
			print file
			diff_cmd = "diff tests/output/" + file + "out" + " tests/output/" + file + "ref"
			os.system(diff_cmd)
			print '\n'