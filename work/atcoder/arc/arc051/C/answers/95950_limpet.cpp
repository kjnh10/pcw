#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <deque>
#include <complex>
#include <stack>
#include <queue>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <ctime>
#include <iterator>
#include <bitset>
#include <numeric>
#include <list>
#include <iomanip>
#include <cassert>

#if __cplusplus >= 201103L
#include <array>
#include <tuple>
#include <initializer_list>
#include <unordered_set>
#include <unordered_map>
#include <forward_list>

#define cauto const auto&
#define ALL(v) begin(v),end(v)
#else
#define ALL(v) (v).begin(),(v).end()
#endif

using namespace std;


namespace{
typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;

typedef vector<int> vint;
typedef vector<vector<int> > vvint;
typedef vector<long long> vll, vLL;
typedef vector<vector<long long> > vvll, vvLL;

#define VV(T) vector<vector< T > >

template <class T>
void initvv(vector<vector<T> > &v, int a, int b, const T &t = T()){
	v.assign(a, vector<T>(b, t));
}

template <class F, class T>
void convert(const F &f, T &t){
	stringstream ss;
	ss << f;
	ss >> t;
}


#define REP(i,n) for(int i=0;i<int(n);++i)
#define RALL(v) (v).rbegin(),(v).rend()


#define MOD 1000000007LL
#define EPS 1e-8

bool check(int dx, int dy, int r){
	return dx * dx + dy * dy <= r * r;
}

void mainmain(){
	int x1, y1, r, x2, y2, x3, y3;
	cin >> x1 >> y1 >> r >> x2 >> y2 >> x3 >> y3;
	
	if(x2 <= x1 - r && x1 + r <= x3 && y2 <= y1 - r && y1 + r <= y3){
		puts("NO");
	}
	else{
		puts("YES");
	}
	
	if(check(x2 - x1, y2 - y1, r) && check(x3 - x1, y2 - y1, r) &&
	   check(x2 - x1, y3 - y1, r) && check(x3 - x1, y3 - y1, r)){
		puts("NO");
	}
	else{
		puts("YES");
	}
}



}
int main() try{
//	ios::sync_with_stdio(false);
	cout << fixed << setprecision(10);
	cerr << fixed << setprecision(4);
	mainmain();
}
catch(...){}
