#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include <vector>
#include<string>
using namespace std;
typedef long long ll;
#define sf scanf
#define pf printf

int main()
{
	int n;
	scanf("%d", &n);
	vector<string> grid(n);
	for (int i = 0; i < n; i++)
	{
		cin >> grid[i];
	}
	char diagonalChar = grid[0][0];
	char otherChar = grid[0][1]; //It is guarented that both of these will exists in any test case as n>=3 atleast

	if (diagonalChar == otherChar)
	{
		pf("NO\n");
		return 0;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j || (i + j+1  == n))
			{
				if (diagonalChar != grid[i][j] )
				{
					pf("NO\n");
					return 0;
				}
			}
			else
			{
				if (otherChar != grid[i][j])
				{
					pf("NO\n");
					return 0;
				}
			}
		}
	}
	pf("YES\n");
	//system("pause");
	return 0;
}