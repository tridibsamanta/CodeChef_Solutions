/*
~ Author        : @tridib_2003
~ Problem Code  : NUM239
~ Link          : https://www.codechef.com/problems/NUM239
*/

#include<bits/stdc++.h>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--) {

		int L, R;
		cin >> L >> R;

		int count = 0;

		for (int i = L; i <= R; ++i) {
			if (i % 10 == 2 || i % 10 == 3 || i % 10 == 9)
				++count;
		}

		cout << count << '\n';

	}

	return 0;
}