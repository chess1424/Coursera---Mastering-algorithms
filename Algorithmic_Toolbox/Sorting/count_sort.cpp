/*
  CountSort(A[1...n])   // We assume that all elements in this array are from 1 to M
  Count[1...M] <- [0,...,0]
  for i from 1 to n:
  count[a[i]] <- cont[A[i]] + 1

  {k appears Count[k] times in A}

  Pos[1...M] <- [0,..,0]
  pos[1] <- 1

  for j from 2 to M:
  Pos[j] <- Pos[j - 1] + Count[j - 1]

  {k will occupy range [Pos[k]...Pos[k+1] - 1]}

  for i from 1 to n:
  A'[Pos[A[i]]] <- A[i]
  Pos[A[i]] <- Pos[A[i]] + 1

  The complexity of this algorithm is O(n + M)
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> CountSort(vector<int> A, int m)
{
  vector<int> count(m+1, 0);
  int n = A.size();
  for(int i = 0; i < n; i++)
    count[A[i]] = count[A[i]] + 1;

  //Until this point we haave calculated all the frecuencies in the A vector
  vector<int> pos(m+1, 0), ans(n);
  pos[1] = 0;

  for(int i = 2; i < pos.size(); i++)
    pos[i] = pos[i-1] + count[i-1];

  for(int i = 0; i < n; i++)
    {
      ans[pos[A[i]]] = A[i];
      pos[A[i]] = pos[A[i]] + 1; 
    }

  return ans;
}

int main()
{
  vector<int> v{2,3,2,1,3,2,2,3,2,2,2,1};
  cout << "Before sort" << endl;
  for(int i = 0; i < v.size(); i++)
    cout << v[i] << " ";

  cout << "\nAfter sort" << endl;
  v = CountSort(v, 3);
  for(int i = 0; i < v.size(); i++)
    cout << v[i] << " ";
  cout << endl;

  return 0;
}
