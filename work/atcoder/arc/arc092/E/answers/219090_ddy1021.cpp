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
#define N 1021
void build(){

}
LL n , a[ N ];
LL dp[ N ] , bk[ N ] , bst , bl , br , tk;
void init(){
  n = getint();
  for( LL i = 1 ; i <= n ; i ++ )
    a[ i ] = getint();
  bst = a[ 1 ];
  bl = br = 1;
  for( LL i = 1 ; i <= n ; i ++ ){
    dp[ i ] = a[ i ];
    bk[ i ] = 0;
    for( LL j = 1 ; j < i ; j ++ ){
      if( i % 2 != j % 2 ) continue;
      LL tdp = dp[ j ] + a[ i ];
      if( tdp > dp[ i ] ){
        dp[ i ] = tdp;
        bk[ i ] = j;
      }
    }
    if( dp[ i ] > bst ){
      bst = dp[ i ];
      tk = 0;
      br = i;
      LL now = i;
      while( now ){
        bl = now;
        tk ++;
        now = bk[ now ];
      }
    }
  }
}
vector<int> op;
void go( int nl , int nr ){
  if( nl == nr ) return;
  int dlt = (nr - bk[ nr ] - 1) / 2;
  while( dlt -- )
    op.push_back( bk[ nr ] - nl + 3 );
  go( nl , bk[ nr ] );
}
void solve(){
  printf( "%lld\n" , bst );
  for( LL i = n ; i > br ; i -- )
    op.push_back( i );
  for( LL i = 1 ; i < bl ; i ++ )
    op.push_back( 1 );
  go( bl , br );
  while( -- tk )
    op.push_back( 2 );
  printf( "%d\n" , (int)op.size() );
  for( int x : op )
    printf( "%d\n" , x );
}
int main(){
  build();
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}
