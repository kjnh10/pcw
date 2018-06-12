#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
#define fin "\n"


#define FOR(i,bg,ed) for(int i=(bg);i<(ed);i++)
#define REP(i,n) FOR(i,0,n)

template <typename T>
inline void chmin(T &l,T r){l=min(l,r);}

template <typename T>
inline void chmax(T &l,T r){l=max(l,r);}

template <typename T>
istream& operator>>(istream &is,vector<T> &v){
    for(auto &it:v)is>>it;
    return is;
}

typedef pair<int,int> P;
#define X first
#define Y second
const LL MOD=1e9+7;
int main(){
    int N,M;
    cin>>N>>M;
    string s;
    cin>>s;
    vector<P> sum(N);
    sum[0].X=(s[0]=='0');
    sum[0].Y=1-sum[0].X;
    FOR(i,1,N)sum[i].X=(s[i]=='0')+sum[i-1].X;
    FOR(i,1,N)sum[i].Y=(s[i]=='1')+sum[i-1].Y;
    vector<int> ub(N);
    iota(ub.begin(),ub.end(),0);
    REP(i,M){
        int l,r;cin>>l>>r;l--;r--;
        chmax(ub[l],r);
    }
    FOR(i,1,N)chmax(ub[i],ub[i-1]);
    //REP(i,N)cout<<sum[i].X<<sum[i].Y<<" ";cout<<endl;
    vector<LL> dp(N+1,0);
    dp[0]=1;
    REP(i,N){
        vector<LL> nxt(N+1,0);
        REP(j,N+1)if(dp[j]){
            const int x=sum[ub[i]].X-j;
            const int y=sum[ub[i]].Y-(i-j);
            if(x)(nxt[j+1]+=dp[j])%=MOD;
            if(y)(nxt[j]+=dp[j])%=MOD;
        }
        swap(dp,nxt);
    }
    cout<<dp[sum.back().X]<<endl;
    return 0;
}
