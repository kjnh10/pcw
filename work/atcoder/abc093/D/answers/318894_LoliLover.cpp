#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>
#include <stack>
#include <queue>
#include <set>
#include <list>

using namespace std;

#define fi first
#define se second
#define long long long
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

long sqr(long x)
{
	long kir = 0, kan = 2e9;
	while(kir < kan)
	{
		long mid = (kir+kan+1)/2;
		if(mid*mid > x) kan = mid-1;
		else kir = mid;
	}
	return kir;
}

int main()
{
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("input.in", "r", stdin);
	int q; scanf("%d", &q);
	while(q--)
	{
		long a, b;
		scanf("%lld %lld", &a, &b);
		if(a == 1 && b == 1)
		{
			printf("0\n");
			continue;
		}
		long x = a*b-1;
		long sq = sqr(x);
		long res = 2*sq - ((long)(sq == x/sq));
		if(a == b) printf("%lld\n", res);
		else printf("%lld\n", res-1);
	}
}



