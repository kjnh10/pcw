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
using namespace std;
typedef long long int ll;
const int N = 1000000;
const ll INF = std::numeric_limits<long long>::max();
#define rep(i,n) for(ll i=(ll)0;i<(ll)n;++i)
#define ALL(x) x.begin(),x.end()
#define pp pair<ll,ll>
#define fi first
#define se second
#define sz size
string YN(bool b) { return(b ? "YES" : "NO"); }
string yn(bool b) { return(b ? "Yes" : "No"); }
ll a, b, c, d, e,ans=0;
string s, ss, sss;
vector<ll>v;
int main() {

	cin >>a>>b>>c ;

	cout<<  yn(a+b>=c) <<endl;

	return 0;
}