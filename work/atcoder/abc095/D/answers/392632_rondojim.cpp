#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 5;
typedef long long ll;

ll xL[MAXN], xR[MAXN], C, preL[MAXN], preR[MAXN], mxL[MAXN], mxR[MAXN];
int vL[MAXN], vR[MAXN], N;

int main(){
	scanf("%d %lld", &N, &C);
	for(int i=1; i<=N; ++i){
		scanf("%lld %d", &xL[i], &vL[i]);
		xR[N - i + 1] = C - xL[i];
		vR[N - i + 1] = vL[i];
	}
	for(int i=1; i<=N; ++i) preL[i] = preL[i - 1] - xL[i] + xL[i - 1] + vL[i];
	for(int i=1; i<=N; ++i) preR[i] = preR[i - 1] - xR[i] + xR[i - 1] + vR[i];
	for(int i=1; i<=N; ++i) mxR[i] = max(mxR[i - 1], preR[i]);
	for(int i=1; i<=N; ++i) mxL[i] = max(mxL[i - 1], preL[i]);
	ll best = 0;
	for(int L=0; L<=N; ++L){
		ll cur = preL[L];
		if(cur > best) best = cur;
		cur = cur - xL[L] + mxR[N - L];
		if(cur > best) best = cur;
	}
	for(int R=0; R<=N; ++R){
		ll cur = preR[R];
		if(cur > best) best = cur;
		cur = cur - xR[R] + mxL[N - R];
		if(cur > best) best = cur;
	}
	printf("%lld\n", best);
	return 0;
}