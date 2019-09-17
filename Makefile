###################################
# Makefile (Linux)
# CSCI 360 - Project 1 - Group 2
# Created on September 16, 2019
###################################

# Flags
CPPFLAGS = -g -std=c++11 -Wall

# Executable directory
EXEC_DIR=.

# Include
INCLUDE = -I.

# Libraries
LIBS = -L/usr/lib -L/usr/local/lib

# Rule for .cpp files
# .SUFFIXES: .cc.o
.cc.o:
	g++ $(CPPFLAGS) $(INCLUDE) -c $< -o $@

# Program
OBJS=Declaration.o ForLoop.o Function.o LogicOperation.o Parser.o main.o
PROGRAM=translator
$(PROGRAM): $(OBJS)
	g++ $(CPPFLAGS) -o $(EXEC_DIR)/$@ $(OBJS) $(INCLUDES) $(LIBS)

## Recipes
# Compile all
all:
	make $(PROGRAM)

# Clean object (*.o) files
clean:
	(rm -f *.o; rm -f translator)
