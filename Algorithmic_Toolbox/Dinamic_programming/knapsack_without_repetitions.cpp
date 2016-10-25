  /*
  initialize all value(0,j) <-0 //items
  initialize all value(w,0) <-0 //total weights

  for i from 1 to n:
	  for w from 1 to w:
	    value(w,i) <- value(w, i-1)
	    if(wi <= w)
	      val <- value(w - wi, i - 1) + vi
	      if value(w, i) < val
	        value(w , i) <- val      `
  return value(W,n)
*/

#include <iostream>
using namespace std;

int knapsack_without_repetitions(int n, int W)
{
  int weight[4] = {6, 3, 4 ,2}, money[4] = {30, 14, 16, 9}, value[5][11];

  for(int i = 0; i < 5; i++){ value[0][i] = 0; value[i][0] = 0; }

  for(int i = 1; i <= n; i++)
  {
    for(int w = 1; w <= W; w++)
    {
      value[i][w] = value[i-1][w];
      if(weight[i-1] <= w)
      {
        int val = value[i-1][w - weight[i-1]] + money[i-1];
        if(value[i][w] < val)
          value[i][w] = val;
      }
    }
  }

  return value[n][W];
}

int main()
{
  int ans = knapsack_without_repetitions(4, 10);//items, total_capacity
  cout << ans << endl;

  return 0;
}
