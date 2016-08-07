/*
QuickSort(A, l, r)
  if l >= r 
 	 return
	m <- partition(A, l, r)
	{A[m] is the final position}
	QuickSort(A, l, m-1)
	QuickSort(A, m+1, r)

Partition(A, l, r)
	x <- A[r] {pivot}
	i <- l-1

	for j from l to r-1:
		if A[j] <= x
			i <- i+1
			swap A[i] and A[j]
	  {A[l...i] <= x , A[i+1...j] > x}
	i = i+1
	swap A[i] and A[r]

	return i

	complexity better case O(n log n) worst case O(n^2)
*/
#include <iostream>
#include <vector>

using namespace std;

vector<int> A{9,6,5,0,8,2,4,7};

int partition(int l,  int r)
{
	int i, x = A[r]; // pivot
	i = l-1;
	for(int j = l; j < r; j++)
	{
		if(A[j] <= x)
		{
			i = i+1;
			swap(A[i] , A[j]);
		}
	}
	i = i+1;
	swap(A[i] , A[r]);

	return i;
}

vector<int> QuickSort(int l, int r)
{
	if(l >= r)
		return A;

	int m;
	m = partition(l, r);
	QuickSort(l, m-1);
	QuickSort(m+1, r);

	return A;
}

int main()
{
	cout << "Before sort "<< endl;
	for(int i = 0; i < A.size(); i++)
		cout << A[i] << " ";

	cout << "\nAfter sort " << endl;
	QuickSort(0, A.size()-1);
	for(int i = 0; i < A.size(); i++)
		cout << A[i] << " ";
	cout << endl;

	return 0;
}
