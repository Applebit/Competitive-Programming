#include <iostream>
using namespace std;
unsigned long long choose(unsigned long long, unsigned long long); //function prototype

int main()
{
	unsigned n, m;
	cin >> n >> m;
	if (m == 1)
	{
		unsigned long long ans = choose(n, 2);
		cout << ans<<" "<<ans<< endl;
		return 0;
	}
	//maximum friend will be possible if max student goes to single group
	unsigned long long maximumFriend=choose(n - (m - 1), 2);
	//minimum friend will be when the uniform distribution between groups takes place 
	unsigned long long scatterdGroup = n / m;
	unsigned long long leftGroup = n%m;
	unsigned long long someFriedWithoutLeft = choose(scatterdGroup, 2);
	unsigned long long withLeft = choose(scatterdGroup + 1, 2);
	unsigned long long minimumFriend = (m - leftGroup)*someFriedWithoutLeft + leftGroup*withLeft;
	cout << minimumFriend << " " << maximumFriend << endl;
	return 0;
}


unsigned long long choose(unsigned long long n, unsigned long long k) {             //Ancient algorithm explained by Donald knuth 
	if (k > n) {
		return 0;
	}
	unsigned long long r = 1;
	for (unsigned long long d = 1; d <= k; ++d) {
		r *= n--;
		r /= d;
	}
	return r;
}