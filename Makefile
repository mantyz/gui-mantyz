CC=g++
CCFLAGS=-Wall -std=c++11
MAKE=make
CLEAN=rm -f
PROGRAM_NAME=test

$(PROGRAM_NAME): test.cpp
	$(CC) $(CCFLAGS) -o $(PROGRAM_NAME) test.cpp `pkg-config gtkmm-3.0 --cflags --libs`

clean:
	$(CLEAN) $(PROGRAM_NAME) *.o
