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
string a, b;

void performFlip(int l, int r) {
	FOR (i, l, r + 1) {
		a[i] = ((a[i] == '0') ? '1' : '0');
	}
}

void solve() {
	cin >> n >> a >> b;

	if (a == b) {
		cout << 0;
		return;
	}

	bool all_chars_same_A = true;
	bool all_chars_same_B = true;

	FOR (i, 1, n) {
		if (a[i] != a[i - 1]) {
			all_chars_same_A = false;
			break;
		}
	}

	FOR (i, 1, n) {
		if (b[i] != b[i - 1]) {
			all_chars_same_B = false;
			break;
		}
	}

	if (all_chars_same_A || all_chars_same_B) {
		cout << -1;
		return;
	}

	int x = -1;

	FOR (i, 0, n - 1) {
		if (b[i] != b[i + 1]) {
			x = i;
			break;
		}
	}

	vpii pos;

	if (a[x] == a[x + 1]) {
		FOR (i, 0, x) {
			if (a[i] != a[i + 1]) {
				performFlip(i, x);
				pos.pb({i, x});
				break;
			}
		}

		if (a[x] == a[x + 1]) {
			RFOR (i, n, x + 2) {
				if (a[i] != a[i - 1]) {
					performFlip(x + 1, i);
					pos.pb({x + 1, i});
					break;
				}
			}
		}
	}

	FOR (i, 0, x) {
		if (a[i] != b[i]) {
			performFlip(i, x + 1);
			pos.pb({i, x + 1});
		}
	}

	RFOR (i, n, x + 2) {
		if (a[i] != b[i]) {
			performFlip(x, i);
			pos.pb({x, i});
		}
	}

	if (a[x] != b[x]) {
		performFlip(x, x + 1);
		pos.pb({x, x + 1});
	}

	cout << sz(pos) << '\n';

	FORALL (i, pos) {
		cout << i.first + 1 << ' ' << i.second + 1 << '\n';
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
