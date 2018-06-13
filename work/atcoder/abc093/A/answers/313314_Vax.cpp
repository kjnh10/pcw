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

int main()
{
	init_ios();
	char a[3];
	cin >> a[0] >> a[1] >> a[2];
	sort(a, a+3);
	if (a[0] == 'a' && a[1] == 'b' && a[2] == 'c')
		cout<<"Yes\n";
	else
		cout<<"No\n";
}