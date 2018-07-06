#include <bits/stdc++.h>
using namespace std;
/*{{{*/  //template
#define REP(i,n) for(int i=0;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1<<29
#define LINF LLONG_MAX/3
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define ALL(v) (v).begin(),(v).end()
#define all(v) ALL(v)
#define debug(x) cerr<<#x<<":"<<x<<endl
#define debug2(x,y) cerr<<#x<<","<<#y":"<<x<<","<<y<<endl
#define CININIT cin.tie(0),ios::sync_with_stdio(false)
struct fin{ fin(){ cin.tie(0); ios::sync_with_stdio(false); } } fin_;
struct Double{ double d; explicit Double(double x) : d(x){} };
ostream& operator<<(ostream& os,const Double x){ os << fixed << setprecision(20) << x.d; return os; }
template<typename T> ostream& operator<<(ostream& os,const vector<T>& vec){ os << "["; for(const auto& v : vec){ os << v << ","; } os << "]"; return os; }
template<typename T,typename U> ostream& operator<<(ostream& os,const pair<T,U>& p){ os << "(" << p.first << ","<< p.second <<")"; return os; }
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
ll gcd(ll a,ll b){ if(b==0) return a; else return gcd(b,a%b); }
 
constexpr ll mod = 1e9+7;
const int dx[]={1,0,-1,0} ,dy[] = {0,1,0,-1};
/*}}}*/

int N;
class LCA{
    private:
        int V;
        int logV;
        vector<vector<int>> G;      // adjacency list
        int root;
        vector<vector<int>>  parent;    // parent[k][v] : 親を2^k会辿って到着する頂点

    public:
        vector<int> depth;          // depth from root

    private:
        void dfs(int v,int p,int d){    // v:node , p:parent , d:depth
            parent[0][v] = p;
            depth[v] = d;
            for(size_t i=0;i<G[v].size();i++){
                if(G[v][i]!=p) dfs(G[v][i],v,d+1);
            }
        }

    public:
        LCA(const vector<vector<int>> &g) : G(g) {
            V = g.size();
            logV = log2(V)+1;
            parent = vector<vector<int>>(logV,vector<int>(V));
            depth = vector<int>(V);
            root=0;
            dfs(root,-1,0);
            //parentの初期化
            for(int k=0;k+1<logV;k++){
                for(int v=0;v<G.size();v++){
                    if(parent[k][v]<0) parent[k+1][v] = -1;
                    else parent[k+1][v] = parent[k][parent[k][v]];
                }
            }
        }

        int lca(int u,int v){
            if(depth[u]>depth[v]) swap(u,v);        //depth[u]<=depth[v]
            for(int k=0;k<logV;k++){
                // ダブリングでdepth[u]=depth[v]になるまで登る
                if((depth[v]-depth[u])>>k & 1){
                    v = parent[k][v];
                }
            }

            if(u==v) return u;

            // find LCA with binary-search
            for(int k=logV-1;k>=0;k--){
                if(parent[k][u]!=parent[k][v]){
                    u = parent[k][u];
                    v = parent[k][v];
                }
            }
            return parent[0][u];
        }

        vector<vector<int>> getG(){
            return G;
        }
};

int main(){
    cin>>N;
    assert(N>1);
    vector<vector<int>> g(N);
    rep(i,N-1){
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    LCA t(g);

    int Q;cin>>Q;
    rep(i,Q){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        int p = t.lca(a,b);

        int d = t.depth[a]+t.depth[b]-2*t.depth[p];
        cout << d + 1 << endl;
    }
}
