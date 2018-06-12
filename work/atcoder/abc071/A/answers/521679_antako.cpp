#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int INF = 1e9;
int MOD = 1e9+7;
main(){
    int X,A,B;
    cin >> X >> A >> B;
    if(abs(X-A) > abs(X-B)){
        cout << "B" << endl;
    }else{
        cout << "A" << endl;
    }
}