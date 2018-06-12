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
	const int X = 100000;
	int cnt[X]={};
	rep(i,N){
		int x;
		cin>>x;
		cnt[x]++;
	}
	int ans = 0;
	rep(i,X-2){
		int tmp = cnt[i]+cnt[i+1]+cnt[i+2];
		ans = max(ans,tmp);
	}
	cout<<ans<<endl;
}