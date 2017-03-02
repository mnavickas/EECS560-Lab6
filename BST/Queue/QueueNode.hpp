/**
*	@file : Node.h
*	@author :  Michael Navickas
*	@date : 2015.09.23
*	Purpose: Header for the templated Node, declares member variables and methods
*/
#ifndef QUEUENODE_H
#define QUEUENODE_H
namespace Queue
{
	template <typename T>
	class Node
	{
	public:
		/**
		*  @pre None
		*  @post Creates and initializes and default Node.
		*  @return Initialized Node with m_next and m_prev pointer to nullptr and value to T();
		*/
		Node();
		/**
		*  @pre Node Object with any int
		*  @post Node Object with the chosen value
		*  @return None
		*/
		void setValue(T aValue);
		/**
		*  @pre Node Object a pointer to nullptr or a Node
		*  @post Node Object with a m_next pointer to chosen Node or nullptr
		*  @return None
		*/
		void setNext(Node<T>* aNext);
		/**
		*  @pre Node Object a pointer to nullptr or a Node
		*  @post Node Object with a m_prev pointer to chosen Node or nullptr
		*  @return None
		*/
		void setPrevious(Node<T>* aPrevios);
		/**
		*  @pre Node Object
		*  @post None
		*  @return Value stored in the Node
		*/
		T getValue() const;
		/**
		*  @pre Node Object
		*  @post None
		*  @return Next Node or nullptr that m_next pointer of Node is looking at
		*/
		Node<T>* getNext() const;
		/**
		*  @pre Node Object
		*  @post None
		*  @return previous Node or nullptr that m_prev pointer of Node is looking at
		*/
		Node<T>* getPrevious() const;

	private:
		T mValue;
		Node<T>* mPrevious;
		Node<T>* mNext;
	};
}
#include "QueueNode.cpp"
#endif
