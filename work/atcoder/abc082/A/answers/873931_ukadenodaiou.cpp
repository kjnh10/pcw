# include <iostream>
# include <algorithm>
# include <vector>
# include <string>
# include <set>
# include <map>
# include <cmath>
# include <iomanip>
# include <functional>
# include <utility>
# include <stack>
# include <queue>
# include <list>
# include <bitset>
# include <complex>
#include<limits.h>
#include<unordered_map>
#include<unordered_set>
#include<deque>
#include<cstdio>
typedef long long int ll;
using namespace std;
#define FOR(i,a,n) for(int i=(ll)a;i<(ll)n;++i)
#define TFOR(i,n)FOR(i,0,n)
#define ALL(x) x.begin(),x.end()
const int INF = 1LL << 30;
const ll LLINF = 1LL << 60;	
int main() {
	int a, b, c, d, e;
	string s, ss, sss;
	cin >> a>>b;
	cout<<  (a+b)/2+((a+b)%2!=0?1:0) <<endl;
	return 0;
}