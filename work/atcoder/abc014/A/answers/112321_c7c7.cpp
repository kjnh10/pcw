#include <bits/stdc++.h>
using namespace std;
#define r(i,a,n) for(int i=a;i<n;i++)
int main(){
	int a,b,c;
	cin>>a>>b;
	c=a%b;
	if(!c)cout<<0<<endl;
	else cout<<b-c<<endl;
}