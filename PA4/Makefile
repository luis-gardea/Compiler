
ASSN = 4
CLASS= cs143
CLASSDIR= /afs/ir/class/cs143
LIB= -L/usr/pubsw/lib -lfl 
# LIB= -L/usr/pubsw/lib -lfl -R/usr/pubsw/lib
AR= gar
ARCHIVE_NEW= -cr
RANLIB= gar -qs

SRC= cgen.cc cgen.h cgen_supp.cc cool-tree.h cool-tree.handcode.h emit.h example.cl README
CSRC= cgen-phase.cc utilities.cc stringtab.cc dumptype.cc tree.cc cool-tree.cc ast-lex.cc ast-parse.cc handle_flags.cc 
TSRC= mycoolc
CGEN=
HGEN= 
LIBS= lexer parser semant
CFIL= cgen.cc cgen_supp.cc ${CSRC} ${CGEN}
LSRC= Makefile
OBJS= ${CFIL:.cc=.o}
OUTPUT= good.output bad.output


CPPINCLUDE= -I. -I./include -I./src


FFLAGS = -d8 -ocool-lex.cc
BFLAGS = -d -v -y -b cool --debug -p cool_yy

CC=g++
CFLAGS=-g -Wall -Wno-unused -Wno-write-strings -Wno-deprecated ${CPPINCLUDE} -DDEBUG -std=c++11
FLEX=flex ${FFLAGS}
BISON= bison ${BFLAGS}
DEPEND = ${CC} -MM ${CPPINCLUDE}
SHELL = /bin/bash

cgen : ${OBJS}
	${CC} ${CFLAGS} ${OBJS} ${LIB} -o $@

${OUTPUT}:	cgen
	@rm -f ${OUTPUT}
	./mycoolc  example.cl &> example.output 

dotest:	cgen example.cl
	@echo "\nRunning code generator on example.cl\n"
	-./mycoolc example.cl

submit: cgen
	$(CLASSDIR)/bin/pa_submit PA4 .

clean:
	rm -f cgen ${OBJS}

# build rules

%.o : %.cc
	${CC} ${CFLAGS} -c $< -o $@

%.o : src/%.cc
	${CC} ${CFLAGS} -c $< -o $@

# extra dependencies 
