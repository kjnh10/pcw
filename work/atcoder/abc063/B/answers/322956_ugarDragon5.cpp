#include"bits/stdc++.h"
using namespace std;
bool f[26];
int main(){
	string str;
	cin>>str;
	for(int i=0;i<str.length();i++){
		if(f[str[i]-'a']){
			cout<<"no"<<endl;
			return 0;
		}
		f[str[i]-'a']=true;
	}
	cout<<"yes"<<endl;
	return 0;
}