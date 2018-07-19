#include <bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c,s=0,o=0,q;
	cin>>a>>b>>c;
	for(int i=0;i<a;i++){
		cin>>q;
		s+=q;
		if(b<=s&&s<=c)o++;
	}
	cout<<o<<endl;
}