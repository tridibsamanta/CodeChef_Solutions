/*
~ Author        : @tridib_2003
~ Problem Code  : CMB02
~ Link          : https://www.codechef.com/problems/CMB02
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int tc;
    cin>>tc;
    while(tc--) {
        long int n;
        cin>>n;
        while(1) {
            n++;
            long int temp=n,rev=0;
            while(temp!=0) {
                rev*=10;
                rev+=temp%10;
                temp/=10;
            }
            if(rev==n) {
                cout<<n<<endl;
                break;
            }
        }
    }
	return 0;
}
