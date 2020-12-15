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

		ll a, b;
		cin >> a >> b;

		ll odd_a = 0, even_a = 0, odd_b = 0, even_b = 0;

		if (a & 1) {
			odd_a = (a / 2) + 1;
			even_a = a / 2;
		}
		else {
			odd_a = a / 2;
			even_a = a / 2;
		}

		if (b & 1) {
			odd_b = (b / 2) + 1;
			even_b = b / 2;
		}
		else {
			odd_b = b / 2;
			even_b = b / 2;
		}

		cout << (odd_a * odd_b) + (even_a * even_b) << '\n';

	}

	return 0;
}
