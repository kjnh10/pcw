#include <bits/stdc++.h>
#define ADD(a, b) a = (a + ll(b)) % mod
#define MUL(a, b) a = (a * ll(b)) % mod
#define MAX(a, b) a = max(a, b)
#define MIN(a, b) a = min(a, b)
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define rer(i, a, b) for(int i = int(a) - 1; i >= int(b); i--)
#define all(a) (a).begin(), (a).end()
#define sz(v) (int)(v).size()
#define pb push_back
#define sec second
#define fst first
#define debug(fmt, ...) Debug(__LINE__, ":", fmt, ##__VA_ARGS__)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<int, pi> ppi;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vl> mat;
typedef complex<double> comp;
void Debug() {cout << '\n'; }
template<class FIRST, class... REST>void Debug(FIRST arg, REST... rest){
	cout<<arg<<" ";Debug(rest...);}
template<class T>ostream& operator<<(ostream& out,const vector<T>& v) {
	out<<"[";if(!v.empty()){rep(i,0,sz(v)-1)out<<v[i]<<", ";out<<v.back();}out<<"]";return out;}
template<class S, class T>ostream& operator<<(ostream& out,const pair<S, T>& v){
	out<<"("<<v.first<<", "<<v.second<<")";return out;}
const int MAX_N = 200010;
const int MAX_V = 100010;
const double eps = 1e-6;
const ll mod = 1000000007;
const int inf = 1 << 29;
const ll linf = 1LL << 60;
const double PI = 3.14159265358979323846;
///////////////////////////////////////////////////////////////////////////////////////////////////

struct BIT { //1-origin!!!
	int n; ll bit0[MAX_N], bit1[MAX_N];
	void init(int mx) {
		n = mx;
		memset(bit0, 0, sizeof(bit0));
		memset(bit1, 0, sizeof(bit1));
	}
	BIT(int mx = 0) { init(mx); } 

	ll ga(ll *bit, int i) {
		ll s = 0;
		while(i > 0) { s += bit[i]; i -= i & -i; }
		return s;
	}
	void app(ll *bit, int i, ll x) {
		while(i <= n) { bit[i] += x; i += i & -i; }
	}
	void range_add(int a, int b, ll x) { //[a, b]
		app(bit0, a, -x * (a - 1));
		app(bit1, a, x);
		app(bit0, b + 1, x * b);
		app(bit1, b + 1, -x);
	}
	ll range_sum(int a, int b) { //[a, b]
		return (ga(bit1, b) * b + ga(bit0, b)) 
			- (ga(bit1, a - 1) * (a - 1) + ga(bit0, a - 1));
	}
	void add(int a, ll x) { range_add(a, a, x); }
	ll sum(int a) { return range_sum(1, a); }
	void show() {
		vector<ll> tmp;
		rep(i, 1, n + 1) tmp.push_back(range_sum(i, i));
		debug(tmp);
	}
};


int N, Q;
vector<int> A[26];
int B[MAX_N];
char str[MAX_N];
BIT bit;

void solve() {
		scanf("%s", str);
		N = strlen(str);

		rep(i, 0, N) {
			A[str[i] - 'a'].push_back(i);
		}
		int odd = 0;
		rep(i, 0, 26) {
			if((int)A[i].size() % 2 == 1) odd++;
		}
		if(odd >= 2) {
			printf("-1\n");
			return;
		}
		rep(i, 0, 26) {
			int n = (int)A[i].size();
			rep(j, 0, (n + 1) / 2) {
				B[A[i][j]] = A[i][n - j - 1];
			}
		}
		ll res = 0;
		bit.init(N);
		rep(i, 0, N) bit.range_add(i + 1, i + 1, i);
		int n = N;
		rep(i, 0, N) {
			if(bit.range_sum(i + 1, i + 1) == 0) {
				int j = B[i] + 1;
				res += n - bit.range_sum(j, j) - 1;
				if(i + 1 != j) {
					bit.range_add(1, j - 1, -1);
					bit.range_add(j, N, -2);
				}
				else {
					bit.range_add(j, N, -1);
				}
				bit.range_add(i + 1, i + 1, inf);
				bit.range_add(j, j, inf);
				n -= 2;
			}
		}
		printf("%lld\n", res);
		
}

int main() {
#ifndef LOCAL
	ios::sync_with_stdio(false);
    cin.tie(0);
#endif
    cout << fixed;
	cout.precision(20);
#ifdef LOCAL
    freopen("in.txt", "rt", stdin);
#endif	
	solve();
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}

