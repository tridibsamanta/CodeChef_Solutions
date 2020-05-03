/*
~ Author        : @tridib_2003
~ Problem Code  : TOTR
~ Link          : https://www.codechef.com/problems/TOTR
*/

#include<bits/stdc++.h>
using namespace std;

char M[27];
char S[101];

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;
	cin >> M;

	while (T--) {
		cin >> S;
		for (int i = 0; S[i]; ++i) {
			if (islower(S[i]))
				S[i] = M[S[i] - 'a'];
			else if (isupper(S[i]))
				S[i] = toupper(M[S[i] - 'A']);
			else if (S[i] == '_')
				S[i] = ' ';
		}
		cout << S << '\n';
	}

	return 0;
}