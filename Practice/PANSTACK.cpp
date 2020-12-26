/*
 ~ Author        : @tridib_2003
*/

#include<bits/stdc++.h>
using namespace std;

#define ll                  long long
#define PI                  3.1415926535897932384626
#define MOD                 1000000007
#define vi                  vector<int>
#define mk(arr, n, type)    type *arr = new type[n];
#define FOR(a, c)           for (int(a) = 0; (a) < (c); (a)++)
#define w(x)                int x; cin >> x; while(x--)
#define FIO                 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

const int mxN = 1001;

int dp[mxN][mxN];

void solve() {

	memset(dp, 0, sizeof(dp));

	dp[0][0] = 1;

	for (int i = 1; i < mxN; ++i) {

		dp[i][0] = dp[i - 1][i - 1];

		for (int j = 1; j <= i; ++j) {
			dp[i][j] = (dp[i - 1][j - 1] + dp[i][j - 1]) % MOD;
		}
	}
}


int main() {

	FIO;

	solve();

	int tc = 1;
	cin >> tc;
	while (tc--) {

		int n;
		cin >> n;

		cout << dp[n - 1][n - 1];

		cout << '\n';
	}

	return 0;
}
