#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define show(x) cout << #x << " = " << x << endl
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;
int main(){
	int N;
	cin>>N;
	int px=0,py=0,pt=0;
	rep(i,N){
		int x,y,t;
		cin>>t>>x>>y;
		int d = abs(x-px) + abs(y-py);
		int dt = t-pt;
		if(dt<d || (dt-d)%2==1){
			puts("No");
			return 0;
		}
	}
	puts("Yes");
}