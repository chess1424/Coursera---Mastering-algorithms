#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct segment{
	long long a, b;
}segment;

bool mySort(segment s1, segment s2)
{
	return s1.a < s2.a;
}

int main()
{
	int n, i;
	long long a, b, l, r;
	scanf("%d",&n);
	vector<long long> v;

	segment segments[n];

	for(int i = 0; i < n; i++)
	{
		scanf("%lld %lld",&a , &b);
		segment newSegment;
		newSegment.a = a;
		newSegment.b = b;
		segments[i] = newSegment;
	}

	sort(segments, segments+n, mySort);

	i = 0;

	while(i < n)
	{
		l = segments[i].a; r = segments[i].b;

		while(segments[i].a <= r && segments[i].a >= l && i < n)
		{
			l = segments[i].a;
			r = min(segments[i].b , r);
			i++;
		}
		v.push_back(l);
	}

	printf("%d\n",v.size());
	for(int i = 0; i < v.size() - 1; i++)
		printf("%lld ",v[i]);
	printf("%lld\n",v[v.size()-1]);

	return 0;
}