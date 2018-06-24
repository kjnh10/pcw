#include <bits/stdc++.h>
#define LL long long
#define pb push_back
#define mp make_pair
#define fi first
#define sc second
using namespace std;

int main() {
	string a,b,c="";
	int x=0,y=0;
	cin>>a>>b;
	while(true){
		if(x<a.size()) c+=a[x++];
		if(y<b.size()) c+=b[y++];
		if(x==a.size() && y==b.size()) break;
	}
	cout<<c<<endl;
	return 0;
}