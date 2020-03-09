/**
 * Title   : Pintu and Fruits
 * Author  : @tridib_2003
 * Created : 08-03-2020
 * Link    : https://www.codechef.com/MARCH20B/problems/CHPINTU
 **/

#include <cstdio>
#include <cstring>
#include <string>
#include <sstream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <map>
#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
using namespace std;

int main()
{
    int T;
    scanf("%d",&T);
    while(T--) {
        int N,M;
        scanf("%d%d",&N,&M);
        int F[N];
        for(int i=0;i<N;i++)
            scanf("%d",&F[i]);
        map<int,int> mp;
        for(int i=0;i<N;i++) {
            int P;
            scanf("%d",&P);
            mp[F[i]]=mp[F[i]]+P;
        }
        int min_price = mp.begin()->second;
        map<int,int>::iterator itr;
        for(itr=mp.begin();itr!=mp.end();itr++) {
            if((itr->second) < min_price)
                min_price = itr->second;
        }
        printf("%d\n",min_price);
    }
    return 0;
}

