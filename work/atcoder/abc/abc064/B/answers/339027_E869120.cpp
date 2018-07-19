#include<bits/stdc++.h>
using namespace std;
int n,a,p=1e9,q=-1e9;
int main(){
	cin>>n;for(int i=0;i<n;i++){cin>>a;p=min(p,a);q=max(q,a);}
	cout<<q-p<<endl;
	return 0;
}