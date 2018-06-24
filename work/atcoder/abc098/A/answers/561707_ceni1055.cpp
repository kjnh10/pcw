#include<bits/stdc++.h>
#include<assert.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b;
	cin >> a >> b;
	cout << max({a + b,a - b,a*b}) << endl;
	
	return 0;
}
