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
 
/**FACEPALM INTENSIFIES**/

int vis[50][100010];
int n;

ll f(ll x){
	int ret = 0;
	while(x)
		ret += x%10, x /= 10;
	return ret;
}

void dfs(int rem, int dist){
	if(dist > 45) return;
	if(vis[dist][rem]) return;
	vis[dist][rem] = 1;
	for(int i = 0; i < 10; i++)
		dfs((rem*10+i)%n, dist+i);
}

int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false);
	
	cin >> n;
	for(int i = 1; i < 10; i++)
		dfs(i, i);
	
	for(int i = 1; i <= 45; i++)
		if(vis[i][0]){
			cout << i << endl;
			return 0;
		}
	return 0;
}	