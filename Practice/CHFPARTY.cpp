/*
~ Author        : @tridib_2003
~ Problem Code  : CHFPARTY
~ Link          : https://www.codechef.com/problems/CHFPARTY
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

		sort(A.begin(), A.end());

		if (A[0] != 0)
			cout << "0\n";
		else {
			int count = 0;
			for (int i = 0; i < N; ++i) {
				if (A[i] >= i + 1)
					break;
				else
					++count;
			}
			cout << count << "\n";
		}

	}

	return 0;
}