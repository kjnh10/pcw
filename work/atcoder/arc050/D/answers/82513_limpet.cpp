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


inline LL calc(LL r, LL b, LL x, LL y, LL t){
	return t + min(r - x * t, (b - t) / y);
}

void mainmain(){
	LL r, b, x, y;
	cin >> r >> b >> x >> y;
	
	LL lt = 0, rt = min(r / x, b);
	while(lt + 10 < rt){
		LL t1 = (lt * 2 + rt) / 3;
		LL t2 = (lt + rt * 2) / 3;
		LL v1 = calc(r, b, x, y, t1);
		LL v2 = calc(r, b, x, y, t2);
		if(v1 < v2){
			lt = t1;
		}
		else{
			rt = t2;
		}
	}
	
	LL ans = 0;
	for(LL i = lt; i <= rt; ++i){
		LL v = calc(r, b, x, y, i);
		ans = max(ans, v);
	}
	cout << ans << endl;
}



}
int main() try{
//	ios::sync_with_stdio(false);
	cout << fixed << setprecision(10);
	cerr << fixed << setprecision(4);
	mainmain();
}
catch(...){}
