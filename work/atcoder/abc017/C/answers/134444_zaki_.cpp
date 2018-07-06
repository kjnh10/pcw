#include <bits/stdc++.h>

using namespace std;
const int INF = numeric_limits<int>::max() / 2;
typedef long long ll;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll j[100010]={};
  int n,m;cin>>n>>m;
  ll sum=0;
  for(int i=0;i<n;i++){
      int l,r,s;cin>>l>>r>>s;
      j[l]+=s;
      j[r+1]-=s;
      sum+=s;
  }
  for(int i=1;i<=100000;i++){
      j[i]=j[i-1]+j[i];
  }
  ll mi=INF;
  for(int i=1;i<=m;i++)mi=min(mi,j[i]);
  cout<<sum-mi<<endl;
}
