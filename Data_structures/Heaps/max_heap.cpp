#include <iostream>
#include <climits>
using namespace std;

/*
Parent(i) return i/2
LeftChild return i*2
RightChild return i*2 + 1

SiftUp(i)
while i > 1 and H[Parent(i)] < H[i]:
  swap H[Parent(i)] and H[i]
  i <- parent

SiftDown(i)
  maxIndex <- i
  l <- LeftChild(i)
  if l <= size and H[l] > H[maxIndex]:
    maxIndex <- l

  r <- RightChild(i)
  if r <= size and H[r] > H[maxIndex]:
    maxIndex <- r

  if maxIndex != i
    swap H[i] and H[maxIndex]
    siftDown(maxIndex)

Insert(p)
  if size > maxSize return ERROR

  H[size] <- p
  size <- size + 1
  SiftUp(size)

ExtractMax()
  result <- H[1]
  swap H[1] and H[size]
  size <- size - 1
  SiftDown(1)

  return result

Remove(i)
  if i > size return ERROR

  H[i] <- INF
  SiftUp(i)
  ExtractMax()

ChangePriority(i, p)
  oldPriority <- H[i]
  H[i] <- p

  if p > oldPriority
    SiftUp(i)
  else
    SiftDown(i)
*/

//This Heap is based on 1 indexed

class Heap{
public:
  Heap(int maxSize)
  {
    this->H       = new int[maxSize + 1];
    this->maxSize = maxSize;
    this->size    = 0;
  }

  void InitializeHeap(int values[], int size)
  {
    if(size > maxSize) return;

    for(int i = 1; i <= size; i++, this->size++)
      H[i] = values[i-1];
  }


  void PrintHeap()
  {
    for(int i = 1; i <= size; i++)
      cout << H[i] << " ";
  }

  void SiftUp(int i)
  {
    if(i > size) return;

    while(i > 1 && H[Parent(i)] < H[i])
    {
      swap(H[Parent(i)], H[i]);
      i = Parent(i);
    }
  }

  void SiftDown(int i)
  {
    if(i < 0 || i > size) return;

    int maxIndex, leftChild, rightChild;

    while(LeftChild(i) <= size)
    {
      maxIndex = i;
      leftChild = LeftChild(i);

      if(H[leftChild] > H[i])
        maxIndex = leftChild;

      rightChild = RightChild(i);

      if(rightChild <= size)
        if(H[rightChild] > H[maxIndex])
          maxIndex = rightChild;

      if(i == maxIndex) break;

      swap(H[maxIndex], H[i]);
      i = maxIndex;
    }
  }

  void Insert(int p)
  {
    if(size >= maxSize) return;

    H[++size] = p;
    SiftUp(size);
  }

  int ExtractMax()
  {
    if(size < 1) return INT_MIN;

    int response = H[1];

    swap(H[1], H[size]);

    SiftDown(1);
    size--;

    return response;
  }

  void Remove(int i)
  {
    if(i < 1 || i > size) return;

    H[i] = INT_MAX;
    SiftUp(i);
    ExtractMax();
  }

  void ChangePriority(int i, int p)
  {
    if(i < 1 || i > size) return;

    int oldPriority = H[i];
    H[i] = p;

    if(H[i] > oldPriority)
      SiftUp(i);
    else
      SiftDown(i);
  }
private:

  int Parent(int i)
  {
    return i/2;
  }

  int LeftChild(int i)
  {
    return i*2;
  }

  int RightChild(int i)
  {
    return i*2 + 1;
  }

  int *H, maxSize, size;
};

int main()
{

  Heap h(20);
  h.Insert(1);
  h.Insert(2);
  h.Insert(3);
  h.Insert(4);
  h.Insert(5);
  h.Insert(6);
  h.Insert(7);
  h.Insert(8);
  h.Insert(9);
  h.Insert(10);
  h.Insert(11);
  h.Insert(12);
  h.PrintHeap();

  return 0;
}