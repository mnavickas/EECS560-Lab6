#ifndef BinarySearchTree_h
#define BinarySearchTree_h

#include "Node.hpp"
#include "Queue/Deque.hpp"
namespace Tree
{
	class BinarySearchTree
	{
	public:
		/* For level order print */
		typedef ::Queue::Deque<Node*> Queue;
		typedef ::Queue::Node<Node*> QNode;

	public:
		BinarySearchTree();
		~BinarySearchTree();
		bool isEmpty() const;
		bool insert(int value);
		Node* search(int value) const;
		void remove(int value);

		int deleteMin();
		int deleteMax();

		void preorder() const;
		void inorder() const;
		void levelorder() const;

	private:
		/* recursive helpers */
		bool insert(int value, Node* subtree);
		Node* search(int value, Node* subtree) const;
		Node* remove(Node* node, int value, bool* removed);
		int deleteMin(Node* node, Node* previous);
		int deleteMax(Node* node, Node* previous);
		void preorder(Node* node) const;
		void inorder(Node* node) const;

	    /* local functions */
		void deleteTree(Node* subtree);
		Node* findMin(Node* subtree);

	private:
		Node* mRoot;


	};
} // end of namespace Tree

#endif
