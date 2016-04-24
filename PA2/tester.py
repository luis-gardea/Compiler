#!/usr/bin/python

import os, sys

# Open a file
path = "tests/"
dirs = os.listdir( path )

# This would print all the files and directories
for file in dirs:
   command1 = "./myparser " + file + " >! output/out" + file
   command2 = "/usr/class/cs143/bin/lexer " + file + " | /usr/class/cs143/bin/parser >! output/ref" + file
   os.system(command1)
   os.system(command2)