#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define MOD                 1000000007LL
#define EPS                 1e-9
#define io                  ios_base::sync_with_stdio(false);cin.tie(NULL);

const int MAXN = 1e5+5;

int main(){
	io;
	ll x, y;
	cin >> x >> y;
	ll ans = 0;
	ll curr = x;
	while(curr <= y){
		ans++;
		curr = curr*2;
	}
	cout << ans << endl;
	return 0;
}