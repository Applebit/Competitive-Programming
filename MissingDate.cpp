//#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<map>
#include<vector>
#include<stdio.h>
#include<string.h>
#include <algorithm>
typedef std::vector<int> vi;

using namespace std;


int main()
{
    int tc;
    scanf("%d", &tc);
    while (tc--)
    {
        int year, yearMonth;
        int age, ageMonth;
        scanf("%d %d", &year, &yearMonth);
        scanf("%d %d", &age, &ageMonth);
        int resYear = 0, resMonth = 0;
        if (yearMonth == 12)
        {
            resYear = year + 1 + age;
            resMonth = ageMonth;
        }
        else if (ageMonth == 12)
        {
            resYear = year + 1 + age;
            resMonth = yearMonth;
        }
        else
        {
            int totalMonth = yearMonth + ageMonth;
            if (totalMonth > 12)
            {
                resYear = (year + (1 + age));
                resMonth = (totalMonth - 12);
            }
            else
            {
                resYear = (year + age);
                resMonth = totalMonth;
            }
        }
        printf("%d %d\n", resYear, resMonth);
    }
    return 0;
}