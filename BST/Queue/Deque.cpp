/**
*	@file : Deque.hpp
*	@author :  Michael Navickas
*	@date : 2015.09.23
*	Purpose: Deque class, contains method for organizing ordered Nodes, altering and searching the list for Templated type T.
*/
namespace Queue
{
	template <typename T>
	Deque<T>::Deque(): mBack(nullptr),mFront(nullptr),mSize(0)
	{
	}

	template <typename T>
	Deque<T>::~Deque()
	{
		//keep removing the front value while you can
		while(popFront());
	}

	template <typename T>
	bool Deque<T>::isEmpty() const
	{
		//return true it has a size of 0
		return(mSize==0);
	}

	template <typename T>
	int Deque<T>::size() const
	{
		//return the size
		return mSize;
	}

	template <typename T>
	void Deque<T>::pushFront(T value)
	{
		//if empty, create a new Node at mFront, assign it the value, point back at it.
		if(isEmpty())
		{
			mFront= new Node<T>();
			mFront->setValue(value);
			mBack=mFront;
		}
		//if its not empty
		else if(!isEmpty())
		{
			//store current mFront as a temp
			Node<T>* temp = mFront;
			//create a new Node at front and give it the value
			mFront=new Node<T>();
			mFront->setValue(value);
			//set the new Nodes next to the temp Node
			mFront->setNext(temp);
			//set the temp's previous to the new Node
			temp->setPrevious(mFront);
		}
		//increment size
		mSize++;
	}

	template <typename T>
	void Deque<T>::pushBack(T value)
	{
		//if empty, create a new Node at mFront, assign it the value, point back at it.
		if(isEmpty())
		{
			mFront= new Node<T>();
			mFront->setValue(value);
			mBack=mFront;
		}
		//if its not empty
		else if(!isEmpty())
		{
			//create a temp Node and set a value to it. set its previous pointer to mBack
			Node<T>* temp = new Node<T>();
			temp->setValue(value);
			temp->setPrevious(mBack);
			//point mBack's next to temp
			mBack->setNext(temp);
			//move mBack pointer to temp
			mBack=temp;
		}
		//increment size
		mSize++;
	}

	template <typename T>
	bool Deque<T>::popFront()
	{
		//if empty return false, cant remove anything
		if(isEmpty())
		{
			return false;
		}
		//decrement size
		mSize--;
		//if its now empty, that means there was only 1 Node. delete it and set mBack/front to nullptr
		if(isEmpty())
		{
			delete mFront;
			mFront=nullptr;
			mBack=nullptr;
		}
		else if(!isEmpty())
		{
			//store the second Node as a temp
			Node<T>* temp = mFront->getNext();
			//delete the front
			delete mFront;
			//set temp's previous to nullptr
			temp->setPrevious(nullptr);
			//move mFront pointer to temp
			mFront=temp;
		}
		//return true a value was removed
		return true;
	}

	template <typename T>
	bool Deque<T>::popBack()
	{
		//if empty return false, cant remove anything
		if(isEmpty()){
			return false;
		}
		//decrement size
		mSize--;
		//if its now empty, that means there was only 1 Node. delete it and set mBack/front to nullptr
		if(isEmpty())
		{
			delete mBack;
			mFront=nullptr;
			mBack=nullptr;
		}
		else if(!isEmpty())
		{
			//create a temp Node looking at the 2nd to last
			Node<T>* temp = mBack->getPrevious();
			//delete the last
			delete mBack;
			//set temp's next to nullptr
			temp->setNext(nullptr);
			//move mBack to look at temp
			mBack=temp;
		}
		//return true a value was removed
		return true;
	}

	template <typename T>
	Node<T>* Deque<T>::peekFront() const
	{
		return mFront;
	}

	template <typename T>
	Node<T>* Deque<T>::peekBack() const
	{
		return mBack;
	}
}
