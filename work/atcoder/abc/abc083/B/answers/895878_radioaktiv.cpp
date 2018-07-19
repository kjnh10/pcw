#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define MOD                 1000000007LL
#define EPS                 1e-9
#define io                  ios_base::sync_with_stdio(false);cin.tie(NULL);

const int MAXN = 1e5+5;

int SOD(int n){
	int ans = 0;
	while(n){
		ans += (n%10);
		n /= 10;
	}
	return ans;
}

int main(){
	io;
	int n, a, b;
	cin >> n >> a >> b;
	ll ans = 0;
	for(int i = 1;i <= n; i++){
		if(SOD(i) >= a && SOD(i) <= b)
			ans += i;
	}
	cout << ans << endl;
	return 0;
}