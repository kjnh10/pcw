#include<bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;

ll E[100001], G[100001];
int c1[100000], c2[100000], a[100000], b[100000];
int main() {
	int r, c, k, n; scanf("%d%d%d%d", &r, &c, &k, &n);
	rep(i, n) {
		scanf("%d%d", &a[i], &b[i]); a[i]--; b[i]--;
		c1[a[i]]++; c2[b[i]]++;
	}
	rep(i, r)E[c1[i]]++;
	rep(i, c)G[c2[i]]++;
	ll cnt = 0;
	for (int i = 0; i <= k; i++)cnt += E[i] * G[k - i];
	rep(i, n) {
		if (c1[a[i]] + c2[b[i]] == k)cnt--;
		if (c1[a[i]] + c2[b[i]] == k + 1)cnt++;
	}
	printf("%lld\n", cnt);
}