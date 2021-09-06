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

	vi a(n);

	FOR (i, 0, n) {
		cin >> a[i];
	}

	vi b(n);

	FOR (i, 0, n) {
		cin >> b[i];
	}

	// face[i] = 0 -> undecided
	// face[i] = 1 -> front face
	// face[i] = 2 -> back face
	vi face(n, 0);

	// check if current bit can be set from MSB to LSB (2^29 to 2^0)
	for (int pow2 = 1 << 29; pow2 > 0; pow2 >>= 1) {

		//int pow2 = 1 << p; // 2^p
		bool isBitSet = true;

		FOR (i, 0, n) {

			// front face
			if (face[i] == 1 && !(a[i] & pow2))
				isBitSet = false;
			// back face
			else if (face[i] == 2 && !(b[i] & pow2))
				isBitSet = false;
			// undecided
			else if (!(a[i] & pow2) && !(b[i] & pow2))
				isBitSet = false;
		}

		if (!isBitSet)
			continue;

		// current bit is set in the answer make sure that
		// current card face arrangement is preserved
		FOR (i, 0, n) {
			// face is already fixed
			if (face[i] != 0)
				continue;

			// set a face such that current bit is set
			if (!(a[i] & pow2))
				face[i] = 2; // back face
			else if (!(b[i] & pow2))
				face[i] = 1; // front face
		}
	}

	// finding the max AND value and min flips
	int ans = (1 << 30) - 1, flips = 0;

	FOR (i, 0, n) {
		// back face
		if (face[i] == 2) {
			ans &= b[i];
			++flips;
		}
		// front face
		else
			ans &= a[i];
	}

	cout << ans << ' ' << flips;
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
