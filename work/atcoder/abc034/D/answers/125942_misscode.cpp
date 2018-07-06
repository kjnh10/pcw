#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define INF 1145141919810
#define REP(i,n) for (int i=0;i<(n);i++)
#define mp make_pair
typedef pair<int,int> P;

int w[1001]={},p[1001];
signed main(){
  int N,K; cin>>N>>K;
  double OK=0,NG=100,MID;
  for(int i=0;i<N;i++) cin>>w[i]>>p[i];
  int cnt=0;
  while(1){
    if(cnt==100) break;
    MID=(OK+NG)/2.0;
    int tmp[1001]={};
    for(int i=0;i<N;i++){
      tmp[i]=w[i]*(p[i]-MID);
    }
    sort(tmp,tmp+N);
    reverse(tmp,tmp+N);
    int hoge=0;
    for(int i=0;i<K;i++){
      hoge+=tmp[i];
    }
    if(hoge>0) OK=MID;
    else NG=MID;
    cnt++;
  }
printf("%.10Lf\n",OK);
}
