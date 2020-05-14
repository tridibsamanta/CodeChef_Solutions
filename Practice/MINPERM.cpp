/*
~ Author        : @tridib_2003
~ Problem Code  : MINPERM
~ Link          : https://www.codechef.com/problems/MINPERM
*/

#include<bits/stdc++.h>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--) {

		long long int n;
		cin >> n;

		long long int arr[n];
		for (long long int i = 0; i < n; ++i)
			arr[i] = i + 1;
		for (long long int i = 0; i < n - 1; i += 2)
			swap(arr[i], arr[i + 1]);
		if (n & 1)
			swap(arr[n - 1], arr[n - 2]);
		for (long long int i = 0; i < n; ++i)
			cout << arr[i] << ' ';
		cout << '\n';

	}

	return 0;
}