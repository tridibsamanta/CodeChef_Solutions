/**
 * Title   : Ada Bishop 2
 * Author  : @tridib_2003
 * Created : 31-03-2020
 * Link    : https://www.codechef.com/problems/ADASHOP2/
 **/

 #include<bits/stdc++.h>
 using namespace std;

 void solution() {
    int r, c;
    cin >> r >> c;

    vector<array<int , 2>> moves;
    //Move bishop to the diagonal y=x
    moves.push_back({(r+c)/2, (r+c)/2});
    //Covering the cell (1,1)
    moves.push_back({1, 1});
    //Covering the next 3 diagonals
    for(int i = 4; i <= 8; i += 2) {
        moves.push_back({i/2, i/2});
        moves.push_back({1, i-1});
        moves.push_back({i-1, 1});
        moves.push_back({i/2, i/2});
    }
    //Covering the last 4 diagonals
    for(int i = 10; i <= 16; i += 2) {
        moves.push_back({i/2, i/2});
        moves.push_back({i-8, 8});
        moves.push_back({8, i-8});
        moves.push_back({i/2, i/2});
    }
    https://www.codechef.com/problems/ADASHOP2/
    cout<< moves.size() << "\n";
    for(array<int, 2> a : moves)
        cout<< a[0] << " " << a[1] << "\n";
 }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>> t;
    while(t--)
        solution();
}
