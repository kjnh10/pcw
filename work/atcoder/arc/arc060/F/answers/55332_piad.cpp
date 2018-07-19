#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

const int N=501000;
char s[N];
int n,nxt[N],acyc[N];
int main() {
	scanf("%s",s);
	n=strlen(s);
	nxt[0]=-1;
	int k=-1;
	rep(i,1,n) {
		while (k>=0&&s[k+1]!=s[i]) k=nxt[k];
		if (s[k+1]==s[i]) ++k;
		nxt[i]=k;
	}
	int prd=n-nxt[n-1]-1;
	if (prd==1) {
		printf("%d\n",n);
		puts("1");
	} else if (prd==n||n%prd!=0) printf("1\n1\n");
	else {
		rep(i,0,n-1) {
			acyc[i]=(nxt[i]==-1)||((i+1)%(i-nxt[i])!=0);
		}
		rep(i,0,n) nxt[i]=0; reverse(s,s+n);
		nxt[0]=-1;
		int k=-1;
		rep(i,1,n) {
			while (k>=0&&s[k+1]!=s[i]) k=nxt[k];
			if (s[k+1]==s[i]) ++k;
			nxt[i]=k;
		}
		int ret=0;
		rep(i,0,n-1) if ((nxt[i]==-1||(i+1)%(i-nxt[i])!=0)&&acyc[n-i-2]) ++ret;
		printf("2\n%d\n",ret);
	}
}
