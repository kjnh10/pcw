#include <bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define RS(X) scanf("%s", (X))
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define PII pair<int,int>
#define VI vector<int>
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define VPLL vector<pair<long long,long long> >
#define F first
#define S second
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 1e6+10;

struct Union_Find{
    int d[SIZE],num[SIZE];
    void init(int n){
        REP(i,n)d[i]=i,num[i]=1;
    }
    int find(int x){
        return (x!=d[x])?(d[x]=find(d[x])):x;
    }
    bool uu(int x,int y){
        x=find(x);
        y=find(y);
        if(x==y)return 0;
        if(num[x]<=num[y]){
            num[y]+=num[x];
            d[x]=y;
        }
        else{
            num[x]+=num[y];
            d[y]=x;
        }
        return 1;
    }
}U;
VPII e[100];
bool used[100];
PII from[100];
void ADD(LL& x,LL v){
    x=(x+v)%MOD;
}
int h[100];
void dfs(int x){
    used[x]=1;
    REP(i,SZ(e[x])){
        int y=e[x][i].F;
        if(used[y]){
            if(h[y]<h[x]){
                int id=e[x][i].S;
                int now=x;
                while(now!=y){
                    U.uu(id,from[now].S);
                    now=from[now].F;
                }
            }
        }
        else{
            from[y]=MP(x,e[x][i].S);
            h[y]=h[x]+1;
            dfs(y);
        }
    }
}
LL dp0[111][111];
PII ee[222];
LL mypow(LL x,LL y){
    x%=MOD;
    LL res=1%MOD;
    while(y){
        if(y&1)res=res*x%MOD;
        y>>=1;
        x=x*x%MOD;
    }
    return res;
}
LL f(int n,int K){
    LL v=0;
    REPP(i,1,n+1){
        int gg=__gcd(i,n);
        ADD(v,mypow(K,gg));
    }
    v=v*mypow(n,MOD-2)%MOD;
    return v;
}
int main(){
    DRIII(N,M,K);
    dp0[0][0]=1;
    REP(i,K){
        REP(j,111){
            if(dp0[i][j]){
                for(int k=0;k+j<111;k++){
                    ADD(dp0[i+1][j+k],dp0[i][j]);
                }
            }
        }
    }
    U.init(M);
    REP(i,M){
        DRII(x,y);x--;y--;
        ee[i]=MP(x,y);
        e[x].PB(MP(y,i));
        e[y].PB(MP(x,i));
    }
    REP(i,N)
        if(!used[i])dfs(i);
    LL an=1;
    REP(i,M){
        if(U.find(i)==i){
            //printf("[%d,%d]\n",i,U.num[i]);
            if(U.num[i]==1)an=an*K%MOD;
            else{
                set<int>P;
                REP(j,M){
                    if(U.find(j)==i){P.insert(ee[j].F);P.insert(ee[j].S);}
                }
                if(SZ(P)<U.num[i])an=an*dp0[K][U.num[i]]%MOD;
                else{
                    an=an*f(U.num[i],K)%MOD;
                }
            }
        }
    }
    cout<<an<<endl;
    return 0;
}
