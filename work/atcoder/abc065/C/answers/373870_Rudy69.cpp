#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define dbg(x) cout << #x << '=' << x << '\n';
#define ll long long
#define pi pair<int,int>
#define pl pair<long long,long long>
#define rd(x) cin >> x;
#define rda(a,n) for(int i=1;i<=n;i++) cin >> a[i];
#define wr(x) cout << x << ' ';
#define wrl(x) cout << x << '\n';
#define wra(a,n) for(int i=1;i<=n;i++) cout << a[i] << ' '; cout << '\n';
#define lg length()
#define pb(x) push_back(x)
ifstream in("file.in");
ofstream out("file.out");
#define MAXN 100005
#define INF 1000000005
#define LINF 1000000000000000005
struct comp{
    bool operator()(long long a, long long b){
        return a>b;
    }
};

long long n,m,ans,mod=1e9+7;

int main(){
    ios_base :: sync_with_stdio(0);
    cin >> n >> m;
    if(abs(n-m)<=1){
        if(!abs(n-m)) ans=2;
        else ans=1;
        for(int i=1;i<=n;i++){
            ans*=i;
            ans%=mod;
        }
        for(int i=1;i<=m;i++){
            ans*=i;
            ans%=mod;
        }
    }
    cout << ans;
}
