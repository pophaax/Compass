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

SOURCES_COMP = Compass.cpp
HEADERS_COMP = Compass.h
FILE_COMP = Compass.o

SOURCES_HMC = HMC6343.cpp
HEADERS_HMC = HMC6343.h
FILE_HMC = HMC6343.o

SOURCES_UTIL = Utility.cpp
HEADERS_UTIL  = Utility.h
FILE_UTIL  = Utility.o

FILES = $(FILE_HMC) $(FILE_UTIL) $(FILE_COMP)

SOURCES = $(SOURCES_HMC) $(SOURCES_UTIL) $(SOURCES_COMP)
HEADERS = $(HEADERS_HMC) $(HEADERS_UTIL) $(HEADERS_COMP)

$(FILE) : $(SOURCES) $(HEADERS)
	$(CC) $(SOURCES) $(FLAGS) $(LIBS) -c -o $(FILE)
	
all : $(FILES)
	
test : $(SOURCES) $(HEADERS) ../catch.hpp testCompass.cpp
	$(CC) $(SOURCES) testCompass.cpp $(LIBS) -o test
	
example : $(SOURCES) $(HEADERS) example.cpp
	$(CC) $(SOURCES) example.cpp $(LIBS) -o example

clean :
	rm -f $(FILES)
	rm -f test