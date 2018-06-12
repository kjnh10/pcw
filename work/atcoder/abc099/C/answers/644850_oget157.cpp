#include <bits/stdc++.h>
using namespace std;
#define mp       make_pair
#define pb       push_back
#define all(x)   (x).begin(),(x).end()
#define YES() printf("YES\n")
#define NO() printf("NO\n")
#define Yes() printf("Yes\n")
#define No() printf("No\n")
#define in(x,y,h,w) x >= 0 && x < h && y >= 0 && y < w

#define int long long
//typedef    long long          ll;
typedef    vector<bool>       vb;
typedef    vector<int>        vi;
typedef    vector<vb>         vvb;
typedef    vector<vi>         vvi;
typedef    pair<int,int>      P;

template <typename T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template <typename T> T &chmax(T &a, const T &b) { return a = max(a, b); }
 
const int INF=1e+18;
const double EPS=1e-9;
const int MOD=1000000007;
 
const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};

signed main(){
	int n,dp[100010] = {};
	cin >> n;
	dp[0] = 0;
	for(int i = 1;i <= n;i++){
		dp[i] = dp[i - 1] + 1;
		for(int j = 6;j <= i;j *= 6) chmin(dp[i],dp[i - j] + 1);
		for(int j = 9;j <= i;j *= 9) chmin(dp[i],dp[i - j] + 1);
	}
	cout << dp[n] << endl;
	return 0;
}