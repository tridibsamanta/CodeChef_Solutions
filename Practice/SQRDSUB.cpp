/*
 ~ Author        : @tridib_2003
 ~ Problem Code  : SQRDSUB
 ~ Link          : https://www.codechef.com/problems/SQRDSUB
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int tc;
	cin >> tc;
	while (tc--) {

		ll n;
		cin >> n;

		ll arr[n];
		for (ll i = 0; i < n; ++i)
			cin >> arr[i];

		for (ll i = 0; i < n; ++i) {
			// Divisible by 4
			if (arr[i] % 4 == 0)
				arr[i] = 2;
			// All even nos (except divisible by 4)
			else if (arr[i] % 2 == 0)
				arr[i] = 1;
			// All odd nos
			else
				arr[i] = 0;
		}

		ll preSum[n];
		preSum[0] = arr[0];

		for (ll i = 1; i < n; ++i)
			preSum[i] = preSum[i - 1] + arr[i];

		ll res = 0;

		for (ll i = 0; i < n; ++i) {

			if (arr[i] == 0) {
				ll idx = upper_bound(preSum, preSum + n, preSum[i]) - preSum;
				res += idx - i;

				idx = lower_bound(preSum, preSum + n, preSum[i] + 2) - preSum;
				res += n - idx;
			}
			else if (arr[i] == 1) {
				ll idx = lower_bound(preSum, preSum + n, preSum[i] + 1) - preSum;
				res += n - idx;
			}
			else {
				res += n - i;
			}
		}

		cout << res <<  '\n';

	}

	return 0;
}