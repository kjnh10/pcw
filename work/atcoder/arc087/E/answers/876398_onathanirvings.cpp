//start of jonathanirvings' template v3.0.3 (BETA)

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
typedef pair<string,string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<LL> vl;
typedef vector<vl> vvl;

double EPS = 1e-9;
int INF = 1000000005;
long long INFF = 1000000000000000005LL;
double PI = acos(-1);
int dirx[8] = {-1,0,0,1,-1,-1,1,1};
int diry[8] = {0,1,-1,0,-1,1,-1,1};

#ifdef TESTING
  #define DEBUG fprintf(stderr,"====TESTING====\n")
  #define VALUE(x) cerr << "The value of " << #x << " is " << x << endl
  #define debug(...) fprintf(stderr, __VA_ARGS__)
#else
  #define DEBUG 
  #define VALUE(x)
  #define debug(...)
#endif

#define FOR(a,b,c) for (int (a)=(b);(a)<(c);++(a))
#define FORN(a,b,c) for (int (a)=(b);(a)<=(c);++(a))
#define FORD(a,b,c) for (int (a)=(b);(a)>=(c);--(a))
#define FORSQ(a,b,c) for (int (a)=(b);(a)*(a)<=(c);++(a))
#define FORC(a,b,c) for (char (a)=(b);(a)<=(c);++(a))
#define FOREACH(a,b) for (auto &(a) : (b))
#define REP(i,n) FOR(i,0,n)
#define REPN(i,n) FORN(i,1,n)
#define MAX(a,b) a = max(a,b)
#define MIN(a,b) a = min(a,b)
#define SQR(x) ((LL)(x) * (x))
#define RESET(a,b) memset(a,b,sizeof(a))
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ALL(v) v.begin(),v.end()
#define ALLA(arr,sz) arr,arr+sz
#define SIZE(v) (int)v.size()
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))
#define SORTA(arr,sz) sort(ALLA(arr,sz))
#define REVERSEA(arr,sz) reverse(ALLA(arr,sz))
#define PERMUTE next_permutation
#define TC(t) while(t--)

inline string IntToString(LL a){
  char x[100];
  sprintf(x,"%lld",a); string s = x;
  return s;
}

inline LL StringToInt(string a){
  char x[100]; LL res;
  strcpy(x,a.c_str()); sscanf(x,"%lld",&res);
  return res;
}

inline string GetString(void){
  char x[1000005];
  scanf("%s",x); string s = x;
  return s;
}

inline string uppercase(string s){
  int n = SIZE(s); 
  REP(i,n) if (s[i] >= 'a' && s[i] <= 'z') s[i] = s[i] - 'a' + 'A';
  return s;
}

inline string lowercase(string s){
  int n = SIZE(s); 
  REP(i,n) if (s[i] >= 'A' && s[i] <= 'Z') s[i] = s[i] - 'A' + 'a';
  return s;
}

inline void OPEN (string s) {
  #ifndef TESTING
  freopen ((s + ".in").c_str (), "r", stdin);
  freopen ((s + ".out").c_str (), "w", stdout);
  #endif
}

//end of jonathanirvings' template v3.0.3 (BETA)

map<int,int> dp;

int jahja(int x)
{
  if (dp.count(x)) return dp[x];
  vi temp;
  temp.pb(0);
  FORN(i,1,x-1)
  {
    int ini = 0;
    FORN(j,i,x-1) ini ^= jahja(j);
    temp.pb(ini);
  }
  SORT(temp);
  temp.erase(unique(ALL(temp)),temp.end());
  REP(i,SIZE(temp)) if(temp[i] != i) return dp[x] = i;
  return dp[x] = SIZE(temp);
}

LL MOD = 1999999999999999909LL;
unordered_set<LL> ada;
int n;
LL l;
string data[100005];
vector<LL> ambil;

void dfs(LL now, LL sisa)
{
  // VALUE(now);
  if (!ada.count(now))
  {
    ambil.pb(sisa);
    return;
  }
  dfs((now * 3 + 1) % MOD, sisa - 1);
  dfs((now * 3 + 2) % MOD, sisa - 1);
}

LL bisa(LL x)
{
  if (x == 0) return 0;
  LL y = 1;
  while (x % y == 0) y *= 2;
  return y / 2;
}

int main()
{
  // FORN(i,1,16) debug("%d %d\n",i,jahja(i));
  scanf("%d %lld",&n,&l);
  REP(i,n)
  {
    data[i] = GetString();
    LL now = 0;
    REP(j,SIZE(data[i]))
    {
      now = (now * 3 + data[i][j] - '0' + 1) % MOD;
      ada.insert(now);
    }
  }
  dfs(1,l); dfs(2,l);
  LL risan = 0;
  REP(i,SIZE(ambil)) risan ^= bisa(ambil[i]);
  puts(risan ? "Alice" : "Bob");
  // REP(i,SIZE(ambil)) debug("%lld\n",ambil[i]);
  return 0;
}









