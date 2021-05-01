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

const int MAXN = 5e5 + 5;

vi adj[MAXN];

void solve() {

	int n, m;
	cin >> n >> m;

	FOR (i, 1, n + 1) {
		adj[i].clear();
	}

	FOR (i, 0, m) {
		int src, dest;
		cin >> src >> dest;
		adj[src].eb(dest);
		adj[dest].eb(src);
	}

	if (m < n - 1) {
		cout << 0 << '\n';
		FOR(i, 0, n) {
			cout << 0;
		}
		return;
	}

	map<vi, int> mp;

	FOR (i, 1, n + 1) {
		sort(all(adj[i]));
		++mp[adj[i]];
	}

	string res;
	FOR (i, 0, n) {
		res.pb('0');
	}

	int cnt = 0;

	FORALL(i, mp) {
		if (sz(i.first) + i.second == n) {
			if (++cnt == 1) {
				FOR (j, 0, n) {
					res[j] = '1';
				}
				FORALL (j, i.first) {
					res[j - 1] = '0';
				}
			}
		}
	}

	cout << cnt << '\n' << res;
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
