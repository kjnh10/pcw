#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, chk[200010], cnt;
ll a[200010], b[200010];
ll amn = 2e9, amx = -1, bmn = 2e9, bmx = -1, ans;
pii x[400010];

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%lld%lld", a + i, b + i);
		if(a[i] > b[i]) swap(a[i], b[i]);
		amn = min(amn, a[i]);
		bmn = min(bmn, b[i]);
		amx = max(amx, a[i]);
		bmx = max(bmx, b[i]);
	}
	ans = (amx - amn) * (bmx - bmn);
	for(int i = 1; i <= n; i++){
		x[2 * i - 1] = {a[i], i};
		x[2 * i] = {b[i], i};
	}
	sort(x + 1, x + 2 * n + 1);
    for(int i = 1, j = 1; i <= 2 * n; i++){
		for(; j <= 2 * n; j++){
			if(cnt == n) break;
			chk[x[j].second]++;
			if(chk[x[j].second] == 1) cnt++;
		}
		if(j > 2 * n && cnt < n) break;
		ans = min(ans, (bmx - amn) * (x[j - 1].first - x[i].first));
		chk[x[i].second]--;
		if(chk[x[i].second] == 0) cnt--;
    }
    printf("%lld\n", ans);
}
