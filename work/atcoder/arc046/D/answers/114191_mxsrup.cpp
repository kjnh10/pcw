#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vint;
typedef pair<int,int> pint;
typedef vector<pint> vpint;
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define chmax(a, b) a = (((a)<(b)) ? (b) : (a))
#define chmin(a, b) a = (((a)>(b)) ? (b) : (a))
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll INFF = 1e18;

int main(void){
	int n, a, b; cin >> n >> a >> b;
	if(n <= a){
		printf("Takahashi\n");
	}else{
		if(a == b){
			// n = a + 1 なら必ず後手勝利. つまり, 先手が x を出したなら, 後手は a + 1 - x を出すようにすればいい.
			// 違うなら, 先手が上の状況を相手に与えられる.
			if(n % (a + 1) == 0) printf("Aoki\n");
			else printf("Takahashi\n");
		}else{
			// 多いほうが勝ち
			// 合計で a + 1 とるように選ぶのを 多いほうがやればいい.
			if(a > b) printf("Takahashi\n");
			else printf("Aoki\n");
		}
	}
	return 0;
}