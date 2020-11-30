/*
 ~ Author        : @tridib_2003
*/

#include<bits/stdc++.h>
using namespace std;

#define ll                  long long
#define PI                  3.1415926535897932384626
#define MOD                 1000000007
#define vi                  vector<int>
#define mk(arr, n, type)    type *arr = new type[n];
#define FOR(a, c)           for (int(a) = 0; (a) < (c); (a)++)
#define w(x)                int x; cin >> x; while(x--)
#define FIO                 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int main() {

	FIO;

	w (tc) {

		bool safe[101];
		memset(safe, true, sizeof(safe));

		int m, x, y;
		cin >> m >> x >> y;

		FOR (i, m) {
			int curr;
			cin >> curr;

			//safe[curr] = false;

			int low = max(curr - (x * y), 1);
			int high = min(curr + (x * y), 100);

			for (; low <= high; ++low)
				safe[low] = false;
		}

		int count = 0;

		for (int i = 1; i < 101; ++i) {
			if (safe[i])
				++count;
		}

		cout << count << '\n';
	}

	return 0;
}
