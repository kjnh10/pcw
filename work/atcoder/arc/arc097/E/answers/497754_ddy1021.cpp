// eddy1021
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL mod7=1000000007LL;
inline LL getint(){
  LL _x=0,_tmp=1; char _tc=getchar();    
  while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
  if( _tc == '-' ) _tc=getchar() , _tmp = -1;
  while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
  return _x*_tmp;
}
inline LL add(LL _x, LL _y, LL _mod=mod7){
  _x+=_y;
  return _x>=_mod ? _x-_mod : _x;
}
inline LL sub(LL _x, LL _y, LL _mod=mod7){
  _x-=_y;
  return _x<0 ? _x+_mod : _x;
}
inline LL mul(LL _x, LL _y ,LL _mod=mod7){
  _x*=_y;
  return _x>=_mod ? _x%_mod : _x;
}
LL mypow(LL _a, LL _x, LL _mod){
  if(_x == 0) return 1LL;
  LL _ret = mypow(mul(_a, _a, _mod), _x>>1, _mod);
  if(_x & 1) _ret=mul(_ret, _a, _mod);
  return _ret;
}
LL mymul(LL _a, LL _x, LL _mod){
  if(_x == 0) return 0LL;
  LL _ret = mymul(add(_a, _a, _mod), _x>>1, _mod);
  if(_x & 1) _ret=add(_ret, _a, _mod);
  return _ret;
}
void sleep(double sec = 1021){
  clock_t s = clock();
  while(clock() - s < CLOCKS_PER_SEC * sec);
}
#define Bye exit(0)
int __ = 1 , _cs;
/*********default*********/
const int N=2048;
void build(){

}
int n, c[N+N], a[N+N];
int pdp[2][N][N], ans;
int tg[N];
void init(){
  n=getint();
  for(int i=0; i<n+n; i++){
    char buf[8];
    scanf("%s", buf);
    a[i]=getint();
    c[i]=(buf[0]=='W');
  }
  for(int i=0; i<n+n; i++)
    for(int j=0; j<i; j++)
      if(c[i] == c[j] and a[j]>a[i])
        ans++;
  for(int i=0; i<n+n; i++){
    for(int j=1; j<=n; j++)
      tg[j]=1;
    for(int j=0; j<i; j++)
      if(c[i] != c[j])
        tg[a[j]]=0;
    for(int j=1; j<=n; j++)
      pdp[c[i]][a[i]][j]=pdp[c[i]][a[i]][j-1]+tg[j];
  }
}
int dp[N][N];
void solve(){
  for(int i=0; i<=n; i++)
    for(int j=0; j<=n; j++)
      dp[i][j]=1e9;
  dp[0][0]=0;
  for(int i=0; i<=n; i++)
    for(int j=0; j<=n; j++){
      if(i<n){
        int tdp=dp[i][j]+pdp[0][i+1][j];
        dp[i+1][j]=min(dp[i+1][j], tdp);
      }
      if(j<n){
        int tdp=dp[i][j]+pdp[1][j+1][i];
        dp[i][j+1]=min(dp[i][j+1], tdp);
      }
    }
  ans+=dp[n][n];
  cout<<ans<<endl;
}
int main(){
  build();
  //__ = getint();
  while(__ --){
    init();
    solve();
  }
}
