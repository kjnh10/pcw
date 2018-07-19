# include <iostream>
# include <algorithm>
# include <vector>
# include <string>
# include <set>
# include <map>
# include <cmath>
# include <iomanip>
# include <functional>
# include <tuple>
# include <utility>
# include <stack>
# include <queue>
# include <list>
# include <bitset>
# include <complex>
# include <chrono>
# include <random>
# include <limits.h>
# include <unordered_map>
# include <unordered_set>
# include <deque>
# include <cstdio>
# include <cstring>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
constexpr long long MOD = 1000000000 + 7;
constexpr long long INF = 1e17 - 10;
const double PI = acos(-1);
typedef pair<LL, LL> Pll;
LL n, m, x, flag = 0;
string st[2];
int main(){
	cin >> st[0] >> st[1];
	for (int i = 0; i < st[0].size(); i++)if (st[0][i] != st[1][st[0].size() - 1 - i])flag = 1;
	cout << (!flag?"YES":"NO")<< endl;
	return 0;
}