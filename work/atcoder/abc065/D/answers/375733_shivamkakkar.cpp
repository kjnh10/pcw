// Sasageyo! Sasageyo! Shinzou wo Sasageyo !
// https://goo.gl/IwJzbx

#include<bits/stdc++.h>

using namespace std;


typedef long long int LL;
typedef pair<LL,LL> II;

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define ALL(a) a.begin(),a.end()
#define SET(a,b) memset(a,b,sizeof(a))
#define si(n) scanf("%d",&n)
#define dout(n) printf("%d\n",n)
#define sll(n) scanf("%lld",&n)
#define lldout(n) printf("%lld\n",n)

#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

#define endl '\n'
const LL N = 1e5;
pair<II,LL> c[N];
int p[N+1];
int find(int u) {
  if(p[u]==u)
    return u;
  return p[u] = find(p[u]);
}
int unio(int u, int v) {
  int pu = find(u);
  int pv = find(v);
  if(pu==pv)
    return 0;
  p[pu] = pv;
  return 1;
}
int main()
{
  for(int i=0;i<=N;i++)
    p[i] = i;
	fast_io;
  LL n;
  cin >> n;
  for(LL i=0;i<n;i++) {
    cin >> c[i].F.F >> c[i].F.S;
    c[i].S = i;
  }
  sort(c, c + n);
  priority_queue< pair<LL, II> > q;
  for(LL i=1;i<n;i++)
    q.push({-abs(c[i].F.F - c[i-1].F.F),  {c[i].S, c[i-1].S}});
  for(LL i=0;i<n;i++)
    swap(c[i].F.F, c[i].F.S);
  sort(c, c + n);
  for(LL i=1;i<n;i++)
    q.push({-abs(c[i].F.F - c[i-1].F.F),  {c[i].S, c[i-1].S}});
  LL ans = 0;
  while(!q.empty()) {
    auto t = q.top();q.pop();
    if(unio(t.S.F, t.S.S))
      ans += -t.F;
  }
  cout << ans << endl;
	return 0;
}