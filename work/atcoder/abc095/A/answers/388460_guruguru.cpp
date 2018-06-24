#include <vector> 
#include <list> 
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <queue>
#include <complex>
using namespace std;

//conversion
//------------------------------------------
inline int toInt(string s) { int v; istringstream sin(s); sin >> v; return v; }
template<class T> inline string toString(T x) { ostringstream sout; sout << x; return sout.str(); }

//math
//-------------------------------------------
template<class T> inline T sqr(T x) { return x * x; }

//typedef
//------------------------------------------
typedef vector<int> VI;

typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;
typedef vector<LL> VLL;

//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(t,c) for(typeof((c).begin()) t=(c).begin(); t!=(c).end(); ++t)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())

//repetition
//------------------------------------------
#define FOR(t,a,b) for(int t=(a);t<(b);++t)
#define REP(t,n)  FOR(t,0,n)

//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI = acos(-1.0);

//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))

//debug
#define dump(x)  cerr << #x << '=' << (x) << endl;
#define debug(x) cerr << #x << '=' << (x) << '('<<'L' << __LINE__ << ')' << ' ' << __FILE__ << endl;



const LL mod = 1000000007;

LL gcd(LL a, LL b) { if (a%b == 0) { return b; } else return gcd(b, a%b); }
LL lcm(LL a, LL b) { return a / gcd(a, b)*b; }

#define Yes_ cout<<"Yes"<<endl; return 0;
#define No_ cout<<"No"<<endl; return 0;


#define YES_ cout<<"YES"<<endl; return 0;
#define NO_ cout<<"NO"<<endl; return 0;

#define POSSIBLE cout<<"POSSIBLE"<<endl; return 0;
#define IMPOSSIBLE cout<<"IMPOSSIBLE"<<endl; return 0;




int main() {
	
	int a, b, c;
	string s;
	cin >> s;
	int num = count(ALL(s), 'o');
	cout << 700 + num * 100 << endl;




}
