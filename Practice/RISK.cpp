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
#define FIO                 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);


static int rPos[] = { -1, 0, 1, 0};
static int cPos[] = {0, 1, 0, -1};

void dfsGrid(int r, int c, vector<vector<bool> >& visited, vvi& grid, int n, int m, int& currSize) {

	visited[r][c] = true;
	++currSize;

	for (int k = 0; k < 4; ++k) {
		int adjR = r + rPos[k];
		int adjC = c + cPos[k];

		if (((adjR >= 0 && adjR < n) && (adjC >= 0 && adjC < m)) &&
		        grid[adjR][adjC] && !visited[adjR][adjC])
			dfsGrid(adjR, adjC, visited, grid, n, m, currSize);
	}
}


void solve() {

	int n, m;
	cin >> n >> m;

	vvi grid(n);

	FOR (i, 0, n) {

		string s;
		cin >> s;

		FOR (j, 0, m) {
			grid[i].eb(s[j] - '0');
		}
	}

	vector<vector<bool> > visited(n, vector<bool> (m, false));

	vi islandSizes;

	FOR (i, 0, n) {
		FOR (j, 0, m) {
			if (!visited[i][j] && grid[i][j] == 1) {
				int currSize = 0;
				dfsGrid(i, j, visited, grid, n, m, currSize);
				// cout << currSize << '\n';
				islandSizes.pb(currSize);
			}
		}
	}

	rsort(islandSizes);

	int ans = 0;

	FOR (i, 0, sz(islandSizes)) {
		if (i & 1)
			ans += islandSizes[i];
	}

	cout << ans;
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
