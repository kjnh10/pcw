#include<stdio.h>
#include<vector>
#include<cmath>
#include<algorithm>
#include<tuple>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> t3;

pii operator-(const pii &l, const pii &r){
	return pii(l.first - r.first, l.second - r.second);
}

int operator/(const pii &l, const pii &r){
	return l.first * r.second - l.second * r.first;
}

int sign(pii x){ return pii(0, 0) < x ? 1 : -1; }
double atan2(pii x){ return atan2(x.second, x.first); }

const int MX = 100005;
const int MM = 1000000007;

pii D[MX];
int N, M;

struct uf{
	int t[MX];
	int find(int x){ return t[x] ? t[x] = find(t[x]) : x; }
	int merge(int a, int b){
		a = find(a), b = find(b);
		return a == b ? 0 : (t[a] = b, 1);
	}
} uf;

int main()
{
	int N;
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d%d", &D[i].first, &D[i].second);
	int O[MX];
	for(int i = 1; i <= N; i++) O[i] = i;
	vector<t3> L;
	
	sort(O+1, O+N+1, [](int l, int r){ return D[l] < D[r]; });
	for(int i = 1; i < N; i++){
		L.emplace_back(D[O[i+1]].first - D[O[i]].first, O[i], O[i+1]);
	}

	sort(O+1, O+N+1, [](int l, int r){ return D[l].second != D[r].second ? D[l].second < D[r].second : D[l].first < D[r].first; });
	for(int i = 1; i < N; i++){
		L.emplace_back(D[O[i+1]].second - D[O[i]].second, O[i], O[i+1]);
	}
	sort(L.begin(), L.end());
	ll ans = 0;
	for(t3 e : L){
		int a, b, c;
		tie(a, b, c) = e;
		if( uf.merge(b, c) ) ans += a;
	}
	printf("%lld\n", ans);
}
