/*
value(0) <- 0
for w from 1 to W:
	value(w) <- 0
	for i from 1 to n:
		if wi <= w
			val <- value(w - wi) + vi
			if val > value(w)
				value(w) <- value
return value(W)
*/
#include <iostream>
#define n 4

using namespace std;

int main()
{
	int value[n] = {30, 14, 16, 9}, weight[n] = {6, 3, 4, 2}, W = 10, val;
  int dp[W + 1];
  fill(dp, dp + W + 1, 0); 
	
	for(int w = 1; w <= W; w++)
		for(int i = 0; i < n; i++)
			if(weight[i] <= w)
			{
				val = dp[w - weight[i]] + value[i]; 
				if(val > dp[w])
					dp[w] = val;
			}

	cout << dp[W] << endl;

 	return 0;
}