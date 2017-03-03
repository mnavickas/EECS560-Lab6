#include <iostream>

namespace Tree
{
/******************************************************************************
 *
 ******************************************************************************/
template <typename T>
BinarySearchTree<T>::BinarySearchTree(): mRoot(nullptr)
{
}

/******************************************************************************
 *
 ******************************************************************************/
template <typename T>
BinarySearchTree<T>::~BinarySearchTree()
{
	if(mRoot == nullptr) return;
	deleteTree( mRoot );
}

/******************************************************************************
 *
 ******************************************************************************/
template <typename T>
bool BinarySearchTree<T>::isEmpty() const
{
	return (mRoot == nullptr);
}

/******************************************************************************
 *
 ******************************************************************************/
template <typename T>
bool BinarySearchTree<T>::insert(int value)
{
	if( mRoot == nullptr )
	{
		mRoot = new Node<T>();
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
template <typename T>
Node<T>* BinarySearchTree<T>::search(int value) const
{
	if( mRoot == nullptr )
	{
		return nullptr;
	}
	return search( value, mRoot );
}


/******************************************************************************
 *
 ******************************************************************************/
template <typename T>
void BinarySearchTree<T>::remove(int value)
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
template <typename T>
T BinarySearchTree<T>::deleteMin()
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
template <typename T>
T BinarySearchTree<T>::deleteMax()
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
template <typename T>
void BinarySearchTree<T>::preorder() const
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
template <typename T>
void BinarySearchTree<T>::inorder() const
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
template <typename T>
void BinarySearchTree<T>::levelorder() const
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
		// because the original LinkedList I adapted this from returns
		// a boolean signifying success of popFront() and not the values
		// that was popped, we have to peek and then pop it. I could change
		// it but this works. So..
		Node<T>* node = queue.peekFront()->getValue();
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
template <typename T>
bool BinarySearchTree<T>::insert(int value, Node<T>* subtree)
{
	if( value < subtree->getValue() )
	{
		if( subtree->getLeft() == nullptr )
		{
			subtree->setLeft( new Node<T>() );
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
			subtree->setRight( new Node<T>() );
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
template <typename T>
Node<T>* BinarySearchTree<T>::search(int value, Node<T>* subtree) const
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
template <typename T>
Node<T>* BinarySearchTree<T>::remove(Node<T>* node, int value, bool* removed)
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
			Node<T>* temp = node;
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
			Node<T>* temp = node;
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
			Node<T>* temp = findMin( node->getRight() );
			node->setValue( temp->getValue() );
			node->setRight( remove( node->getRight(), temp->getValue(),removed ) );
		}
	}
	return node;
}
/******************************************************************************
 *
 ******************************************************************************/
template <typename T>
T BinarySearchTree<T>::deleteMin(Node<T>* node, Node<T>* previous)
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
template <typename T>
T BinarySearchTree<T>::deleteMax(Node<T>* node, Node<T>* previous)
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
template <typename T>
void BinarySearchTree<T>::preorder(Node<T>* node) const
{
	node->printValue();
	if( node->getLeft() != nullptr ) preorder( node->getLeft() );
	if( node->getRight() != nullptr ) preorder( node->getRight() );
}

/******************************************************************************
 *
 ******************************************************************************/
template <typename T>
void BinarySearchTree<T>::inorder(Node<T>* node) const
{

	if( node->getLeft() != nullptr ) inorder( node->getLeft() );
	node->printValue();
	if( node->getRight() != nullptr ) inorder( node->getRight() );
}

/******************************************************************************
 *
 ******************************************************************************/
template <typename T>
void BinarySearchTree<T>::deleteTree(Node<T>* subtree)
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
template <typename T>
Node<T>* BinarySearchTree<T>::findMin(Node<T>* subtree)
{
	Node<T>* node = subtree;
	while( node->getLeft() != nullptr )
	{
		node= node->getLeft();
	}
	return node;
}

} //end of namespace Tree
