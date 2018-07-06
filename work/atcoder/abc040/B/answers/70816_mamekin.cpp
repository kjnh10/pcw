#define _USE_MATH_DEFINES
#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <complex>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <limits>
#include <climits>
#include <cfloat>
#include <functional>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int ans = INT_MAX;
	for(int y=1; y<=n; ++y){
		int x = n / y;
		ans = min(ans, abs(y - x) + (n - y * x));
	}
	cout << ans << endl;

	return 0;
}