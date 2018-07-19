#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define RREP(i,a,b) for(int i=(a);i>=(b);i--)
#define pq priotity_queue
typedef long long ll; typedef long double ld;
using namespace std;
const int INF=1e9, MOD=1e9+7, around[]={0,1,1,-1,-1,0,-1,1,0,0};
const ld PI=abs(acos(-1)); 
int n,m,a,b,c,d;
string s,w;

int main(){
	cin >> s;
	cin >> w;
	
	if(s[0]==w[2] and s[1]==w[1] and s[2]==w[0]) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}
