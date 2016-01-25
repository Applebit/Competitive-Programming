#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{


	int n;
	scanf("%d", &n);
	vector< pair<int, int> > priceAndQuality;
	for (int i = 0; i < n; i++)
	{
		int price, quality;
		scanf("%d %d", &price, &quality);
		priceAndQuality.push_back(make_pair(price, quality));
	}
	sort(priceAndQuality.begin(), priceAndQuality.end());
	for (int i = 0; i < n-1; i++)
	{
		if (priceAndQuality[i].second > priceAndQuality[i + 1].second)
		{
			printf("Happy Alex\n");
			return 0;
		}
	}
	printf("Poor Alex\n");
	//system("pause");
	return 0;

}