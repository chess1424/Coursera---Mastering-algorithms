/* Euclidean properties:
	gcd(a,b)
		a' = remainder of a divided by b
		a = a' + bq for some q
		d divdides a and b if and only if it divides a' and b
*/	

#include <iostream>
using namespace std;

long long gcd(long long a, long long b)
{
	if(b == 0)
		return a;
	return gcd(b, a%b);
}

int main()
{
	long long a,b;
	while(cin >> a >> b)
		cout<<gcd(a,b)<<endl;
	return 0;
}