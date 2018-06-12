#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define REYNA(i,a,b) for(int i=(a);i<(b);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long int ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, int> PLLI;
typedef pair <PLL, pair <int, ll> > PP;
typedef pair <PII, int> PPI;
typedef pair <int, PII> PIP;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const long long INF = 1e18+3;
const int maxn = 1e5 + 5;
string s;
int t[maxn];
int deg[maxn], n;
vector <int> v[maxn];
vector <int> ch[maxn];
int BEST = 0;

int UP[maxn], DOWN[maxn]; //DOWN to takie ktore licza dolny wierzcholek

inline int fun(int x)
{
	if (t[x]) return 1;
	return -1;
}

void DFS(int x, int par)
{
	bool leaf = 1;
	int downbest = 0, upbest = 0;
	for (auto u : ch[x])
		if (u != par)
		{
			DFS(u, x);
			leaf = 0;
			BEST = max(BEST, downbest + UP[u] + fun(x));
			BEST = max(BEST, upbest + DOWN[u] + fun(x));
			downbest = max(DOWN[u], downbest);
			upbest = max(UP[u], upbest);
		}

	if (leaf)
	{
		UP[x] = 1;
		DOWN[x] = 1 + fun(x);
	}
	else
	{
		UP[x] = 1; DOWN[x] = 1 + fun(x);
		for (auto u : ch[x])
		if (u != par)
		{
			UP[x] = max(UP[x], UP[u] + 1 + fun(x));
			DOWN[x] = max(DOWN[x], DOWN[u] + 1 + fun(x));
		}
	}
	
	BEST = max(BEST, UP[x] - 1);
	BEST = max(BEST, DOWN[x] - 1);
}

int main()
{
	boost;
	cin >> n;
	FOR(i, 2, n)
	{
		int a, b;
		cin >> a >> b;
		v[a].pb(b);
		v[b].pb(a);
		deg[a]++; deg[b]++;
	}
	
	cin >> s;
	int sum = 0;
	for (int i=0; i<n; ++i)
	{
		if (s[i] == 'W') t[i + 1] = 1;
		else t[i + 1] = 0;
		sum += t[i + 1];
	}
	
	if (!sum) OUT(0);
	if (sum == 1) OUT(1);
	//istnieje juz jakies sensowne drzewo
	queue <int> q;
	FOR(i, 1, n)
		if (deg[i] == 1 && !t[i]) q.push(i);

	int flag = n;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		flag--;
		deg[x] = 0;
		for (auto u : v[x])
		{
			if (deg[u] > 1) deg[u]--;
			if (deg[u] == 1 && !t[u]) q.push(u);
		}
	}
	int result = 2 * (flag - 1);
	FOR(i, 1, n)
	{
		if (deg[i] == 0) continue;
		t[i] ^= (deg[i] % 2);
		result += t[i];
	}

	FOR(i, 1, n)
	{
		UP[i] = DOWN[i] = -1;
		if (!deg[i]) continue;
		for (auto u : v[i])
			if (deg[u]) ch[i].pb(u);
	}
	
	FOR(i, 1, n)
		if (deg[i]) 
		{
			DFS(i, 0);
			break;
		}

	cout << result - BEST;
}
