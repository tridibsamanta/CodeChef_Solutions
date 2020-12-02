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

		string str;
		cin >> str;

		int n = str.length();

		int end, start;

		if (n & 1) {
			end = n / 2 - 1;
			start = n / 2 + 1;
		}
		else {
			end = n / 2 - 1;
			start = n / 2;
		}

		int freq[26];
		memset(freq, 0, sizeof(freq));

		for (int i = 0; i <= end; ++i)
			++freq[str[i] - 'a'];

		for (int i = start; i < n; ++i)
			--freq[str[i] - 'a'];

		bool check = true;

		for (int i = 0; i < 26; ++i) {
			if (freq[i] != 0) {
				check = false;
				break;
			}
		}

		if (check)
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}

	return 0;
}
