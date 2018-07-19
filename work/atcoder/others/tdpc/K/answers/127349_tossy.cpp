#include <bits/stdc++.h>
using namespace std;
#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repl(i,0,n)
#define mp(a,b) make_pair((a),(b))
#define pb(a) push_back((a))
#define all(x) (x).begin(),(x).end()
#define uniq(x) sort(all(x)),(x).erase(unique(all(x)),end(x))
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

#define INF 2147483600
#define long long long // for codeforces

int main(){
  int n;
  cin>>n;
  vector<pair<int,int>> vec(n);
  // ひだり，みぎ
  rep(i,n){
    int x,r;
    cin>>x>>r;
    vec[i] = mp(x-r, x+r);
  }

  sort(all(vec), greater<pair<int,int>>());

  vector<int> lis(n, INF);
  rep(i,n){
    lis[lower_bound(all(lis),vec[i].se) - lis.begin()] = vec[i].se;
  }

  cout << lower_bound(all(lis), INF) - lis.begin() << endl;

  return 0;
}
