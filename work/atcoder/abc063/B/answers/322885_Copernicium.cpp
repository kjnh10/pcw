#include"bits/stdc++.h"
using namespace std;
int main(){
	string x;
	cin>>x;
	map<char,int> y;
	for(auto i:x)
		++y[i];
	bool ch=false;
	for(auto i:y)
		if(i.second>1)
			ch=true;
	cout<<(ch ? "no":"yes");
}