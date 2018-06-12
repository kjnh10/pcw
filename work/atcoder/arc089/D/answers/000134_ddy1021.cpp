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
#define K 1021
void build(){

}
int c[ 2 ][ K << 2 ][ K << 2 ];
int n , k;
void init(){
  n = getint();
  k = getint();
  while( n -- ){
    int xi = getint() % (k + k);
    int yi = getint() % (k + k);
    char clr[ 9 ]; scanf( "%s" , clr );
    int nclr = 1;
    if( clr[ 0 ] == 'W' ) nclr = 0;
    c[ nclr ][ xi ][ yi ] ++;
    c[ nclr ][ xi + k + k ][ yi ] ++;
    c[ nclr ][ xi ][ yi + k + k ] ++;
    c[ nclr ][ xi + k + k ][ yi + k + k ] ++;
  }
  for( int nc = 0 ; nc < 2 ; nc ++ )
    for( int i = 0 ; i < (k << 2) ; i ++ )
      for( int j = 0 ; j < (k << 2) ; j ++ ){
        if( i ) c[ nc ][ i ][ j ] += c[ nc ][ i - 1 ][ j ];
        if( j ) c[ nc ][ i ][ j ] += c[ nc ][ i ][ j - 1 ];
        if( i and j )
          c[ nc ][ i ][ j ] -= c[ nc ][ i - 1 ][ j - 1 ];
      }
}
int ans;
inline int Sum( int nclr , int i , int j , int i2 , int j2 ){
  int ret = c[ nclr ][ i2 ][ j2 ];
  if( i ) ret -= c[ nclr ][ i - 1 ][ j2 ];
  if( j ) ret -= c[ nclr ][ i2 ][ j - 1 ];
  if( i and j ) ret += c[ nclr ][ i - 1 ][ j - 1 ];
  return ret;
}
void solve(){
  for( int nc = 0 ; nc < 2 ; nc ++ )
    for( int i = 0 ; i < k ; i ++ )
      for( int j = 0 ; j < k ; j ++ ){
        int tans = Sum( nc , i , j , i + k - 1 , j + k - 1 ) +
                   Sum( 1 - nc , i , j + k , i + k - 1 , j + k + k - 1 ) +
                   Sum( 1 - nc , i + k , j , i + k + k - 1 , j + k - 1 ) +
                   Sum( nc , i + k , j + k , i + k + k - 1 , j + k + k - 1 );
        ans = max( ans , tans );
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
