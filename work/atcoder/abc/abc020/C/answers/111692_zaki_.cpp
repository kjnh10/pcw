#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = numeric_limits<int>::max() / 2;

int sx,sy,tx,ty;
int h,w;
int board[11][11];//黒の時1　白の時0 S,Gは-1
ll d[101][101];

int conv(int x,int y){return x*w+y;}

int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};

ll solve(ll t){
    for(int i=0;i<h*w;i++)for(int j=0;j<h*w;j++){
        d[i][j]=INF;
        if(i==j) d[i][j]=0;
    }
    for(int x=0;x<h;x++)for(int y=0;y<w;y++){
        for(int k=0;k<4;k++){
            int nx=x+dx[k],ny=y+dy[k];
            if(0<=nx&&nx<h&&0<=ny&&ny<w){
                if(board[nx][ny]==-1) d[conv(x,y)][conv(nx,ny)]=0;
                else if(board[nx][ny]) d[conv(x,y)][conv(nx,ny)]=t;
                else d[conv(x,y)][conv(nx,ny)]=1;
            }
        }
    }
    for(int k=0;k<h*w;k++){
        for(int i=0;i<h*w;i++){
            for(int j=0;j<h*w;j++){
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
    return d[conv(sx,sy)][conv(tx,ty)];
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll t;
  cin>>h>>w>>t;
  for(int i=0;i<h;i++){
      string s;cin>>s;
      for(int j=0;j<w;j++){
          if(s[j]=='S'){sx=i;sy=j;board[i][j]=-1;}
          else if(s[j]=='G'){tx=i;ty=j;board[i][j]=-1;}
          else if(s[j]=='#') board[i][j]=1;
          else board[i][j]=0;
      }
  }
  ll low=0,high=1e9;
  for(int i=0;i<50;i++){
      ll mid=(low+high)/2;
      ll time=solve(mid);
      if(time<t) low=mid;
      else high=mid;
  }
  cout<< low<<endl;
  return 0;
}