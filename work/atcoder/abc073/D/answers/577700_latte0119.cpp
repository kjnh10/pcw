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

int N,M,R;
int r[114514];

const int INF=1001001001001001001ll;
int dist[222][222];

signed main(){
    cin>>N>>M>>R;
    rep(i,R)cin>>r[i],r[i]--;

    fill_n(*dist,222*222,INF);
    rep(i,N)dist[i][i]=0;
    rep(i,M){
        int a,b,c;
        cin>>a>>b>>c;
        a--;b--;
        chmin(dist[a][b],c);
        chmin(dist[b][a],c);
    }
    rep(k,N)rep(i,N)rep(j,N)chmin(dist[i][j],dist[i][k]+dist[k][j]);

    sort(r,r+R);
    int ans=INF;
    do{
        int tmp=0;
        rep(i,R-1)tmp+=dist[r[i]][r[i+1]];
        chmin(ans,tmp);
    }while(next_permutation(r,r+R));
    cout<<ans<<endl;
    return 0;
}
