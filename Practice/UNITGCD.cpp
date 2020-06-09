/*
 ~ Author        : @tridib_2003
 ~ Problem Code  : UNITGCD
 ~ Link          : https://www.codechef.com/problems/UNITGCD
*/

#include<bits/stdc++.h>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int tc;
	cin >> tc;
	while (tc--) {

		int n;
		cin >> n;

		if (n == 1) {
			cout << 1 << '\n';
			cout << 1 << ' ' << 1 << '\n';
		}
		else {
			int days = n / 2;
			cout << days << '\n';

			if (n & 1) {
				cout << 3 << ' ' << 1 << ' ' << 2 << ' ' << 3 << '\n';
				int page = 4;
				for (int i = 2; i <= days; ++i) {
					cout << 2 << ' ' << page << ' ';
					++page;
					cout << page << '\n';
					++page;
				}
			}
			else {
				int page = 1;
				for (int i = 1; i <= days; ++i) {
					cout << 2 << ' ' << page << ' ';
					++page;
					cout << page << '\n';
					++page;
				}
			}
		}

	}

	return 0;
}