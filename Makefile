#######################################################
#
#    Aland Sailing Robot
#    ===========================================
#    compass
#    -------------------------------------------
#
#######################################################

CC = g++
FLAGS = -Wall -pedantic -Werror -std=c++14 
LIBS = -lpthread -lwiringPi -lrt

SOURCES = Compass.cpp MockCompass.cpp
HEADERS = Compass.h MockCompass.h
FILE = Compass.o MockCompass.o

all : $(FILE)

$(FILE) : $(SOURCES) $(HEADERS)
	$(CC) $(SOURCES) $(FLAGS) $(LIBS) -c -o $(FILE)

test : $(SOURCES) $(HEADERS) ../catch.hpp testCompass.cpp
	$(CC) $(SOURCES) testCompass.cpp $(LIBS) -o test

clean :
	rm -f $(FILE)
	rm -f test