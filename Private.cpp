//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<stdio.h>
#include<math.h>
#include<vector>
#include<stdio.h>
#include<string>
#include <algorithm>
typedef long long ll;
typedef std::vector<int> vi;


using namespace std;


int main()
{
    int n;
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++)
    {
        string key;
        cin >> key;
        int beforeDot = 0, afterDot = 0;
        int counter = 1;
        for (int j = 0; j < key.length(); j++)
        {
            if (key[j] != '.' && counter == 1)
            {
                if ((int)key[j] >= 65 && (int)key[j] <= 90)
                    beforeDot += (int)key[j] - 64;
                else
                    beforeDot += (int)key[j] - 96;
            }
            else if (key[j] != '.' && counter == 2)
            {
                if ((int)key[j] >= 65 && (int)key[j] <= 90)
                    afterDot += (int)key[j] - 64;
                else
                    afterDot += (int)key[j] - 96;
            }
            else
            {
                counter++;
            }
        }
        if (beforeDot != afterDot)
            cout << key << endl;
    }
    //system("pause");
    return 0;
}