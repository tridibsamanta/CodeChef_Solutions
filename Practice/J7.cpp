/*
~ Author        : @tridib_2003
~ Problem Code  : J7
~ Link          : https://www.codechef.com/problems/J7
*/

#include<bits/stdc++.h>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--) {

		int P, S;
		cin >> P >> S;

		// Perimeter of a cuboid = 4(l + b + h)
		double a = P / 4;
		double b = sqrt(a * a - 3 * (S / 2));
		double volume = abs(((a - b) * (a - b) * (a + 2 * b)) / 27);
		cout << fixed << setprecision(2) << volume << "\n";

	}

	return 0;
}