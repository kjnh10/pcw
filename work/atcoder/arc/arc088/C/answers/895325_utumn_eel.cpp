#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define EPS (1e-10)
using namespace std;
typedef long long ll;
typedef pair<int,int>P;

signed main(){
	ll x,y;cin>>x>>y;
	int cnt=0;
	while(x<=y){
		cnt++;
		x*=2;
	}
	cout<<cnt<<endl;
}