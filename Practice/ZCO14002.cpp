/*
 ~ Author        : @tridib_2003
*/

#include<bits/stdc++.h>
using namespace std;

#define ll                  long long
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


void solve() {

	int n;
	cin >> n;

	vi nums(n);

	FOR (i, 0, n) {
		cin >> nums[i];
	}

	if (n == 1) {
		cout << nums[0];
		return;
	}

	if (n == 2) {
		cout << min(nums[0], nums[1]);
		return;
	}

	if (n == 3) {
		cout << min(nums[0], min(nums[1], nums[2]));
	}

	vi dp(n, 0);

	dp[0] = nums[0];
	dp[1] = nums[1];
	dp[2] = nums[2];

	FOR (i, 3, n) {
		dp[i] = nums[i] + min(dp[i - 1], min(dp[i - 2], dp[i - 3]));
	}

	cout << min(dp[n - 1], min(dp[n - 2], dp[n - 3]));
}

int main() {

	FIO;

	int t = 1;
	// cin >> t;
	while (t--) {
		solve();
		cout << '\n';
	}

	return 0;
}
