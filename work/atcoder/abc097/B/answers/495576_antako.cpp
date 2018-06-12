#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int INF = 1LL << 30;
int MOD = 1e9+7;
main(){
    int X;
    cin >> X;
    ll maxi = 1;
    for(int i = 2;i*i <= X;i++){
        ll j = i;
        while(j <= X){
            j *= i;
        }
        maxi = max(maxi, j/i);
    }
    cout << maxi << endl;
}