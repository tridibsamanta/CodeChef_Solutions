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

		int n, k;
		cin >> n >> k;

		if (n == k) {
			FOR(i, n) {
				cout << i + 1 << ' ';
			}
		}
		else if (k == n / 2) {
			FOR(i, n) {
				if (i & 1)
					cout << i + 1 << ' ';
				else
					cout << -(i + 1) << ' ';
			}
		}
		else {

			int neg = n - k, i = 1;

			while (neg > 0 && k > 0) {
				if (i & 1) {
					cout << -i << ' ';
					--neg;
				}
				else {
					cout << i << ' ';
					--k;
				}
				++i;
			}

			while (neg--) {
				cout << -i << ' ';
				++i;
			}

			while (k--) {
				cout << i << ' ';
				++i;
			}
		}

		cout << '\n';
	}

	return 0;
}
