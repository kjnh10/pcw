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
#define MAX 100005
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
//	base();
	int x,y,arr[MAX];
	FOR(i,1,13){
		if (i==1 || i==3 || i==5 || i==7 || i==8 || i==10 || i==12) arr[i]=1;
		else if (i==4 || i==6 || i==9 || i==11) arr[i]=2;
		else arr[i]=3;
	}
	cin>>x>>y;
	if (arr[x]==arr[y]) cout<<"Yes\n";
	else cout<<"No\n";
	return 0;
}

