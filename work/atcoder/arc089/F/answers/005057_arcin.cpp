#include <bits/stdc++.h>

using namespace std;
#define PB push_back
#define MP make_pair
#define LL long long
#define int LL
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define RE(i,n) FOR(i,1,n)
#define REP(i,n) FOR(i,0,(int)(n)-1)
#define R(i,n) REP(i,n)
#define VI vector<int>
#define PII pair<int,int>
#define LD long double
#define FI first
#define SE second
#define st FI
#define nd SE
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())

template<class C> void mini(C &a4, C b4) { a4 = min(a4, b4); }
template<class C> void maxi(C &a4, C b4) { a4 = max(a4, b4); }

template<class TH> void _dbg(const char *sdbg, TH h){ cerr<<sdbg<<'='<<h<<endl; }
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;cerr<<'='<<h<<','; _dbg(sdbg+1, a...);
}

template<class T> ostream &operator<<(ostream& os, vector<T> V) {
  os << "["; for (auto vv : V) os << vv << ","; return os << "]";
}
template<class L, class R> ostream &operator<<(ostream &os, pair<L,R> P) {
  return os << "(" << P.st << "," << P.nd << ")";
}

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif


const int P = 1e9 + 7;
const int MAX = 300;
set<vector<int>> x;
vector<set<vector<int>>::iterator> zr,zb;
int res = 1;
int sil[MAX],odw[MAX];
int newt[MAX][MAX];
string z;
int n,k;
void add(vector<int> ak){
  auto pom = x.insert(ak);
  if(pom.SE){
    int mn = 1;
    int sum = 0;
    int sum2 = 0;
    R(i,SZ(ak)){
      sum += ak[i];
      sum2 += ak[i] * i;
      mn = (mn * odw[ak[i]]) % P;
    }
    int a = n + 2 + (sum - ak[0]) * 2 - 1;
    int b = 2 * sum2 + 2 * sum;
    if(a >= b){
      res += mn * sil[sum] % P * newt[a][b] % P;
      zr.PB(pom.FI);
      zb.PB(pom.FI);
    }
  }
}
void dod(vector<int> pom,int zak){
  R(i,SZ(pom))if(i != zak && (i == 0 || pom[i-1])){
    if(i)pom[i-1]--;
    pom[i]++;
    add(pom);
    pom[i]--;
    if(i)pom[i-1]++;
  }
  if(SZ(pom) != zak){
    if(SZ(pom))pom.back()--;
    pom.PB(1);
    add(pom);
  }
}
int pot(int a,int w){
  int r = 1;
  while(w){
    if(w & 1){
      r = r * a % P;
    }
    w/=2;
    a = a * a % P;
  }
  return r;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  sil[0] = 1;
  R(i,MAX-1){
    sil[i+1] = (i+1) * sil[i] % P;
  }
  R(i,MAX){
    odw[i] = pot(sil[i],P-2);
  }
  R(i,MAX)R(j,i+1){
    if(j == 0){
      newt[i][j] = 1;
    }else{
      newt[i][j] = newt[i-1][j-1] + newt[i-1][j];
      if(newt[i][j] >= P)
        newt[i][j] -= P;
    }
  }
  cin >> n >> k >> z;

  auto xx = x.insert(vector<int>());
  zr.PB(xx.FI);
  zb.PB(xx.FI);
  R(i,k){
    if(z[i] == 'r'){
      vector<set<vector<int>>::iterator> pom;
      swap(pom,zr);
      for(auto el:pom){
        dod(*el,1);
      }
    }else{
      vector<set<vector<int>>::iterator> pom;
      swap(pom,zb);
      for(auto el:pom){
        dod(*el,0);
      }
    }
  }
  cout << res % P << "\n";
}
