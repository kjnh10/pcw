#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(I,A,B) for(ll I = (A); I < (B); ++I)
const ll INF=1e15+7;
const ll N = 1002;
ll a,b,c,ans=0,m,mn=0,m1=0;

int main(){
	cin>>a>>b>>c;
	m=max(a,b);
	m=max(m,c);

	ans+=(m-a)/2;
	if(m%2==a%2)a=m;
	else a=m-1;

	ans+=(m-b)/2;
	if(m%2==b%2)b=m;
	else b=m-1;

	ans+=(m-c)/2;
	if(m%2==c%2)c=m;
	else c=m-1;	

	if(a==b && c==b){
		cout<<ans<<endl;
		return 0;
	}
	if(a==m){
		mn++;
	}else{
		m1++;
	}
	if(b==m){
		mn++;
	}else{
		m1++;
	}
	if(c==m){
		mn++;
	}else{
		m1++;
	}
	if(mn==2){
		cout<<ans+2<<endl;
		return 0;
	}else{
		cout<<ans+1<<endl;
		return 0;
	}

	return 0;
}
