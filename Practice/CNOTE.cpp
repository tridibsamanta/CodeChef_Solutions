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

		int x, y, k, n;
		cin >> x >> y >> k >> n;

		int extra = x - y;
		bool canBuy = false;

		int i = 0;
		for (; i < n; ++i) {
			int pages, cost;
			cin >> pages >> cost;

			if (cost <= k && pages >= extra)
				canBuy = true;
		}

		if (canBuy)
			cout << "LuckyChef" << '\n';
		else
			cout << "UnluckyChef" << '\n';

	}

	return 0;
}
