#include <iostream>

using namespace std;

int main(){

	int size, n;

	scanf("%d",&size);

	long long arr[size], num;

	for(int i = 0; i < size; i++) scanf("%lld", &arr[i]);

	scanf("%d",&n);

	for(int i = 0; i < n; i++)
	{
		scanf("%lld",&num);
		
		//Binary sarch
		int l = 0, r = size-1, m, ans = -1;
		while(l <= r)
		{
			m = (l + r) / 2;
			if(arr[m] == num)
			{
				ans = m; 
				break;
			}
			else if(arr[m] < num)// my number is on the right side
			{
				l = m + 1;
			}
			else//my number is on the left side
			{
				r = m - 1;
			}
		}
		printf("%d", ans);
		printf((i != n-1) ? " " : "\n");

	}	
	return 0;
}