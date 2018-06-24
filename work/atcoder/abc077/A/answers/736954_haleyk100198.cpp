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

string str[2];

int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false);
	
	cin >> str[0] >> str[1];
	if(str[0][0] == str[1][2] && str[0][1] == str[1][1] && str[0][2] == str[1][0])
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}
