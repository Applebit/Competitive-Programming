#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <bitset>
#include <vector>
using namespace std;
#define pf(n) printf("%d\n",n);
#define sf(x) scanf("%d",&x);

using namespace std;

int main()
{
	int n;
	bitset<4> isCenterPoint=0;
	vector<pair<int,int> > pointCollection;
	int countSuperCentralPoint=0;
	sf(n);
	for (int i = 0; i < n; i++)
	{
		int xCoordinate, ycoordinate;
		sf(xCoordinate);sf(ycoordinate);
		pointCollection.push_back(make_pair(xCoordinate, ycoordinate));
	}

	for (int j = 0; j < n; j++)
	{
		int currentX = pointCollection[j].first, currentY = pointCollection[j].second;
		isCenterPoint = 0;
		for (int i = 0; i < n; i++)
		{
			if (i != j)
			{
				if (currentX > pointCollection[i].first && currentY == pointCollection[i].second)
				{
					isCenterPoint[0] = 1;  
				}
				else if (currentX < pointCollection[i].first && currentY == pointCollection[i].second)
				{
					isCenterPoint[1] = 1;
				}
				else if (currentX == pointCollection[i].first && currentY > pointCollection[i].second)
				{
					isCenterPoint[2] = 1;
				}
				else if (currentX == pointCollection[i].first && currentY < pointCollection[i].second)
				{
					isCenterPoint[3] = 1;
				}

			}		
		}
		if (isCenterPoint.all())
		{
			countSuperCentralPoint++;
		}
	}
	pf(countSuperCentralPoint);
	//system("pause");
	return 0;
}