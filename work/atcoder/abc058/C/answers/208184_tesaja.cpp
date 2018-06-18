#include <bits/stdc++.h>
#define LL long long
#define pb push_back
#define mp make_pair
#define fi first
#define sc second
using namespace std;

int n,mn,cnt[55][30];
string s;

int main() {
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s;
		for(int j=0;j<s.size();j++) cnt[i][s[j]-'a']++;
	}
	s.clear();
	for(int i=0;i<26;i++){
		mn = 1e9;
		for(int j=0;j<n;j++){
			mn = min(mn, cnt[j][i]);
		}
		string ss="";
		for(int j=0;j<mn;j++){
			s.pb(char(i+'a'));
		}
		s += ss;
	}
	sort(s.begin(), s.end());
	cout<<s<<endl;
	return 0;
}