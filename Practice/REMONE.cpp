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


void solve() {

	int n;
	cin >> n;

	vi arr1(n);

	FOR (i, 0, n) {
		cin >> arr1[i];
	}

	vi arr2(n - 1);

	FOR (i, 0, n - 1) {
		cin >> arr2[i];
	}

	if (n == 2) {
		int d1 = arr2[0] - arr1[0];
		int d2 = arr2[0] - arr1[1];

		if (d1 > 0 && d2 > 0)
			cout << min(d1, d2);
		else
			cout << max(d1, d2);

		return;
	}

	sort(all(arr1));
	sort(all(arr2));

	bool equalDiff = true;

	FOR (i, 2, n) {
		if ((arr1[i] - arr1[i - 1]) != (arr1[i - 1] - arr1[i - 2]))
			equalDiff = false;
	}

	int x; // positive integer that was added

	int d_11 = arr2[0] - arr1[0];
	int d_22 = arr2[1] - arr1[1];
	int d_12 = arr2[0] - arr1[1];
	int d_23 = arr2[1] - arr1[2];

	if (equalDiff) {
		if (arr2[0] > arr1[1]) {
			x = d_12;
		}
		else {
			x = d_11;
		}
	}
	else {
		if (d_11 == d_22) {
			x = d_11;
		}
		else if (d_12 == d_23) {
			x = d_12;
		}
		else if (d_11 == d_23) {
			x = d_11;
		}
	}

	cout << x;
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
