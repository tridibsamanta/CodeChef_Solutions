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


int n;
vvi adj;
vi value;
vi subTreeGcd;
int ans;

void init() {
	ans = 0;

	adj.clear();
	adj.resize(n + 1);

	value.clear();
	value.resize(n + 1);

	subTreeGcd.clear();
	subTreeGcd.resize(n + 1);
}

int computeSubTreeGcd(int u, int p) {
	int currGcd = value[u];

	for (int i = 0; i < sz(adj[u]); ++i) {
		int v = adj[u][i];

		if (v != p) {
			int childGcd = computeSubTreeGcd(v, u);
			currGcd = __gcd(currGcd, childGcd);
		}
	}

	subTreeGcd[u] = currGcd;
	return currGcd;
}

void getMaxDamage(int u, int p, int parentGcd) {
	int curr = parentGcd;
	vi child, pGcd, s_Gcd;

	for (int i = 0; i < sz(adj[u]); ++i) {
		int v = adj[u][i];

		if (v != p) {
			curr += subTreeGcd[v];
			child.eb(v);
			pGcd.eb(subTreeGcd[v]);
			s_Gcd.eb(subTreeGcd[v]);
		}
	}

	ans = max(ans, curr);

	int m = sz(pGcd);

	FOR (i, 1, m) {
		pGcd[i] = __gcd(pGcd[i], pGcd[i - 1]);
	}

	RFOR (i, m - 1, 0) {
		s_Gcd[i] = __gcd(s_Gcd[i], s_Gcd[i + 1]);
	}

	FOR (i, 0, m) {
		int currParentGcd = value[u];

		if (i > 0)
			currParentGcd = __gcd(currParentGcd, pGcd[i - 1]);

		if (i < (m - 1))
			currParentGcd = __gcd(currParentGcd, s_Gcd[i + 1]);

		if (p != -1)
			currParentGcd = __gcd(currParentGcd, parentGcd);

		getMaxDamage(child[i], u, currParentGcd);
	}
}

void solve() {

	cin >> n;

	init();

	FOR (i, 0, n - 1) {
		int u, v;
		cin >> u >> v;

		adj[u].eb(v);
		adj[v].eb(u);
	}

	FOR (i, 1, n + 1) {
		cin >> value[i];
	}

	computeSubTreeGcd(1, -1);
	getMaxDamage(1, -1, 0);

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
