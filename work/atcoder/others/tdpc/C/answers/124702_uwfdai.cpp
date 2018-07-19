#include <bits/stdc++.h>
#define REP(i,n,N) for(int i=n;i<N;i++)
#define p(S) cout<<S<<endl
using namespace std;
int R[1024];
double dp[1024][11];
double rate(int RQ,int RP){
	return 1.0/(1+pow(10,(RP-RQ)/400.0));
}

int main(){
	int K;
	cin>>K;
	int n=1<<K;
	REP(i,0,n){
		cin>>R[i];
		dp[i][0]=1;
	}
	for(int j=0;j<K;j++){
		for(int i=0;i<n;i++){
			double p=0;
			for(int l=0;l<(1<<j);l++){
				int idx=((i^1<<j)&~((1<<j)-1))+l;
				p+=dp[idx][j]*rate(R[i],R[idx]);
			}
			dp[i][j+1]=p*dp[i][j];
		}
	}
	REP(i,0,n) printf("%.9lf\n",dp[i][K]);
	return 0;
}
