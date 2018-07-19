#include <iostream>/*{{{*/
#include <bits/stdc++.h>
#define rep(i, x) for(int i = 0; i < (int)(x); i++)
#define reps(i,x) for(int i = 1; i <= (int)(x); i++)
#define rrep(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define rreps(i,x) for(int i=((int)(x));i>0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define RFOR(i, m, n) for(int i = m;i >= n;i--)
#define foreach(x,a) for(auto& (x) : (a) )
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define fill(x,y) memset(x,y,sizeof(x))
#define pb(a) push_back(a)
#define debug(x)                 cerr << __LINE__ << ": " << #x << " -> " << x << '\n'
#define debug2(x, y)             cerr << __LINE__ << #x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define debug3(x, y, z)          cerr << __LINE__ << #x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define debug4(a, b, c, d)       cerr << __LINE__ << #a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define debug5(a, b, c, d, e)    cerr << __LINE__ << #a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define debug6(a, b, c, d, e, f) cerr << __LINE__ << #a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl
#define INF 999999999
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef vector<long long> vll;
typedef vector<vll> vvll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector<vii> vvii;
typedef tuple<int,int,int> iii;
typedef set<int> si;
typedef complex<double> pnt;
typedef vector<pnt> vpnt;
typedef priority_queue<pii,vii,greater<pii> > spq;
int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};/*}}}*/

int preprocess(){/*{{{*/
  cin.tie(0);
  ios::sync_with_stdio(false);
}/*}}}*/

ll n;
ll m;
ll x[1001];
ll y[1001];
ll z[1001];

ll f(int mask){
  ll tmp[n];
  rep(i, n){
    tmp[i] = x[i] * ((mask & 1)?1:-1);
    tmp[i] += y[i] * ((mask & 2)?1:-1);
    tmp[i] += z[i] * ((mask & 4)?1:-1);
  }
  sort(tmp, tmp+n, greater<ll>());

  ll res=0;
  rep(i, m){
    res += tmp[i];
  }
  debug(res);
  return res;
}

int main() {
  preprocess();

  cin >>n;
  cin >>m;
  rep(i,n){
    cin >> x[i];
    cin >> y[i];
    cin >> z[i];
  }

  ll res = 0;
  rep(mask, 1<<3){
    res = max(f(mask), res);
  }

  cout << res << endl;

  return 0;
}
