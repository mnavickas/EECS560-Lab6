/*
 * Node.hpp
 *
 *  Created on: Sep 21, 2015
 *      Author: Michael
 */

#include "Node.hpp"
#include <iostream>

namespace Tree
{
Node::Node(): mLeft(nullptr),mRight(nullptr),mValue(-1)
{
}

// deep the node and its children onto *this
Node::Node(const Node& other)
{
	mLeft = nullptr;
	mRight = nullptr;
	mValue = other.getValue();

	if(other.getLeft() != nullptr )
	{
		//recursive. kinda.
		mLeft = new Node(*other.getLeft());
	}
	if(other.getRight() != nullptr )
	{
		//recursive. kinda.
		mRight = new Node(*other.getRight());
	}
}

int Node::getValue() const
{
	return mValue;
}
Node* Node::getLeft() const
{
	return mLeft;
}
Node* Node::getRight() const
{
	return mRight;
}
void Node::setRight(Node* aRight)
{
	mRight = aRight;
}
void Node::setLeft(Node* aLeft)
{
	mLeft = aLeft;
}
void Node::setValue(int aValue)
{
	mValue = aValue;
}
void Node::printValue() const
{
	std::cout<< mValue<<" ";
}
} // end of namespace Tree
