#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Edge {
    ll u,v,c;
    
};

struct state {
    ll v,c;
    bool operator < (const state& t) const {
	return c > t.c;
    }
    void dump(){
	cout << v+1 << " " << c << endl;

    }
};

ll dijkstra(vector<vector<Edge>>& g , ll s, ll t) {
    const ll N = g.size();
    vector<int> used(N,-1);

    priority_queue<state> pq;
    pq.push( state{s,0} );

    while( pq.size() ){
	state curr = pq.top(); pq.pop();
//	curr.dump();
	if( used[curr.v] != -1 ) continue;
	used[curr.v] = curr.c;

	if( curr.v == t ) return used[t];
	
	for(auto& e : g[curr.v]) {
	    if( used[e.v] == -1 )
		pq.push( state{e.v, curr.c + e.c} );
	}
    }
    return -1;
}


int main () {

    ll N,M;
    cin >> N >> M;

    vector<Edge> st;

    
    vector<vector<Edge>> g(N);
    for(int i=0; i<M; i++) {
	ll u,v,l;
	cin >> u >> v >> l;
	u--; v--;
	
	if( u == 0 or v == 0 ){
	    st.emplace_back(Edge{u,v,l});
	}
	else {
	    g[u].emplace_back(Edge{u,v,l});
	    g[v].emplace_back(Edge{v,u,l});
	}
    }

    ll ans = INT_MAX;
    for(int i=0; i<st.size(); i++) {

	// gを作る
	vector<vector<Edge>> gt = g;
	Edge e;
	for(int j=0; j<st.size(); j++) {
	    if( i != j ) {
		ll u = st[j].u, v = st[j].v, c = st[j].c;
		gt[u].emplace_back(Edge{u,v,c});
		gt[v].emplace_back(Edge{v,u,c});
	    }
	    else{
		e = st[i];
	    }
	}
	ll s = max(e.u,e.v);
	ll res = dijkstra(gt,s,0);
	if(res != -1)
	    ans = min(ans,res + e.c);
    }
    if(ans != INT_MAX)
	cout << ans << endl;
    else
	cout << -1 << endl;

    return 0;
}
