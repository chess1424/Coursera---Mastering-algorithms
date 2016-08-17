#include <iostream>
#include <vector>

#define INFINITY numeric_limits<int>::max()
using namespace std;

int main()
{
	int money;
	while(cin >> money)
	{
		vector<int> coins = {1, 8, 20};
		vector<int> MinNumCoins(money + 1);
		MinNumCoins[0] = 0;
		for(int m = 1; m <= money; m++)
		{
			MinNumCoins[m] = INFINITY;
			for(int i = 0; i < coins.size(); i++)
			{
				if(m >= coins[i])
				{
					int NumCoins = MinNumCoins[m - coins[i]] + 1;
					if(NumCoins < MinNumCoins[m])
						MinNumCoins[m] = NumCoins;
				}
			}
		}
		cout << MinNumCoins[money] << endl;
	}
	return 0;
}