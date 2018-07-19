#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int a,b;
	cin>>a>>b;
	int ans=max({a+b,a-b,a*b});
	cout<<ans<<endl;
}
