#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
#define pf printf
#define sf scanf

int main()
{
	int t = 0;
	int l, r, n, m, x;
	sf("%d%d", &n, &x);
	int sum;
	int temp = 0;
	for (int i = 1; i <= n; i++)
	{
		sf("%d%d", &l, &r);
		sum = 0;
		while (1)
		{
			t = t + x;
			if (t >= l)
			{
				t = (t - x);
				sum = sum + (r - t);
				t = t + sum;
				break;
			}
		}
		temp = temp + sum;
	}
	pf("%d\n", temp);
}