#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:16777216")
#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
#include <cassert>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
#include <stack>
#include <deque>
#include <cmath>
#include <memory.h>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <utility>
#include <time.h>
#include <complex>
using namespace std;

#define FOR(i, a, b) for(int i=(a);i<(b);i++)
#define RFOR(i, b, a) for(int i=(b)-1;i>=(a);--i)
#define FILL(A,value) memset(A,value,sizeof(A))

#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair
#define Pi 3.14159265358979
#define x0 ikjnrmthklmnt
#define y0 lkrjhkltr
#define y1 ewrgrg

typedef long long Int;
typedef unsigned long long UInt;
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef pair<Int, Int> PLL;
typedef pair<double, double> PDD;
typedef complex<double> base;

const int INF = 1000000000;
const int BASE = 1000000007;
const int MAX = 10000007;
const int MAX2 = 7777;
const int MAXE = 100000;
const int ADD = 1000000;
const int MOD = 1000000007;
const int CNT = 800;

int p[MAX];

vector<int> g[107];
int M[107];
bool U[107];

bool dfs(int v) {
	if (U[v])  return 0;
	U[v] = 1;
	FOR(i,0,SZ(g[v]))
	{
		int to = g[v][i];
		if (M[to] == -1 || dfs(M[to])) {
			M[to] = v;
			return 1;
		}
	}
	return 0;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("distance.in",  "r", stdin);
    //freopen("distance.out", "w", stdout);
    //freopen("out.txt" , "w" , stdout);

	for(int i = 2; i * i < MAX; ++i)
		if (!p[i])
			for(int j = i * i; j < MAX; j += i)
				p[j] = 1;

	p[2] = 1;
	p[1] = 1;
	p[0] = 1;

	vector<int> V[2];

	int n;
	cin >> n;
	VI A(n);
	FOR(i,0,n)
	{
		cin >> A[i];
	}

	FOR(i,0,n)
	{
		if (i == 0 || A[i - 1] + 1 != A[i])
		{
			V[A[i] % 2].push_back(A[i]);
		}
		if (i == n - 1 || A[i] + 1 != A[i + 1])
		{
			V[(A[i] + 1) % 2].push_back(A[i] + 1);
		}
	}

	FOR(i,0,SZ(V[0]))
		FOR(j,0,SZ(V[1]))
		{
			if (!p[abs(V[0][i] - V[1][j])])
			{
				g[i].push_back(j);
			}
		}

	int r = 0;

	FILL(M,-1);
	FOR(i,0,SZ(V[0]))
	{
		FILL(U,0);
		r += dfs(i);
	}



	int res = SZ(V[0]) + SZ(V[1]) - r;

	if ((SZ(V[0]) - r) % 2 == 1) ++ res;

	cout << res << endl;

    return 0;
}



