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

template <typename T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template <typename T> T &chmax(T &a, const T &b) { return a = max(a, b); }
 
const int INF=1e+9;
const double EPS=1e-9;
const int MOD=1000000007;
 
const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};

signed main(){
	int a,b;
	bool flag = true;
	string s;
	cin >> a >> b >> s;
	for(int i = 0;i < a;i++) if(!(s[i] >= '0' && s[i] <= '9')) flag = false;
	if(s[a] != '-') flag = false;
	for(int i = a + 1;i < a + b + 1;i++) if(!(s[i] >= '0' && s[i] <= '9')) flag = false;
	if(flag) Yes();
	else No();
	return 0;
}