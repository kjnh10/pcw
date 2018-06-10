#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }


template<int MOD>
struct ModInt {
	static const int Mod = MOD;
	unsigned x;
	ModInt() : x(0) {}
	ModInt(signed sig) { int sigt = sig % MOD; if(sigt < 0) sigt += MOD; x = sigt; }
	ModInt(signed long long sig) { int sigt = sig % MOD; if(sigt < 0) sigt += MOD; x = sigt; }
	int get() const { return (int)x; }

	ModInt &operator+=(ModInt that) { if((x += that.x) >= MOD) x -= MOD; return *this; }
	ModInt &operator-=(ModInt that) { if((x += MOD - that.x) >= MOD) x -= MOD; return *this; }
	ModInt &operator*=(ModInt that) { x = (unsigned long long)x * that.x % MOD; return *this; }

	ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
	ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
	ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
};

typedef ModInt<1000000007> mint;

int main() {
	int N; int X; int Y; int Z;
	while(~scanf("%d%d%d%d", &N, &X, &Y, &Z)) {
		const int D = 10;
		int S = (1 << (X + Y + Z)) + 1;
		vector<vector<int>> nextst(S, vector<int>(D + 1, -1));
		int accept = 1 << (X + Y + Z);
		rep(s, 1 << (X + Y + Z)) if(s & 1) {
			rer(d, 1, 10) {
				int t = 1 << 0;
				rep(i, X + Y + Z) if(s >> i & 1) {
					int bound = i < X ? X : i < X + Y ? X + Y : X + Y + Z;
					if(i + d <= bound)
						t |= 1 << (i + d);
				}
				if(t >> (X + Y + Z) & 1)
					t = accept;
				nextst[s][d] = t;
			}
		}
		rer(d, 1, D)
			nextst[accept][d] = accept;
		vector<vector<mint>> dp(N + 1, vector<mint>(S));
		dp[0][1 << 0] = 1;
		rep(i, N) rep(s, S) {
			mint x = dp[i][s];
			if(x.x == 0) continue;
			rer(d, 1, D) {
				int t = nextst[s][d];
				dp[i + 1][t] += x;
			}
		}
		mint ans = dp[N][accept];
		printf("%d\n", ans.get());
	}
	return 0;
}
