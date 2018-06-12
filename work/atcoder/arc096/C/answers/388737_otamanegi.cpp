#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <algorithm>
#include <utility>
#include <functional>
#include <cstring>
#include <queue>
#include <stack>
#include <math.h>
#include <iterator>
#include <vector>
#include <string>
#include <set>
#include <math.h>
#include <iostream>
#include <map>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cassert>
#include<fstream>
#include <cstdlib>
#include <unordered_map>
using namespace std;
#define Ma_PI 3.141592653589793
#define eps 0.0000000001
#define LONG_INF 3000000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define SECOND_MOD 1000000009
#define REP(i,n) for(long long i = 0;i < n;++i)
#define seg_size 524288
using namespace std;
int main() {
	long long a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	long long ans = LONG_INF;
	for (long long i = 0; i <= max(x, y); ++i) {
		long long hoge = i*2LL * c + max(0LL, (x - i) * a) + max(0LL, (y - i) * b);
		ans = min(ans, hoge);
	}
	cout << ans << endl;
	return 0;
}