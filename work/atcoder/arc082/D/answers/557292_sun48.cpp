#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n;
	cin >> n;
	int a[n];
	vector<int> f;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		a[i]--;
		if(a[i] == i) f.push_back(i);
	}
	int s = 0;
	int ans = 0;
	while(s < f.size()){
		if(s + 1 == f.size()){
			ans++;
			break;
		}
		if(f[s] + 1 == f[s+1]){
			ans ++;
			s += 2;
		} else {
			ans++;
			s += 1;
		}
	}
	cout << ans << endl;
}
