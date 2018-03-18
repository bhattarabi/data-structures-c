#File:      makefile
#Name:      Binaya Bhattarai
#Class:     CSIS 352
#Program:   assignment 2
#Date:      2/13/2016

# This file contains make instructions for bhattarai2.

CC = g++
OBJECTS = main.o date.o
EXE = prog2
CFLAGS = -c
LFLAGS = -o
ZIP = bhattarai2.tar.gz
TFLAGS = cvzf

$(EXE):		$(OBJECTS)
		$(CC) $(LFLAGS) $(EXE) $(OBJECTS)

main.o: 	main.cpp date.h
		$(CC) $(CFLAGS) main.cpp

date.o:		date.cpp date.h
		$(CC) $(CFLAGS) date.cpp

clean:
		rm -rf prog2 *~ $(ZIP) $(OBJECTS) $(EXE)

tar:
		tar $(TFLAGS) $(ZIP) date.h dateexception.h\
		date.cpp main.cpp makefile README
