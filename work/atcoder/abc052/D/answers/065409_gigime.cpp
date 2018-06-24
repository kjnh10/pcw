#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for(int i = (int) (l);i < (int) (r);i++)
#define ALL(x) x.begin(),x.end()
template<typename T> bool chmax(T& a,const T& b){ return a < b ? (a = b,true) : false; }
template<typename T> bool chmin(T& a,const T& b){ return b < a ? (a = b,true) : false; }
typedef long long ll;

int N;
ll A,B;

int main()
{
	scanf("%d%lld%lld",&N,&A,&B);
	vector<ll> X(N),diff(N - 1);
	FOR(i,0,N){
		scanf("%lld",&X [i]);
	}
	FOR(i,0,N - 1){
		diff [i] = X [i + 1] - X [i];
	}
	sort(ALL(diff),greater<ll>());

	ll sum = accumulate(ALL(diff),0ll) * A,ans = sum;
	FOR(i,0,N - 1){
		sum += B - diff [i] * A;
		chmin(ans,sum);
	}

	printf("%lld\n",ans);

	return 0;
}
