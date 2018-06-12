
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <cstring>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <array>
#include <cassert>
#include <bitset>
using namespace std;
using LL = long long;

LL N;
LL Y;

int main(void)
{
	cin >> N >> Y;
	for (int i = 0; i <= N; ++i) {
		for (int j = 0; j <= N - i; ++j) {
			int k = N - i - j;
			if (i * 1000 + j * 5000 + k * 10000 == Y) {
				cout << k << " " << j << " " << i << endl;
				return 0;
			}
		}
	}
	cout << "-1 -1 -1\n";
	return 0;
}
