#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
int x[26];
int main(){
	string s; cin >> s;
	for(int i=0;i<s.size();i++) x[s[i]-'a']++;
	int S = 0,N = 0;
	for(int i=0;i<26;i++){
		if(x[i]%2 == 0) S+=x[i]/2;
		else {N++; S+=(x[i]-1)/2; }
	}
	if(N == 0){
		cout << s.size() << endl;
	}
	else{
		cout << S/N*2+1 << endl;
	}
}