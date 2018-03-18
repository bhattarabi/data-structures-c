# File:     makefile
# Author:   Dan Brekke

# Description
# This makefile will compile the program

OBJECTS=main.o
EXE=prog
CC=g++

$(EXE):		$(OBJECTS)
		$(CC) -o $(EXE) $(OBJECTS)
		
main.o: 	main.cpp binarySearchTree.h binaryTree.h
		$(CC) -c main.cpp
		
clean:
		rm -rf $(OBJECTS) *~ $(EXE)

