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

SOURCES_COMPASS = Compass.cpp
HEADERS_COMPASS = Compass.h
FILE_COMPASS = Compass.o

SOURCES_MOCK = MockCompass.cpp
HEADERS_MOCK = MockCompass.h
FILE_MOCK = MockCompass.o

SOURCES_HMC = HMC6343.cpp
HEADERS_HMC = HMC6343.h
FILE_HMC = HMC6343.o

FILES = $(FILE_COMPASS) $(FILE_MOCK) $(FILE_HMC)

all : $(FILES)

$(FILE_COMPASS) : $(SOURCES_COMPASS) $(HEADERS_COMPASS)
	$(CC) $(SOURCES_COMPASS) $(FLAGS) $(LIBS) -c -o $(FILE_COMPASS)

$(FILE_MOCK) : $(SOURCES_MOCK) $(HEADERS_MOCK)
	$(CC) $(SOURCES_MOCK) $(FLAGS) $(LIBS) -c -o $(FILE_MOCK)

$(FILE_HMC) : $(SOURCES_HMC) $(HEADERS_HMC)
	$(CC) $(SOURCES_HMC) $(FLAGS) $(LIBS) -c -o $(FILE_HMC)

test : $(SOURCES) $(HEADERS) ../catch.hpp testCompass.cpp
	$(CC) $(SOURCES) testCompass.cpp $(LIBS) -o test

clean :
	rm -f $(FILES)
	rm -f test