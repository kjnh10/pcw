#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdlib>
#include <cmath>
#include <string.h>
#include <memory.h>
#include <algorithm>
#include <iomanip>
#include <string>
#include <bitset>

#define F first
#define S second
#define MP make_pair

typedef long long ll;

using namespace std;

int const PI = acos(-1);
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

long long gcd(long long a, long long b) {
	return b == 0 ? a : gcd(b, a % b);
}

long long lcm(long long a, long long b) {
	return a * (b / gcd(a, b));
}

int const N = 101;
long long n, w;
long long dp[N][10000];
vector<pair<long long, long long> > a;

long long calc(int index, long long sum) {
  if(index == n) return 0;
  if(dp[index][int(sum % 10000)] != -1) return dp[index][int(sum % 10000)];
  
  long long res1 = 0, res2 = 0;
  if(sum >= a[index].first) res1 = calc(index + 1, sum - a[index].first) + a[index].second;
  res2 = calc(index + 1, sum);
  return dp[index][int(sum % 10000)] = max(res1, res2);
}

int main() {
	scanf("%d%d", &n, &w);
	a.resize(n);
	for(int i = 0; i < n; ++i)
	  scanf("%d%d", &a[i].first, &a[i].second);
	
	memset(dp, -1, sizeof dp);
	cout << calc(0, w) << endl;

  return 0;
}