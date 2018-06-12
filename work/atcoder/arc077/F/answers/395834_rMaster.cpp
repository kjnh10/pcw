
/*\
 * ...
 * ......
 * In the name of ALLAH
 * ......
 * ...
\*/

#include <bits/stdc++.h>

using namespace std;
#define Size(x) ((int)(x).size())
#define pb push_back
#define LD_OUT setprecision(12) << fixed
typedef long long ll;
typedef long double ld;
typedef pair<int,int>pii;
const int INF = 1e9 + 10 , MN = 2e5 + 10 , LG = 222;
const ll BIG = 1000ll*1000*1000*1000*1000*1000 + 10;

int n , nxt[MN];
string s;
ll Nx[LG] , Ny[LG] , X[33][LG] , Y[33][LG];
int ps[33][MN];

void prep()
{
	int cur = 0;
	for(int i=1;i<n;++i){
		while(cur && s[i] != s[cur]) cur = nxt[cur];
		cur += (s[i] == s[cur]);
		nxt[i+1] = cur;
	}
	Nx[0] = n - nxt[n] , Ny[0] = nxt[n];
	for(int i=0;i<Nx[0];++i)
		X[s[i]-'a'][0]++;
	for(int i=Nx[0];i<n;++i)
		Y[s[i]-'a'][0]++;
	for(int i=1;i<LG;++i){
		Nx[i] = Nx[i-1] + Ny[i-1];
		Nx[i] = min(Nx[i] , BIG);
		Ny[i] = Nx[i-1];
		for(int j=0;j<26;++j){
			X[j][i] = X[j][i-1] + Y[j][i-1];
			Y[j][i] = X[j][i-1];
			X[j][i] = min(X[j][i] , BIG);
		}
	}
	for(int i=0;i<n;++i)
		for(int j=0;j<26;++j)
			ps[j][i+1] = ps[j][i] + (s[i]-'a' == j);
}

ll get(ll val,int c)
{
	for(int i=LG-1;~i;--i)
		if(Nx[i] <= val) return min(BIG , X[c][i] + get(val - Nx[i] , c));
	return ps[c][val];
}

int main()
{
	ios_base :: sync_with_stdio(false) ,cin.tie(0) , cout.tie(0);
	cin>>s;
	n = Size(s)/2;
	prep();

	ll l , r;
	cin >> l >> r;
	for(int c=0;c<26;++c) cout << get(r , c) - get(l-1 , c) << ' ';
	cout << '\n';
	return 0;
}
