#include <iostream>

using namespace std;

int main()
{
  int W, n;
  scanf("%d %d",&W, &n);

  long long dp[2][W + 1], gold_bars[n + 1], max_value;

  for(int i = 1; i <= n; i++)
    scanf("%lld",&gold_bars[i]);

  for(long long i = 0; i <= W; i++)
    dp[0][i] = dp[1][i] = 0;

  for(long long i = 1; i <= n; i++)
  {
    for(long long j = 1; j <= W; j++)
    {
      max_value = dp[0][j]; //Is not possible to take the gold_bar i
      if(gold_bars[i] <= j) //Is possible to take the gold_bar i
        max_value = max(max_value, dp[0][j - gold_bars[i]] + gold_bars[i]);
      dp[1][j] = max_value;
    }
    for(int k = 0; k <= W; k++)
      dp[0][k] = dp[1][k];
  }

  cout << dp[1][W] << endl;

  return 0;
}