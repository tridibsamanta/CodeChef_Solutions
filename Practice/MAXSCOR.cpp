/*
 ~ Author        : @tridib_2003
*/

#include<bits/stdc++.h>
using namespace std;

#define int                 long long
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


int dp[1001][10001][2]; // dp[chapters][time][first chapter's contribution]

/*
    First chapter's contribution range is [0,1]
    If value is 0 -> Max. marks which can be obtained including all the chapters
    If value is 1 -> Max. marks which can be obtained omitting the marks gained from the first chapter
*/

void solve() {

	int n, k;
	cin >> n >> k;

	vi m(n), t(n);
	FOR (i, 0, n) {
		cin >> m[i] >> t[i];
	}

	FOR (i, 0, n + 1) {
		FOR (j, 0, k + 1) {
			dp[i][j][0] = 0;
			dp[i][j][1] = INT_MIN;
		}
	}

	FOR (i, 1, n + 1) {
		FOR (j, 1, k + 1) {

			if (t[i - 1] <= j) {
				/*
				    dp[i][j][0] = max(Select current chapter considering all chapter's marks, Omit current chapter considering all chapter's marks);
				*/
				dp[i][j][0] = max(m[i - 1] + dp[i - 1][j - t[i - 1]][0], dp[i - 1][j][0]);

				/*
				    dp[i][j][1] = max(Select current chapter AS NOT the first chapter hence previous value where first chapter's marks is omitted needs to be taken,
				                        max(Select current chapter AS the first chapter hence previous value where all the chapter's marks is considered is taken, Omit current chapter hence previous value where first chapter's marks is omitted needs to be taken));
				*/
				dp[i][j][1] = max(m[i - 1] + dp[i - 1][j - t[i - 1]][1], max(dp[i - 1][j - t[i - 1]][0], dp[i - 1][j][1]));
			}
			/* Current chapter cannot be studied due to shortage of time */
			else {
				dp[i][j][0] = dp[i - 1][j][0];
				dp[i][j][1] = dp[i - 1][j][1];
			}
		}
	}

	cout << max(dp[n][k][1], (int)0);
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
