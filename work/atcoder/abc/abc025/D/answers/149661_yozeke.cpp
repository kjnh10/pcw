#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#include<climits>
#include<string>
#include<set>
#include<map>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i = 0;i<((int)(n));i++)
#define reg(i,a,b) for(int i = ((int)(a));i<=((int)(b));i++)
#define irep(i,n) for(int i = ((int)(n)-1);i>=0;i--)
#define ireg(i,a,b) for(int i = ((int)(b)-1);i>=((int)(a));i--)
typedef long long int lli;
typedef pair<int, int> mp;
#define fir first
#define sec second
#define IINF INT_MAX
#define LINF LLONG_MAX
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#define pque(type) priority_queue<type,vector<type>,greater<type> >
#define memst(a,b) memset(a,b,sizeof(a))
#define MOD 1000000007
#define N25 33554431

bool a[25]; int b[26];

int f(lli i, int j){
	if(i == 0) return 1;
	
	int I = j/5, J = j%5;
	if((I!=0&&I!=4)&&(((i>>(j-5))&1)^((i>>(j+5))&1))) return 0;
	if((J!=0&&J!=4)&&(((i>>(j-1))&1)^((i>>(j+1))&1))) return 0;
	return 1;
}



int main(void){
	vector<int> dp(N25 + 1, 0); dp[0] = 1;
	rep(i, 25) {a[i] = true; b[i+1] = -1;}
	rep(i, 5) rep(j, 5){
		int td; scanf("%d", &td);
		if(td!=0){
			a[i*5+j] = false;
			b[td] = i*5+j;
		}
	}
	reg(i, 1, N25){
		int k = 0; rep(c, 25) if((i>>c)&1) k++;
		if(b[k]==-1){
			rep(j, 25) if(a[j]){
				if((i>>j)&1){
					dp[i]= (dp[i] + dp[i-(1<<j)]*f(i-(1<<j), j))%MOD;
				}
			}
		}else if(i&(1<<b[k])){
			dp[i] = dp[i-(1<<b[k])]*f(i-(1<<b[k]), b[k]);
		}
	}
	
	printf("%d\n", dp[N25]%MOD);
	
	return 0;
}