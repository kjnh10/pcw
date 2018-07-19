#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
#define all(x) (x).begin(),(x).end()
#define pb push_back

int N, W, C;
int w[110];
int val[110];
int col[110];

vector<int> my[51];

void in(){
	cin >> N >> W >> C;
	for(int i=1; i<=N; ++i){
		cin >> w[i] >> val[i] >> col[i];
		my[col[i]].pb(i);
	}
}

const ll inf = 1ll<<60;

ll dp[51][10010];
ll u1[51][10010];

int main()
{
    in();
    
    for(int i=0; i<=50; ++i) for(int j=0; j<=W; ++j) dp[i][j]=-inf;
    dp[0][0] = 0;
    
    ll ans = 0;
    for(int i=1; i<=50; ++i){
		for(int i=0; i<=50; ++i) for(int j=0; j<=W; ++j) u1[i][j]=-inf;
		for(int j=C; j>=1; --j){
			for(int x:my[i]){
				for(int k=W; k>=w[x]; --k){
					if(u1[j][k-w[x]] != -inf)
						u1[j][k]=max(u1[j][k], u1[j][k-w[x]]+val[x]);
					if(dp[j-1][k-w[x]] != -inf)
						u1[j][k]=max(u1[j][k], dp[j-1][k-w[x]]+val[x]);
				}
			}
		}
		for(int i=0; i<=50; ++i) for(int j=0; j<=W; ++j){
			dp[i][j] = max(dp[i][j], u1[i][j]);
			ans = max(ans, dp[i][j]);
		}
    }
    
    printf("%lld\n", ans);
    return 0;
}
