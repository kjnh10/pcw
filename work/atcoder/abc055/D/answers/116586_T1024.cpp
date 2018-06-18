#include <cmath>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

#define MAXN 100111

bool solve(int ans[], int a[], int n)
{
	for(int i=2; i<=n+1; ++i)
	{
		if(ans[i-1] == 1)
			ans[i] = a[i-1] ? ans[i-2] : 1-ans[i-2];
		else
			ans[i] = (1-a[i-1]) ? ans[i-2] : 1-ans[i-2];
	}

	return ans[0] == ans[n] && ans[1] == ans[n+1];
}

int main()
{
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	string s;
	cin >> s;
	int a[MAXN];
	for(int i=0; i<n; ++i)
		a[i] = s[i] == 'o' ? 1 : 0;
	a[n] = a[0];
	a[n+1] = a[1];

	int ans[MAXN];
	for(int i=0; i<4; ++i)
	{
		ans[0] = i/2;
		ans[1] = i%2;
		if(solve(ans, a, n))
		{
			for(int j=0; j<n; ++j)
				cout << (ans[j] ? 'S' : 'W');
			cout << "\n";
			return 0;
		}
	}

	cout << "-1\n";
	return 0;
}
