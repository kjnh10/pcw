#include <stdio.h>
#include <iostream>
#include <vector>
#include <assert.h>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <string>
#include <sstream>
#include <memory.h>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
typedef long long ll;
int n, v[500000];
ll calc(bool neg) {
	ll cur = 0;
	ll cost = 0;
	for (int i = 0; i < n; ++i) {
		cur += v[i];
		if (neg) {
			if (cur >= 0) {
				ll need = cur + 1;
				cost += need;
				cur = -1;
			}
		}else {
			if (cur <= 0) {
				ll need = 1 - cur;
				cost += need;
				cur = 1;
			}
		}
		neg = !neg;
	}
	return cost;
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &v[i]);
	printf("%lld\n", min(calc(0), calc(1)));
	return 0;
}