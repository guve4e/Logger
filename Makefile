TARGETS=LoggerImpl.o main.o log

CC = g++
CFLAGS = -Wall -g -O0 -Wno-attributes
GCC_VERSION = -std=c++1y 

all: $(TARGETS)

LoggerImpl.o: LoggerImpl.cpp LoggerImpl.h
	$(CC) $(CFLAGS) $(GCC_VERSION) -c LoggerImpl.cpp 
	
main.o: main.cpp
	$(CC) $(CFLAGS) $(GCC_VERSION) -c main.cpp 

log: main.o LoggerImpl.o Logger.h
	$(CC) $(CFLAGS) $(GCC_VERSION) -o log main.o LoggerImpl.o



clean:
	rm -f $(TARGETS)
	rm *.txt
