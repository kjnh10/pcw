#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e6+5;
int tab[MAXN];
map <string,int> mp;

int main(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int n,m;
    string s;
    cin >> n;
    for(int i=0;i<n;i++){
		cin >> s;
		mp[s]++;
	}
	cin >> m;
	for(int i=0;i<m;i++){
		cin >> s;
		mp[s]--;
	}
	int res=0;
	for(auto i:mp)
		res=max(res,i.second);
	cout << res;
}
