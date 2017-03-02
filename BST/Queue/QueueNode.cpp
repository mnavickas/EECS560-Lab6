/**
*	@file : Node.hpp
*	@author :  Michael Navickas
*	@date : 2015.09.23
*	Purpose: Node class, houses pointers to next and previous, as well as the templated type value.
*/
namespace Queue
{
	template <typename T>
	Node<T>::Node(): mNext(nullptr),mPrevious(nullptr),mValue(T())
	{
	}

	template <typename T>
	T Node<T>::getValue() const
	{
		return mValue;
	}

	template <typename T>
	Node<T>* Node<T>::getNext() const
	{
		return mNext;
	}

	template <typename T>
	Node<T>* Node<T>::getPrevious() const
	{
		return mPrevious;
	}

	template <typename T>
	void Node<T>::setNext(Node<T>* aNext)
	{
		mNext = aNext;
	}

	template <typename T>
	void Node<T>::setPrevious(Node<T>* aPrevious)
	{
		mPrevious = aPrevious;
	}

	template <typename T>
	void Node<T>::setValue(T aValue)
	{
		mValue = aValue;
	}
}
