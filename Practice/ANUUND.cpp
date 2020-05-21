/*
 ~ Author        : @tridib_2003
 ~ Problem Code  : ANUUND
 ~ Link          : https://www.codechef.com/problems/ANUUND
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

		int arr[n];
		for (int i = 0; i < n; ++i)
			cin >> arr[i];

		for (int i = 0; i < n - 1; ++i) {
			if (i & 1) {
				if (arr[i] < arr[i + 1])
					swap(arr[i], arr[i + 1]);
				cout << arr[i] << ' ';
			}
			else {
				if (arr[i] > arr[i + 1])
					swap(arr[i], arr[i + 1]);
				cout << arr[i] << ' ';
			}
		}
		cout << arr[n - 1] << '\n';

	}

	return 0;
}