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
	class Node
	{
	public:
		Node();
		Node(const Node& other);

		void setValue(int aValue);
		int getValue() const;

		Node* getLeft() const;
		Node* getRight() const;

		void setLeft(Node* aLeft);
		void setRight(Node* Right);
		void printValue() const;

	private:
		int mValue;
		Node* mLeft;
		Node* mRight;
	};
} // end of namespace Tree

#endif
