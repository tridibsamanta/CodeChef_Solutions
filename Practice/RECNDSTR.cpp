/*
~ Author        : @tridib_2003
~ Problem Code  : RECNDSTR
~ Link          : https://www.codechef.com/problems/RECNDSTR
*/

#include<bits/stdc++.h>
using namespace std;

void leftrotate(string &s, int d)
{
    reverse(s.begin(), s.begin()+d);
    reverse(s.begin()+d, s.end());
    reverse(s.begin(), s.end());
}

void rightrotate(string &s, int d)
{
   leftrotate(s, s.length()-d);
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--) {

        string s;
        cin >> s;

        string lrs = s, rrs = s;

        leftrotate(lrs, 1);
        rightrotate(rrs, 1);

        if (!lrs.compare(rrs))
            cout << "YES\n";
        else
            cout << "NO\n";

    }
    return 0;
}
