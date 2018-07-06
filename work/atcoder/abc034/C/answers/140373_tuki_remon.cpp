#include<iostream>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define rep(i,a) loop(i,0,a)
using namespace std;
typedef long long ll;

const ll mod=1e9+7;

ll pow(ll a,ll b){
	if(b==0)return 1;
	if(b%2==0)return (pow((a*a)%mod,b/2)%mod);
	else return a*(pow(a,b-1)%mod)%mod;
}

ll exc(ll n){
	if(n==1)return 1;
	return n*(exc(n-1)%mod)%mod;
}

ll combi(ll n,ll r){
	return (exc(n)*(pow((exc(r)*exc(n-r)%mod),mod-2)%mod))%mod;
}

int main(){
	int w,h;
	cin>>w>>h;
	w--;h--;
	cout<<combi(w+h,h)<<endl;
	return 0;
}