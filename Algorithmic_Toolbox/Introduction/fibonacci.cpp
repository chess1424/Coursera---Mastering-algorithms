#include <iostream>
#include <vector>
using namespace std;

long long fibo(long long num)
{
	vector<long long> v(num+1); 
	v[0] = 0;
	v[1] = 1;

	for(long long i = 2; i <= num; i++)
		v[i] = v[i-1] + v[i-2];

	return v[num];
}

int main()
{
	long long num;
	while(scanf("%lld",&num) != EOF)
		printf("%lld\n",fibo(num));
}