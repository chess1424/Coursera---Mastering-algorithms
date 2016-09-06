/*=
EditDistance(A[1...n], B[1...m])
  D(i, 0) <- i and D(0, j) <- j for all i, j

  for(j from i to m):
    for(i from i to n):
      insertion <- D(i, j-1) + 1
      deletion  <- D(i-1, j) + 1
      mismatch  <- D(i - 1, j -1) + 1
      match     <- D(i-1 , j-1) 

      if(A[i] = B[j])
        D(i, j) <- min(insertion, deletion, match)
      else
        D(i, j) <- min(insertion, deletion, mismatch)


OutputAligment(i, j)
  if i == 0 and j == 0
    return

  if i > 0 and D(i, j) = D(i - 1, j) + 1
    OutputAlimgent(i-1, j)
    print(A[i] , -)
  else if j > 0 and D(i , j) = D(i, j-1) + 1
    OutputAligment(i, j-1)
    print(-, B[j])
  else
    OutputAligment(i-1, j-1)
    print(A[i], B[j])
*/

#include <iostream>
#include <string>
#define  MAXSIZE 1000

using namespace std;

int n, m, dp[MAXSIZE][MAXSIZE];
string A, B;
int EditDistance(string A, string B)
{
  n = A.length(); m = B.length();
	int insertion, deletion, match, mismatch;

	for(int i = 0; i <= m; i++) dp[0][i] = i;
	for(int i = 0; i <= n; i++) dp[i][0] = i;
  
  for(int j = 1; j <= m; j++)
  {
  	for(int i = 1; i <= n; i++)
  	{
  		insertion = dp[i][j -1] + 1;
  		deletion  = dp[i - 1][j] + 1;
  		mismatch  = dp[i - 1][j - 1] + 1;
  		match     = dp[i - 1][j - 1];

  		if(A[i-1] == B[j-1])
  			dp[i][j] = min( min(insertion, deletion) , match );
  		else
  			dp[i][j] = min( min(insertion, deletion) , mismatch );
  	}
  }

  return dp[n][m];
}	

string str1, str2;
void OutputAligment(int i , int j)// i for string A and j for string B
{
  if(i == 0 && j == 0) return;

  if(i > 0 && dp[i][j] == dp[i - 1][j] + 1)
  {
    str1 = A[i-1] + str1; str2 = '-' + str2;
    OutputAligment(i-1, j);
  }
  else if(j > 0 && dp[i][j] == dp[i][j -1] + 1)
  {
    str1 = '-' + str1; str2 = B[j-1] + str2;
    OutputAligment(i, j-1);
  }
  else
  {
    str1 = A[i-1] + str1; str2 = B[j-1] + str2;
    OutputAligment(i-1, j-1);
  }

}

int main()
{
  A = "thou-shalt-not" , B = "you-should-not";
	cout << EditDistance(A, B) << endl;
 
  str1 = str2 = "";
  OutputAligment(A.size(), B.size());

  cout << str1 << endl;
  cout << str2 << endl;

	return 0;
}