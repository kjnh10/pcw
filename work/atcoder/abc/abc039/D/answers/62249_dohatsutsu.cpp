#include<bits/stdc++.h>
using namespace std;

int H,W;
char t[100][100];
char u[100][100];
char v[100][100];

int main(){
  cin>>H>>W;
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin>>t[i][j];
      u[i][j]=v[i][j]='.';
    }
  }

  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      int a=0,b=0;
      for(int k=-1;k<=1;k++){
        for(int l=-1;l<=1;l++){
          int y=i+k;
          int x=j+l;
          if(y<0||x<0)continue;
          if(y>=H||x>=W)continue;
          b++;
          if(t[y][x]=='#')a++;
        }
      }

      if(a==b){
        v[i][j]='#';
        for(int k=-1;k<=1;k++){
          for(int l=-1;l<=1;l++){
            int y=i+k;
            int x=j+l;
            if(y<0||x<0)continue;
            if(y>=H||x>=W)continue;
            u[y][x]='#';
          }
        } 
      }
    }
  }

  bool ans=true;
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(t[i][j]!=u[i][j]){
        ans=false;
      }
    }
  }
  if(ans){
    cout<<"possible"<<endl;
    for(int i=0;i<H;i++){
      for(int j=0;j<W;j++){
        cout<<v[i][j];
      }
      cout<<endl;
    }
  }else{
    cout<<"impossible"<<endl; 
  }
  return 0;
}
