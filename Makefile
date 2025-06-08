CXX=g++
CXXFLAGS = -Wall -Wextra -std=c++17

all: completeGraph.exe

completeGraph.exe: completeGraph.o common.o
	$(CXX) $(CXXFLAGS) completeGraph.o common.o -o completeGraph.exe

# mainGraph.o: mainGraph.cpp completeGraph.h
# 	$(CXX) $(CXXFLAGS) -c mainGraph.cpp

completeGraph.o: completeGraph.cpp completeGraph.hpp 
	$(CXX) $(CXXFLAGS) -c completeGraph.cpp

common.o: common.cpp common.hpp
	$(CXX) $(CXXFLAGS) -c common.cpp

clean:
	rm -f *.o *.exe