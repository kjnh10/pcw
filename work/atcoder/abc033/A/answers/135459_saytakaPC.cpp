#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define REP(i,n) for (int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define ALL(a) (a).begin(),(a).end()
int INF=1e9;
int MOD=1e9+7;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
double EPS = 1e-10;
const int mod=1e9+7;
const double pai=3.14159265358979;
int main(){
	string s;
	cin>>s;
	char t=s[0];
	bool ans=true;
	REP(i,s.size())if(t!=s[i])ans=false;
	if(ans)cout<<"SAME"<<endl;
	else cout<<"DIFFERENT"<<endl;
}
