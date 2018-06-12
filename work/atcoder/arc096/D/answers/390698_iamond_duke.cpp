#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <cmath>
#include <set>
#include <map>
#define my_abs(x) ((x) < 0 ? -(x) : (x))
#define mp std::make_pair
#define pb push_back
typedef long long ll; 
ll dis[100005], val[100005], mx[100005], mx2[100005]; 
int main()
{
	// freopen("ARC096-D.in", "r", stdin); 
	int n;
	ll c; 
	scanf("%d%lld", &n, &c); 
	for (int i = 0; i < n; i++)
		scanf("%lld%lld", dis + i, val + i); 
	ll sum = 0, ans = 0; 
	for (int i = 0; i < n; i++)
	{
		if (i)
		{
			mx[i] = mx[i - 1]; 
			mx2[i] = mx2[i - 1]; 
		}
		sum += val[i]; 
		mx[i] = std::max(mx[i], sum - dis[i]); 
		mx2[i] = std::max(mx2[i], sum - dis[i] * 2); 
		ans = std::max(ans, mx[i]); 
	}
	sum = 0; 
	for (int i = n - 1; i >= 0; i--)
	{
		sum += val[i]; 
		ans = std::max(ans, sum - (c - dis[i])); 
		if (i)
		{
			ans = std::max(ans, sum - (c - dis[i]) * 2 + mx[i - 1]); 
			ans = std::max(ans, sum - (c - dis[i]) + mx2[i - 1]); 
		}
	}
	printf("%lld\n", ans);
	return 0; 
}
