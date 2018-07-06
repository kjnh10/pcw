#include <bits/stdc++.h>

using namespace std;

#define int long long
#define all(v) begin(v), end(v)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define reps(i, s, n) for(int i = (int)(s); i < (int)(n); i++)
#define min(...) min({__VA_ARGS__})
#define max(...) max({__VA_ARGS__})

template<class T1, class T2> void chmin(T1 &a, T2 b){if(a>b)a=b;}
template<class T1, class T2> void chmax(T1 &a, T2 b){if(a<b)a=b;}

using pint = pair<int, int>;
using tint = tuple<int, int, int>;
using vint = vector<int>;

const int inf = 1LL << 55;
const int mod = 1e9 + 7;
const double PI = acos(-1);
const double EPS = 1e-9;

int N;
int x[2000], y[2000];
int xx[2000], yy[2000];

int ritri, obtri;

void solve(int id) {
  rep(i, N) xx[i] = x[i]-x[id], yy[i] = y[i]-y[id];

  vector<double> v;
  rep(i, N) if(i != id) {
    double a = atan2(yy[i], xx[i]);
    v.push_back(a);
    v.push_back(a+2*PI);
  }
  sort(all(v));

  int j = 0, k = 0;
  rep(i, N-1) {
    double a = v[i];
    while(j < v.size()) {
      double b = v[j] - a;
      if(b + EPS > PI/2) break;
      j++;
    }
    while(j < v.size() && fabs(v[j]-a-PI/2) < EPS) {
      ritri++;
      j++;
    }
    while(k < v.size()) {
      double b = v[k]-a;
      if(b + EPS > PI) break;
      k++;
    }
    obtri += k-j;
  }
}

signed main()
{
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);

  cin >> N;
  rep(i, N) cin >> x[i] >> y[i];

  rep(i, N) solve(i);

  cout << N*(N-1)*(N-2)/6-ritri-obtri << " " << ritri << " " << obtri << endl;

  return 0;
}
