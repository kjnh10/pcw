#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint ungigned
#define db double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pli pair<ll,int>
#define vi vector<int>
#define vpi vector<pii >
#define IT iterator

#define PB push_back
#define MK make_pair
#define LB lower_bound
#define UB upper_bound
#define BG begin
#define ED end

#define For(i,j,k) for (int i=(j);i<=(int)k;i++)
#define Rep(i,j,k) for (int i=(j);i>=(int)k;i++)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));

#define LS3 k*2,l,mid
#define RS3 k*2+1,mid+1,r
#define LS5 k*2,l,mid,x,y
#define RS5 k*2+1,mid+1,r,x,y
#define GET pushdown(k);int mid=(l+r)/2
using namespace std;

int S(ll i){
	int s=0;
	for (;i;s+=i%10,i/=10);
	return s;
}
const int N=100005;
ll q[N];
double v[N];
int main(){
	ll val1=1;
	int top=0;
	for (int i=1;i<=15;i++,val1*=10)
		for (int j=1;j<=999;j++)
			q[++top]=j*val1+val1-1;
	sort(q+1,q+top+1);
	top=unique(q+1,q+top+1)-q-1;
	v[top+1]=1e18;
	for (int i=top;i;i--){
		v[i]=1.0*q[i]/S(q[i]);
		if (v[i]>v[i+1]) q[i]=0;
		v[i]=min(v[i],v[i+1]);
	}
	int k;
	scanf("%d",&k);
	for (int i=1;k;i++)
		if (q[i]) printf("%lld\n",q[i]),k--; 
}