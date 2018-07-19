#include <bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c,d,e,f;
	cin>>a>>b>>c>>d>>e>>f;
	if(e+f>=d)cout<<(a*e+b*f)-c*(e+f)<<endl;
	else cout<<(a*e+b*f)<<endl;
}