/* Author haleyk10198 */
/* 作者:  haleyk10198 */
/* CF handle: haleyk100198*/
/* FOR ACM-ICPC WF*/
#include <bits/stdc++.h>

#define MOD 1000000007
#define LINF (1LL<<60)
#define INF 2147483647
#define PI 3.1415926535897932384626433
#define ll long long
#define pii pair<int,int>
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back((x))
#define vi vector<int>
#define vvi vector<vi>
#define EPS 1e-9

using namespace std;

ll x, l, r;

int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false);
	
	l = 0, r = 31700;
	cin >> x;
	while(l+1 < r){
		ll mid = (l+r)/2;
		if(mid*mid > x)
			r = mid;
		else
			l = mid;
	}
	cout << l*l << endl;
	return 0;
}
