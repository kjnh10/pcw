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
	string s;
	int K;
	cin>>s>>K;
	int N = s.size();
	vector<string> vec;
	rep1(len,K){
		rep(i,N+1-len){
			vec.pb(s.substr(i,len));
		}
	}
	sort(all(vec));
	vec.erase(unique(vec.begin(),vec.end()),vec.end());
	cout<<vec[K-1]<<endl;
}