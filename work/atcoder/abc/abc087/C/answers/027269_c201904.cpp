#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>
using namespace std;
int n;
long long a[100005]={0},b[100005]={0}; 
int main(){
	scanf("%d",&n);
	int x;
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		a[i]=a[i-1]+x; 
	} 
	long long ans=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		b[i]=b[i-1]+x;
	}
	for(int i=1;i<=n;i++){
		ans=max(ans,a[i]+(b[n]-b[i-1]));
	}
	cout<<ans;
    return 0;
}
