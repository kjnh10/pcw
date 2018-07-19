#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int pd[1100],num[1100];
int n;
const int mo=1e9+7;
int main(){
	scanf("%d",&n);
	for (int i=2;i<=n;i++)
		for (int j=i+i;j<=n;j+=i) pd[j]=1;
	int ans=1;
	for (int i=2;i<=n;i++)
		if (pd[i]==0){
			int tot=0;
			for (int j=i;j<=n;j*=i) tot+=n/j;
			ans=1ll*ans*(tot+1)%mo;
		}
	cout<<ans<<endl;
}