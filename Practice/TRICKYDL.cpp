/*
 ~ Author        : @tridib_2003
 ~ Problem Code  : TRICKYDL
 ~ Link          : https://www.codechef.com/problems/TRICKYDL
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int tc;
	cin >> tc;
	while (tc--) {
		ll int a; cin >> a;
		int count = 1;
		ll int chef = 1, friendMoney = a, profit = friendMoney - chef;
		ll int maxProfit = profit, maxProfitDay = count;
		while (profit > 0) {
			chef += pow(2, count);
			friendMoney += a;
			profit = friendMoney - chef;
			if (profit > 0)
				++count;
			if (profit > maxProfit) {
				maxProfit = profit;
				maxProfitDay = count;
			}
		}
		cout << count << ' ' << maxProfitDay << '\n';
	}
	return 0;
}