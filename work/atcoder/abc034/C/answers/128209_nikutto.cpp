#include<bits/stdc++.h>
using namespace std;

long long int extgcd(long long int a,long long int b,long long int& x,long long int& y){
	long long int d=a;
	if(b!=0){
		d=extgcd(b,a%b,y,x);
		y-=(a/b)*x;
	}
	else{
		x=1;y=0;
	}
	return d;
}

long long int mod_inverse(long long int a,long long int m){
	long long int x,y;
	extgcd(a,m,x,y);
	return (m+x%m)%m;
}



const long long int MOD=1e9+7;
int main(){
	long long int w;
	long long int h;
	cin>>w>>h;
	w--,h--;
	long long int facwh=1;
	for(int i=1;i<=w+h;i++){
		facwh*=i;
		facwh%=MOD;
	}
	long long int facw=1;
	for(int i=1;i<=w;i++){
		facw*=i;
		facw%=MOD;
	}
	long long int fach=1;
	for(int i=1;i<=h;i++){
		fach*=i;
		fach%=MOD;
	}
	long long int res=facwh*mod_inverse(facw,MOD);
	res%=MOD;
	res*=mod_inverse(fach,MOD);
	res%=MOD;
	cout<<res<<endl;
	return 0;
}
