//Daniel Grzegorzewski
#include <bits/stdc++.h>

#define MP make_pair
#define PB push_back
#define ST first
#define ND second

using namespace std;

typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VII;
typedef long long LL;

void init_ios()
{
     ios_base::sync_with_stdio(0);
     cin.tie(0);
}

int a, b, k;
VI v;

int main()
{
	init_ios();
	cin >> a >> b >> k;
	for (int i = a; i < min(b+1, a+k); ++i)
		v.PB(i);
	for (int i = max(a, b-k+1); i <= b; ++i)
		v.PB(i);
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); ++i)
		if (i == 0 || v[i] != v[i-1])
			cout<<v[i]<<"\n";
}