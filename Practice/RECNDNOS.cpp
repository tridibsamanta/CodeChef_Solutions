/*
~ Author        : @tridib_2003
~ Problem Code  : RECNDNOS
~ Link          : https://www.codechef.com/problems/RECNDNOS
*/

#include<bits/stdc++.h>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--) {

		int n;
		cin >> n;

		map<int, int> freq;

		int A;
		cin >> A;

		freq[A]++;
		int dish = A, dist = 1;

		for (int i = 1; i < n; ++i) {
			cin >> A;
			if (A != dish || dist % 2 == 0) {
				freq[A]++;
				dist = 1;
			}
			else
				++dist;
			dish = A;
		}

		dish = 0;
		int max_freq = 0;

		map<int, int>::iterator itr;
		for (itr = freq.begin(); itr != freq.end(); itr++) {
			if (itr->second > max_freq) {
				max_freq = itr->second;
				dish = itr->first;
			}
		}

		cout << dish << '\n';
	}

	return 0;
}
