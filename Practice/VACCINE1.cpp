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

	int d1, v1, d2, v2, p;
	cin >> d1 >> v1 >> d2 >> v2 >> p;

	int days = 0; bool start = false;

	if (d1 < d2) {

		int extra = d2 - d1;

		if (extra * v1 >= p) {

			days += p / v1;
			days += d1 - 1;

			cout << days;
			return 0;
		}
		else {
			days += extra;
			p -= extra * v1;
		}
	}
	else if (d2 < d1) {

		start = true;

		int extra = d1 - d2;

		if (extra * v2 >= p) {

			days += p / v2;
			days += d2 - 1;

			cout << days;
			return 0;
		}
		else {
			days += extra;
			p -= extra * v2;
		}
	}

	if (p < v1 + v2) {
		days++;

		if (start)
			days += d2 - 1;
		else
			days += d1 - 1;
	}
	else {
		days += p / (v1 + v2);
		p -= (p / (v1 + v2)) * (v1 + v2);

		if (p != 0)
			++days;

		if (start)
			days += d2 - 1;
		else
			days += d1 - 1;
	}

	cout << days;

	return 0;
}
