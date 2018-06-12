#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<deque>
#include<string>
#include<string.h>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<stdlib.h>
#include<cassert>
#include<time.h>
#include<bitset>
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;
const long long d2=(mod+1)/2;
const double EPS=1e-6;
const double PI=acos(-1.0);
int ABS(int a){return max(a,-a);}
long long ABS(long long a){return max(a,-a);}
char in[110];
int R[110];
int bl[110];
int used[110];
int lim[110];
int sz;
long long C[210][210];
long long fact[110];
long long inv[110];
long long finv[110];
int now[110];
 
long long dp[110][110][110];
long long calc(int x,int y,int a){
	for(int i=0;i<80;i++)for(int j=0;j<80;j++)for(int k=0;k<80;k++)dp[i][j][k]=0;
	dp[0][0][0]=1;
	int n=a-y-(x+y-1);
	for(int i=0;i<n;i++){
		for(int j=0;j<=x;j++){
			for(int k=0;k<=n;k++){
				if(!dp[i][j][k])continue;
				for(int l=0;j+l<=x&&k+l*(2*i+1)<=n;l++){
					if(l&&lim[x-l-j]<(k-j)/2+l*i)break;
					dp[i+1][j+l][k+l*(2*i+1)]=(dp[i][j][k]*C[j+l+y][l]+dp[i+1][j+l][k+l*(2*i+1)])%mod;
				}
			}
		}
	}
	long long ret=0;
	for(int i=0;i<=n;i++){
		ret=(ret+C[n+3*x+2*y][n-i]*dp[n][x][i])%mod;
	}
	//printf("%d %d %d: %lld\n",x,y,a,ret);
	return ret;
}
int main(){
	C[0][0]=1;
	for(int i=0;i<205;i++){
		for(int j=0;j<=i;j++){
			C[i+1][j]=(C[i+1][j]+C[i][j])%mod;
			C[i+1][j+1]=(C[i+1][j+1]+C[i][j])%mod;
		}
	}
	int a,b;scanf("%d%d",&a,&b);
	//n=a;
	fact[0]=finv[0]=inv[1]=1;
	for(int i=2;i<110;i++)inv[i]=(mod-(mod/i)*inv[mod%i]%mod)%mod;
	for(int i=1;i<110;i++){
		fact[i]=fact[i-1]*i%mod;
		finv[i]=finv[i-1]*inv[i]%mod;
	}
	scanf("%s",in);
	long long ret=0;
	for(int i=0;i<b;i++){
		if(in[i]=='r'){
			R[sz++]=i;
		}
	}
	for(int i=0;i<=sz;i++){
		for(int j=0;i+j<=sz;j++){
			for(int k=0;k<b;k++)used[k]=lim[k]=0;
			for(int k=0;k<i+j;k++)used[R[k]]=1;
			bool dame=false;
			for(int k=0;k<i;k++){
				bool ok=false;
				for(int l=R[k];l<b;l++){
					if(!used[l]&&in[l]=='b'){
						ok=true;used[l]=1;bl[k]=l;break;
					}
				}
				if(!ok){dame=true;break;}
			}
			if(dame)continue;
		//	printf("%d %d\n",i,j);
			for(int k=0;k<i;k++){
				for(int l=bl[k]+1;l<b;l++){
					if(!used[l])lim[k]++;
				}
			}
 
			ret=(ret+calc(i,j,a))%mod;
		}
	}
	printf("%lld\n",ret);
}