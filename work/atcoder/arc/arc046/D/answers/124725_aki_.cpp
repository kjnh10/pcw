#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n,a,b;cin>>n>>a>>b;
    if(n<=a){
        cout<<"Takahashi"<<endl;
    }
    else{
        if(a==b){
            if(n%(a+1)) cout<<"Takahashi"<<endl;
            else cout<<"Aoki"<<endl;
            return 0;
        }
        else if(a>b) cout<<"Takahashi"<<endl;
        else cout<<"Aoki"<<endl;
    }
    return 0;
}