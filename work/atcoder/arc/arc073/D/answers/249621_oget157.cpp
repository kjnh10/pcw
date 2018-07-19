#include<map>
#include<set>
#include<list>
#include<cmath>
#include<queue>
#include<stack>
#include<cstdio>
#include<string>
#include<vector>
#include<complex>
#include<cstdlib>
#include<cstring>
#include<numeric>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<functional>
 
#define mp       make_pair
#define pb       push_back
#define all(x)   (x).begin(),(x).end()
#define YES() printf("YES\n")
#define NO() printf("NO\n")
 
using namespace std;
 
#define int long long
//typedef    long long          ll;
typedef    unsigned long long ull;
typedef    vector<bool>       vb;
typedef    vector<int>        vi;
typedef    vector<vb>         vvb;
typedef    vector<vi>         vvi;
typedef    pair<int,int>      P;
 
const int INF=1e+9;
const double EPS=1e-9;
const int MOD=1000000007;
 
const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};

signed main(){
	int n,W,w[100],v[100],w1;
	int dp[101][101][301] = {};
	cin >> n >> W;
	for(int i = 0;i < n;i++){
		cin >> w[i] >> v[i];
		if(!i) w1 = w[i];
		w[i] -= w1;
	}
	for(int i = 1;i <= n;i++){
		for(int j = 0;j <= n;j++){
			for(int k = 0;k <= 300;k++){
				if(j && k - w[i - 1] >= 0) dp[i][j][k] = max(dp[i - 1][j][k],dp[i - 1][j - 1][k - w[i - 1]] + v[i - 1]);
				else dp[i][j][k] = dp[i - 1][j][k];
			}
		}
	}
	int ma = 0;
	for(int i = 0;i <= n;i++){
		for(int j = 0;j <= 300;j++){
			if(j + w1 * i <= W){
				ma = max(ma,dp[n][i][j]);
			}
		}
	}
	cout << ma << endl;
	return 0;
}