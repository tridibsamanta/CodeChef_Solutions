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

		string str;
		cin >> str;

		ll oneCount = 0;

		for (int i = 0; i < n; ++i)
			if (str[i] == '1')
				++oneCount;

		cout << (oneCount * (oneCount + 1) / 2) << '\n';
	}

	return 0;
}
