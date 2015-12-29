all: LinkedList

LinkedList: LinkedList.o
	g++ LinkedList.o -o LinkedList
	
LinkedList.o: LinkedList.cpp
	g++ -c LinkedList.cpp