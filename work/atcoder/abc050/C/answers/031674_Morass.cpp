#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define ZERO (1e-10)
#define INF (1<<29)
#define CL(A,I) (memset(A,I,sizeof(A)))
#define DEB printf("DEB!\n");
#define D(X) cout<<"  "<<#X": "<<X<<endl;
#define EQ(A,B) (A+ZERO>B&&A-ZERO<B)
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
#define IN(n) int n;scanf("%d",&n);
#define FOR(i, m, n) for (int i(m); i < n; i++)
#define REP(i, n) FOR(i, 0, n)
#define F(n) REP(i, n)
#define FF(n) REP(j, n)
#define FT(m, n) FOR(k, m, n)
#define aa first
#define bb second
void ga(int N,int *A){F(N)scanf("%d",A+i);}
#define MX (1<<19)
#define MOD (1000000007)
ll pw(ll n,ll k){
    ll r(1);
    while(k){
        if(k&1)r*=n,r%=MOD;
        n*=n,n%=MOD;
        k>>=1;
    }
    return r;
}
int C[MX],A[MX],N;
int go(){
    F(N)++C[A[i]];
    if(N&1){
        F(N)if(A[i]&1)return 0;
        if(*C^1)return 0;
        FT(2,N)if(!(k&1)&&C[k]^2)return 0;
    }else{
        F(N)if(!(A[i]&1))return 0;
        FT(1,N)if(k&1&&C[k]^2)return 0;
    }
    return pw(2,N/2);
}
int main(void){
    scanf("%d",&N),ga(N,A),printf("%d\n",go());
    return 0;
}
