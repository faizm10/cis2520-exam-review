
##
## This file builds the week 1 lab
##

##
## Some macros (makefile 'variables') are defined by default
## by make(1).  The ones relevant to C compiling are:
##  CC     : the name of the compiler (defaults to system compiler)
##  CFLAGS : the flags (options) to pass to the compiler
##
## There are similar macros for other languages, for example C++ uses
##  CXX      : the name of the c++ compiler (defaults to system compiler)
##  CXXFLAGS : the flags (options) to pass to the c++ compiler


## explicitly add debugger support to each file compiled
CFLAGS = -g -Wall

## uncomment/change this next line if you need to use a non-default compiler
#CC = cc


OBJS = dataReader.o mainline.o
EXE  = lab1


## default (first) target - create executable file
## implicit rules create the objects
$(EXE) : $(OBJS)
	$(CC) $(CFLAGS) -o $(EXE) $(OBJS)

## it is always good practice to provide a rule to clean things up
clean :
	- rm -f $(EXE)
	- rm -f $(OBJS)
