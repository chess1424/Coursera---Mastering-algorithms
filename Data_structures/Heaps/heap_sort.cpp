//
//  main.cpp
//  HeapSort
//
//  Created by Carlos Roberto Martinez Ojeda on 3/2/17.
//  Copyright © 2017 Carlos Roberto Martinez Ojeda. All rights reserved.
//

#include <iostream>

using namespace std;

class HeapSort{
public:
  HeapSort(int *arr, int size)
  {
    this->arr  = arr;
    this->size = size;
  }

  void sortHeap()
  {
    buildHeap();
    while(size > 1)
    {
      extractMax();
      siftDown();
    }
  }

private:
  int *arr;
  int size;

  void siftDown(int index = 0)
  {
    int maxIndex;

    while(leftChild(index) < size)
    {
      maxIndex = index;

      if(arr[leftChild(index)] > arr[index])
        maxIndex = leftChild(index);

      if(rightChild(index) < size && arr[rightChild(index)] > arr[maxIndex])
        maxIndex = rightChild(index);

      if(maxIndex == index)
        break;

      swap(arr[index], arr[maxIndex]);
      index = maxIndex;
    }
  }

  int extractMax()
  {
    if(size == 0) return INT_MIN;

    int max = arr[0];

    swap(arr[0], arr[size-1]);
    size--;
    siftDown();

    return max;
  }

  void buildHeap()
  {
    for(int i = size/2 - 1; i >= 0; i--)
      siftDown(i);
  }

  int leftChild(int index)
  {
    return (index+1) * 2 - 1;
  }

  int rightChild(int index)
  {
    return (index+1) * 2;
  }

};


int main()
{
  int arr[] = {4,7,10,2,15,3,1,23,8};

  HeapSort hs(arr,9);
  hs.sortHeap();

  //Sorted array
  for(int i = 0; i < 9; i++)
    cout << arr[i] << " ";
  cout << endl;

  return 0;
}
