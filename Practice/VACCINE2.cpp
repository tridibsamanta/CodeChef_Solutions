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

		ll n, d;
		cin >> n >> d;

		vi ages(n);

		int riskCount = 0, days = 0;

		FOR(i, n) {
			cin >> ages[i];

			if (ages[i] <= 9 || ages[i] >= 80)
				++riskCount;
		}

		if (d == 1) {
			days = n;
		}
		else {

			if (riskCount == 0) {
				days = n / d;
				n = n % d;
				if (n != 0)
					++days;
			}
			else {

				days += riskCount / d;

				if (riskCount % d != 0)
					++days;

				n = n - riskCount;

				days += n / d;
				n = n % d;
				if (n != 0)
					++days;
			}

		}

		cout << days << '\n';
	}

	return 0;
}
