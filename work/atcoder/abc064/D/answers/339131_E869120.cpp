#include<bits/stdc++.h>
using namespace std;
string S;int n,d,c;
int main(){
	cin>>n>>S;
	for(int i=0;i<S.size();i++){if(S[i]=='(')c++;else c--;d=min(d,c);}
	for(int i=0;i<-d;i++)cout<<"(";cout<<S;for(int i=0;i<c-d;i++)cout<<")";
	return 0;
}