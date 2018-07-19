#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>
using namespace std;
long long a,b,c,d,e,ans;
int main(){
	ans=1111111111;
	cin>>a>>b>>c>>d>>e;
    ans=min(ans,a*d+b*e);
    ans=min(ans,max(d,e)*c*2);
    if(d>e){
    	ans=min(ans,e*c*2+(d-e)*a);
	}
	else ans=min(ans,d*c*2+(e-d)*b);
	cout<<ans<<endl;
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
    return 0;
}
