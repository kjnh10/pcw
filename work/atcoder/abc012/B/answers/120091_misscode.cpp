#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <utility>
#include <stack>
#include <queue>
#include <sstream>
#include <fstream>
#include <float.h>
#include <cmath>
#include <cstring>

using namespace std;
#define int long long
signed main() {
	int N;
	cin >> N;
	int a, b, c;
	a = N / 3600;
	b = (N - a*3600) / 60;
	c = N - (a*3600)-(b*60);
	printf("%02lld:%02lld:%02lld\n", a,b,c);
	return 0;
}