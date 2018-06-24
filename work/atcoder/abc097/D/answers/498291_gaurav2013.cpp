#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef vector <int> vi;
typedef pair< int ,int > pii;
typedef istringstream iss;
typedef ostringstream oss;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define sz size()
#define ln length()
#define rep(i,n) for(int i=0;i<n;i++)
#define fu(i,a,n) for(int i=a;i<=n;i++)
#define fd(i,n,a) for(int i=n;i>=a;i--)
#define all(a)  a.begin(),a.end() 
#define ESP (1e-9)

const int md = 100100 ; 
int n , m, s[200100] , a , b   ;
vector < int> g[200100] , ans ;
map < int ,int> ms;
bool vis[200100] ;  
void dfs ( int x ){
	  ans.pb ( x ) ; 
	  vis[x] = 1;
	  for ( auto p : g[x] ){
	  	  if ( !vis[p] )  dfs ( p ) ; 
	  }
}
int main () {
	// freopen ("in.in" , "r" , stdin ) ; 
	cin >> n >> m ;
	fu ( i , 1, n)  cin >> s[i] ; 
	while ( m--){
		  cin >> a >> b ;
		  g[a].pb ( b ) ; 
		  g[b].pb ( a) ;
	}
	int cnt = 1, res = 0 ; 
	fu ( i , 1,n ){
		  if ( vis[i] == 0 ){
		  	  ms.clear (); 
			  ans.clear () ; 
		  	  dfs ( i ) ;
			  rep ( j , ans.size () ){
			     ms[ s[ans[j] ] ] = 1 ; 	
			  }
			  rep( j , ans.size () ){
			  	  if ( ms[ans[j]] == 1  )  ++res; 
			  } 
		  }
	}
	cout << res ; 
	return 0; 
}