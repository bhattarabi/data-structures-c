#File:      makefile
#Name:      Binaya Bhattarai
#Class:     CSIS 352
#Program:   assignment 1
#Date:      1/19/2016

# This file contains the make instructions for bhattarai1.

CC = g++
OBJECTS = currencymain.o currency.o
EXE = prog1
CFLAGS = -c
LFLAGS = -o
ZIP = bhattarai1.tar.gz
TFLAGS = cvzf

$(EXE):		$(OBJECTS)
		$(CC) $(LFLAGS) $(EXE) $(OBJECTS)

currencymain.o: currencymain.cpp currency.h
		$(CC) $(CFLAGS) currencymain.cpp

currency.o:	currency.cpp currency.h
		$(CC) $(CFLAGS) currency.cpp

clean:
		rm -rf prog1 *~ $(ZIP) $(OBJECTS) $(EXE)

tar:
		tar $(TFLAGS) $(ZIP) currency.h\
		currency.cpp currencymain.cpp makefile README