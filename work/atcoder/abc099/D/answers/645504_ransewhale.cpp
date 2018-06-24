#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define INF (1<<30)
#define INFLL (1ll<<60)
typedef pair<int, int> P;
typedef pair<ll, P> E;
#define MOD (998244353ll)
#define l_ength size
#define EPS (1e-10)

void add_mod(ll &a, ll b){
	a += b;
	a %= MOD;
}

void mul_mod(ll &a, ll b){
	a *= b;
	a %= MOD;
}

int main(void){
	int n,c,i,j,k,x;
	ll d[33][33], t[3][33] ,ans = INFLL;
	fill(t[0],t[3],0ll);
	cin >> n >> c;
	for(i=0; i<c; ++i){
		for(j=0; j<c; ++j){
			cin >> d[i][j];
		}
	}
	for(i=0; i<n; ++i){
		for(j=0; j<n; ++j){
			cin >> x; --x;
			for(k=0; k<30; ++k){
				t[(i+j)%3][k] += d[x][k];
			}
		}
	}
	for(i=0; i<c; ++i){
		for(j=0; j<c; ++j){
			if(i == j){
				continue;
			}
			for(k=0; k<c; ++k){
				if(i==k || j==k){
					continue;
				}
				ans = min(ans,t[0][i]+t[1][j]+t[2][k]);
			}
		}
	}
	cout << ans << endl;
	return 0;
}
