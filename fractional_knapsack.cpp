#include <iostream>
#include <algorithm>
using namespace std;

typedef struct item
{
	double value;
	double weight;
	double valueUnit;
	double stored;
	
}item;


bool mySort(item i1, item i2){ return i1.valueUnit > i2.valueUnit; }

int main()
{
	int n,i;
	double W, v, w, ans;
	scanf("%d %lf",&n,&W);

	item arr[n];
	
	for(int i = 0; i < n; i++)
	{
		scanf("%lf %lf",&v,&w);
		item newItem;
		newItem.value = v;
		newItem.weight = w;
		newItem.stored = 0;
		newItem.valueUnit = v / w;
		arr[i] = newItem;
	}

	sort(arr, arr+n , mySort);

	ans = i = 0;

	while(W > 0)
	{
		if(arr[i].weight == 0) i++;
		if(i == n) break;

		arr[i].stored = min(W, arr[i].weight);
		W -= arr[i].weight;
		arr[i].weight -= arr[i].stored;
		ans += arr[i].stored * arr[i].valueUnit;
	}

	printf("%lf\n",ans);


	return 0;
}