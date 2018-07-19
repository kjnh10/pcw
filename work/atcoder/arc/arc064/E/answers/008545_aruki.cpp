#include "bits/stdc++.h"
using namespace std;
#define FOR(i,j,k) for(int (i)=(j);(i)<(int)(k);++(i))
#define rep(i,j) FOR(i,0,j)
#define each(x,y) for(auto &(x):(y))
#define mp make_pair
#define mt make_tuple
#define all(x) (x).begin(),(x).end()
#define debug(x) cout<<#x<<": "<<(x)<<endl
#define smax(x,y) (x)=max((x),(y))
#define smin(x,y) (x)=min((x),(y))
#define MEM(x,y) memset((x),(y),sizeof (x))
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

typedef double Weight;
struct Edge{
    int from, to;
    Weight wei;
    Edge(int from_, int to_, Weight wei_):from(from_),to(to_),wei(wei_){}
};
typedef vector<Edge> Edges;
const Weight INFW = numeric_limits<Weight>::max();
struct Graph : public vector<Edges>{
    Graph(){ }
    Graph(int V): vector<Edges>(V){ }
    /*
    有向辺を追加する
    */
    void addEdge(int from, int to, Weight wei=1){
        (*this)[from].push_back(Edge(from, to, wei));
    }
    /*
    無向辺を追加する
    */
    void addUEdge(int u, int v, Weight wei=1){
        (*this)[u].push_back(Edge(u, v, wei));
        (*this)[v].push_back(Edge(v, u, wei));
    }
};

/*
ダイクストラで使うのはこっち
*/
bool operator>(const Edge &a, const Edge &b){
    return a.wei>b.wei;
}
vector<Weight> dijkstra(const Graph &G, int src){
    typedef pair<Weight, int> pwi;
    priority_queue<pwi, vector<pwi>, greater<pwi>> pq;
    pq.push(mp(0, src));
    int V = (int)G.size();
    vector<Weight> res(V, -1);
    while(pq.size()){
        auto p = pq.top(); pq.pop();
        Weight d = p.first;
        int v = p.second;
        if(res[v] > -0.5)continue;
        res[v] = d;
        for(const auto &edge : G[v]){
            int to = edge.to;
            Weight wei = edge.wei;
            pq.push(make_pair(d + wei, to));
        }
    }
    return res;
}


double X[1002], Y[1002], R[1002];

double f(int i, int j) {
    double d = hypot(X[i] - X[j], Y[i] - Y[j]);
    return max(0.0, d - R[i] - R[j]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    double xs, ys, xt, yt;
    cin >> xs >> ys >> xt >> yt;

    int N;
    cin >> N;
    rep(i, N) {
        cin >> X[i] >> Y[i] >> R[i];
    }
    X[N] = xs;
    Y[N] = ys;
    X[N + 1] = xt;
    Y[N + 1] = yt;

    Graph G(N+2);
    rep(i, N+2)rep(j, i) {
        G.addUEdge(i, j, f(i, j));
    }

    auto dis = dijkstra(G, N);
    cout << setprecision(20) << dis[N + 1] << endl;
}