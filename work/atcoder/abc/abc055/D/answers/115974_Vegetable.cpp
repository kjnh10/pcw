#include <set>
#include <map>
#include <queue>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <bitset>
#include <vector>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pa;
typedef unsigned int uint;
typedef unsigned long long ull;
#define w1 first
#define ls (x<<1)
#define w2 second
#define ins insert
#define rs (x<<1|1) 
#define mp make_pair
#define pb push_back
#define mid ((l+r)>>1)
#define sqr(x) ((x)*(x))
#define cle(x) ((x).clear())
#define lowbit(x) ((x)&(-x))
#define SZ(x) (int((x).size()))
#define ms(x,y) memset(x,y,sizeof (x))
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define rep2(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define per(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
#define Rep(p,x) for(int (p)=head[(x)];(p);(p)=nxt[(p)])
#define Rep2(p,x) for(int (p)=cur[(x)];(p);(p)=nxt[(p)])
template<class T>inline void rread(T&num){
	num=0;T f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')num=num*10+ch-'0',ch=getchar();
	num*=f;
}
inline int getgcd(int x,int y){if(!x)return y;return getgcd(y%x,x);}
inline int power(int x,int k,int p){int res=1;for(;k;k>>=1,x=(ll)x*x%p)if(k&1)res=(ll)res*x%p;return res;}
const double pi=acos(-1);
inline void judge(){
	freopen("input.txt","r",stdin);
} 
//********************************head*************************************
const int maxn=1e5+5;
int n;
int a[maxn],b[maxn],c[maxn];
char str[maxn];
int main(){
	rread(n);
	scanf("%s",str+1);
	rep(i,1,n)
		if(str[i]=='o')a[i]=0;
		else a[i]=1;
	for(b[1]=0;b[1]<=1;b[1]++)
		for(b[2]=0;b[2]<=1;b[2]++){
			rep(i,1,n)c[i]=a[i];
			c[1]^=b[1];
			rep(i,2,n-1){
				c[i]^=b[i];
				b[i+1]=b[i-1]^c[i];
			}
			c[n]^=b[n];
			if((b[1]==(b[n-1]^c[n]))&&(b[n]==(b[2]^c[1]))){
				rep(i,1,n)if(!b[i])putchar('S');
				else putchar('W');
				puts("");
				return 0;
			}
		}
	puts("-1");
	return 0;
}