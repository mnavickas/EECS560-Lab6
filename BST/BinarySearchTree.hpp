#ifndef BinarySearchTree_h
#define BinarySearchTree_h

#include "Node.hpp"
#include "Queue/Deque.hpp"
namespace Tree
{
	template <typename T>
	class BinarySearchTree
	{
	public:
		/* For level order print */
		typedef ::Queue::Deque<Node<T>*> Queue;

	public:
		BinarySearchTree();
		~BinarySearchTree();
		bool isEmpty() const;
		bool insert(int value);
		Node<T>* search(int value) const;
		void remove(int value);

		int deleteMin();
		int deleteMax();

		void preorder() const;
		void inorder() const;
		void levelorder() const;

	private:
		/* recursive helpers */
		bool insert(int value, Node<T>* subtree);
		Node<T>* search(int value, Node<T>* subtree) const;
		Node<T>* remove(Node<T>* node, int value, bool* removed);
		int deleteMin(Node<T>* node, Node<T>* previous);
		int deleteMax(Node<T>* node, Node<T>* previous);
		void preorder(Node<T>* node) const;
		void inorder(Node<T>* node) const;

	    /* local functions */
		void deleteTree(Node<T>* subtree);
		Node<T>* findMin(Node<T>* subtree);

	private:
		Node<T>* mRoot;


	};
} // end of namespace Tree
#include "BinarySearchTree.cpp"

#endif
