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
int out[114514],pat[114514];
string s;
string sw="SW";
int n;
int main()
{
	cin>>n;cin>>s;
	rep(i,n){
		if(s[i]=='o') pat[i]=0;else pat[i]=1;
	}
	pat[n]=pat[0];pat[n+1]=pat[1];
	rep(i,4){
		out[0]=i/2;out[1]=i%2;
		REP(j,1,n+1){
			out[j+1]=(pat[j]+out[j]+out[j-1])%2;
		}
		if(out[0]==out[n] && out[1]==out[n+1]){
			string ret="";
			rep(j,n) ret+=sw[out[j]];
			cout<<ret<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;
}
