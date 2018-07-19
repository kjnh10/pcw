#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define N 20
int h , w;
char c[ N ][ N ];
int ord[ N ];
void check( int len ){
  unordered_set<LL> cand;
  for( int i = 0 ; i < w ; i ++ ){
    //string tmp = "";
    LL hs = 0 , rhs = 0;
    for( int j = 0 ; j < len ; j ++ )
      hs = hs * 26 + (c[ ord[ j ] ][ i ] - 'a');
    for( int j = len - 1 ; j >= 0 ; j -- )
      rhs = rhs * 26 + (c[ ord[ j ] ][ i ] - 'a');
      //tmp += t[ j ][ i ];
    //string rtmp = tmp;
    //reverse( rtmp.begin() , rtmp.end() );
    auto it = cand.find( rhs );
    if( it != cand.end() )
      cand.erase( it );
    else
      cand.insert( hs );
  }
  if( cand.size() < 2u ){
    puts( "YES" );
    exit(0);
  }
}
void gogo( int msk1 , int msk2 ){
  int tot1 = 0;
  for( int i = 0 ; i < h ; i ++ ){
    if( (msk1 >> i) & 1 )
      ord[ tot1 ++ ] = i;
  }
  int tot2 = tot1;
  for( int i = 0 ; i < h ; i ++ ){
    if( (msk2 >> i) & 1 )
      ord[ tot2 ++ ] = i;
  }
  do check( tot2 );
  while( next_permutation( ord + tot1 , ord + tot2 ) );
}
int main(){
  scanf( "%d%d" , &h , &w );
  for( int i = 0 ; i < h ; i ++ )
    scanf( "%s" , c[ i ] );
  if( h == 1 ){
    int cnt[ 26 ] = {};
    for( int i = 0 ; i < w ; i ++ )
      cnt[ c[ 0 ][ i ] - 'a' ] ++;
    int od = 0;
    for( int i = 0 ; i < 26 ; i ++ )
      od += cnt[ i ] & 1;
    puts( od > 1 ? "NO" : "YES" );
    return 0;
  }
  int need = (h + 1) / 2;
  for( int i = 0 ; i < (1 << h) ; i ++ ){
    if( __builtin_popcount( i ) != need ) continue;
    if( h & 1 ){
      for( int j = 0 ; j < h ; j ++ )
        if( (i >> j) & 1 )
          gogo( i ^ (1 << j) , ((1 << h) - 1) ^ i );
    }else
      gogo( i , ((1 << h) - 1) ^ i );
  }
  puts( "NO" );
}
