#include<iostream>
#include<algorithm>
#include <string>
#include<cstdio>
#include<math.h>
#include<stack>
#include<cstring>
#include<vector>
#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define EREP(i,n) for(int i=(n-1);i>=0;--i)
#define D(n,retu) REP(i,n){cin>>retu[i];}
#define mod 1000000007
#define MIN -93193111451418101
using namespace std;
typedef long long int ll;
template<typename T>
void fill_all(T& arr, const T& v) {
	arr = v;
}
template<typename T, typename ARR>
void fill_all(ARR& arr, const T& v) {
	for (auto& i : arr) { fill_all(i, v); }
}

//------------------変数-----------------------//
ll n, cost[30],m,a[100001],k,d;
vector<vector<ll>> v(39);
//-------------------関数----------------------//


int main() {
	cin >> n;
	cout << "ABC" << n << endl;


	return 0;
}