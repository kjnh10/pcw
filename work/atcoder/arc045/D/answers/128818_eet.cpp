#include<bits/stdc++.h>
using namespace std;
#define int long long
struct StarrySky{
  static const int MAX_N = 1 << 22;
  int datm[2*MAX_N],data[2*MAX_N],n;
  StarrySky(){}
  StarrySky(int n_){init(n_);}
  void init(int n_){
    n=1;
    while(n<n_) n*=2;
    for(int i=0;i<n*2;i++) datm[i]=data[i]=0;
  }
  void add(int a,int b,int x,int k,int l,int r){
    if(r<=a||b<=l) return;
    if(a<=l&&r<=b){
      data[k]+=x;
      return;
    }
    add(a,b,x,k*2+1,l,(l+r)/2);
    add(a,b,x,k*2+2,(l+r)/2,r);
    datm[k]=min(datm[k*2+1]+data[k*2+1],datm[k*2+2]+data[k*2+2]);
  }
  int query(int a,int b,int k,int l,int r){
    if(r<=a||b<=l) return INT_MAX;
    if(a<=l&&r<=b) return datm[k]+data[k];
    int vl=query(a,b,k*2+1,l,(l+r)/2);
    int vr=query(a,b,k*2+2,(l+r)/2,r);
    return min(vl,vr)+data[k];
  }
  void add(int a,int b,int x){
    add(a,b,x,0,0,n);
  }
  int query(int a,int b){
    return query(a,b,0,0,n);
  }
};
signed main(){
  int n,q;
  cin>>n>>q;
  StarrySky ss(n);
  int s[q],t[q];
  for(int i=0;i<q;i++){
    cin>>s[i]>>t[i];
    s[i]--;
    ss.add(s[i],t[i],1);
  }
  //for(int i=0;i<n;i++) cout<<ss.query(i,i+1)<<endl;
  //cout<<endl;
  vector<int> ans;
  for(int i=0;i<q;i++){
    ss.add(s[i],t[i],-1);
    //cout<<ss.query(0,n)<<endl;
    if(ss.query(0,n)) ans.push_back(i);
    ss.add(s[i],t[i],1);
  }
  cout<<ans.size()<<endl;
  for(int i=0;i<(int)ans.size();i++) cout<<ans[i]+1<<endl;
  return 0;
}

/*
verified on 2017/02/18
http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E
*/

