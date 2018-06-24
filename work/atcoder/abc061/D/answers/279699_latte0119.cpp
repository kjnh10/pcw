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

int N,M;
vpint G[1111];
vint rG[1111];

bool re[1111];
int ma[1111];
signed main(){
    cin>>N>>M;
    rep(i,M){
        int a,b,c;
        scanf("%lld%lld%lld",&a,&b,&c);
        a--;b--;
        G[a].pb({b,c});
        rG[b].pb(a);
    }

    queue<int>que;
    que.push(N-1);
    re[N-1]=true;
    while(que.size()){
        int v=que.front();
        que.pop();
        for(auto u:rG[v]){
            if(re[u])continue;
            re[u]=true;
            que.push(u);
        }
    }

    fill_n(ma,N,-(LLONG_MAX/10));
    ma[0]=0;
    rep(i,2*N){
        bool update=false;
        rep(v,N){
            for(auto &e:G[v]){
                int u,c;
            tie(u,c)=e;
                if(!re[v]||!re[u])continue;
                if(ma[u]<ma[v]+c){
                    ma[u]=ma[v]+c;
                    update=true;
                }
            }
        }
        if(update&&i>=N){
            cout<<"inf"<<endl;
            return 0;
        }
    }
    cout<<ma[N-1]<<endl;
    return 0;
}
