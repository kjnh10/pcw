#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)

int main()
{
	string D;
	cin >> D;

	int ans = 0;

	rep(i, 0, D.length())
	{
		if ('0' <= D[i] && D[i] <= '9') ans = ans * 10 + D[i] - '0';
	}

	cout << ans << endl;
}