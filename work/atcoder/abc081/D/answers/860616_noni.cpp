#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <numeric>
#include <iostream>

using namespace std;

#define FOR(i, a, b)   for(int i = (a); i < (b); ++i)
#define RFOR(i, a, b)  for(int i = (a); i > (b); --i)
#define rep(i, n)      for(int i = 0; i < (n); ++i)
#define all(c)         begin(c), end(c)
#define rall(c)        rbegin(c), rend(c)
#define SZ(a)          ((ll) a.size())

typedef long long ll;
typedef unsigned long long ull;


int main(){
	ll N;
	cin >> N;
	vector<ll> a(N);
	rep(i,N) cin >> a[i];
	ll mi = a[0];
	ll mi_index = 0;
	rep(i,N){
		if(a[i]<mi){
			mi = a[i];
			mi_index=i;
		}
	}
	ll ma = a[0];
	ll ma_index = 0;
	rep(i,N){
		if(a[i]>ma){
			ma = a[i];
			ma_index=i;
		}
	}
	printf("%lld\n",2*N-2);
	if(abs(mi)>abs(ma)){
		rep(i,N){
			if(i!=mi_index) printf("%lld %lld\n",mi_index+1,i+1);
		}
		rep(i,N-1){
			printf("%lld %lld\n",N-i,N-i-1);
		}
	}
	else{
		rep(i,N){
			if(i!=ma_index) printf("%lld %lld\n",ma_index+1,i+1);
		}
		rep(i,N-1){
			printf("%lld %lld\n",i+1,i+2);
		}
	}

  return 0;
}
