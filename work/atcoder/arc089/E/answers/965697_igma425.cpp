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
int A,B;
int d[11][11];
const int T = 100;

int c[T+1][T+1];

int main(){
	cin>>A>>B;
	rep1(x,A) rep1(y,B) cin>>d[x][y];
	rep(i,T+1) rep(j,T+1){
		int cij = 0;
		rep1(x,A) rep1(y,B) chmax(cij,d[x][y]-x*i-y*j);
		c[i][j] = cij;
	}

	rep1(x,A) rep1(y,B){
		int dxy = 1e9;
		rep(i,T+1) rep(j,T+1) chmin(dxy,x*i+y*j+c[i][j]);
		if(dxy != d[x][y]){
			puts("Impossible");
			return 0;
		}
	}
	puts("Possible");
	int N = (T+1)*2, M = T*2 + (T+1)*(T+1);
	cout<<N<<" "<<M<<endl;
	rep(t,T){
		cout<<1+t<<" "<<2+t<<" X"<<endl;
	}
	rep(t,T){
		cout<<T+3+t<<" "<<T+2+t<<" Y"<<endl;
	}
	rep(i,T+1) rep(j,T+1){
		cout<<1+i<<" "<<T+2+j<<" "<<c[i][j]<<endl;
	}
	cout<<1<<" "<<T+2<<endl;
}
