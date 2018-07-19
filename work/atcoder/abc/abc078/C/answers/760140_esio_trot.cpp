#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,m,a;
	cin>>n>>m;
	a=(n-m)*100+m*1900;
	for(int i=0;i<m;i++) a*=2;
	cout<<a;
	return 0;
}
