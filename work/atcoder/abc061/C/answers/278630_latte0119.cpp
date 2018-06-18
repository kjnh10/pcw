#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

signed main(){
    int N,K;
    cin>>N>>K;
    vpint vec;
    rep(i,N){
        int a,b;
        cin>>a>>b;
        vec.pb({a,b});
    }
    sort(all(vec));

    rep(i,vec.size()){
        if(vec[i].se<K){
            K-=vec[i].se;
            continue;
        }
        cout<<vec[i].fi<<endl;
        return 0;
    }
    return 0;
}
