#ifndef HEAP_HPP
#define HEAP_HPP

namespace KHeap
{
  class Heap
  {
  typedef int index_t;

  public:
    Heap(int aSize = 40, int aKValue = 3);
    ~Heap();
    void insert(int aValue);
    void deleteMin();
    void deleteMax();
    void remove(int aValue);
    void levelOrder();
    void upHeap( index_t aIndexStart);
    void downHeap(index_t aCurrentParentIndex);

  private:

    void Build();
    bool removeInternal(int aValue);
    int getParent(index_t aChild)
    {
      if(aChild == 0)
      {
        return -1;
      }
      return mArray[(aChild-1)/K];
    }

    int getChild(index_t aParent, int aChildNumber)
    {
      int child = K*aParent+aChildNumber;
      if( child >= cMaxSize)
      {
        return -1;
      }
      else
      {
        return mArray[child];
      }

    }

    index_t getParentIndex(index_t aChild)
    {
      if(aChild == 0)
      {
        return -1;
      }
      return ((aChild-1)/K);
    }

    index_t getChildIndex(index_t aParent, int aChildNumber)
    {
      int child = K*aParent+aChildNumber;
      if( child >= cMaxSize)
      {
        return -1;
      }
      else
      {
        return child;
      }
    }

    int* mArray;
    index_t mLastIndex;
    const index_t cMaxSize;
    const int K;

  };
}

#endif
