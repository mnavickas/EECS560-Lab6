#include "heap.hpp"
#include <iostream>

//#define DEBUG
#ifdef DEBUG
  #define DEBUG_EVAL(x)  std::cout<< "Function "<<__func__<< ":\n"; x
#else
  #define DEBUG_EVAL(x) //no-op
#endif
namespace KHeap
{
Heap::Heap( int aSize, int aKValue ): mArray( new int[aSize] ), mLastIndex ( -1 ), cMaxSize( aSize ), K(aKValue)
{

}

Heap::~Heap()
{
  delete[] mArray;
}

void Heap::Build()
{
  const index_t lastParentIndex = ((mLastIndex-1)/K);

  index_t currentParentIndex = lastParentIndex;

  DEBUG_EVAL
  (
    levelOrder();
  )

  while(currentParentIndex != -1)
  {
    DEBUG_EVAL
    (
      std::cout<<"Current Index: "<<currentParentIndex<<std::endl;
    )


    downHeap(currentParentIndex);

    // print
    DEBUG_EVAL
    (
      levelOrder();
    )
    // previous parent
    currentParentIndex--;
  }
}
void Heap::downHeap(index_t aCurrentParentIndex)
{
  DEBUG_EVAL
  (
  levelOrder();
  )
  index_t childIndex = getChildIndex(aCurrentParentIndex,1);
  if(childIndex == -1 || childIndex > mLastIndex)
  {
    return;
  }

  int childValue = getChild(aCurrentParentIndex,1);

  //find smallest child.
  for(int i = 2; i <= K; i++)
  {
    if( getChild(aCurrentParentIndex,i) < childValue && getChild(aCurrentParentIndex,i) != -1 )
    {
      childIndex = getChildIndex(aCurrentParentIndex,i);
      childValue = getChild(aCurrentParentIndex,i);
    }
  }
  //swap if needed.
  if( childValue < mArray[aCurrentParentIndex] )
  {
    //swap
    int temp = mArray[aCurrentParentIndex];
    mArray[aCurrentParentIndex] = childValue;
    mArray[childIndex] = temp;


    // if swapped, repeat
    downHeap(childIndex);
  }
}

void Heap::insert(int aValue)
{

  DEBUG_EVAL
  (
  std::cout<< "Start" <<std::endl;
  levelOrder();
  )

  if( mLastIndex+1 >= cMaxSize)
  {
    // this would cause an overflow
    return;
  }

  mArray[++mLastIndex] = aValue;

  DEBUG_EVAL
  (
  std::cout<< "Initial" <<std::endl;
  levelOrder();
  )

  upHeap(mLastIndex);
}
/**
 * Give the child pointer, heaps it up to correct location.
 */
void Heap::upHeap( index_t aIndexStart )
{
  index_t parent = getParentIndex(aIndexStart);
  index_t child = aIndexStart;
  bool swap = true;

  while( parent != -1 && swap )
  {

    if( mArray[child] < mArray[parent] )
    {
      // swap up
      int temp = mArray[child];
      mArray[child] = mArray[parent];
      mArray[parent] = temp;
      // set new parent and child
      child = parent;
      parent = getParentIndex(parent);
    }
    else
    {
      swap = false;
    }

    DEBUG_EVAL
    (
    levelOrder();
    )
  }
}

void Heap::deleteMin()
{
  mArray[0] = mArray[mLastIndex];
  mArray[mLastIndex] = -1;
  mLastIndex--;
  downHeap( 0 );
}

void Heap::deleteMax()
{
  const index_t firstChildIndex = ((mLastIndex-1)/K)+1;

  int maxValue = mArray[firstChildIndex];
  index_t maxValueIndex = firstChildIndex;
  index_t currentIndex = firstChildIndex;

  while( currentIndex < mLastIndex )
  {
    if( mArray[++currentIndex] > maxValue )
    {
      maxValue = mArray[currentIndex];
      maxValueIndex = currentIndex;
    }
  }

  DEBUG_EVAL
  (
  std::cout<<"Max Value: "<<maxValue<<" at Index: "<<maxValueIndex<<std::endl;
  )
  // delete and put the next value there.
  mArray[maxValueIndex] = mArray[mLastIndex];
  mArray[mLastIndex--] = -1;

  // heapify
  upHeap(maxValueIndex);

}

void Heap::remove(int aValue)
{
  // remove until all are gone.
  while( removeInternal(aValue) );
}
bool Heap::removeInternal(int aValue)
{
  for(index_t index = 0; index <= mLastIndex; index++)
  {
    if( mArray[index] == aValue )
    {
      if(index == mLastIndex)
      {
        // it was last index
        mArray[mLastIndex] = -1;
        mLastIndex--;
        return true;
      }
      mArray[index] = mArray[mLastIndex];
      mArray[mLastIndex] = -1;
      mLastIndex--;

      if ( mArray[index] < getParent(index) )
      {
        // upheap the replacement
        upHeap(index);
      }
      else if ( mArray[index] == getParent(index) )
      {
        // no-op
      }
      else/* if( mArray[index] > getParent(index) ) */
      {
        // downheap the replacement
        downHeap(index);
      }
      return true;
    }
  }
  return false;
}

void Heap::levelOrder()
{
  index_t childIndex = 1;
  for(index_t i = 0; i < cMaxSize; i++)
  {
    if( mArray[i] == -1 )
    {
      std::cout <<"- ";
    }
    else
    {
      std::cout << mArray[i] << " ";
    }
    if( i+1 == childIndex )
    {
      std::cout << std::endl;
      childIndex = getChildIndex(i+1,1);
    }
  }
  std::cout<<"\n"<< std::endl;
}

} // end of namespace KHeap
