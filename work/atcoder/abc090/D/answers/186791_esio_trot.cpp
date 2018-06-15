#include <bits/stdc++.h>
using namespace std;

int main(){
	long long n,k,ans=0;
	cin>>n>>k;
	if(k==0){
		cout<<n*n;
		return 0;
	}
	for(int i=k+1;i<=n;i++){
		ans+=(i-k)*(n/i);
		if(n%i>=k) ans+=(n%i)-k+1;
	}
	cout<<ans;
	return 0;
}
