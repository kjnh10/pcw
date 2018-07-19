#include <bits/stdc++.h>
#define LL long long
#define pb push_back
#define mp make_pair
#define fi first
#define sc second
using namespace std;


int main() {
	string s;
	int ans = 0;
	cin>>s;
	while(s.size()){
		s.pop_back();
		if(s.size()%2!=0) continue;
		string t;
		for(int i=0;i<s.size()/2;i++) t.pb(s[i]);
		if(t+t==s) ans = max(ans, (int)t.size()*2);
	}
	cout<<ans<<endl;
	return 0;
}