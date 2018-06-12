#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)




typedef long long ll;
ll N, M;
//-----------------------------------------------------------------
int main() {
	cin >> N >> M;

	ll ans = 0;
	ans = min(N, M / 2);

	N -= ans;
	M -= ans * 2;

	ans += M / 4;

	cout << ans << endl;
}