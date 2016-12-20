#include <iostream>
#include <cstring>
using namespace std;
int fibos[46];


int fibo(int n)
{
	if(fibos[n] != -1) return fibos[n];
	if(n == 0 || n == 1) return fibos[n] = n;
	return fibos[n] = fibo(n-1) + fibo(n-2);
}

int main()
{
	int num;
	memset(fibos,-1,sizeof(fibos));
	scanf("%d",&num);
	printf("%d\n",fibo(num));
	return 0;
}