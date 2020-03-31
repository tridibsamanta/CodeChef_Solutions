/**
 * Title   : XOR Engine
 * Author  : @tridib_2003
 * Created : 16-03-2020
 * Link    : https://www.codechef.com/MARCH20B/problems/ENGXOR
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
#include <bits/stdc++.h>
using namespace std;


int num_to_bits[16] = { 0, 1, 1, 2, 1, 2, 2, 3,
                        1, 2, 2, 3, 2, 3, 3, 4 };

int countSetBitsRec(int num)
{
    int nibble = 0;
    if (0 == num)
        return 0;
    nibble = num & 0xf;
    return num_to_bits[nibble] + countSetBitsRec(num >> 4);
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--) {
        int N,Q,A,P,even_count_A = 0, odd_count_A = 0;
        scanf("%d%d",&N,&Q);
        for(int i=N;i--;) {
            scanf("%d",&A);
            (!(countSetBitsRec(A)& 1) ? ++even_count_A : ++odd_count_A);
        }
        for(int i=Q;i--;) {
            scanf("%d",&P);
            (!(countSetBitsRec(P)& 1) ? (printf("%d %d\n",even_count_A,odd_count_A)) : (printf("%d %d\n",odd_count_A,even_count_A)));
        }
    }
    return 0;
}
