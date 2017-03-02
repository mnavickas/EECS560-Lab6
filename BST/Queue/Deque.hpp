/**
*	@file : Deque.h
*	@author :  Michael Navickas
*	@date : 2015.09.23
*	Purpose: Header for the Deque, declares member methods and variables
*/
#ifndef DEQUE_H
#define DEQUE_H
#include "QueueNode.hpp"

namespace Queue
{
	template<typename T>
	class Deque
	{
	public:
		/**
		*  @pre None
		*  @post Creates and initializes and empty templated Deque
		*  @return Initialized empty templated Deque
		*/
		Deque();
		/**
		*  @pre Deque structure
		*  @post Deconsructs Deque by calling remove methods
		*/
		~Deque();
		/**
		*  @pre Deque
		*  @post None
		*  @return true if empty, else false
		*/
		bool isEmpty() const;
		/**
		*  @pre Deque
		*  @post None
		*  @return size of LinkedList
		*/
		int size() const;
		/**
		*  @pre Deque of any number of entries
		*  @post Adds a node with chosen value of type T to the front of the list
		*  @return None
		*/
		void pushFront(T value);
		/**
		*  @pre Deque of any number of entries
		*  @post Adds a node with chosen value of type T to the back of the list
		*  @return None
		*/
		void pushBack(T value);
		/**
		*  @pre Deque of any number of entries
		*  @post Removes last node in the list if it exists
		*  @return True if a node was able to be removed
		*/
		bool popBack();
		/**
		*  @pre Deque of any number of entries
		*  @post Removes first node in the list if it exists
		*  @return True if a node was able to be removed
		*/
		bool popFront();

		Node<T>* peekFront() const;

		Node<T>* peekBack() const;
		/**
		*  @pre None
		*  @post Prints values of Nodes in the Deque
		*  @return None
		*/
		void printList() const;
	private:
		Node<T>* mFront;
		Node<T>* mBack;
		int mSize;
	};
}
	#include "Deque.cpp"
#endif
