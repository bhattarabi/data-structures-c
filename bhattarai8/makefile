#File:      makefile
#Name:      Binaya Bhattarai
#Class:     CSIS 352
#Program:   assignment 8
#Date:      5/4/2016

# This file contains make instructions for bhattarai8.

CC = g++
OBJECTS = main.o symbol.o
EXE = prog8
CFLAGS = -c
LFLAGS = -o

$(EXE):		$(OBJECTS)
		$(CC) $(LFLAGS) $(EXE) $(OBJECTS)

main.o: 	main.cpp hashtable.h symbol.h
		$(CC) $(CFLAGS) main.cpp

symbol.o:	symbol.cpp symbol.h
		$(CC) $(CFLAGS) symbol.cpp

clean:
		rm -rf prog8 *~ $(ZIP) $(OBJECTS) $(EXE)