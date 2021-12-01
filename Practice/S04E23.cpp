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


bool isReachable(int x, int y, int move_x, int move_y) {
	if (((x & 1) && !(move_x & 1)) || (!(x & 1) && (move_x & 1)))
		return false;
	if (((y & 1) && !(move_y & 1)) || (!(y & 1) && (move_y & 1)))
		return false;

	if ((abs(x) > move_x) || (abs(y) > move_y))
		return false;

	return true;
}

void getMoves(string s, int &move_x, int &move_y) {
	bool on_X_axis = true;

	for (int i = 0; i < sz(s); ++i) {
		if (s[i] == '0')
			on_X_axis = !on_X_axis;

		move_x += on_X_axis;
		move_y += !(on_X_axis);
	}
}

void solve() {
	int n, x, y;
	cin >> n >> x >> y;

	string s;
	cin >> s;

	int move_x = 0, move_y = 0;

	getMoves(s, move_x, move_y);

	cout << ((isReachable(x, y, move_x, move_y)) ||
	         (isReachable(x, y, move_y, move_x)) ? "YES" : "NO");
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
