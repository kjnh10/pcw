#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main()
{
	int n;
	cin >> n;
	LL a, b, pr;
	LL ans;
	for(int i = 1; i <= n; i++)
	{
		cin >> a >> b;
		pr = a * b;
		LL t = sqrt(pr);
		if(t * (t + 1) < pr)
			ans = t * 2 - 1;
		else if(t * t == pr)
		{
			if(a == b)
				ans = (t - 1) * 2;
			else
				ans = (t - 1) * 2 - 1;
		}
		else
			ans = (t - 1) * 2;
		cout << ans << endl;
	}
	return 0;
}