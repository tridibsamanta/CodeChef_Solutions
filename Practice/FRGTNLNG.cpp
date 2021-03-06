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

		vector<string> forgotten(n);

		FOR (i, n) {
			cin >> forgotten[i];
		}

		set<string> modern;

		while (k--) {
			int l;
			cin >> l;
			FOR (j, l) {
				string word;
				cin >> word;
				modern.insert(word);
			}
		}

		FOR (i, n) {
			auto it = modern.find(forgotten[i]);
			if (it != modern.end())
				cout << "YES" << ' ';
			else
				cout << "NO" << ' ';
		}

		cout << '\n';
	}

	return 0;
}
