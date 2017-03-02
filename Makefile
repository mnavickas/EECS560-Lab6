Lab6:main.o heap.o BinarySearchTree.o Node.o
	g++ -std=c++11 -g main.o heap.o BinarySearchTree.o Node.o -o Lab6
	rm *.o

main.o: main.cpp heap.hpp
	g++ -std=c++11 -g -c main.cpp

heap.o: heap.cpp
	g++ -std=c++11 -g -c heap.cpp

BinarySearchTree.o: BST/BinarySearchTree.cpp
	g++ -std=c++11 -g -c BST/BinarySearchTree.cpp

Node.o: BST/Node.cpp
	g++ -std=c++11 -g -c BST/Node.cpp

clean:
	rm *.o  Lab6

remake:
	make clean  && make
