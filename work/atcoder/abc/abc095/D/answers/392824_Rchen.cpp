#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
const int maxn = 1e5 + 10;
const ll oo = 0x3f3f3f3f3f3f3f3f;
class Point{
public:
	ll x;
	int v;
};
Point p[maxn];
int n;
ll C;
ll ans = 0;
bool cmp(Point p1 , Point p2){
	return p1.x < p2.x;
}

ll sum[maxn];
void solve(){
	sort(p + 1 , p + n + 1 , cmp);
	sum[0] = 0;
	ll cur = 0 , mx = 0;
	for(int i = 1 ; i <= n ; ++ i){
		cur += p[i].v - (p[i].x - p[i - 1].x);
		if(cur > mx) mx = cur;
		sum[i] = mx;
	}
	ans = max(ans , sum[n]);
	ll now = 0;
	for(int i = n ; i >= 1 ; -- i){
		now += p[i].v;
		ans = max(ans , sum[i - 1] - 2 * (C - p[i].x) + now);
	} 
}
int main(){
	ios::sync_with_stdio(0);
	cin >> n >> C;
	for(int i = 1 ; i <= n ; ++ i)
		cin >> p[i].x >> p[i].v;
	solve();
	for(int i = 1 ; i <= n ; ++ i)
		p[i].x = C - p[i].x;
	solve();
	cout << ans << endl;
	return 0;
}