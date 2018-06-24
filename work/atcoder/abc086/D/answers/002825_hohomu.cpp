#include<bits/stdc++.h>
using namespace std;
#define FOR(i,s,e) for(int i = (s); i < (e); i++)
#define FOE(i,s,e) for(int i = (s); i <= (e); i++)
#define FOD(i,s,e) for(int i = (s); i >= (e); i--)
#define ll long long
#define pb push_back
#define mp make_pair

int n, m, x, y, z, k, w;
int A[4005][4005];

char s[2];

void add(int x, int y, int val)
{
//	printf("(%d, %d) = %d\n", x, y, val);
	A[x][y] += val;
}

int main ()
{
	scanf("%d %d", &n, &k);
	
	FOR(i, 0, n)
	{
		scanf("%d %d %s", &x, &y, s);
		
		if (s[0] == 'W') x += k;
		
		w = min(x / k, y / k);
		x -= w * k;
		y -= w * k;
		
		if (x > y)
		{
			w = x / (2 * k);
			x -= w * (2 * k);
		}
		else
		{
			w = y / (2 * k);
			y -= w * (2 * k);
		}
		
		add(x, y, 1);
		add(x, y + k, -1);
		add(x + k, y, -1);
		add(x + k, y + k, 1);
	}

	int ans = 0;
	
	FOE(i, 0, 3 * k) FOE(j, 0, 3 * k)
	{
		if (i > 0) A[i][j] += A[i - 1][j];
	}	
	FOE(i, 0, 3 * k) FOE(j, 0, 3 * k)
	{
		if (j > 0) A[i][j] += A[i][j - 1];
	}
	
	FOR(i, 0, 3 * k) FOR(j, 0, 3 * k)
	{
		x = i; y = j;
		if (i < k && j < 2 * k) continue;
		
		if (x >= 2 * k) x -= 2 * k;
		if (x >= k && y >= k) x -= k, y -= k;
		if (y >= 2 * k) y -= 2 * k;
		
		if (x >= k) x -= k, y += k;
		
		A[x][y] += A[i][j]; 
	}
	
	//FOD(i, k - 1, 0) { FOR(j, 0, 2 * k) printf("%d ", A[i][j]); printf("\n"); }
	
	FOR(i, 0, k) FOR(j, 0, 2 * k) ans = max(ans, A[i][j]);
	
	printf("%d\n", ans);
	return 0;
}
	
	
	