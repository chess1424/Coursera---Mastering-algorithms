/*
Selection sort algorithm:
  for i from 1 to n:
    minIndex <- i
    for j from i + i to n:
      if A[i] < A[minIndex]:
         minIndex <= j
    {A[minIndex] = min A[i...n]}
    swap(A[i], A[minIndex])
    {A[1...i] is in final position}

The complexity for this sort algorithm is O(n^2)
 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> selectionSort(vector<int> A)
{
  int n = A.size(), minIndex;

  for(int i = 0; i < n; i++)
  {
    minIndex = i;
    for(int j = i+1; j < n; j++)
      if(A[j] < A[minIndex]) minIndex = j;

    swap(A[minIndex] , A[i]);
  }

  return A;
}
int main()
{
  vector<int> A {100, 5, 40, 30, 20, 10, 78, 9, 0, -10};

  cout << "Before selection sort\n";
  for(int i = 0; i < A.size(); i++) cout << A[i] << " ";

  A = selectionSort(A);
  cout << "\nAfter selection sort\n";
  for(int i = 0; i < A.size(); i++) cout << A[i] << " ";

  return 0;
}
