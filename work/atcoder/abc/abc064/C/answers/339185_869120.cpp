#include<bits/stdc++.h>
using namespace std;
int G[9],n,a,c;
int main(){
	cin>>n;for(int i=0;i<n;i++){cin>>a;G[min(8,a/400)]++;}
	for(int i=0;i<8;i++){if(G[i]>=1)c++;}
	if(c>=1)cout<<c<<endl<<c+G[8]<<endl;
	else cout<<1<<endl<<n<<endl;
	return 0;
}