#include <bits/stdc++.h>
#define  rep(i,n) for(li i=0;i<(n);i++)
#define  red(i,n) for(li i=(n)-1;i>=0;i--)
#define  all(a)   begin(a),end(a)
#define  pb(a)    push_back(a) 
using namespace std;
using li = long long;
using ul = unsigned long long;
using vi = vector<li>;
using vs = vector<string>;
inline ul gcd(ul a,ul b) { return b?gcd(b,a%b):a; }
const int INF=1000000009;


int main()
{
    int n,k,ans=0,a;
    cin>>n>>k;
    rep(i,n)cin>>a,ans+=min(a,k-a);
    cout<<ans*2<<endl;
    return 0;
}
