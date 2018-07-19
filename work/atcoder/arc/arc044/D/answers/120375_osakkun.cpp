#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <set>
#include <iomanip>
#include <deque>
#include <stdio.h>
using namespace std;

#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define RREP(i,n) for(int (i)=(int)(n)-1;i>=0;i--)
#define FILL(Itr,n) fill((Itr).begin(),(Itr).end(),n)
#define REMOVE(Itr,n) (Itr).erase(remove((Itr).begin(),(Itr).end(),n),(Itr).end())
#define UNIQUE(Itr) sort((Itr).begin(),(Itr).end()); (Itr).erase(unique((Itr).begin(),(Itr).end()),(Itr).end())
#define LBOUND(Itr,val) lower_bound((Itr).begin(),(Itr).end(),(val))
#define UBOUND(Itr,val) upper_bound((Itr).begin(),(Itr).end(),(val))
typedef long long ll;
#define MOD 1000000007

long long pow_mod(long long n, long long k, long long m){
    long long res=1;
    for(;k>0;k>>=1){
        if(k&1)res=((res%m)*(n%m))%m;
        n=((n%m)*(n%m))%m;
    }
    return res;
}

int main(){
    
    int N; cin>>N;
    vector<ll> A(N);
    REP(i,N)cin>>A[i];
    
    ll ans=1;
    ll maxv = 1;
    map<ll,ll> cnt;
    REP(i,N){
        if(cnt.find(A[i])==cnt.end())cnt[A[i]]=1;
        else cnt[A[i]]++;
        maxv = max(maxv,A[i]);
    }
    
    if(cnt[0]!=1||A[0]!=0){
        cout<<0<<endl;
        return 0;
    }
    
    for(ll i=1;i<=maxv;i++){
        ans = (ans * pow_mod(2,cnt[i]*(cnt[i]-1)/2,MOD)) % MOD;
        ans = (ans * pow_mod((pow_mod(2,cnt[i-1],MOD)-1+MOD)%MOD,cnt[i],MOD)) % MOD;
    }
 
    cout<<ans<<endl;
    
    return 0;
}