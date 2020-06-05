/*
 ~ Author        : @tridib_2003
 ~ Problem Code  : STRNO
 ~ Link          : https://www.codechef.com/problems/STRNO
*/

#include<bits/stdc++.h>
using namespace std;

#define ll                  long long int
#define PI                  3.141592653589793
#define MOD                 1000000007
#define vi                  vector<int>
#define mk(arr, n, type)    type *arr = new type[n];
#define FOR(a, c)           for (int(a) = 0; (a) < (c); (a)++)
#define w(x)                int x; cin >> x; while(x--)
#define FIO                 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

ll getPrimeFactors(ll n) {

	ll cnt = 0;

	while (n % 2 == 0) {
		n /= 2;
		++cnt;
	}

	for (int i = 3; i < sqrt(n); i += 2) {

		while (n % i == 0) {
			n /= i;
			++cnt;
		}
	}

	if (n > 2)
		++cnt;

	return cnt;

}

int main() {

	FIO;
	w(tc) {

		ll x, k;
		cin >> x >> k;

		ll cnt = getPrimeFactors(x);

		if (cnt >= k)
			cout << 1 << '\n';
		else
			cout << 0 << '\n';

	}

	return 0;
}