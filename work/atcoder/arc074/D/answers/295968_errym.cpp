#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

multiset<ll> hv;
ll l[300005], r[300005], v[300005], s, ans(-(1ll<<60));
int n;

int main()
{
	scanf("%d", &n);
	for (int i = 0;i < 3*n;i++) scanf("%lld", v+i);
	for (int i = 0;i < 3*n;i++)
	{
		hv.insert(v[i]); s += v[i];
		if (hv.size() > n) { s -= *hv.begin(); hv.erase(hv.begin()); }
		if (hv.size() == n)
			l[i] = s;
		else
			l[i] = -(1ll<<60);
	}
	s = 0; hv.clear();
	for (int i = 3*n-1;i >= 0;i--)
	{
		hv.insert(v[i]); s += v[i];
		if (hv.size() > n) { s -= *hv.rbegin(); hv.erase(--hv.end()); }
		if (hv.size() == n)
			r[i] = s;
		else
			r[i] = 1ll<<60;
	}
	for (int i = 1;i < 3*n;i++)
		ans = max(ans, l[i-1]-r[i]);
	printf("%lld\n", ans);
	return 0;
}
