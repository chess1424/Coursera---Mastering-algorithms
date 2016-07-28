#include <iostream>
#include <vector>
#define MOD 10
using namespace std;


long long fibo(long long n)
{
	vector<long long> v(n+1);
	v[0] = 0;
	v[1] = 1;
	for(long long i = 2; i <= n; i++)
		v[i] = v[i-1] % MOD + v[i-2] % MOD;

	return v[n] % MOD;
}
int main()
{
	long long n;
	scanf("%lld",&n);
	printf("%lld\n",fibo(n));

	return 0;
}