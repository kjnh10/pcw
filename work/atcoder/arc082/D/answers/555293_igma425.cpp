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
	vector<bool> ok(N+1,false);
	rep(i,N){
		int x;
		cin>>x;
		x--;
		ok[i] = (x!=i);
	}
	int ans = 0;
	rep(i,N) if(!ok[i]){
		ans++;
		ok[i] = 1;
		ok[i+1] = 1;
	}
	cout<<ans<<endl;
}