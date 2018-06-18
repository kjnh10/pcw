#include <iostream>
using namespace std;

int a[100010];

int main () {

int n;
cin>>n;
int cet=0,dva=0;
for (int i=0; i<n; i++) {
	cin>>a[i];
	if (a[i]%4==0) {cet++;}
	else if (a[i]%2==0) {dva++;}
}
if (cet+(dva/2)>=(n/2)) {cout<<"Yes";} else {cout<<"No";}

return 0;
}