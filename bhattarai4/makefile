#File:      makefile
#Name:      Binaya Bhattarai
#Class:     CSIS 352
#Program:   assignment 4
#Date:      3/10/2016

# This file contains make instructions for bhattarai4.

CC = g++
OBJECTS = main.o
EXE = prog4
CFLAGS = -c
LFLAGS = -o

$(EXE):		$(OBJECTS)
		$(CC) $(LFLAGS) $(EXE) $(OBJECTS)

main.o: 	main.cpp linkedQueue.h
		$(CC) $(CFLAGS) main.cpp

clean:
		rm -rf prog3 *~ $(OBJECTS) $(EXE)
