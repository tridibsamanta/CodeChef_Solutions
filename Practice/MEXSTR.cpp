/*
 ~ Author        : @tridib_2003
*/

#include<bits/stdc++.h>
using namespace std;

#define int                 long long
#define ull                 unsigned long long
#define PI                  3.1415926535897932384626
#define MOD                 1000000007
#define vi                  vector<int>
#define vll                 vector<long long>
#define vvi                 vector<vector<int> >
#define pb                  push_back
#define eb                  emplace_back
#define mp(a, b)            make_pair(a, b)
#define pii                 pair<int, int>
#define vpii                vector<pair<int, int> >
#define mk(arr, n, type)    type *arr = new type[n];
#define FOR(i, a, b)        for (int(i) = (a); (i) < (b); ++(i))
#define RFOR(i, a, b)       for (int(i) = (a)-1; (i) >= (b); --(i))
#define FORALL(i, dp)       for (auto& (i) : (dp))
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
#define FIO                 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

#define INT_MAX             LLONG_MAX

void solve() {

	string s;
	cin >> s;

	int n = sz(s);

	int nextZero_idx = INT_MAX, nextOne_idx = INT_MAX;
	vll nextZero(n, INT_MAX), nextOne(n, INT_MAX);

	RFOR(i, n, 0) {
		nextZero[i] = nextZero_idx;
		nextOne[i] = nextOne_idx;
		if (s[i] == '0')
			nextZero_idx = i;
		else
			nextOne_idx = i;
	}

	// s[i] = '1' for all i in [0, n)
	if (nextZero_idx == INT_MAX) {
		cout << 0;
		return;
	}
	// s[i] = '0', for all i in [0, n)
	if (nextOne_idx == INT_MAX) {
		cout << 1;
		return;
	}

	vll dp(n);
	bool one = false, zero = false;
	int cnt = 0;

	RFOR(i, n, 0) {
		dp[i] = cnt;

		if (s[i] == '1')
			one = true;
		if (s[i] == '0')
			zero = true;

		if (one && zero) {
			++cnt;
			zero = one = false;
		}
	}

	// FORALL(i, dp) {
	// 	cout << i << ' ';
	// }

	int idx = nextOne_idx;
	string mexStr = "";

	while (1) {

		mexStr.pb(s[idx]);

		if (nextZero[idx] == INT_MAX) {
			mexStr.pb('0');
			break;
		}
		if (nextOne[idx] == INT_MAX) {
			mexStr.pb('1');
			break;
		}

		if (dp[nextZero[idx]] <= dp[nextOne[idx]])
			idx = nextZero[idx];
		else
			idx = nextOne[idx];
	}

	cout << mexStr;
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
