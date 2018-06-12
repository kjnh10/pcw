#include<bits/stdc++.h>
using namespace std;
#define int long long
#define MAX 114514
signed main(){
  int n;
  cin>>n;
  int r[n],h[n];
  for(int i=0;i<n;i++) cin>>r[i]>>h[i];
  int num[3][MAX];
  for(int i=0;i<n;i++){
    h[i]--;
    num[h[i]][r[i]]++;
  }
  int win[MAX];
  win[0]=0;
  for(int i=0;i<MAX-1;i++)
    win[i+1]=win[i]+num[0][i]+num[1][i]+num[2][i];
  for(int i=0;i<n;i++){
    int w,d,l;
    w=win[r[i]];
    w+=num[(h[i]+1)%3][r[i]];
    d=num[h[i]][r[i]]-1;
    l=n-1-w-d;
    cout<<w<<" "<<l<<" "<<d<<endl;
  }
  return 0;
}
