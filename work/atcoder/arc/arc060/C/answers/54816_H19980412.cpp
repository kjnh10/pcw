#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <cassert>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
ll dp[55][55][2505];
int n,a,x[55];
int main(){
	cin >> n >> a;
	for(int i=1;i<=n;i++){
		cin >> x[i];
	}
	dp[0][0][0] = 1;
	for(int i=1;i<=n;i++){
		for(int q=n;q>=0;q--){
			for(int r=2500;r>=0;r--){
				dp[i][q][r] = dp[i-1][q][r];
				if(q && r>=x[i]){
					dp[i][q][r] += dp[i-1][q-1][r-x[i]];
				}
			}
		}
	}
	ll ret = 0;
	for(int i=1;i<=n;i++) ret += dp[n][i][i*a];
	cout << ret << endl;
}