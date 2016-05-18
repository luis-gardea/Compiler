#!/usr/bin/python

import os, sys

# Open a file
path = "tests/"
dirs = os.listdir( path )

if len(sys.argv) == 2:
	path = str(sys.argv[1])
	filename = path[path.find('/')+1:]
	# print filename
	name = filename[:filename.find('.')]
	command1 = "./mycoolc " + filename;
	command2 = "mv " + name + ".s " + "output/"
	command3 = "/usr/class/cs143/bin/coolc " + filename
	command4 = "mv " + name + ".s " + name + "ref.s"
	command5 = "mv " + name + "ref.s output/" 
	os.system(command1)
	os.system(command2)
	os.system(command3)
	os.system(command4)
	os.system(command5)
	# print filename
	diff_cmd = "diff tests/" + name + ".s" + " tests/" + name + "ref.s"
	#os.system(diff_cmd)
else:
# This would print all the files and directories
	for filename in dirs:
		if filename[0] != '.':
			name = filename[:filename.find('.')]
			command1 = "./mycoolc " + filename;
			command2 = "mv " + name + ".s " + "output/"
			command3 = "/usr/class/cs143/bin/coolc " + filename
			command4 = "mv " + name + ".s " + name + "ref.s"
			command5 = "mv " + name + "ref.s output/" 
			os.system(command1)
			os.system(command2)
			os.system(command3)
			os.system(command4)
			os.system(command5)
			# print filename
			diff_cmd = "diff tests/" + name + ".s" + " tests/" + name + "ref.s"
			#os.system(diff_cmd)