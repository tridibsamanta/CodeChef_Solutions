/*
~ Author        : @tridib_2003
~ Problem Code  : NDIFFPAL
~ Link          : https://www.codechef.com/problems/NDIFFPAL
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

		string pal_str = "";

		string alphabets = "abcdefghijklmnopqrstuvwxyz";

		int times = N / 26;
		int rem = N % 26;

		while (times) {
			pal_str += alphabets;
			--times;
		}

		char start = 'a';
		while (rem) {
			pal_str += start;
			++start;
			--rem;
		}

		cout << pal_str << "\n";

	}

	return 0;
}