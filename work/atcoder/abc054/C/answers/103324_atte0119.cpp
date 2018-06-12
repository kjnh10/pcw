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
template<class T,class U>void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>void chmax(T &t,U f){if(t<f)t=f;}

int N,M;
int G[10][10];

int ans;
bool used[10];
void dfs(int v,int cnt){
    if(cnt==N){
        ans++;
        return;
    }
    used[v]=1;
    rep(i,N)if(!used[i]&&G[v][i])dfs(i,cnt+1);
    used[v]=0;
}

signed main(){
    cin>>N>>M;
    rep(i,M){
        int a,b;
        cin>>a>>b;
        a--;b--;
        G[a][b]=G[b][a]=1;
    }

    dfs(0,1);
    cout<<ans<<endl;
    return 0;
}
