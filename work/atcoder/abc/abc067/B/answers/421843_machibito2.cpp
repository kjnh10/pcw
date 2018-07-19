#include <bits/stdc++.h>
using namespace std;

#define INF 1145141919

int main()
{
	int n,k,bou[50];
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
	{
		cin >> bou[i];
	}
	sort(bou,bou+n,greater<int>());
	int ans = 0;
	for (int i = 0; i < k; ++i)
	{
		ans += bou[i];
	}
	cout << ans << endl;
	return 0;
}