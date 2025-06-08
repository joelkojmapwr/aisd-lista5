CXX=g++
CXXFLAGS = -Wall -Wextra -std=c++17

all: mainGraph.exe

mainGraph.exe: mainGraph.o completeGraph.o
	$(CXX) $(CXXFLAGS) mainGraph.o completeGraph.o -o mainGraph.exe

mainGraph.o: mainGraph.cpp completeGraph.h
	$(CXX) $(CXXFLAGS) -c mainGraph.cpp

completeGraph.o: completeGraph.cpp completeGraph.h
	$(CXX) $(CXXFLAGS) -c completeGraph.cpp

clean:
	rm -f *.o *.exe