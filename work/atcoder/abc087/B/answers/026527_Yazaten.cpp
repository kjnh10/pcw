#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define all(a) (a).begin(),(a).end()
#define pb emplace_back
#define INF (1e9+1)

int main(){
    int a,b,c;
    cin>>a>>b>>c;
    int x;
    cin>>x;
    int sum = 0;
    rep(i,a+1){
        rep(j,b+1){
            rep(k,c+1){
                if(i*500+j*100+k*50==x)sum++;
            }
        }
    }
    cout<<sum<<endl;
}
