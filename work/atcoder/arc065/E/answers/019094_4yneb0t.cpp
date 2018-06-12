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
in ab(in a){
  return a<0?-a:a;
}
in sm=0;
map<pair<in,in>, in> dcd;
map<in,set<in> > ups,dns;
map<in,VI> upv,dnv;
in d;
VI x,y;
VI cr;
queue<in> q;
void aad(in rx, in ry){
  in id=dcd[MP(rx,ry)];
  if(!cr[id]){
    cr[id]=1;
    q.push(id);
  }
}
void prk(map<in,set<in> >& cs, map<in,VI>& cv, in vl, in mn, in mx, bool tup){
  if(!(cs.count(vl)))
    return;
  set<in>& ss=cs[vl];
  auto it=ss.lower_bound(mn);
  auto it2=it;
  in rx,ry;
  while(it!=ss.end() && *it<=mx){
    rx=*it;
    if(tup)
      ry=rx-vl;
    else
      ry=vl-rx;
    aad(rx,ry);
    it2=it;
    ++it;
    ss.erase(it2);
  }
  VI& vv=cv[vl];
  in tl=lower_bound(all(vv),mn)-vv.begin();
  in tr=upper_bound(all(vv),mx)-vv.begin();
  sm+=tr-tl;
}
void proc(in a){
  in cx=x[a];
  in cy=y[a];
  prk(ups,upv,cx-cy-d,cx-d,cx-1,1);
  prk(ups,upv,cx-cy+d,cx+1,cx+d,1);
  prk(dns,dnv,cx+cy-d,cx-d+1,cx,0);
  prk(dns,dnv,cx+cy+d,cx,cx+d-1,0);
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n,a,b;
  cin>>n>>a>>b;
  --a;
  --b;
  x=y=cr=VI(n);
  cr[a]=cr[b]=1;
  forn(i,n){
    cin>>x[i]>>y[i];
    ups[x[i]-y[i]].insert(x[i]);
    dns[x[i]+y[i]].insert(x[i]);
    dcd[MP(x[i],y[i])]=i;
  }
  fors(i,ups){
    fors(j,i->second)
      upv[i->first].PB(*j);
  }
  fors(i,dns){
    fors(j,i->second)
      dnv[i->first].PB(*j);
  }
  d=ab(x[a]-x[b])+ab(y[a]-y[b]);
  q.push(a);
  q.push(b);
  while(!q.empty()){
    a=q.front();
    q.pop();
    proc(a);
  }
  cout<<(sm/2)<<endl;
  return 0;
}
