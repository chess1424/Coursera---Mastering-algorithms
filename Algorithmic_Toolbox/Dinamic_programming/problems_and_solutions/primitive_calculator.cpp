#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int n, min_k;

  scanf("%d",&n);

  int dp[n + 1]; dp[1] = 0;

  //Calculating minimum path.
  for(int i = 2; i <= n; i++)
  {
    min_k = n + 1;

    if(i % 2 == 0)
      min_k = min(min_k, dp[i/2] + 1);
    if(i % 3 == 0)
      min_k = min(min_k, dp[i/3] + 1);
    min_k = min(min_k, dp[i - 1] + 1);

    dp[i] = min_k;
  }

  printf("%d\n",dp[n]);

  //Calculating set of numbers.
  vector<int> v;
  v.push_back(n);

  while(n != 1)
  {
    if(n % 2 == 0 && dp[n/2] + 1 == dp[n])
    {
      v.push_back(n / 2);
      n /= 2;
    }
    else if(n % 3 == 0 && dp[n/3] + 1 == dp[n])
    {
      v.push_back(n / 3);
      n /= 3;
    }
    else
    {
      v.push_back(n - 1);
      n -= 1;
    }
  }


  for(int i = v.size() - 1; i >= 0; i--)
    printf("%d ", v[i]);
  cout<<endl;

  return 0;
}