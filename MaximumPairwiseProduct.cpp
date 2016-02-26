#include <iostream>

using namespace std;

int main()
{
	int n, max1, max2, num;
	scanf("%d",&n);
	scanf("%d",&max1);
	scanf("%d",&max2);

	for(int i = 2; i < n; i++)
	{
		scanf("%d",&num);
		if(num > max1 || num > max2)
		{
			max2 = max(max1, max2);
			max1 = num;
		}
	}

	printf("%lld\n",(long long)max1*max2);

	return 0;
}
