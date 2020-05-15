/*
 ~ Author        : @tridib_2003
 ~ Problem Code  : PROB
 ~ Link          : https://www.codechef.com/problems/PROB
*/

#include<bits/stdc++.h>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--) {

		double T1, T2, T3, T4;
		cin >> T1 >> T2 >> T3 >> T4;

		cout << T1 / (T1 + T2) << '\n';

	}

	return 0;
}