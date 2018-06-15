/*
	Author: Hamza Hasbi
	Copyrights: "h.hamza" ==> "www.hamzahasbi.me"
	Date: 20/08/2017 12:55:17
*/
#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define ull unsigned long long
#define uld unsigned long double
#define ui unsigned int
#define ud unsigned double
#define uf unsigned float
#define pi 2*acos(0.0)
#define module cin.ignore()
#define rep(i,l,r) for(auto i=l;i<=r;i++)
#define range(x,y) for(auto x:y)
//inline long longlcm(ll a,ll b) {return a*b/__gcd(a,b);}
//inline long long gcd(ll a,ll b) {return 1LL*b == 0 ? a : gcd(1LL*b, a*1LL % b*1LL);}
using namespace std;

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s;
	cin>>s;
	map<char,bool>mp;
	for(auto c:s) mp[c]=true;
	for(char i='a';i<='z';i++) {
		if(!mp[i]){
			cout<<i<<endl;
			return 0;
		}
	}
	cout<<"None"<<endl;
	
	
	return 0;
}
