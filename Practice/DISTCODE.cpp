/*
 ~ Author        : @tridib_2003
 ~ Problem Code  : DISTCODE
 ~ Link          : https://www.codechef.com/problems/DISTCODE
*/

#include<bits/stdc++.h>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int tc;
	cin >> tc;
	while (tc--) {

		string s;
		cin >> s;

		set<pair<char, char> > distinct;

		for (int i = 0; i < s.length() - 1; ++i) {
			distinct.insert(make_pair(s[i], s[i + 1]));
		}

		cout << distinct.size() << '\n';

	}

	return 0;
}