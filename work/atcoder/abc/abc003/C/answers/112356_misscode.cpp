#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
  int N,K,R[101]={};
  cin>>N>>K;
  for(int i=0;i<N;i++) cin>>R[i];
  sort(R,R+N);
  float ans=0.0;
  for(int i=0;i<K;i++) ans=(float)((float)ans+R[(N-K)+i])/2;
  printf("%.6f\n",ans);
  return 0;
}
