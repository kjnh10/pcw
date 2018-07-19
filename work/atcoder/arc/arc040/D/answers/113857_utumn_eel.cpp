#include<bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;

int main(){
	int n,r;string s;cin>>n>>r>>s;
	int g;
	for(int i=s.size()-1;i>=0;i--){
		if(s[i]=='.'){
			g=max(0,i-r+1);break;
		}
	}
	int cnt=0,pos=0,a=count(s.begin(),s.end(),'.');
	rep(i,s.size()){
		if(s[i]=='.'){
			cnt++;
			rep(j,r){
				if(i+j<s.size()&&s[i+j]=='.'){
					a--;s[i+j]='o';
				}
			}
		}
		if(a==0)break;
		if(i==g&&s[i]!='.'){
			cnt++;break;
		}
		pos++;cnt++;

	}
	cout<<cnt<<endl;
}
