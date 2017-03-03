/*
 * Node.hpp
 *
 *  Created on: Sep 21, 2015
 *      Author: Michael
 */
#include <iostream>

namespace Tree
{
template<typename T>
Node<T>::Node(): mLeft(nullptr),mRight(nullptr),mValue(T())
{
}

// deep the node and its children onto *this
template<typename T>
Node<T>::Node(const Node<T>& other)
{
	mLeft = nullptr;
	mRight = nullptr;
	mValue = other.getValue();

	if(other.getLeft() != nullptr )
	{
		//recursive. kinda.
		mLeft = new Node<T>(*other.getLeft());
	}
	if(other.getRight() != nullptr )
	{
		//recursive. kinda.
		mRight = new Node<T>(*other.getRight());
	}
}
template<typename T>
int Node<T>::getValue() const
{
	return mValue;
}
template<typename T>
Node<T>* Node<T>::getLeft() const
{
	return mLeft;
}
template<typename T>
Node<T>* Node<T>::getRight() const
{
	return mRight;
}
template<typename T>
void Node<T>::setRight(Node<T>* aRight)
{
	mRight = aRight;
}
template<typename T>
void Node<T>::setLeft(Node<T>* aLeft)
{
	mLeft = aLeft;
}
template<typename T>
void Node<T>::setValue(T aValue)
{
	mValue = aValue;
}
template<typename T>
void Node<T>::printValue() const
{
	std::cout<< mValue<<" ";
}
} // end of namespace Tree
