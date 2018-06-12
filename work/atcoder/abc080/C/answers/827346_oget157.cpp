#include <bits/stdc++.h>
#define mp       make_pair
#define pb       push_back
#define all(x)   (x).begin(),(x).end()
#define YES() printf("YES\n")
#define NO() printf("NO\n")
#define Yes() printf("Yes\n")
#define No() printf("No\n")
#define in(x,y,h,w) x >= 0 && x < h && y >= 0 && y < w
using namespace std;

#define int long long
//typedef    long long          ll;
typedef    vector<bool>       vb;
typedef    vector<int>        vi;
typedef    vector<vb>         vvb;
typedef    vector<vi>         vvi;
typedef    pair<int,int>      P;
 
const int INF=1e+18;
const double EPS=1e-9;
const int MOD=1000000007;
 
const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};

signed main(){
	int n,f[10][100],p[100][11],ma = -INF;
	cin >> n;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < 10;j++) cin >> f[j][i];
	}
	for(int i = 0;i < n;i++){
		for(int j = 0;j < 11;j++) cin >> p[i][j];
	}
	for(int i = 1;i < (1 << 10);i++){
		int ans = 0;
		for(int j = 0;j < n;j++){
			int cnt = 0;
			for(int k = 0;k < 10;k++){
				if(f[k][j] && ((i >> k) & 1)) cnt++;
			}
			ans += p[j][cnt];
		}
		ma = max(ma,ans);
	}
	cout << ma << endl;
	return 0;
}