#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <sstream>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <iomanip>
#include <cstdlib>

using namespace std;
int main()
{
	vector< pair<string, string> > accountInformation;

	int n;
	scanf("%d", &n);
	while (n--)
	{
		string fname, lname, balance;
		cin >> fname >> lname >> balance;
		accountInformation.push_back(make_pair(fname + " " + lname, balance));
	}
	int m;
	cin >> m;
	double totalCent = 0.0;
	while (m--)
	{
			string fname, lname, withdrawnAmount;
			cin >> fname >> lname >> withdrawnAmount;
			for (int i = 0; i < accountInformation.size(); i++)
			{
				if ((fname+" "+ lname) == accountInformation[i].first)
				{
					accountInformation[i].second.erase(0,1);
					istringstream iss(accountInformation[i].second);
					vector<string> tokens;
					tokens.clear();
					string token;
					while (getline(iss, token, '.'))
					{
						if (!token.empty())
							tokens.push_back(token);
					}
					withdrawnAmount.erase(0, 1);
					double serviceDuty = atoi(tokens[1].c_str()) *atoi(withdrawnAmount.c_str()) / atoi(tokens[0].c_str()); //This transaction is not a concurrent transaction
					totalCent += serviceDuty;
					double totalWithdrawn=(serviceDuty / (double)100 + atof(withdrawnAmount.c_str()));
					double newBalance = atof(accountInformation[i].second.c_str()) - totalWithdrawn; //updated balance
					ostringstream oss;
					oss << fixed<<setprecision(2)<<newBalance; //don't loss the trailing values
					accountInformation[i].second = '$' + oss.str();
					break;
				}
			}
	}
	for (int i = 0; i < accountInformation.size(); i++)
	{
		cout << accountInformation[i].first <<" "<< accountInformation[i].second << endl;
	}
	printf("$%.2f\n", totalCent / (double)100);
	system("pause");

 return 0;
}