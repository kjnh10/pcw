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
lint cal(lint n,lint b){
	lint ret=0;
	while(n>0){
		ret+=n%b;n/=b;
	}
	return ret;
}
int main()
{
	lint b=2,n,s;
	cin>>n;cin>>s;
	if(n==s){
		cout<<n+1<<endl;return 0;
	}
	if(n<s){
		cout<<-1<<endl;return 0;
	}
	for(;b*b<=n;b++){
		if(cal(n,b)==s){
			cout<<b<<endl;return 0;
		}
	}
	b=1145141919810893LL;
	for(lint c=1;c*c<=n-s;c++){
		if((n-s)%c>0) continue;
		if(cal(n,(n-s)/c+1)==s) b=min(b,(n-s)/c+1);
		if(cal(n,c+1)==s) b=min(b,c+1);
	}
	if(b>=1145141919810893LL){
		cout<<-1<<endl;return 0;
	}
	cout<<b<<endl;
}
