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


const int MAXN = 2e5 + 5;
const int LG = 22;

vector<int> adj[MAXN];
int st[MAXN], en[MAXN], lvl[MAXN], P[MAXN][LG], timer;

int k;
vi path;

void dfs(int node, int parent) {
	lvl[node] = 1 + lvl[parent];
	P[node][0]  = parent;

	st[node] = timer++;

	for (int i : adj[node]) {
		if (i != parent)
			dfs(i, node);
	}

	en[node] = timer++;
}

void pre(int u, int p) {
	P[u][0] = p;

	for (int i = 1; i < LG; ++i)
		P[u][i] = P[P[u][i - 1]][i - 1];

	for (auto i : adj[u])
		if (i != p)
			pre(i, u);
}

int lca(int u, int v) {
	int i, lg;
	if (lvl[u] < lvl[v])
		swap(u, v);

	for (lg = 0; (1 << lg) <= lvl[u]; ++lg);
	lg--;

	for (i = lg; i >= 0; i--) {
		if (lvl[u] - (1 << i) >= lvl[v])
			u = P[u][i];
	}

	if (u == v)
		return u;

	for (i = lg; i >= 0; i--) {
		if (P[u][i] != -1 and P[u][i] != P[v][i])
			u = P[u][i], v = P[v][i];
	}

	return P[u][0];
}

bool isSimplePath() {
	vpii vec;

	FORALL (i, path) {
		vec.pb({st[i], i});
	}

	sort(all(vec));

	// FOR (i, 0, sz(vec)) {
	// 	cout << vec[i].first << ' ' << vec[i].second << '\n';
	// }

	vi node;

	FOR (i, 0, k) {
		if (!(i + 1 < k and en[vec[i + 1].second] < en[vec[i].second]))
			node.eb(vec[i].second);
	}

	// printall(node); cout << '\n';

	if (sz(node) > 2)
		return false;
	if (sz(node) == 1)
		return true;

	int lca_node = lca(node[0], node[1]);
	// print(lca_node);

	FORALL (i, path) {
		if (i != lca_node and lvl[lca_node] >= lvl[i])
			return false;
	}

	return true;
}

void solve() {

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		adj[i].clear();
		st[i] = en[i] = lvl[i] = 0;
		for (int j = 0; j < LG; j++) {
			P[i][j] = -1;
		}
	}
	timer = 0;

	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;

		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	dfs(1, 0);
	pre(1, 0);

	int q;
	cin >> q;

	while (q--) {

		cin >> k;

		path.clear();
		path.resize(k);

		FORALL (i, path) {
			cin >> i;
		}

		cout << (isSimplePath() ? "YES\n" : "NO\n");
	}
}

int32_t main() {

	FIO;

	int t = 1;
	cin >> t;
	while (t--) {
		solve();
		// cout << '\n';
	}

	return 0;
}
