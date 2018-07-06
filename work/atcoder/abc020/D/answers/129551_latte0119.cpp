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

const int mod=1000000007;

int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}

int dp[111111];
int N,K;

signed main(){
    cin>>N>>K;
    vint v;
    for(int i=1;i*i<=K;i++){
        if(K%i)continue;
        v.pb(i);
        if(i*i!=K)v.pb(K/i);
    }
    sort(all(v));reverse(all(v));

    int ans=0;
    for(int i=0;i<v.size();i++){
        int t=N/v[i]%mod;
        dp[i]=t*(t+1)/2%mod*v[i]%mod;
        for(int j=0;j<i;j++){
            if(v[j]%v[i]==0)dp[i]=(dp[i]-dp[j]+mod)%mod;
        }
        ans=(ans+K/v[i]%mod*dp[i])%mod;
    }

    cout<<ans<<endl;
    return 0;
}
