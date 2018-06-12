#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
const int mod = 1e9 + 7;
typedef pair<lint, lint> pi;

lint d;
lint p[20];
int dx1[20], dx2[20];
vector<lint> v;

void dfs(int s, int e, vector<pi> &w, lint val, lint cnt){
	if(s == e){
		w.push_back(pi(val, cnt));
		return;
	}
	for(int i=-9; i<=9; i++){
		dfs(s+1, e, w, val + i * v[s], cnt * (s == 0 ? dx2[i + 10] : dx1[i + 10]));
	}
}

lint solve(int l){
	v.clear();
	for(int i=0; l-1-i > i; i++){
		v.push_back(p[l-1-i] - p[i]);
	}
	vector<pi> v1, v2;
	dfs(0, (v.size() + 1) / 2, v1, 0, 1);
	dfs((v.size() + 1) / 2, v.size(), v2, 0, 1);
	lint ans = 0;
	map<lint, lint> mp;
	for(auto &i : v2) mp[i.first] += i.second;
	for(auto &i : v1){
		ans += mp[i.first + d] * i.second;
	}	
	if(l % 2 == 1) ans *= 10;
	return ans;
}

int main(){
	p[0] = 1;
	for(int i=1; i<20; i++) p[i] = p[i-1] * 10;
	for(int i=0; i<10; i++){
		for(int j=0; j<10; j++){
			dx1[i-j+10]++;
		}
	}
	for(int i=1; i<10; i++){
		for(int j=0; j<10; j++){
			dx2[i-j+10]++;
		}
	}
	cin >> d;
	lint ans = 0;
	for(int i=2; i<=18; i++) ans += solve(i);
	cout << ans << endl;
}
