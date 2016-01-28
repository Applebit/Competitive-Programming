#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
typedef long long ll;
using namespace std;
#define pf(n) printf("%d\n",n)
#define sf(n) scanf("%d",&n)
typedef long long ll;


using namespace std;


int main() {
	map<string, string> languageCombination;
	vector<string> professorLecture;
	int n, m;
	sf(n); sf(m);
	for (int i = 0; i < m; i++)
	{
		string firstLanguage, secondLanguage;
		cin >> firstLanguage >> secondLanguage;
		languageCombination[firstLanguage] = secondLanguage;
	}
	for (int i = 0; i < n; i++)
	{
		string lectureWord;
		cin >> lectureWord;
		for (map<string, string>::iterator it = languageCombination.begin(); it != languageCombination.end(); ++it)
		{
			if (lectureWord == it->first || lectureWord == it->second)
			{
				professorLecture.push_back(it->first.length() <= it->second.length()?it->first:it->second); //push the minimum length string into the lecture notes
				break;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (i == n)
		{
			cout << professorLecture[i] << endl;
		}
		else
		{
			cout << professorLecture[i] << " ";
		}
			
	}
	//system("pause");
	return 0;
}