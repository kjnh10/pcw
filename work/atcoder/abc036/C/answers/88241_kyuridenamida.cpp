#include <bits/stdc++.h>
using namespace std;

void solve(long long N, vector<long long> a){
	vector<long long> u = a;
	sort(u.begin(),u.end());
	u.erase(unique(u.begin(),u.end()),u.end());
	for(int i = 0 ; i < N ; i++){
		cout << lower_bound(u.begin(),u.end(),a[i]) - u.begin() << endl;
		
	}
}



int main(){	
	ios::sync_with_stdio(false);
	long long N;
	cin >> N;
	vector<long long> a(N-1+1);
	for(int i = 0 ; i <= N-1 ; i++){
		cin >> a[i];
	}
	solve(N, a);
	return 0;
}
