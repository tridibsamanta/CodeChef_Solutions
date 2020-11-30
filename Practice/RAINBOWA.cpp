/*
 ~ Author        : @tridib_2003
*/

#include<bits/stdc++.h>
using namespace std;

#define ll                  long long
#define PI                  3.1415926535897932384626
#define MOD                 1000000007
#define vi                  vector<int>
#define mk(arr, n, type)    type *arr = new type[n];
#define FOR(a, c)           for (int(a) = 0; (a) < (c); (a)++)
#define w(x)                int x; cin >> x; while(x--)
#define FIO                 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int main() {

	FIO;

	w (tc) {

		int n;
		cin >> n;

		vi nums(n);
		FOR (i, n) {
			cin >> nums[i];
		}

		int l = 0, r = n - 1;
		bool check = true;

		if (nums[0] != 1)
			check = false;
		else {

			while (l < r) {

				if (nums[l] != nums[r]) {
					check = false;
					break;
				}

				if (nums[l] != nums[l + 1] && nums[l] + 1 != nums[l + 1]) {
					check = false;
					break;
				}

				++l;
				--r;
			}

			if (nums[l] != 7)
				check = false;
		}

		if (check)
			cout << "yes" << '\n';
		else
			cout << "no" << '\n';

	}

	return 0;
}
