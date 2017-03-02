#include "BinarySearchTree.hpp"
#include <iostream>

namespace Tree
{
/******************************************************************************
 *
 ******************************************************************************/
BinarySearchTree::BinarySearchTree(): mRoot(nullptr)
{
}

/******************************************************************************
 *
 ******************************************************************************/
BinarySearchTree::~BinarySearchTree()
{
	if(mRoot == nullptr) return;
	deleteTree( mRoot );
}

/******************************************************************************
 *
 ******************************************************************************/
bool BinarySearchTree::isEmpty() const
{
	return (mRoot == nullptr);
}

/******************************************************************************
 *
 ******************************************************************************/
bool BinarySearchTree::insert(int value)
{
	if( mRoot == nullptr )
	{
		mRoot = new Node();
		mRoot->setValue(value);
		return true;
	}
	else
	{
		return insert( value, mRoot );
	}
}

/******************************************************************************
 *
 ******************************************************************************/
Node* BinarySearchTree::search(int value) const
{
	if( mRoot == nullptr )
	{
		return nullptr;
	}
	return search( value, mRoot );
}

void BinarySearchTree::remove(int value)
{
	if(isEmpty())
	{
		return;
	}

	bool removed;
	do{
		removed = false;
	remove(mRoot,value, &removed);
	}while(removed);
}

 /******************************************************************************
  *
  ******************************************************************************/
 int BinarySearchTree::deleteMin()
 {
 	if(mRoot == nullptr)
 	{
 		return -1;
 	}
 	return deleteMin(mRoot, nullptr);
 }
 /******************************************************************************
  *
  ******************************************************************************/
 int BinarySearchTree::deleteMax()
 {
 	if(mRoot == nullptr)
 	{
 		return -1;
 	}
 	return deleteMax(mRoot, nullptr);
 }

/******************************************************************************
 *
 ******************************************************************************/
void BinarySearchTree::preorder() const
{
	if(isEmpty())
	{
		std::cout << "Empty" << std::endl;
		return;
	}
	preorder(mRoot);
	std::cout<<std::endl;
}
/******************************************************************************
 *
 ******************************************************************************/
void BinarySearchTree::inorder() const
{
	if(isEmpty())
	{
		std::cout << "Empty" << std::endl;
		return;
	}
	inorder(mRoot);
	std::cout<<std::endl;
}
/******************************************************************************
 *
 ******************************************************************************/
void BinarySearchTree::levelorder() const
{
	if(isEmpty())
	{
		std::cout << "Empty" << std::endl;
		return;
	}
	Queue queue;

	queue.pushBack(mRoot);

	while( !queue.isEmpty() )
	{
		QNode* temp = queue.peekFront();
		Node* node = temp->getValue();
		queue.popFront();

		if( nullptr != node->getLeft() )
		{
			queue.pushBack( node->getLeft() );
		}

		if( nullptr != node->getRight() )
		{
			queue.pushBack( node->getRight() );
		}
		node->printValue();
	}
	std::cout<<std::endl;
}

// private

/******************************************************************************
 *
 ******************************************************************************/
bool BinarySearchTree::insert(int value, Node* subtree)
{
	if( value < subtree->getValue() )
	{
		if( subtree->getLeft() == nullptr )
		{
			subtree->setLeft( new Node() );
			subtree->getLeft()->setValue(value);
			return true;
		}
		else
		{
			//recurse
			return insert( value, subtree->getLeft() );
		}
	}
	else
	{
		if( subtree->getRight() == nullptr )
		{
			subtree->setRight( new Node() );
			subtree->getRight()->setValue(value);
			return true;
		}
		else
		{
			//recurse
			return insert( value, subtree->getRight() );
		}
	}
}
/******************************************************************************
 *
 ******************************************************************************/
Node* BinarySearchTree::search(int value, Node* subtree) const
{
	if( subtree->getValue() == value )
	{
		return subtree;
	}

	// check left
	if( value < subtree->getValue() )
	{
		if( subtree->getLeft() == nullptr )
		{
			return nullptr;
		}
		else
		{
			return search( value, subtree->getLeft() );
		}
	}
	else // check right
	{
		if( subtree->getRight() == nullptr )
		{
			return nullptr;
		}
		else
		{
			return search( value, subtree->getRight() );
		}
	}
}
/******************************************************************************
 *
 ******************************************************************************/
Node* BinarySearchTree::remove(Node* node, int value, bool* removed)
{
if(node == nullptr)
{
	return nullptr;
}
if( value < node->getValue() )
{
	//value would be in left tree
	node->setLeft( remove(node->getLeft(),value, removed) );
}
else if( value > node->getValue() )
{
	// value would be in right tree
	node->setRight( remove(node->getRight(), value, removed) );
}
else
{
	//this is the value

	if(node->getLeft() == nullptr && node->getRight() == nullptr)
	{
		//no children;
		*removed = true;
		if(node == mRoot)
		{
			mRoot = nullptr;
		}
		//no children
		delete node;
		node = nullptr;
	}
	else if ( node->getLeft() == nullptr )
	{
		*removed = true;
		//only right child
		Node* temp = node;
		node = node->getRight();
		if(temp == mRoot)
		{
			mRoot = node;
		}
		delete temp;
	}
	else if( node->getRight() == nullptr )
	{
		*removed = true;
		//only left child
		Node* temp = node;
		node = node->getLeft();
		if(temp == mRoot)
		{
			mRoot = node;
		}
		delete temp;
	}
	else
	{
		//two children
		Node* temp = findMin( node->getRight() );
		node->setValue( temp->getValue() );
		node->setRight( remove( node->getRight(), temp->getValue(),removed ) );
	}
}
return node;
}
/******************************************************************************
 *
 ******************************************************************************/
int BinarySearchTree::deleteMin(Node* node, Node* previous)
{
	if(node->getLeft() != nullptr)
	{
		return deleteMin(node->getLeft(), node);
	}
	else // this is the smallest
	{
		if(previous != nullptr)
		{
           // could be nullptr, we would be assigning nullptr anyways
			previous->setLeft( node->getRight() );

		}
		else // it was root;
		{
			mRoot = node->getRight();
		}
		int value = node->getValue();
		delete node;
		return value;
	}

}

/******************************************************************************
 *
 ******************************************************************************/
int BinarySearchTree::deleteMax(Node* node, Node* previous)
{
	if(node->getRight() != nullptr)
	{
		return deleteMax(node->getRight(), node);
	}
	else // this is the largest
	{
		if(previous != nullptr)
		{
           // could be nullptr, we would be assigning nullptr anyways
			previous->setRight( node->getLeft() );
		}
		else // it was root;
		{
			mRoot = node->getLeft();
		}
		int value = node->getValue();
		delete node;
		return value;
	}
}

/******************************************************************************
 *
 ******************************************************************************/
void BinarySearchTree::preorder(Node* node) const
{
	node->printValue();
	if( node->getLeft() != nullptr ) preorder( node->getLeft() );
	if( node->getRight() != nullptr ) preorder( node->getRight() );
}

/******************************************************************************
 *
 ******************************************************************************/
void BinarySearchTree::inorder(Node* node) const
{

	if( node->getLeft() != nullptr ) inorder( node->getLeft() );
	node->printValue();
	if( node->getRight() != nullptr ) inorder( node->getRight() );
}

/******************************************************************************
 *
 ******************************************************************************/
void BinarySearchTree::deleteTree(Node* subtree)
{

	if( subtree->getRight() != nullptr )
	{
		deleteTree( subtree->getRight() );
	}
	if( subtree->getLeft() != nullptr )
	{
		deleteTree( subtree->getLeft() );
	}
	delete subtree;
}

/******************************************************************************
 *
 ******************************************************************************/
Node* BinarySearchTree::findMin(Node* subtree)
{
	Node* node = subtree;
	while( node->getLeft() != nullptr )
	{
		node= node->getLeft();
	}
	return node;
}

} //end of namespace Tree
