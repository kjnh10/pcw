#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <bitset>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#define mp make_pair
#define pb push_back
#define off 10000
using namespace std; 
typedef long long ll; 
bitset<off * 2 + 5> xx, yy; 
char str[off + 5]; 
int main()
{
	// freopen("ARC087-D.in", "r", stdin); 
	scanf("%s", str); 
	int n = strlen(str), cnt = 0; 
	bool f = false, fst = true;
	xx.set(off); 
	yy.set(off); 
	for (int i = 0; i <= n; i++)
	{
		if (str[i] == 'F')
			cnt++; 
		else
		{
			auto &t = f ? yy : xx; 
			if (fst)
				t <<= cnt; 
			else
				t = (t << cnt) | (t >> cnt); 
			fst = false; 
			cnt = 0; 
			f ^= 1; 
		}
	}
	int x, y; 
	scanf("%d%d", &x, &y); 
	if (x < -off || y < -off || x > off || y > off)
		puts("No"); 
	else
		puts(xx.test(x + off) && yy.test(y + off) ? "Yes" : "No"); 
	return 0; 
}
