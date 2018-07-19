#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define RFOR(i,b,a) for (int i = (b)-1; i >= (a); --i)
#define ITER(it,a) for (__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define FILL(a,value) memset(a, value, sizeof(a))

#define SZ(a) (int)a.size()
#define ALL(a) a.begin(), a.end()
#define PB push_back
#define MP make_pair

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

const double PI = acos(-1.0);
const int INF = 1000 * 1000 * 1000 + 7;
const LL LINF = 1LL * INF * INF;

const int MAX = 1000;

int D[MAX][MAX];

int f(int x, int y)
{
	if (D[x][y] != -1) return D[x][y];

	if (x <= 1 && y <= 1) return D[x][y] = 0;

	FOR (i, 2, x+1)
	{
		if (i & 1) continue;
		if (f(x - i, y + i/2) == 0) return D[x][y] = 1;
	}

	FOR (i, 2, y+1)
	{
		if (i & 1) continue;
		if (f(x + i / 2, y - i) == 0) return D[x][y] = 1;
	}

	return D[x][y] = 0;

}

int main()
{
	//freopen("in.txt", "r", stdin);
	//ios::sync_with_stdio(false); cin.tie(0);

	LL x, y;
	cin>>x>>y;
	if (abs(x-y) <= 1)
	{
		cout<<"Brown"<<endl;
	}
	else
	{
		cout<<"Alice"<<endl;
	}
return 0;

	FILL(D, -1);

	FOR (i, 0, 100)
	{
		FOR (j, 0, 100)
		{
			cout<<f(i, j)<<' ';
		}
		cout<<endl;
	}

}
