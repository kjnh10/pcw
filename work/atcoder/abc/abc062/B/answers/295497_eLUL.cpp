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
#define MAX 105
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


	int n,m;
	char arr[MAX][MAX];
int main(){
//	base();
	cin>>n>>m;
	FOR(i,1,n+1){
		FOR(j,1,m+1){
			cin>>arr[i][j];
		}
	}
	
	FOR(i,0,n+2){
		FOR(j,0,m+2){
			if (i==0 || j==0 || i==n+1 || j==m+1) cout<<"#";
			else cout<<arr[i][j];
		}
		cout<<endl;
	}
	
	return 0;
}

