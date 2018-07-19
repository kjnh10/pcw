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
int n,m;
int a[100005];
int main()
{
	cin >> n >> m;
	set<int>S;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		S.insert(a[i]);
	}
	int M = 0,ans = 0;
	for(int i=1;i<n;i++){
		S.erase(S.find(a[i]));
		set<int>::iterator it = S.end(); it--;
		if(M < (*it)-a[i]){
			M = (*it)-a[i]; ans = 1;
		}
		else if(M == (*it)-a[i]) ans++;
	}
	cout << ans << endl;
}