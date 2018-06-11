#include<bits/stdc++.h>
using namespace std;

long long int gcd(long long int x,long long int y){
	if(y==0) return x;
	return gcd(y,x%y);
}
const double EPS=1e-10;
int main(){
	long long int x,y;
	cin>>x;
	cin.ignore();
	cin>>y;
	long long int g=gcd(x,y);
	x/=g,y/=g;
	long long  xy=2*x/y;
	long long int kouho[3]={xy-1,xy,xy+1};
	vector<pair<long long int,long long int>> res;
	for(int i=0;i<3;i++){
		if(kouho[i]%y!=0) continue;
		long long int m=kouho[i]*(kouho[i]+1)/2-kouho[i]/y*x;
		if(m<=0 || kouho[i]<m) continue;
		if(kouho[i]<=0) continue;
		long long int lef;
		g=gcd(m*y,kouho[i]);
		if(kouho[i]/g>2) continue;
		if(kouho[i]/g==2){
			if(((kouho[i]+1)*y)%2==0) continue;
			lef=(kouho[i]+1)*y/2-m*y/kouho[i];
		}
		if(kouho[i]/g==1){
			if(((kouho[i]+1)*y)%2==1) continue;
			lef=(kouho[i]+1)*y/2-m*y/kouho[i];
		}
		if(lef-x==0){
			res.emplace_back(kouho[i],m);
		}
	}
	if(res.size()==0){
		cout<<"Impossible"<<endl;
		return 0;
	}
	else{
		for(int i=0;i<res.size();i++){
			cout<<res[i].first<<" "<<res[i].second<<endl;
		}
	}
	return 0;

}
