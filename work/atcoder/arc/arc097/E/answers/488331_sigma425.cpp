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

struct BIT{
	using D = int;
	int N;
	vector<D> bit;
	BIT(int n){		//nは区間幅!!!
		N=n;
		bit.assign(n+1,0);
	}
	D sum(int i){		//i個の和a[0]+..a[i-1]
		D s=0;
		while(i>0){
			s+=bit[i];
			i-=(i&-i);
		}
		return s;
	}
	void add(int i,D x){	//a[i]+=x (0-indexed)
		i++;
		while(i<=N){
			bit[i]+=x;
			i+=(i&-i);
		}
	}
};


int N;
int dp[2001][2001];
int costi[2001][2001];	//(i,j) -> put i
int costj[2001][2001];	//(i,j) -> put j
int p[2][2000];

void input(){
	cin>>N;
	rep(i,N*2){
		char c;
		int a;
		cin>>c>>a;
		a--;
		p[(c=='B')][a] = i;
	}
}

int main(){
	input();
	rep(i,N+1){
		BIT bit(2*N);
		rep(k,i) bit.add(p[0][k],1);
		rep(j,N+1){
			if(i!=N){
				costi[i][j] = i+j - bit.sum(p[0][i]);
			}
			if(j!=N){
				costj[i][j] = i+j - bit.sum(p[1][j]);
			}
			if(j==N) continue;
			bit.add(p[1][j],1);
		}
	}
	rep(i,N+1) rep(j,N+1){
		int tmp = 1e9;
		if(i==0 && j==0) tmp = 0;
		if(i>0) chmin(tmp,dp[i-1][j]+costi[i-1][j]);
		if(j>0) chmin(tmp,dp[i][j-1]+costj[i][j-1]);
		dp[i][j] = tmp;
	}
	cout<<dp[N][N]<<endl;
}