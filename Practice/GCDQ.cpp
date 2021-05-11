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

const int MAXN = 1e5 + 5;

int arr[MAXN];
int pref_gcd[MAXN];
int suff_gcd[MAXN];

void compute(int n) {

// 	memset(pref_gcd, 0, sizeof(pref_gcd));
// 	memset(suff_gcd, 0, sizeof(suff_gcd));

	pref_gcd[1] = arr[1];
	suff_gcd[n] = arr[n];

	FOR (i, 2, n + 1) {
		pref_gcd[i] = __gcd(pref_gcd[i - 1], arr[i]);
	}

	RFOR (i, n, 1) {
		suff_gcd[i] = __gcd(suff_gcd[i + 1], arr[i]);
	}
}

void solve() {

	int n, q;
	cin >> n >> q;

// 	memset(arr, 0, sizeof(arr));

	FOR (i, 1, n + 1) {
		cin >> arr[i];
	}

	compute(n);

	while (q--) {

		int l, r;
		cin >> l >> r;

		if (l == 1)
			cout << suff_gcd[r + 1] << '\n';
		else if (r == n)
			cout << pref_gcd[l - 1] << '\n';
		else
			cout << __gcd(pref_gcd[l - 1], suff_gcd[r + 1]) << '\n';
	}
}

int32_t main() {

	FIO;

	int t = 1;
	cin >> t;
	while (t--) {
		solve();
// 		cout << '\n';
	}

	return 0;
}
