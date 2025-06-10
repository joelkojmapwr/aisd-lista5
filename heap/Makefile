# Makefile for heap project

CC = g++
CFLAGS = -Wall -Wextra -O2 -std=c++17

all: mainHeap.exe

mainHeap.exe: BinomialHeap.o mainHeap.o common.o
	$(CC) $(CFLAGS) -o mainHeap.exe BinomialHeap.o mainHeap.o common.o

BinomialHeap.o: BinomialHeap.cpp BinomialHeap.hpp
	$(CC) $(CFLAGS) -c BinomialHeap.cpp

mainHeap.o: mainHeap.cpp BinomialHeap.hpp common.hpp
	$(CC) $(CFLAGS) -c mainHeap.cpp

common.o: common.cpp common.hpp
	$(CC) $(CFLAGS) -c common.cpp

clean:
	rm -f *.o *.exe

