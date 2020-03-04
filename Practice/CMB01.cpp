/*
~ Author        : @tridib_2003
~ Problem Code  : CMB01
~ Link          : https://www.codechef.com/problems/CMB01
*/

#include<bits/stdc++.h>
using namespace std;

int rev(int n) {
    int rev_n=0;
    while(n>0)
    {
        rev_n = rev_n*10 + n%10;
        n/=10;
    }
    return rev_n;
}

int main() {
    int tc,num1,num2;
    cin>>tc;
    while(tc--) {
        cin>>num1>>num2;
        cout<<rev(rev(num1)+rev(num2))<<endl;
    }
	return 0;
}
