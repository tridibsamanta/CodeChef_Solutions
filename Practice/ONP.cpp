/*
~ Author        : @tridib_2003
~ Problem Code  : ONP
~ Link          : https://www.codechef.com/problems/ONP
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int top = 0,l;
        l = s.length();
        char stack[l];
        for(int i = 0; i < l; i++){
            if(s[i] == '('){
                top++;
            }
            else if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '%' || s[i] == '^'){
                   stack[top] = s[i];
            }
            else if(s[i] == ')'){
                cout << stack[top];
                 top--;
            }
            else {
                cout << s[i];
            }
        }
        cout << endl;
    }
    return 0;
}
