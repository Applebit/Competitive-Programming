#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
	vector<int> heightOfTree;
	int numberOfTree;
	scanf("%d", &numberOfTree);
	for (int i = 0; i < numberOfTree; ++i)
	{
		int height;
		scanf("%d", &height);
		heightOfTree.push_back(height);
	}
	int sum = 0;
	int currentHeight = 0;
	for (int i = 0; i < numberOfTree; i++)
	{
		 if (i == numberOfTree - 1)
		{
			sum += (heightOfTree[i] - currentHeight) + 1;
		}
		else if (i==0)
		{
			sum += heightOfTree[i] + 1; //+2 means one for the eating the nut next for the jumping from first tree to next tree
			if (numberOfTree > 1)
			{
				currentHeight = min(heightOfTree[i], heightOfTree[i + 1]);
				if (currentHeight < heightOfTree[i])
				{
					sum += heightOfTree[i] - currentHeight;
				}
				sum += 1;
			}	
		}
	   else
		 {  
		   sum += (heightOfTree[i] - currentHeight) +2;
		   currentHeight = min(heightOfTree[i], heightOfTree[i + 1]);
		   if (currentHeight < heightOfTree[i])
		   {
			   sum += heightOfTree[i] - currentHeight;
		   }
		 }
	}
	printf("%d\n", sum);
	//system("pause");
	return 0;
}