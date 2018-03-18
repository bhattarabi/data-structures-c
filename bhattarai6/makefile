#File:      makefile
#Name:      Binaya Bhattarai
#Class:     CSIS 352
#Program:   assignment 6
#Date:      4/6/2016

#This file contains make instructions for bhattarai6.

CC = g++
OBJECTS = main.o date.o
EXE = prog6
CFLAGS = -c
LFLAGS = -o

$(EXE):		$(OBJECTS)
		$(CC) $(LFLAGS) $(EXE) $(OBJECTS)

main.o: 	main.cpp sortedlist.h
		$(CC) $(CFLAGS) main.cpp
		
date.o:		date.cpp date.h
		$(CC) $(CFLAGS) date.cpp

clean:
		rm -rf prog6 *~ $(OBJECTS) $(EXE)