#include "bits/stdc++.h"
using namespace std;

using  ll =          long long;
using ull = unsigned long long;
const char en = '\n';
const ll INFL = 810000001919114514;
const int INF =         1919114514;

#define REP(i  ,n) for(int i=0;i<n;i++)
#define FOR(i,s,g) for(int i=s;i<g;i++)


int main(){
	ios::sync_with_stdio(false);cin.tie();

	ll s,c,result=0;
	cin>>s>>c;
	
	result+=min(s,c/2);

	c-=result*2;
	result+=c/4;

	cout<<result<<en;
	return 0;
}
