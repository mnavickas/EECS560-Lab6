Lab6:main.o heap.o
	g++ -std=c++11 -g main.o heap.o -o Lab6
	rm *.o

main.o: main.cpp heap.hpp BST/BinarySearchTree.hpp BST/Node.hpp
	g++ -std=c++11 -g -c main.cpp

heap.o: heap.cpp
	g++ -std=c++11 -g -c heap.cpp

clean:
	rm *.o  Lab6

remake:
	make clean  && make
