/*
 ~ Author        : @tridib_2003
*/

#pragma GCC optimize("O3")
// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")

#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update> indexed_set;

#define ll                  long long
#define ull                 unsigned long long
#define PI                  acos(-1)
#define MOD                 1000000007 // 998244353
#define EPS                 1e-9
#define vi                  vector<int>
#define vb                  vector<bool>
#define vvi                 vector<vector<int> >
#define vll                 vector<long long>
#define vvll                vector<vector<long long> >
#define pii                 pair<int, int>
#define pll                 pair<long long, long long>
#define vpii                vector<pair<int, int> >
#define vpll                vector<pair<long long, long long> >
#define pb                  push_back
#define eb                  emplace_back
#define mp                  make_pair
#define mk(arr, n, type)    type *arr = new type[n];
#define FOR(i, a, b)        for (int(i) = (a); (i) < (b); ++(i))
#define RFOR(i, a, b)       for (int(i) = (a)-1; (i) >= (b); --(i))
#define FORALL(i, a)        for (auto& (i) : (a))
#define print(a)            cout << a << '\n'
#define printall(a)         for (auto& (i) : (a)) cout << i << ' '
#define rsort(a)            sort((a).rbegin(), (a).rend())
#define w(x)                int x; cin >> x; while(x--)
#define all(c)              (c).begin(), (c).end()
#define sz(c)               (int)(c).size()
#define pqmx                priority_queue<int>
#define pqmn                priority_queue<int, vector<int>, greater<int> >
#define max3(a, b, c)       max((a), max((b), (c)))
#define min3(a, b, c)       min((a), min((b), (c)))
#define mx_all(c)           *max_element((c).begin(), (c).end())
#define mn_all(c)           *min_element((c).begin(), (c).end())
#define lwr_b(c, a)         lower_bound((c).begin(), (c).end(), (a)) - ((c).begin())
#define upr_b(c, a)         upper_bound((c).begin(), (c).end(), (a)) - ((c).begin())
#define FIO                 ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);


void solve() {
	int n;
	cin >> n;

	string a, b;
	cin >> a >> b;

	vi suffZeroCnt_A(n + 1, 0), suffZeroCnt_B(n + 1, 0);

	RFOR (i, n, 0) {
		suffZeroCnt_A[i] = suffZeroCnt_A[i + 1] + (a[i] == '0');
	}

	RFOR (i, n, 0) {
		suffZeroCnt_B[i] = suffZeroCnt_B[i + 1] + (b[i] == '0');
	}

	vvi dp(n + 1, vi (n + 1, 0));
	// dp[i][j] = # of inversions considering
	// we've merged the substrings A[i...n] and B[j...n]

	RFOR (i, n, 0) {
		dp[i][n] = dp[i + 1][n];

		if (a[i] == '1')
			dp[i][n] += suffZeroCnt_A[i];
	}

	RFOR (j, n, 0) {
		dp[n][j] = dp[n][j + 1];

		if (b[j] == '1')
			dp[n][j] += suffZeroCnt_B[j];
	}

	RFOR (i, n, 0) {
		RFOR (j, n, 0) {
			int val1 = 0, val2 = 0;

			if (a[i] == '0')
				val1 = dp[i + 1][j];
			else
				val1 = dp[i + 1][j] + suffZeroCnt_A[i] + suffZeroCnt_B[j];

			if (b[j] == '0')
				val2 = dp[i][j + 1];
			else
				val2 = dp[i][j + 1] + suffZeroCnt_A[i] + suffZeroCnt_B[j];

			dp[i][j] = min(val1, val2);
		}
	}

	cout << dp[0][0];
}

int32_t main() {

	FIO;

	int t = 1;
	cin >> t;
	while (t--) {
		solve();
		cout << '\n';
	}

	return 0;
}
