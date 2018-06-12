#include<bits/stdc++.h>

using namespace std;

#define mp make_pair
#define F first
#define S second
#define pb push_back
#define fo(i, n) for(int i = 1; i <= n; ++i)

typedef long long ll;
typedef pair<int, int> pii;

const int N = 200200;
const int mod = 1e9 + 7;
int n, a[N];
vector<int> bad, good, other;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	fo(i, n)
	{
		cin >> a[i];
		if(a[i] % 2)
			bad.pb(a[i]);
		else if(a[i] % 4 == 0)
			good.pb(a[i]);
		else 
			other.pb(a[i]);
	}
	if(bad.size() > good.size() + 1)
		return cout << "No", 0;
	if(bad.size() == good.size() + 1 && other.size())
		return cout << "No", 0;
	cout << "Yes";
	return 0;
}