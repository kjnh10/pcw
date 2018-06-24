#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define RREP(i,a,b) for(int i=(a);i>=(b);i--)
#define pq priotity_queue
#define P pair<int,int>
#define P2 pair<int,P>
#define P3 pair<int,P2>
typedef long long ll; typedef long double ld;
using namespace std;
const int INF=1e9, MOD=1e9+7, around[]={0,1,1,-1,-1,0,-1,1,0,0};
const ld PI=abs(acos(-1));
int n,a,b,v[2010];

int main(){
	cin >> n >> a >> b;
	REP(i,0,n) cin >> v[i];
	
	cout << max(abs(b-v[n-1]), abs((n==1?0:v[n-1]-v[n-2]))) << endl;
	return 0;
}
