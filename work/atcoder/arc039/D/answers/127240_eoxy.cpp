#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>
#include <limits>
#include <climits>
#include <functional>
#include <numeric>

using namespace std;

#define alloc(type,n) (type*)calloc(sizeof(type),(n));
typedef long long lli;

#define N 501
#define MOD 1000000007

lli n,k;
lli exeuclid(lli a,lli aa,lli x,lli xx,lli y,lli yy){
	lli q;
	if(a == 0) return aa > 0 ? xx : -xx;
	q = aa / a;
	return exeuclid(aa - q * a,a,xx - q * x,x,yy - q * y,y);
}

lli invarse(lli x){
	return (exeuclid(MOD,x,0,1,1,0) + MOD) % MOD;
}


lli factrial(lli x){
	static lli dp[N];
	if(dp[x]) return dp[x];
	if(x == 0) 	return dp[x] = 1;
				return dp[x] = (factrial(x-1) * x) % MOD;
}

lli combination(lli n,lli k){
    return (((factrial(n) * invarse(factrial(k))) % MOD) * invarse(factrial(n-k))) % MOD;
}

lli lli_pow(lli a,lli n,lli mod){
	lli ret = 1;
	for(;n!=0;n=n>>1){
		if(n&1) ret = (ret * a) % mod;
		a = (a * a) % mod;
	}
	return ret;
}

lli euclid(lli a,lli b){
	if(a) return euclid(b%a,a);
	return b;
}

int main(){
    cin >> n >> k;
    if(k < n) cout << combination(n+k-1,k) << endl;
    else cout << combination(n,k%n)<< endl;

	return 0;
}
