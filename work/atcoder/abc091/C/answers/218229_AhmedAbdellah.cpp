
//#include <ext/pb_ds/assoc_container.hpp> // Common file
//#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
//#include <ext/pb_ds/detail/standard_policies.hpp>
#include<set>
#include<map>
#include <unordered_map>
#include <unordered_set>
#include<list>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<complex>
#include<sstream>
#include<iostream>
#include<fstream>
#include<algorithm>
#include<numeric>
#include<utility>
#include<functional>
#include<stdio.h>
#include<assert.h>
#include<memory.h>
#include<bitset>
#include<math.h>
#include <strings.h>



#define f first
#define s second
#define mp make_pair
#define pb push_back
#define lp(i,a,n) for(int i=a;i<=n;++i)
#define lpd(i,a,n) for(int i=a;i>=n;--i)
#define mem(a,b) memset(a,b,sizeof a)
#define all(v) v.begin(),v.end()
#define println(a) cout <<(a) <<endl
#define sz(x) ((int)(x).size())
#define readi(x) scanf("%d",&x)
#define read2i(x,y) scanf("%d%d",&x,&y)
#define read3i(x,y,z) scanf("%d%d%d",&x,&y,&z)
//#define mod 1000000007
#define eps 1e-8
#define infi 1000000000
#define infll 1000000000000000000ll
#define mod1 100050001
#define mod2 100030001
#define base1 37
#define base2 31


using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef set<int> si;
typedef map<int,int> mii;


const int N = 102;
int n;
pii a[N], b[N];




//NODES ARE 1-INDEXED

class BipGraph{
    int m,n;
    vi *adj;
    int *pairU, *pairV, *dist;
    
public:
    BipGraph(int m, int n);
    void addEdge(int u, int v);
    bool bfs();
    bool dfs(int u);
    int hopcroftKarp();
};

int BipGraph::hopcroftKarp(){
    pairU = new int[m+1];
    pairV = new int[n+1];
    dist = new int[m+1];
    
    for(int u = 0; u <= m; ++u)
        pairU[u] = 0;
    for(int v = 0; v <= n; ++v)
        pairV[v] = 0;
    
    int result = 0;
    while(bfs()){
        for(int u = 1; u <= m; ++u)
            if(pairU[u] == 0 and dfs(u))
                ++result;
    }
    return result;
}

bool BipGraph::bfs(){
    queue<int> Q;
    
    for(int u = 1; u <= m; ++u){
        if(pairU[u] == 0){
            dist[u] = 0;
            Q.push(u);
        }
        else dist[u] = infi;
    }
    
    dist[0] = infi;
    
    while(sz(Q)){
        int u = Q.front(); Q.pop();
        
        if(dist[u] < dist[0]){
            vi::iterator i;
            for(i = adj[u].begin(); i != adj[u].end(); ++i){
                int v = *i;
                if(dist[pairV[v]] == infi){
                    dist[pairV[v]] = dist[u] + 1;
                    Q.push(pairV[v]);
                }
            }
        }
    }
    
    return dist[0] != infi;
}

bool BipGraph::dfs(int u){
    if(u){
        for(int v:adj[u]){
            if(dist[pairV[v]] == dist[u]+1){
                if(dfs(pairV[v])){
                    pairV[v] = u;
                    pairU[u] = v;
                    return true;
                }
            }
        }
        dist[u] = infi;
        return false;
    }
    return true;
}

BipGraph::BipGraph(int m, int n){
    this->m = m;
    this->n = n;
    adj = new vi[m+1];
}

void BipGraph::addEdge(int u, int v){
    adj[u].pb(v);
}
int main(){
    scanf("%d",&n);
    lp(i, 1, n) scanf("%d%d",&a[i].f,&a[i].s);
    lp(i, 1, n) scanf("%d%d",&b[i].f,&b[i].s);
    
    BipGraph g(n+1,n+1);
    lp(i, 1, n) {
        lp(j, 1, n) if(a[i].f < b[j].f && a[i].s < b[j].s) {
            g.addEdge(i, j);
        }
        
    }
    
    printf("%d\n",g.hopcroftKarp());
    
    return 0;
}



/*

 5 3
 1 3
 1 5
 3 6
 4 4
 2 6
 1 5 3
 1 5 4
 1 1 1

 */
//freopen("output.txt","w",stdout);
//freopen("input.txt","r",stdin);
//ios::sync_with_stdio(0);cin.tie(0);