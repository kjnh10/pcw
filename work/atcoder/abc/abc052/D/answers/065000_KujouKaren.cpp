#include<cmath>
#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
int n,A,B,x[110000];
int main(){
	scanf("%d%d%d",&n,&A,&B);
	for (int i=1;i<=n;i++) scanf("%d",&x[i]);
	long long ans=0;
	for (int i=1;i<n;i++)
		ans+=min(1ll*(x[i+1]-x[i])*A,1ll*B);
	cout<<ans<<endl;
}