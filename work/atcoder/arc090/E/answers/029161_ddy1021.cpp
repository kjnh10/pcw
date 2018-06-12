// eddy1021
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long double LD;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
#define mod9 1000000009LL
#define mod7 1000000007LL
#define INF  1023456789LL
#define INF16 10000000000000000LL
#define eps 1e-9
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(), (x).end()
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#ifndef ONLINE_JUDGE
#define debug(...) printf(__VA_ARGS__)
#else 
#define debug(...)
#endif
inline LL getint(){
  LL _x=0,_tmp=1; char _tc=getchar();    
  while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
  if( _tc == '-' ) _tc=getchar() , _tmp = -1;
  while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
  return _x*_tmp;
}
inline LL add( LL _x , LL _y , LL _mod = mod7 ){
  _x += _y;
  return _x >= _mod ? _x - _mod : _x;
}
inline LL sub( LL _x , LL _y , LL _mod = mod7 ){
  _x -= _y;
  return _x < 0 ? _x + _mod : _x;
}
inline LL mul( LL _x , LL _y , LL _mod = mod7 ){
  _x *= _y;
  return _x >= _mod ? _x % _mod : _x;
}
LL mypow( LL _a , LL _x , LL _mod ){
  if( _x == 0 ) return 1LL;
  LL _ret = mypow( mul( _a , _a , _mod ) , _x >> 1 , _mod );
  if( _x & 1 ) _ret = mul( _ret , _a , _mod );
  return _ret;
}
LL mymul( LL _a , LL _x , LL _mod ){
  if( _x == 0 ) return 0LL;
  LL _ret = mymul( add( _a , _a , _mod ) , _x >> 1 , _mod );
  if( _x & 1 ) _ret = add( _ret , _a , _mod );
  return _ret;
}
inline bool equal( D _x ,  D _y ){
  return _x > _y - eps && _x < _y + eps;
}
void sleep( double sec = 1021 ){
  clock_t s = clock();
  while( clock() - s < CLOCKS_PER_SEC * sec );
}
#define Bye exit(0)
int __ = 1 , _cs;
/*********default*********/
#define N 101010
int n , m , s[ 2 ];
vector< pair<int,LL> > v[ N ];
void build(){

}
void init(){
  n = getint();
  m = getint();
  for( int i = 0 ; i < 2 ; i ++ )
    s[ i ] = getint();
  while( m -- ){
    int ui = getint();
    int vi = getint();
    int di = getint();
    v[ ui ].push_back( { vi , di } );
    v[ vi ].push_back( { ui , di } );
  }
}
LL dst[ 2 ][ N ];
int wy[ 2 ][ N ];
bool gt[ 2 ][ N ];
void go( int id , int ss ){
  priority_queue< pair<LL,int> ,
          vector< pair<LL,int> >,
         greater< pair<LL,int> > > heap;
  for( int i = 1 ; i <= n ; i ++ )
    dst[ id ][ i ] = INF16;
  heap.push( { 0 , ss } );
  wy[ id ][ ss ] = 1;
  dst[ id ][ ss ] = 0;
  while( heap.size() ){
    LL nd; int who;
    tie( nd , who ) = heap.top(); heap.pop();
    if( gt[ id ][ who ] ) continue;
    gt[ id ][ who ] = true;
    dst[ id ][ who ] = nd;
    for( auto e : v[ who ] ){
      int nxt = e.first;
      LL nxtd = nd + e.second;
      if( gt[ id ][ nxt ] ) continue;
      if( nxtd < dst[ id ][ nxt ] ){
        dst[ id ][ nxt ] = nxtd;
        wy[ id ][ nxt ] = wy[ id ][ who ];
        heap.push( { nxtd , nxt } );
      }else if( nxtd == dst[ id ][ nxt ] )
        wy[ id ][ nxt ] = add( wy[ id ][ nxt ] , wy[ id ][ who ] );
    }
  }
}
void solve(){
  for( int i = 0 ; i < 2 ; i ++ )
    go( i , s[ i ] );
  LL ans = mul( wy[ 0 ][ s[ 1 ] ] , wy[ 0 ][ s[ 1 ] ] );
  LL far = dst[ 0 ][ s[ 1 ] ];
  for( int i = 1 ; i <= n ; i ++ )
    if( dst[ 0 ][ i ] == dst[ 1 ][ i ] and dst[ 0 ][ i ] + dst[ 1 ][ i ] == far ){
      LL dlt = mul( wy[ 0 ][ i ] , wy[ 1 ][ i ] );
      ans = sub( ans , mul( dlt , dlt ) );
    }
  for( int i = 1 ; i <= n ; i ++ )
    for( auto e : v[ i ] ){
      int nxt = e.first;
      LL dd = e.second;
      if( dst[ 0 ][ i ] + dd + dst[ 1 ][ nxt ] == far and
          dst[ 0 ][ i ] + dst[ 0 ][ i ] < far and
          dst[ 1 ][ nxt ] + dst[ 1 ][ nxt ] < far ){
        LL dlt = mul( wy[ 0 ][ i ] , wy[ 1 ][ nxt ] );
        ans = sub( ans , mul( dlt , dlt ) );
      }
    }
  cout << ans << endl;
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}
