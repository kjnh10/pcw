#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<cassert>
#define PB push_back
#define MP make_pair
#define sz(v) (in((v).size()))
#define forn(i,n) for(in i=0;i<(n);++i)
#define forv(i,v) forn(i,sz(v))
#define fors(i,s) for(auto i=(s).begin();i!=(s).end();++i)
#define all(v) (v).begin(),(v).end()
using namespace std;
typedef long long in;
typedef vector<in> VI;
typedef vector<VI> VVI;
struct unifnd{
  VI ht,pr;
  in fnd(in a){
    in ta=a;
    while(a!=pr[a])a=pr[a];
    in tt=ta;
    while(ta!=a){
      tt=pr[ta];
      pr[ta]=a;
      ta=tt;
    }
    return a;
  }
  void uni(in a, in b){
    a=fnd(a);
    b=fnd(b);
    if(a==b)return;
    if(ht[b]<ht[a])swap(a,b);
    pr[a]=b;
    ht[b]+=(ht[a]==ht[b]);
  }
  void ini(in n){
    ht.resize(n);
    pr.resize(n);
    forn(i,n){
      ht[i]=0;
      pr[i]=i;
    }
  }
};
unifnd tf1,tf2;
map<pair<in,in>,in> ct;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n,k,l;
  cin>>n>>k>>l;
  tf1.ini(n);
  tf2.ini(n);
  in ta,tb;
  forn(z,k){
    cin>>ta>>tb;
    tf1.uni(ta-1,tb-1);
  }
  forn(z,l){
    cin>>ta>>tb;
    tf2.uni(ta-1,tb-1);
  }
  forn(i,n)
    ++ct[MP(tf1.fnd(i),tf2.fnd(i))];
  forn(i,n)
    cout<<(ct[MP(tf1.fnd(i),tf2.fnd(i))])<<" ";
  cout<<endl;
  return 0;
}
