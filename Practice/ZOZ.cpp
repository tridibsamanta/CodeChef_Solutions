/*
 ~ Author        : @tridib_2003
 ~ Problem Code  : ZOZ
 ~ Link          : https://www.codechef.com/problems/ZOZ
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--) {

		ll int n, k;
		cin >> n >> k;

		ll int a[n], sum = 0;
		for (ll int i = 0; i < n; ++i) {
			cin >> a[i];
			sum += a[i];
		}

		int pos = 0;
		for (ll int i = 0; i < n; ++i)
			if ((a[i] + k) > (sum - a[i]))
				++pos;

		cout << pos << '\n';

	}

	return 0;
}