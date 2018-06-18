#include"bits/stdc++.h"
using namespace std;
int main(){
	string a,b;
	cin>>a>>b;
	if(a.size()>b.size())
		cout<<"GREATER";
	else if(a.size()<b.size())
		cout<<"LESS";
	else{
	if(a>b)
		cout<<"GREATER";
	else if(a<b)
		cout<<"LESS";
	else
		cout<<"EQUAL";
}
}