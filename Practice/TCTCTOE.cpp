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


void getWinCount(vector<string>& grid, int& x_wins, int& o_wins) {

	if (grid[0][0] == 'X' && grid[0][1] == 'X' && grid[0][2] == 'X')
		++x_wins;
	if (grid[0][0] == 'X' && grid[1][1] == 'X' && grid[2][2] == 'X')
		++x_wins;
	if (grid[0][0] == 'X' && grid[1][0] == 'X' && grid[2][0] == 'X')
		++x_wins;
	if (grid[0][1] == 'X' && grid[1][1] == 'X' && grid[2][1] == 'X')
		++x_wins;
	if (grid[0][2] == 'X' && grid[1][1] == 'X' && grid[2][0] == 'X')
		++x_wins;
	if (grid[0][2] == 'X' && grid[1][2] == 'X' && grid[2][2] == 'X')
		++x_wins;
	if (grid[1][0] == 'X' && grid[1][1] == 'X' && grid[1][2] == 'X')
		++x_wins;
	if (grid[2][0] == 'X' && grid[2][1] == 'X' && grid[2][2] == 'X')
		++x_wins;

	if (grid[0][0] == 'O' && grid[0][1] == 'O' && grid[0][2] == 'O')
		++o_wins;
	if (grid[0][0] == 'O' && grid[1][1] == 'O' && grid[2][2] == 'O')
		++o_wins;
	if (grid[0][0] == 'O' && grid[1][0] == 'O' && grid[2][0] == 'O')
		++o_wins;
	if (grid[0][1] == 'O' && grid[1][1] == 'O' && grid[2][1] == 'O')
		++o_wins;
	if (grid[0][2] == 'O' && grid[1][1] == 'O' && grid[2][0] == 'O')
		++o_wins;
	if (grid[0][2] == 'O' && grid[1][2] == 'O' && grid[2][2] == 'O')
		++o_wins;
	if (grid[1][0] == 'O' && grid[1][1] == 'O' && grid[1][2] == 'O')
		++o_wins;
	if (grid[2][0] == 'O' && grid[2][1] == 'O' && grid[2][2] == 'O')
		++o_wins;
}

void solve() {

	vector<string> grid;

	FOR (i, 0, 3) {
		string s;
		cin >> s;

		grid.eb(s);
	}

	int x_cnt = 0, o_cnt = 0, empty_cnt = 0;

	FOR (i, 0, 3) {
		FOR (j, 0, 3) {
			if (grid[i][j] == 'X')
				++x_cnt;
			else if (grid[i][j] == 'O')
				++o_cnt;
			else
				++empty_cnt;
		}
	}

	// game has not yet started
	if (x_cnt == 0 && o_cnt == 0 && empty_cnt == 9) {
		cout << 2;
		return;
	}

	// players dont play sequentially
	if ((x_cnt - o_cnt < 0) || (x_cnt - o_cnt > 1)) {
		cout << 3;
		return;
	}

	int x_wins = 0, o_wins = 0;
	getWinCount(grid, x_wins, o_wins);

	if (x_wins == 2 && o_wins == 0 && empty_cnt == 0) {
		/* this block handles the case below
		X | O | O
		X | O | O
		X | X | X
		*/
		cout << 1;
	}
	else if (x_wins == 1 && o_wins == 1) // X & O cannot win together
		cout << 3;
	else if (x_wins == 1 && o_wins == 0 && x_cnt == o_cnt + 1) // X wins
		cout << 1;
	else if (x_wins == 0 && o_wins == 1 && x_cnt == o_cnt) // O wins
		cout << 1;
	else if (x_wins == 0 && o_wins == 0 && empty_cnt == 0) // game drawn
		cout << 1;
	else if (x_wins == 0 && o_wins == 0 && empty_cnt > 0) // moves left
		cout << 2;
	else // unreachable state
		cout << 3;
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
