#include <bits/stdc++.h>
using namespace std;
#define r(i,a,n) for(int i=a;i<n;i++)
int dy[]={1,1,0,0,-1,-1};
int dx[]={1,0,1,-1,0,-1};
int a[200][200];
int main(){
	double a;
	long double s=0;
	cin>>a;
	r(i,1,a+1){
		s+=10000.0*i/a;
	}
	cout<<s<<endl;
}