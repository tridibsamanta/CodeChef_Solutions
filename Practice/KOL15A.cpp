/*
~ Author        : @tridib_2003
~ Problem Code  : KOL15A
~ Link          : https://www.codechef.com/problems/KOL15A
*/

#include<bits/stdc++.h>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--) {

		string s;
		cin >> s;

		int total = 0;

		for (int i = 0; s[i]; ++i) {
			if (s[i] >= '0' && s[i] <= '9')
				total += s[i] - '0';
		}

		cout << total << '\n';
	}

	return 0;
}