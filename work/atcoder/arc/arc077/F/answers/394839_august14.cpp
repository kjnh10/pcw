#include <stdio.h>
#include <algorithm>
using namespace std;

char S[202020];
int F[202020], L;
long long x[100], y[100], cntx[100][26], cnty[100][26], ans[26];

void go(int p, long long l, long long r)
{
	if (r <= L){
		while (l < r){
			ans[S[l]-'a']++;
			l++;
		}
		return;
	}

	long long w = 0;
	for (int k=0;;k++){
		long long a = (k%3==1?y[p]:x[p]);
		long long u = max(l, w);
		long long v = min(r, w+a);
		if (r <= w) break;
		if (v - u == a){
			if (k % 3 == 1) for (int k=0;k<26;k++) ans[k] += cnty[p][k];
			else for (int k=0;k<26;k++) ans[k] += cntx[p][k];
		}
		else if (u < v) go(p-1, u-w, v-w);
		w += a;
	}
}

int main()
{
	scanf("%s", S);

	int l = 0;
	while (S[l]) l++;
	L = l;

	int k = -1; F[0] = -1;
	for (int i=1;i<l;i++){
		while (k >= 0 && S[k+1] != S[i]) k = F[k];
		if (S[k+1] == S[i]) k++;
		F[i] = k;
	}

	int u = l-1;
	while ((u + 1) >= (l + 1) / 2) u = F[u];
	int r = l - (u + 1) * 2;

	const long long lim = (long long)1e18 + 10;
	int v = u+r;
	while ((v + 1) > (u + r + 1) / 2) v = F[v];
	for (int i=0;i<=v;i++) cntx[0][S[i]-'a']++;
	for (int i=v+1;i<=u+r-v-1;i++) cnty[0][S[i]-'a']++;
	x[0] = v + 1;
	y[0] = u+r-v-1 - v;

	int p = 1;
	while (1){
		for (int k=0;k<26;k++){
			cntx[p][k] = cntx[p-1][k] + cnty[p-1][k];
			cnty[p][k] = cntx[p-1][k];
		}
		x[p] = x[p-1] + y[p-1];
		y[p] = x[p-1];
		if (x[p] > lim) break;
		p++;
	}
	{
		long long l, r;
		scanf("%lld %lld", &l, &r);
		go(p, l-1, r);
	}
	for (int i=0;i<26;i++) printf("%lld%c", ans[i], i+1<26?' ':'\n');

	return 0;
}