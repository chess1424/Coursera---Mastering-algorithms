/*
MergeSort(A[1...n])
if n = 1:
	return A

m <- [n/2]
B <- MergeSort(A[1...m])
C <- MergeSort(A[m] + 1...n)
A' <- Merge(B, C)
return A'

Merge(B[1...p], C[1...q])
{B and C are sorted}
D <- empty arreay of size p + q
while B amd C are both non-empty:
	b<- the first element of B
	c<- the first element of C

	if b<=c:
		move b from B to the end of D
	else
	  move c from C to the end of D
move the rest of B an dC to the end of D

The complexity of this sort algorithm is O(n log n)
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> merge(vector<int> B, vector<int> C)
{
  vector<int> merged_vector;
  while(!B.empty() && !C.empty())
    {
      int b = B[0];
      int c = C[0];

      if(b <= c)
	{ merged_vector.push_back(b); B.erase(B.begin()); }
      else
	{ merged_vector.push_back(c); C.erase(C.begin()); }
    }

  for(int i = 0; i < B.size(); i++) merged_vector.push_back(B[i]);
  for(int i = 0; i < C.size(); i++) merged_vector.push_back(C[i]);

  return merged_vector;
}

vector<int> mergeSort(vector<int> A)
{
  int n = A.size(), m;

  if(n == 1)
    return A;

  m = n/2;

  vector<int> B = mergeSort( vector<int>(A.begin(), A.begin()+m) );
  vector<int> C = mergeSort( vector<int>(A.begin()+m, A.begin()+n) );

  vector<int> sorted_vector = merge(B, C);

  return sorted_vector;
}

int main()
{
  vector<int> A {7,2,5,3,7,13,1,6};

  cout << "\nBefore sort" << endl;
  for(int i = 0; i < A.size(); i++) cout << A[i] << " ";

  A = mergeSort(A);
  cout << "\nAfter sort" << endl;
  for(int i = 0; i < A.size(); i++) cout << A[i] << " ";

  return 0;
}
