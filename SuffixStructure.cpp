#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include <math.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;
const int N = 1e5 + 5;

int cnt[30];
char s[N], t[N];
void solve();

void solve()
{
	scanf("%s%s", &s, &t);
	int n = strlen(s);
	int m = strlen(t);

	memset(cnt, 0, sizeof cnt);

	bool sau = false;
	for (int i = 0, j = 0; i<n; ++i){
		if (j<m && s[i] == t[j]) ++j;
		if (j == m) sau = true;
	}

	for (int i = 0; i<n; ++i) cnt[s[i] - 'a']++;
	for (int i = 0; i<m; ++i) cnt[t[i] - 'a']--;

	bool sar = true;
	bool all = true;

	for (int i = 0; i<26; ++i){
		sar &= cnt[i] == 0;
		all &= cnt[i] >= 0;
	}

	if (sau) cout << "automaton" << endl; else
	if (sar) cout << "array" << endl; else
	if (all) cout << "both" << endl; else
		cout << "need tree" << endl;
	
}

int main(){
	//freopen("input.txt","r",stdin);// freopen("output.txt","w",stdout);
	solve();
	return 0;
}