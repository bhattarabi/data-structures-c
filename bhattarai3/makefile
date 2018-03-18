#File:      makefile
#Name:      Binaya Bhattarai
#Class:     CSIS 352
#Program:   assignment 3
#Date:      2/22/2016

# This file contains make instructions for bhattarai3.

CC = g++
OBJECTS = main.o
EXE = prog3
CFLAGS = -c
LFLAGS = -o

$(EXE):		$(OBJECTS)
		$(CC) $(LFLAGS) $(EXE) $(OBJECTS)

main.o: 	main.cpp array.h
		$(CC) $(CFLAGS) main.cpp

clean:
		rm -rf prog3 *~ $(OBJECTS) $(EXE)
