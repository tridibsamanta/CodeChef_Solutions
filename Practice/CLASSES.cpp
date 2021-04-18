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


void solve() {

	int n, m, s, k;
	cin >> n >> m >> s >> k;

	int vertices = n + 1;

	vvi adj(vertices);

	FOR (i, 0, m) {
		int src, dest;
		cin >> src >> dest;
		adj[src].eb(dest);
		adj[dest].eb(src);
	}

	vi subPresent(vertices, 0);

	FOR (i, 0, s) {
		int building;
		cin >> building;
		++subPresent[building];
	}

	vi distance(vertices, -1);
	distance[0] = 0;

	queue<int> q;
	q.push(0);

	while (!q.empty()) {

		int currV = q.front();
		q.pop();

		FOR (i, 0, sz(adj[currV])) {
			if (distance[adj[currV][i]] == -1) {
				distance[adj[currV][i]] = distance[currV] + 1;
				q.push(adj[currV][i]);
			}
		}
	}

	multiset<pii> dist;

	FOR (i, 1, vertices) {
		if (subPresent[i])
			dist.insert(mp(distance[i], i));
	}

	ll ans = 0;

	while (true) {

		auto curr = *dist.begin();

		ans += (2 * curr.first);

		if (--subPresent[curr.second] == 0) {
			dist.erase(dist.begin());
		}

		if (--k == 0)
			break;
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
