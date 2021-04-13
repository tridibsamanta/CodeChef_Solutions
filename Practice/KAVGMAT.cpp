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


vector<vector<int> > grid;

int getSubmatrixSum(int x1, int y1, int l) {
	if (l == 0)
		return 0;

	int x2 = x1 + l - 1, y2 = y1 + l - 1;

	return (grid[x2][y2] - grid[x1 - 1][y2] - grid[x2][y1 - 1] + grid[x1 - 1][y1 - 1]);
}

void solve() {

	int n, m, k;
	cin >> n >> m >> k;

	grid.clear();
	grid.resize(n + 1, vector<int> (m + 1));

	FOR (i, 1, n + 1) {
		FOR (j, 1, m + 1) {
			cin >> grid[i][j];
		}
	}

	FOR(i, 1, n + 1) {
		FOR (j, 1, m + 1) {
			grid[i][j] += grid[i - 1][j] + grid[i][j - 1] - grid[i - 1][j - 1];
		}
	}

	int cnt = 0;

	FOR (i, 1, n + 1) {
		FOR (j, 1, m + 1) {

			// perform binary search
			int maxLen = min(n - i + 1, m - j + 1);
			int l = 0, r = maxLen, mid;

			while (l < r) {

				mid = (l + r + 1) / 2;

				if (k > getSubmatrixSum(i, j, mid) / (mid * mid))
					l = mid;
				else
					r = mid - 1;

			}

			cnt += maxLen - l;
		}
	}

	cout << cnt;
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
