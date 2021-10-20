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


int n, m;
vvi adj;
vi indegree, ans;

void init() {
	adj.clear();
	adj.resize(n + 1);
	indegree.clear();
	indegree.resize(n + 1, 0);
	ans.clear();
	ans.resize(n + 1, 0);
}

bool isPossible(int d) {
	vi nodes(n + 1, 0);
	vi indeg = indegree;

	int cV = n;
	queue<int> todo;

	FOR (i, 1, n + 1) {
		if (indeg[i] <= d) {
			nodes[i] = cV--;
			todo.push(i);
		}
	}

	while (!todo.empty()) {
		int currNode = todo.front();
		todo.pop();

		FOR (i, 0, sz(adj[currNode])) {
			int adjNode = adj[currNode][i];
			--indeg[adjNode];

			if (nodes[adjNode] != 0)
				continue;

			if (indeg[adjNode] <= d) {
				nodes[adjNode] = cV--;
				todo.push(adjNode);
			}
		}
	}

	FOR (i, 1, n + 1) {
		if (nodes[i] == 0)
			return false;
	}

	ans = nodes;
	return true;
}

void solve() {

	cin >> n >> m;

	init();

	int u, v;
	FOR (i, 0, m) {
		cin >> u >> v;

		adj[u].eb(v);
		adj[v].eb(u);

		++indegree[u];
		++indegree[v];
	}

	int lo = 0, hi = n, diff = -1;

	while (lo <= hi) {
		int mid = lo + (hi - lo) / 2;

		if (isPossible(mid)) {
			diff = mid;
			hi = mid - 1;
		}
		else
			lo = mid + 1;
	}

	cout << diff << '\n';

	FOR (i, 1, n + 1) {
		cout << ans[i] << ' ';
	}
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
