/*
 ~ Author        : @tridib_2003
*/

#include<bits/stdc++.h>
using namespace std;

#define ll                  long long
#define int                 long long
#define ull                 unsigned long long
#define PI                  3.1415926535897932384626
#define MOD                 1000000007
#define vi                  vector<int>
#define vvi                 vector<vector<int> >
#define pb                  push_back
#define eb                  emplace_back
#define mp(a, b)            make_pair(a, b)
#define pii                 pair<int, int>
#define vpii                vector<pair<int, int> >
#define mk(arr, n, type)    type *arr = new type[n];
#define FOR(i, a, b)        for (int(i) = (a); (i) < (b); ++(i))
#define RFOR(i, a, b)       for (int(i) = (a)-1; (i) >= (b); --(i))
#define w(x)                int x; cin >> x; while(x--)
#define all(c)              (c).begin(), (c).end()
#define sz(c)               (int)(c).size()
#define pqmx                priority_queue<int>
#define pqmn                priority_queue<int, vector<int>, greater<int> >
#define mx_all(c)           *max_element((c).begin(), (c).end())
#define mn_all(c)           *min_element((c).begin(), (c).end())
#define lwr_b(c, a)         lower_bound((c).begin(), (c).end(), (a)) - ((c).begin())
#define upr_b(c, a)         upper_bound((c).begin(), (c).end(), (a)) - ((c).begin())
#define FIO                 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);


int dp[100001][11][2];
int cntdp[100001][2];
int pows[100001];

bool done = 0;

int power10(int n) {

	if (!done) {

		pows[0] = 1;

		for (int i = 1; i <= 100000; ++i)
			pows[i] = (pows[i - 1] * 10LL) % MOD;

		done = 1;
	}

	return pows[n];
}

ll countNumbers(string& num, int n, bool tight) {

	if (tight == 0)
		return power10(n);

	if (n == 0)
		return 1;

	if (cntdp[n][tight] != -1)
		return cntdp[n][tight];

	int maxDigit = 9;

	if (tight) {
		maxDigit = num[num.length() - n] - '0';
	}

	ll ans = 0;

	for (int dig = 0; dig <= maxDigit; ++dig) {
		ans = (ans + countNumbers(num, n - 1, tight & (dig == maxDigit))) % MOD;
	}

	return cntdp[n][tight] = ans % MOD;
}

int computePassword(string& num, int n, int prev, bool tight) {

	if (n == 0)
		return 0;

	if (dp[n][prev][tight] != -1)
		return dp[n][prev][tight];

	int maxDigit = 9;

	if (tight)
		maxDigit = num[num.length() - n] - '0';

	ll ans = 0;

	for (int dig = 0; dig <= maxDigit; ++dig) {

		if (dig != prev) {

			ll curr = (dig * (1LL * power10(n - 1)) * countNumbers(num, n - 1, tight & (dig == maxDigit))) % MOD;
			ans = (ans + curr) % MOD;
		}

		ans = (ans + computePassword(num, n - 1, dig, tight & (dig == maxDigit))) % MOD;
	}

	return dp[n][prev][tight] = ans % MOD;
}

int bruteForce(string& num, int n) {

	int prev = -1;
	ll ans = 0;

	for (int i = 0; i < num.length(); ++i) {
		if ((num[i] - '0') != prev) {
			ans = (ans + (num[i] - '0') * power10(num.length() - i - 1)) % MOD;
		}

		prev = num[i] - '0';
	}

	return ans % MOD;
}

void solve() {

	int nl;
	string L;
	cin >> nl >> L;

	int nr;
	string R;
	cin >> nr >> R;

	memset(dp, -1, sizeof(dp));
	memset(cntdp, -1, sizeof(cntdp));

	ll R_ans = computePassword(R, nr, -1, 1);

	memset(dp, -1, sizeof(dp));
	memset(cntdp, -1, sizeof(cntdp));

	ll L_ans = computePassword(L, nl, -1, 1);

	cout << (R_ans + (MOD - L_ans) + bruteForce(L, nl)) % MOD;
}

signed main() {

	FIO;

	int t = 1;
	cin >> t;
	while (t--) {
		solve();
		cout << '\n';
	}

	return 0;
}
