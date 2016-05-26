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
	command2 = "mv -f " + name + ".s " + "output1"
	command3 = "/usr/class/cs143/bin/coolc " + filename
	command4 = "mv -f " + name + ".s " + name + "ref.s"
	command5 = "mv -f " + name + "ref.s output1" 
	os.system(command1)
	os.system(command2)
	os.system(command3)
	os.system(command4)
	os.system(command5)
	# print filename
	# command6 = "./spim " + "output1/" + name + ".s >& output2/" + name
	# command7 = "./spim " + "output1/" + name + "ref.s >& output2/" + name + "ref"
	# os.system(command6)
	# os.system(command7)
	# diff_cmd = "diff output2/" + name + " output2/" + name
	# os.system(diff_cmd)
else:
# This would print all the files and directories
	for filename in dirs:
		if filename[0] != '.':
			print filename, "\n"
			name = filename[:filename.find('.')]
			command1 = "./mycoolc " + "tests/"+ filename;
			command2 = "mv -f " + name + ".s " + "output1"
			command3 = "./coolc " + "tests/"+ filename
			command4 = "mv -f " + name + ".s " + name + "ref.s"
			command5 = "mv -f " + name + "ref.s output1" 
			os.system(command1)
			os.system(command2)
			os.system(command3)
			print command4
			print command5
			os.system(command4)
			os.system(command5)
			# print filename
			# command6 = "./spim " + "output1/" + name + ".s >& output2/" + name
			# command7 = "./spim " + "output1/" + name + "ref.s >& output2/" + name
			# os.system(command6)
			# os.system(command7)
			# diff_cmd = "diff output2/" + name + " output2/" + name
			# os.system(diff_cmd)