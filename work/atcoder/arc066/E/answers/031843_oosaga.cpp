#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;

lint n, a[100005], dp[100005];
lint sum[100005];
int nxt[100005];
string s[100005];

lint getsum(int ss, int e){
	return sum[e] - sum[ss-1];
}

lint getcost(int x){
	lint ret = 0;
	int w = nxt[x];
	return -getsum(x, w-1) + getsum(w, n);
}

int main(){
	scanf("%lld %lld",&n, &a[1]);
	sum[1] = a[1];
	for(int i=2; i<=n; i++){
		cin >> s[i] >> a[i];
		sum[i] = sum[i-1] + a[i];
	}
	nxt[n+1] = n+1;
	for(int i=n; i>=2; i--){
		if(s[i] == "+"){
			nxt[i] = nxt[i+1];
			dp[i] = dp[i+1] + a[i];
		}
		else{
			nxt[i] = i;
			dp[i] = max(dp[i+1] - a[i], getcost(i+1) - a[i]);
		}
	}
	cout << dp[2] + a[1] << endl;
}

