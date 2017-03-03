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
		bool insert(T value);
		Node<T>* search(T value) const;
		void remove(T value);

		T deleteMin();
		T deleteMax();

		void preorder() const;
		void inorder() const;
		void levelorder() const;

	private:
		/* recursive helpers */
		bool insert(T value, Node<T>* subtree);
		Node<T>* search(T value, Node<T>* subtree) const;
		Node<T>* remove(Node<T>* node, T value, bool* removed);
		T deleteMin(Node<T>* node, Node<T>* previous);
		T deleteMax(Node<T>* node, Node<T>* previous);
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
