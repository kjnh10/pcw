/*******************************\
   Name:    REAJUL HAQUE REAYZ  |
   School:  COMILLA UNIVERSITY  |
            CSE (5TH BATCH)     |
********************************/
#include<bits/stdc++.h>
#define endl "\n"
#define inf 1<<30
#define pi acos(-1.0)
#define pb push_back
#define mp make_pair
#define ss stringstream
#define all(v) v.begin(), v.end()
#define mem(x,y) memset(x,y,sizeof(x))
#define bit_cnt(mask) __builtin_popcount(mask)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int MOD = 1000000007; /// 1e9+7
const int MAX = 100005;     /// 1e5+5
ll bigmod(ll n, ll r)
{
    if(r==0) return 1;
    if(r==1) return n;
    if(r%2==0)
    {
        ll ret = bigmod(n, r/2);
        return ((ret%MOD) * (ret%MOD)) % MOD;
    }
    else return ((n%MOD) * (bigmod(n,r-1)%MOD)) % MOD;
}
ll modinverse(ll a){return bigmod(a,MOD-2)%MOD;}
ll lcm(ll a, ll b) {a=abs(a); b=abs(b); return (a/__gcd(a,b))*b;}
ll gcd(ll a, ll b) {a=abs(a); b=abs(b); if(!b) return a; return __gcd(b,a%b);}

int n;
bool visit[MAX][100];
int summ(int x){
    int ret = 0;
    while(x>0){
        ret += x%10;
        x/=10;
    }
    return ret;
}
void dfs(int num, int sum){
    if(sum>=99) return;
    if(num>=n) return;
    if(visit[num][sum]) return;
    visit[num][sum]=true;
    for(int i=0; i<10; i++)
        dfs((num*10+i)%n, sum+i);
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int i=0; i<n; i++){
        dfs(i, summ(i));
    }
    int ans = summ(n);
    for(int i=1; i<99; i++){
        if(visit[0][i]) ans = min(ans, i);
    }
    cout<<ans<<endl;
    return 0;
}
