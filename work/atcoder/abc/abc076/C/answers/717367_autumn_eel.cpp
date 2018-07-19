#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
#define MOD 1000000007
#define EPS (1e-10)
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int>P;

int main(){
	string s,t;cin>>s>>t;
	string Min(100000,'z');
	rep(i,s.size()-t.size()+1){
		bool flag=true;
		string k=s;
		for(int j=0;j<t.size();j++){
			if(k[i+j]!='?'&&t[j]!=k[i+j]){
				flag=false;
			}
			else k[i+j]=t[j];
		}
		for(char&c:k){
			if(c=='?')c='a';
		}
		if(flag)Min=min(Min,k);
	}
	if(Min.size()==100000)puts("UNRESTORABLE");
	else cout<<Min<<endl;
}
