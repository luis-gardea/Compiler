#!/usr/bin/python

import os, sys

# Open a file
path = "tests/"
dirs = os.listdir( path )

if len(sys.argv) == 2:
	path = str(sys.argv[1])
	filename = path[path.find('/')+1:]
	name = filename[:filename.find('.')]
	command1 = "/usr/class/cs143/bin/lexer " + filename + " | /usr/class/cs143/bin/parser | /usr/class/cs143/bin/semant | ./cgen >& output/" + name + "out.s"
	command2 = "/usr/class/cs143/bin/lexer " + filename + " | /usr/class/cs143/bin/parser | /usr/class/cs143/bin/semant | /usr/class/cs143/bin/cgen >& output/" + name + "ref.s"
	os.system(command1)
	os.system(command2)
	print filename
	diff_cmd = "diff output/" + name + "out.s" + " output/" + name + "ref.s"
	#os.system(diff_cmd)
else:
# This would print all the files and directories
	for file in dirs:
		if file[0] != '.':
			command1 = "/usr/class/cs143/bin/lexer " + file + " | /usr/class/cs143/bin/parser | ./semant >& output/" + file + "out"
			command2 = "/usr/class/cs143/bin/lexer " + file + " | /usr/class/cs143/bin/parser | /usr/class/cs143/bin/semant >& output/" + file + "ref"
			os.system(command1)
			os.system(command2)
			print file
			diff_cmd = "diff output/" + file + "out" + " output/" + file + "ref"
			os.system(diff_cmd)
			print '\n'