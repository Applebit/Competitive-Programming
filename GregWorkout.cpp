
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
	bool isChest=true, isBiseps=false, isBack = false;
	int countChest = 0, countBiseps = 0, countBack = 0;
	while (n--)
	{
		int counter;
		scanf("%d", &counter);
		if (isChest)
		{
			countChest += counter;
			isChest = false;
			isBiseps = true;
			isBack = false;
		}
		else if (isBiseps)
		{
			countBiseps += counter;
			isChest = false;
			isBiseps = false;
			isBack = true;
		}
		else if (isBack)
		{
			countBack += counter;
			isChest = true;
			isBiseps = false;
			isBack = false;
		}

	}
	if (max(countChest, max(countBiseps, countBack)) == countChest)
	{
		printf("chest\n");
	}
	else if (max(countChest, max(countBiseps, countBack)) == countBiseps)
	{
		printf("biceps\n");
	}
	else
	{
		printf("back\n");
	}
	//system("pause");
	return 0;

}