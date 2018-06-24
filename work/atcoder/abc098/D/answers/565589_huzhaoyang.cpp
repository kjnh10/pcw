#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int s,a[200001];
bool fj(int k){
	if ((s^k)!=(s+k))return false;
	s^=k;
	return true;
}
int main(){
	int n,t;
	long long ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	int j=1;
	for(int i=1;i<=n;i++){
		while ((j<=n)&&(fj(a[j])))j++;
		ans=ans+j-i;
		s^=a[i];
	}
	printf("%lld",ans);
}