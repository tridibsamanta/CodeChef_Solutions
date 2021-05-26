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
#define FORALL(i, a)        for (auto& (i) : (a))
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

const int MAXN = 1e3 + 3;

int grid[MAXN][MAXN];

void precompute() {

	for (int i = 1; i <= 1000; ++i) {

		grid[i][1] = grid[i - 1][2] + 1;
		int d = i;

		for (int j = 2; j <= 1000; ++j) {
			grid[i][j] = grid[i][j - 1] + d++;
		}
	}
}

void solve() {

	int x1, x2, y1, y2;
	cin >> x1 >> y1 >> x2 >> y2;

	int pathSum = 0;

	FOR (i, x1, x2 + 1) {
		pathSum += grid[i][y1];
	}

	FOR (i, y1 + 1, y2 + 1) {
		pathSum += grid[x2][i];
	}

	cout << pathSum;
}

int32_t main() {

	FIO;

	precompute();

	int t = 1;
	cin >> t;
	while (t--) {
		solve();
		cout << '\n';
	}

	return 0;
}
