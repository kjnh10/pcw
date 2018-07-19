#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <cassert>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
ll a,b,ret=1e18;
int main(){
	cin >> a >> b;
	if(a==b) ret=a+1;
	for(ll i=2;i<=1000000;i++){
		ll c = a;
		ll d = 0;
		while(c){
			d += c%i;
			c /= i;
		}
		if(d == b) ret = min(ret,i);
	}
	for(ll i=1;i<=1000000;i++){
		if(i > b) continue;
		// i*x + (b-i) == a && x > b-i
		ll c = b-i;
		if(a-c > 0 && (a-c)%i==0 && (a-c)/i > c && i<(a-c)/i) ret = min(ret,(a-c)/i);
	}
	if(ret > 1e17) puts("-1");
	else cout << ret << endl;
}