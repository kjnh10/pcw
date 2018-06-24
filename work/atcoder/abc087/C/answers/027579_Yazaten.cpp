#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define all(a) (a).begin(),(a).end()
#define pb emplace_back
#define INF (1e9+1)

int main(){
    int h=2,w;
    cin>>w;
    
    vector<vector<int>> v(h,vector<int>(w));
    rep(i,h){
        rep(j,w)cin>>v[i][j];
    }
    
    int sum = 0;
    int maxi = 0;
    
    rep(i,v[0].size()){
        sum+=v[0][i];
    }
    
    sum+=v[1][w-1];
    
    maxi = sum;
    for(int i=w-1;i>=1;i--){
        sum-=v[0][i];
        sum+=v[1][i-1];
        maxi = max(maxi,sum);
    }
    cout<<maxi<<endl;
}
