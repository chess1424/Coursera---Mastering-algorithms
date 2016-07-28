#include <iostream>

using namespace std;

int main()
{
	int m, ans = 0, coins[] = {10,5,1};

	scanf("%d",&m);

	for(int i = 0; i < 3; i++)
	{
		ans += m / coins[i];
		m -= (m / coins[i]) * coins[i];
	}
    printf("%d\n",ans);

	return 0;
}