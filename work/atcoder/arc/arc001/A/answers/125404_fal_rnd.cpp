#include "bits/stdc++.h"
 
using namespace std;
 
const char en = '\n';
using  ll =          long long;
using ull = unsigned long long;
 
#define REP(i  ,n) for(int i=0;i<n;i++)
#define FOR(i,s,g) for(int i=s;i<g;i++)
 
const ll INFL = 810000001919114514;
const int INF =         1919114514;
 
int main(){
	ios::sync_with_stdio(false);cin.tie();
	
	int n,MIN=INF,MAX=-INF,ar[4]{0};
	char c;
 
	cin>>n;
	REP(i,n){
		cin>>c;
		ar[c-'1']++;
	}
	REP(i,4){
		MIN=min(MIN,ar[i]);
		MAX=max(MAX,ar[i]);
	}
	cout<<MAX<<' '<<MIN<<en;
 
	return 0;
}
