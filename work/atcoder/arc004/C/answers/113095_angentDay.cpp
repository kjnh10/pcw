#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
 
#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define ALL(c) (c).begin(), (c).end()
#define pi acos(-1.0)
 
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

int main(){
	ll x, y;
	scanf("%lld/%lld", &x, &y);
	ll d = __gcd(x,y);
	x /= d;
	y /= d;
	bool exist = false;
	for(ll n = x/y*2-10; n <= x/y*2+10; n++){
		if (n % y) continue;
		ll m = n*(n+1)/2 - n/y*x;
		if (m < 1 || m > n) continue;
		exist = true;
		cout << n << " " << m << endl;
	}
	if (!exist) cout << "Impossible" << endl;

	return 0;
}