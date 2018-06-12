#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

int mod=1000000007;
inline void add(int &a,int b){
    a+=b;
    if(a>=mod)a-=mod;
}
int mpow(int n,int m,int mod){
    int ret=1;
    while(m){
        if(m&1)ret=ret*n%mod;
        n=n*n%mod;
        m>>=1;
    }
    return ret;
}
const int FACT_SIZE=1111111;
int fact[FACT_SIZE];
int inv[FACT_SIZE];
struct fact_exec{
    fact_exec(){
        fact[0]=1;
        for(int i=1;i<FACT_SIZE;i++)fact[i]=fact[i-1]*i%mod;
        inv[FACT_SIZE-1]=mpow(fact[FACT_SIZE-1],mod-2,mod);
        for(int i=FACT_SIZE-2;i>=0;i--)inv[i]=inv[i+1]*(i+1)%mod;
    }
};
int nCk(int n,int k){
    if(n<0|k<0||k>n)return 0;
    return fact[n]*inv[k]%mod*inv[n-k]%mod;
}
int nPk(int n,int k){
    if(n<0||k<0||k>n)return 0;
    return fact[n]*inv[n-k]%mod;
}

int N;

int S[3333][3333];
int T[3333];

int po[3333*3333];

signed main(){
    cin>>N>>mod;
    fact_exec();

    S[0][0]=1;
    for(int i=1;i<3333;i++){
        for(int j=1;j<=i;j++)S[i][j]=(S[i-1][j-1]+j*S[i-1][j])%mod;
    }
    po[0]=1;
    for(int i=1;i<3333*3333;i++)po[i]=po[i-1]*2%mod;

    int ans=0;
    for(int i=0;i<=N;i++){
        int tmp=0;
        for(int j=0;j<=i;j++){
            add(tmp,S[i][j]*po[(N-i)*j]%mod);
            add(tmp,S[i][j+1]*(j+1)%mod*po[(N-i)*j]%mod);
        }
        tmp=tmp*nCk(N,i)%mod;
        tmp=tmp*mpow(2,mpow(2,N-i,mod-1),mod)%mod;

        if(i&1)add(ans,mod-tmp);
        else add(ans,tmp);
    }
    cout<<ans<<endl;
    return 0;
}
