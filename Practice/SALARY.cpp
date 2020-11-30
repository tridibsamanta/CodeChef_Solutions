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

		int n;
		cin >> n;

		vi wages(n);
		int min_wage = INT_MAX;

		FOR (i, n) {
			cin >> wages[i];
			min_wage = min(min_wage, wages[i]);
		}

		int op_count = 0;

		FOR (i, n) {
			op_count += wages[i] - min_wage;
		}

		cout << op_count << '\n';

	}

	return 0;
}
