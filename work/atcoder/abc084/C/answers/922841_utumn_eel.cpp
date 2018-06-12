#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define EPS (1e-10)
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int,int>P;

int c[500],s[500],f[500];
signed main(){
	int n;scanf("%d",&n);
	rep(i,n-1)scanf("%d%d%d",&c[i],&s[i],&f[i]);
	rep(i,n){
		int p=i,tim=0;
		while(p!=n-1){
			tim=max(s[p],(tim/f[p]+!!(tim%f[p]))*f[p])+c[p];
			p++;
		}
		cout<<tim<<endl;
	}
}