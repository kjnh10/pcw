#include<iostream>
#include<iomanip>
#include<algorithm>
#include<array>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<functional>
#include<limits>
#include<list>
#include<map>
#include<numeric>
#include<set>
#include<stack>
#include<string>
#include<sstream>
#include<queue>
#include<vector>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

#define dump(o) { cerr << #o << " " << o << endl; }
#define dumpc(o) { cerr << #o; for (auto &e : (o)) cerr << " " << e; cerr << endl; }
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL

int main() {
	int A, B, C; cin >> A >> B >> C;
	if (A*B*C == 5 * 5 * 7)cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}