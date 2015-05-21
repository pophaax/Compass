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
LIBS = -lpthread -lwiringPi -lrt -I$(SAILINGROBOTS_HOME)

SOURCES_MOCK = MockCompass.cpp
HEADERS_MOCK = MockCompass.h
FILE_MOCK = MockCompass.o

SOURCES_COMP = Compass.cpp
HEADERS_COMP = Compass.h
FILE_COMP = Compass.o

SOURCES_HMC = HMC6343.cpp
HEADERS_HMC = HMC6343.h
FILE_HMC = HMC6343.o

SOURCES_UTIL = Utility.cpp
HEADERS_UTIL  = Utility.h
FILE_UTIL  = Utility.o

FILES = $(FILE_HMC) $(FILE_UTIL) $(FILE_COMP) $(FILE_MOCK)

SOURCES = $(SOURCES_COMP) $(SOURCES_HMC) $(SOURCES_UTIL) $(SOURCES_MOCK)
HEADERS = $(HEADERS_COMP) $(HEADERS_HMC) $(HEADERS_UTIL) $(HEADERS_MOCK)

all : $(FILES)

$(FILE_MOCK) : $(SOURCES_MOCK) $(HEADERS_MOCK)
	$(CC) $(SOURCES_MOCK) $(FLAGS) $(LIBS) -c -o $(FILE_MOCK)

$(FILE_COMP) : $(SOURCES_COMP) $(HEADERS_COMP)
	$(CC) $(SOURCES_COMP) $(FLAGS) $(LIBS) -c -o $(FILE_COMP)

$(FILE_HMC) : $(SOURCES_HMC) $(HEADERS_HMC)
	$(CC) $(SOURCES_HMC) $(FLAGS) $(LIBS) -c -o $(FILE_HMC)

$(FILE_UTIL) : $(SOURCES_UTIL) $(HEADERS_UTIL)
	$(CC) $(SOURCES_UTIL) $(FLAGS) $(LIBS) -c -o $(FILE_UTIL)

example : $(SOURCES) $(HEADERS) example.cpp
	$(CC) $(SOURCES) example.cpp $(LIBS) -o example

clean :
	rm -f $(FILES)