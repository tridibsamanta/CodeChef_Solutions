/*
 ~ Author        : @tridib_2003
 ~ Problem Code  : PAIRING
 ~ Link          : https://www.codechef.com/problems/PAIRING
*/

#include<bits/stdc++.h>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int tc;
	cin >> tc;
	while (tc--) {

		int n, m;
		cin >> n >> m;

		int selected[n] = {0};
		int pairs[m][2];

		int u, v;
		for (int i = 0; i < m; ++i)
			cin >> pairs[i][1] >> pairs[i][2];

		vector<int> opt;

		for (int i = m - 1; i >= 0; --i) {
			if (selected[pairs[i][1]] != 1 && selected[pairs[i][2]] != 1) {
				++selected[pairs[i][1]];
				++selected[pairs[i][2]];
				opt.push_back(i);
			}
		}

		sort(opt.begin(), opt.end());

		for (auto i = opt.begin(); i != opt.end(); ++i)
			cout << *i << ' ';

		cout << '\n';

	}

	return 0;
}