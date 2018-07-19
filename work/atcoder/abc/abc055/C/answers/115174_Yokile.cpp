#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <map>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

typedef long long ll;
ll n, m;

int main(){
	scanf("%lld%lld", &n, &m);
	ll sum = 0;
	if(n >= m / 2){
		printf("%lld\n", m / 2);
		return 0;
	}
	sum = n;
	m = m - 2 * n;
	sum += m / 4;
	printf("%lld\n", sum);
	return 0;
}
