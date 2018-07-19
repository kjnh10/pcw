#include <string.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <iomanip>

using namespace std;
#define INF 1e9
#define MAX 300005
#define MOD 1000000007
#define Q queue
#define PQ priority_queue
#define fr first
#define sc second
#define pb push_back
#define mp make_pair
#define FOR( i, L, U ) for(int i=(int)L ; i<(int)U ; i++ )
#define FORD( i, U, L ) for(int i=(int)U ; i>=(int)L ; i-- )
#define wa cout<<"Wa"<<endl
#define READ(filename)  freopen(filename, "r", stdin);
#define WRITE(filename)  freopen(filename, "w", stdout);

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int> > vvi;
typedef map<int, int> mii;
typedef map<string, int> msi;
typedef map<int, string> mis;
typedef map<int , vector<int> > mvi;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;

void base(){
	 ios_base::sync_with_stdio(false);
	 cin.tie(NULL);
}


int main(){
	base();
	int n,arr[MAX];
	vi v;
	cin>>n;
	FOR(i,1,n+1){
		cin>>arr[i];
	}
	if (n%2==0){
		for(int i=n;i>=1;i-=2){
			v.pb(arr[i]);
		}
		for(int i=1;i<=n;i+=2){
			v.pb(arr[i]);
		}
	}else {
		for(int i=n; i>=1; i-=2){
			v.pb(arr[i]);
		}
		for(int i=2;i<=n;i+=2){
			v.pb(arr[i]);
		}
	}
	bool flag = false;
	FOR(i,0,v.size()){
		if (flag) cout<<" ";
		flag = true;
		cout<<v[i];
	}
	return 0;
}

