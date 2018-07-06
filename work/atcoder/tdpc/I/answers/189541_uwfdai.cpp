#include <bits/stdc++.h>
#define REP(i,n,N) for(int i=n;i<N;i++)
#define p(S) cout<<(S)<<endl
using namespace std;

int main(){
	string s;
	cin>>s;
	int n=s.size();
	int dp[310][310]={};
	for(int k=2;k<n;k++){
		for(int i=0;i+k<n;i++){
			if(dp[i+1][i+k-1]==(k+1)/3-1){
				bool flag=false;
				if(s[i]=='i'&&s[i+k]=='i'){
					int cnt=0;
					REP(t,i+1,i+k) if(s[t]=='w') cnt++;
					if(cnt==(k+1)/3) flag=true;
				}
				dp[i][i+k]=dp[i+1][i+k-1]+flag;
			}
			for(int j=i;j<i+k;j++)
				dp[i][i+k]=max(dp[i][i+k],dp[i][j]+dp[j+1][i+k]);
		}
	}
	p(dp[0][n-1]);
	return 0;
}