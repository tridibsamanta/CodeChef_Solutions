/*
~ Author        : @tridib_2003
~ Problem Code  : LEPERMUT
~ Link          : https://www.codechef.com/problems/LEPERMUT
*/

#include<bits/stdc++.h>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--) {

		int N;
		cin >> N;

		vector<int> A(N);
		for (int i = 0; i < N; ++i)
			cin >> A[i];

		int inv = 0, loc_inv = 0;

		for (int i = 0; i < N - 1; ++i) {
			if (A[i] > A[i + 1])
				++loc_inv;
			for (int j = i + 1; j < N; ++j) {
				if (A[i] > A[j])
					++inv;
			}
		}

		cout << (inv == loc_inv ? "YES" : "NO") << "\n";

	}

	return 0;
}