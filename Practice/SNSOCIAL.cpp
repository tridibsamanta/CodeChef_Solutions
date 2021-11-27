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


static int row8D[] = { -1, -1, -1, 0, 0, 1, 1, 1};
static int col8D[] = { -1, 0, 1, -1, 1, -1, 0, 1};

int n, m, ans;
vvi grid;
queue<pii> todo;
vector<vb> visited;

void init() {
	grid.clear();
	grid.resize(n);

	FOR (i, 0, n) {
		grid[i].resize(m, 0);
	}

	visited.clear();
	visited.resize(n);

	FOR (i, 0, n) {
		visited[i].resize(m, false);
	}

	ans = 0;
}

bool isValid(int x, int y) {
	return ((x >= 0 && x < n) && (y >= 0 && y < m));
}

void bfs() {
	while (!todo.empty()) {
		bool flag = false;
		int m = sz(todo);

		FOR (i, 0, m) {
			pii curr = todo.front();
			todo.pop();

			int currX = curr.first;
			int currY = curr.second;

			FOR (k, 0, 8) {
				int adjX = currX + row8D[k];
				int adjY = currY + col8D[k];

				if (isValid(adjX, adjY)) {
					if (visited[adjX][adjY])
						continue;

					todo.push({adjX, adjY});
					visited[adjX][adjY] = true;
					flag = true;
				}
			}
		}

		if (flag)
			++ans;
	}
}

void solve() {
	cin >> n >> m;

	init();

	int maxVal = 0;

	FOR (i, 0, n) {
		FOR (j, 0, m) {
			cin >> grid[i][j];

			maxVal = max(maxVal, grid[i][j]);
		}
	}

	FOR (i, 0, n) {
		FOR (j, 0, m) {
			if (grid[i][j] == maxVal) {
				todo.push({i, j});
				visited[i][j] = true;
			}
		}
	}

	bfs();

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
