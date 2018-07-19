#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a,b,c,d;
int main()
{
	cin>>a>>b>>c>>d;
	if(a+b>c+d)
		cout<<"Left\n";
	else
	if(a+b<c+d)
		cout<<"Right\n";
	else
		cout<<"Balanced\n";
}