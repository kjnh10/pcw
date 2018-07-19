#include"bits/stdc++.h"
using namespace std;
int main(){
	string s;
	cin>>s;
	while(true){
		s.erase(s.size()-1);
		if(!(s.size()&1) && s.substr(0,s.size()/2)==s.substr(s.size()/2))
			break;
	}
	cout<<s.size();
}