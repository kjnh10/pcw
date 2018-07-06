#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF 1145141919810364364
#define REP(i,n) for (int i=0;i<(n);i++)
typedef pair<int,int> P;

int memo_R[100010],memo_C[100010]={};
int m_R[100010]={},m_C[100010]={};
P data[100000];
signed main() {
  int R,C,K,N;
  cin>>R>>C>>K>>N;
  for(int i=0;i<N;i++){
    cin>>data[i].first>>data[i].second;
    memo_R[data[i].first]++;
    memo_C[data[i].second]++;
  }
  int ans=0;
  for(int i=1;i<=R;i++){
    m_R[memo_R[i]]++;
  }
  for(int i=1;i<=C;i++){
    m_C[memo_C[i]]++;
  }
  for(int i=0;i<=K;i++){
    ans+=m_R[i]*m_C[K-i];
  }
  for(int i=0;i<N;i++){
    int cnt=memo_R[data[i].first]+memo_C[data[i].second];
    if(cnt==K) ans--;
    if((cnt-1)==K)ans++;
  }
  cout<<ans<<endl;
}
