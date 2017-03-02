Lab5:main.o BinarySearchTree.o Node.o
	g++ -std=c++11 -g main.o BinarySearchTree.o Node.o -o Lab5
	rm *.o

main.o: main.cpp BinarySearchTree.hpp Node.hpp
	g++ -std=c++11 -g -c main.cpp

BinarySearchTree.o: BinarySearchTree.cpp
	g++ -std=c++11 -g -c BinarySearchTree.cpp

Node.o: Node.cpp
	g++ -std=c++11 -g -c Node.cpp

clean:
	rm *.o  Lab5

remake:
	make clean  && make
