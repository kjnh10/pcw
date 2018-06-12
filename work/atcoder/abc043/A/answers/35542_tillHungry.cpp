#include <vector>
#include <list>
#include <map>
#include <set>
#include "queue"
#include <deque>
#include <stack>
#include <numeric>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <climits>
#include <cassert>
#include <iostream>
#define MOD1 1000000007

inline void inp( long long int  &n ){n=0;int ch=getchar();int sign=1;while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar();}while( ch >= '0' && ch <= '9' )n = (n<<3)+(n<<1) + ch-'0', ch=getchar();n=n*sign;}
#define pi acos(-1)
#define pii pair<int,int>
#define vii vector<pii>
#define ll  long long int
#define loop(i,n) for(ll i=0;i<n;i++)
#define ll  long long int
#define LL long long int
#define loop2(i,n) for(ll i=1;i<=n;i++)
#define MIN(a,b) (a) < (b) ? (a) : (b)
#define MAX(a,b) (a) > (b) ? (a) : (b)
#define ABS(a) (a) > 0 ? (a) : -(a)
#define rep1(i,a,n) for(i=a;i<(n);i++)
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define OUT_RT cerr << (float(clock()) / CLOCKS_PER_SEC) << endl
#define EPS 1e-9
#define ld long double
using namespace std;
//JAI SHREE KRISHNA
// Find the holy grail in an  adventure frought with danger
// The bigger the occasion, the better the response.
// Never giving in, fighting to the end
// Look at  the limits
// Check if it is binary search
// Code till the end of contest
#define Long                    long long
#define Ulong                   unsigned long long
#define forn(i,n)               for( int i=0 ; i < n ; i++ )
#define mp(i,j)                 make_pair(i,j)
#define pb(a)                   push_back((a))
#define all(x)                  (x).begin(),(x).end()
#define gc                      getchar_unlocked
#define PI                      acos(-1.0)
#define EPS                     1e-9
#define xx                      first
#define yy                      second
#define lc                      ((n)<<1)
#define rc                      ((n)<<1|1)
#define db(x)                   cout << #x << " -> " << x << endl;
#define Di(x)                   int x;scanf("%d",&x)
#define min(a,b)                ((a)>(b) ? (b) : (a) )
#define max(a,b)                ((a)>(b) ? (a):(b))
#define ms(ara_name,value)      memset(ara_name,value,sizeof(ara_name))




int main(){
    ios::sync_with_stdio(false);
    
    cin.tie(0);
    ll n;
    cin>>n;
    cout<<(n*(n+1))/2;
    
    

   
    return 0;
}