/*
 ~ Author        : @tridib_2003
 ~ Problem Code  : DRAGNXOR
 ~ Link          : https://www.codechef.com/problems/DRAGNXOR
*/

#include<bits/stdc++.h>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int tc;
	cin >> tc;
	while (tc--) {

		int n, a, b;
		cin >> n >> a >> b;

		int aSetBits = __builtin_popcount(a), aZeros = n - aSetBits;
		int bSetBits = __builtin_popcount(b), bZeros = n - bSetBits;

		int pair_1a_0b = min(aSetBits, bZeros);
		int pair_0a_1b = min(bSetBits, aZeros);

		int resSetBits = pair_1a_0b + pair_0a_1b;
		int ans = ((1 << resSetBits) - 1) << (n - resSetBits);

		cout << ans << '\n';

	}

	return 0;
}