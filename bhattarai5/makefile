#File:      makefile
#Name:      Binaya Bhattarai
#Class:     CSIS 352
#Program:   assignment 5
#Date:      3/30/2016

#This file contains make instructions for bhattarai5.

CC = g++
OBJECTS = main.o city.o
EXE = prog5
CFLAGS = -c
LFLAGS = -o

$(EXE):		$(OBJECTS)
		$(CC) $(LFLAGS) $(EXE) $(OBJECTS)

main.o: 	main.cpp graph.h
		$(CC) $(CFLAGS) main.cpp

city.o:		city.cpp city.h
		$(CC) $(CFLAGS) city.cpp
clean:
		rm -rf prog5 *~ $(OBJECTS) $(EXE)