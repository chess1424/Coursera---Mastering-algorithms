#include <iostream>
#include <map>
using namespace std;

int main()
{
	map<int , long long> m;
	cout << m[4] << endl;
	cout << m[4] << endl;

	m[3]++;
	m[3]++;
	cout << m[3] << endl;
	return 0;
}