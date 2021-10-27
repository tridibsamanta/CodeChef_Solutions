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

#define int                 long long
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


long long mod_mul(long long a, long long b) {a = a % MOD; b = b % MOD; return (((a * b) % MOD) + MOD) % MOD;}
long long mod_add(long long a, long long b) {a = a % MOD; b = b % MOD; return (((a + b) % MOD) + MOD) % MOD;}

int n;
vi arr;

vector<int> getNextGreaterElementIndex() {
	vector<int> nge(n + 1, n + 1);
	stack<pii> s;

	for (int i = n; i > 0; --i) {

		while (!s.empty() && arr[i] > s.top().first) {
			s.pop();
		}

		if (!s.empty())
			nge[i] = s.top().second;

		s.push({arr[i], i});
	}

	return nge;
}

void solve() {

	cin >> n;

	arr.clear();
	arr.resize(n + 1, 0);

	FOR (i, 1, n + 1) {
		cin >> arr[i];
	}

	vi nge = getNextGreaterElementIndex();

	// printall(nge); cout << '\n';

	vi dp(n + 2, 0);
	// dp[i] = f(i, i) + f(i, i + 1) + f(i, i + 2) + ... + f(i, n)

	RFOR (i, n + 1, 1) {
		int nge_idx = nge[i];
		int lesser = nge_idx - i;

		int s1 = mod_mul(arr[i], (lesser * (lesser + 1)) / 2);
		int s2 = mod_mul(mod_mul(lesser, arr[i]), n - nge_idx + 1);
		int s3 = mod_add(dp[i], dp[nge_idx]);

		dp[i] = mod_add(s1, s2);
		dp[i] = mod_add(dp[i], s3);
	}

	int ans = 0;

	FOR (i, 1, n + 1) {
		ans = mod_add(ans, dp[i]);;
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
