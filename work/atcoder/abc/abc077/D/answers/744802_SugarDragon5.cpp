
#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define vs vector<string>
#define pb push_back
#define P pair<int,int>
#define vp vector<P>
#define PP pair<P,int>
#define vpp vector<PP>
#define fi first
#define se second
#define INF (1<<30)
#define MOD 1000000007
#define REP(i,n) for(int i=0;i<n;i++)
#define REPR(i,n) for(int i=n;i>=0;i--)
#define FOR(i,m,n) for(int i=m;i<n;i++)
#define all(x) (x).begin(),(x).end()
const int MAX_V=100000;
struct edge{int to,cost;};
int V;
vector<edge> G[MAX_V];
int d[MAX_V];
void dijkstra(int s){
    priority_queue<P,vector<P>,greater<P> > que;
    fill(d,d+V,INF);
    d[s]=0;
    que.push(P(0,s));
    while(!que.empty()){
        P p=que.top();que.pop();
        int v=p.se;
        if(d[v]<p.fi)continue;
        for(int i=0;i<G[v].size();i++){
            edge e=G[v][i];
            if(d[e.to]>d[v]+e.cost){
                d[e.to]=d[v]+e.cost;
                que.push(P(d[e.to],e.to));
            }
        }
    }
}
int main(){
    cin>>V;
    REP(i,V){
        edge t;
        t.to=(i+1)%V;
        t.cost=1;
        G[i].pb(t);
    }
    REP(i,V){
        edge t;
        t.to=(i*10)%V;
        t.cost=0;
        G[i].pb(t);
    }
    dijkstra(1);
    cout<<d[0]+1<<endl;
    return 0;
}