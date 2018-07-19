#include <bits/stdc++.h>
#define int long long
#define r(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef pair<int,int>P;
#define fi first
#define se second
#define all(a) a.begin(),a.end()
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
signed main(){
	int h,w;
	cin>>h>>w;
	string s[h];
	r(i,h)cin>>s[i];
	r(i,h)r(j,w)if(s[i][j]=='#'){
		int sum=0;
		r(k,4){
			int y=i+dy[k];
			int x=j+dx[k];
			if(y<0||x<0||y>=h||x>=w)continue;
			if(s[y][x]=='#')sum++;
		}
		if(!sum){
			cout<<"No"<<endl;
			return 0;
		}
	}
	cout<<"Yes"<<endl;
}