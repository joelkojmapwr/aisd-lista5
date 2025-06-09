CXX=g++
CXXFLAGS = -Wall -Wextra -std=c++17

all: completeGraph.exe mainKruskal.exe mainPrim.exe propagateInfo.exe

completeGraph.exe: completeGraph.o common.o
	$(CXX) $(CXXFLAGS) completeGraph.o common.o -o completeGraph.exe

propagateInfo.exe: propagateInfo.o common.o
	$(CXX) $(CXXFLAGS) propagateInfo.o common.o -o propagateInfo.exe

mainKruskal.exe: mainKruskal.o kruskal.o common.o Graph.o
	$(CXX) $(CXXFLAGS) mainKruskal.o kruskal.o common.o Graph.o -o mainKruskal.exe

Graph.o: Graph.cpp Graph.hpp
	$(CXX) $(CXXFLAGS) -c Graph.cpp

mainKruskal.o: mainKruskal.cpp kruskal.hpp common.hpp
	$(CXX) $(CXXFLAGS) -c mainKruskal.cpp

completeGraph.o: completeGraph.cpp completeGraph.hpp 
	$(CXX) $(CXXFLAGS) -c completeGraph.cpp

common.o: common.cpp common.hpp
	$(CXX) $(CXXFLAGS) -c common.cpp

kruskal.o: kruskal.cpp kruskal.hpp
	$(CXX) $(CXXFLAGS) -c kruskal.cpp

prim.o: prim.cpp prim.hpp
	$(CXX) $(CXXFLAGS) -c prim.cpp

mainPrim.exe: mainPrim.o prim.o common.o Graph.o
	$(CXX) $(CXXFLAGS) mainPrim.o prim.o common.o Graph.o -o mainPrim.exe

clean:
	rm -f *.o *.exe