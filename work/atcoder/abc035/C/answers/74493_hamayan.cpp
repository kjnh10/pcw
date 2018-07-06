#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)

int main()
{
	int N, Q;
	cin >> N >> Q;

	vector<int> imos(N + 1, 0);
	rep(i, 0, Q)
	{
		int l, r;
		cin >> l >> r;
		imos[l-1]++;
		imos[r]--;
	}
	rep(i, 1, N) imos[i] += imos[i - 1];
	rep(i, 0, N)
	{
		if (imos[i] % 2 == 0)
			imos[i] = 0;
		else
			imos[i] = 1;
	}
	rep(i, 0, N) cout << imos[i];
	cout << endl;
}