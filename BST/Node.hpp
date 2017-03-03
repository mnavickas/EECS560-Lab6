/*
 * Node.h
 *
 *  Created on: Sep 21, 2015
 *      Author: Michael
 */

#ifndef NODE_H
#define NODE_H
namespace Tree
{
	template<typename T>
	class Node
	{
	public:
		Node();
		Node(const Node<T>& other);

		void setValue(T aValue);
		T getValue() const;

		Node<T>* getLeft() const;
		Node<T>* getRight() const;

		void setLeft(Node<T>* aLeft);
		void setRight(Node<T>* Right);
		void printValue() const;

	private:
		T mValue;
		Node<T>* mLeft;
		Node<T>* mRight;
	};
} // end of namespace Tree
#include "Node.cpp"

#endif
