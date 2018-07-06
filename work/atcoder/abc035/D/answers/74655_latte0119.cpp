#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int>pint;
typedef vector<int>vint;
typedef vector<pint>vpint;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
template<class T,class U>inline void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>inline void chmax(T &t,U f){if(t<f)t=f;}

struct edge{
    int to,cost;
    edge(int to,int cost):to(to),cost(cost){}
};

int N,M,T;
int A[111111];
int a[111111],b[111111],c[111111];
vector<edge>G[111111];
const int INF=1001001001001001001ll;

vint dijkstra(){
    vint dist(N,INF);dist[0]=0;

    dist[0]=0;
    priority_queue<pint,vector<pint>,greater<pint> >que;
    que.push(pint(0,0));

    while(que.size()){
        pint p=que.top();que.pop();
        if(dist[p.se]<p.fi)continue;
        for(auto &e:G[p.se]){
            if(dist[e.to]<=p.fi+e.cost)continue;
            dist[e.to]=p.fi+e.cost;
            que.push(pint(dist[e.to],e.to));
        }
    }
    return dist;
}

signed main(){
    cin>>N>>M>>T;
    rep(i,N)cin>>A[i];
    rep(i,M){
        cin>>a[i]>>b[i]>>c[i];
        a[i]--;b[i]--;
        G[a[i]].pb(edge(b[i],c[i]));
    }

    vint dist1=dijkstra();
    rep(i,N)G[i].clear();
    rep(i,M){
        G[b[i]].pb(edge(a[i],c[i]));
    }
    vint dist2=dijkstra();
    int ma=0;
    rep(i,N){
        int d=dist1[i]+dist2[i];
        if(d>T)continue;
        chmax(ma,(T-d)*A[i]);
    }

    cout<<ma<<endl;

    return 0;
}
