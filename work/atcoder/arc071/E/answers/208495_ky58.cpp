#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<ctime>
#include<queue>
#include<deque>
#include<complex>
#include<cassert>
using namespace std;
#define pb push_back
#define pf push_front
typedef long long lint;
typedef complex<double> P;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
int s1[100100],s2[100100];
int cal(char a){
	if(a=='A') return 1;return 2;
}
int main()
{
	string s,t;int a,b,c,d,q;
	cin>>s;cin>>t;
	s1[0]=0;s2[0]=0;
	rep(i,s.size()) s1[i+1]=s1[i]+cal(s[i]);
	rep(i,t.size()) s2[i+1]=s2[i]+cal(t[i]);
	cin>>q;
	rep(i,q){
		cin>>a>>b>>c>>d;
		int x=s1[b]-s1[a-1],y=s2[d]-s2[c-1];
		if(x%3==y%3) cout<<"YES"<<endl;else cout<<"NO"<<endl;
	}
}
