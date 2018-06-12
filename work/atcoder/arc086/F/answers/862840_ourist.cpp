/**
 *    author:  tourist
 *    created: 10.12.2017 16:17:19       
**/
#include <bits/stdc++.h>

using namespace std;

string to_string(string s) {
  return '"' + s + '"';
}

string to_string(const char* s) {
  return to_string((string) s);
}

string to_string(bool b) {
  return (b ? "true" : "false");
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

const int md = (int) 1e9 + 7;

int main() {
  int n;
  long long k;
  cin >> n >> k;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  map< vector<long long>, vector< pair<long long, long long> > > mp;
  for (int d = 0; d <= 60; d++) {
    vector<long long> p;
    p.push_back(0);
    for (int i = 0; i < n; i++) {
      long long r = a[i] % (1LL << d) + 1;
      if (r < (1LL << d) && r <= a[0]) {
        p.push_back(r);
      }
    }
    sort(p.begin(), p.end());
    p.resize(unique(p.begin(), p.end()) - p.begin());
    p.push_back(1LL << d);
    for (int id = 0; id < (int) p.size() - 1; id++) {
      long long x = p[id];
      long long to = p[id + 1] - 1;
      long long best = 0;
      for (int bit = 60; bit >= 0; bit--) {
        long long bbb = (1LL << bit);
        if ((x & bbb) == (to & bbb)) {
          best += (x & bbb);
        } else {
          if ((x & (bbb - 1)) != 0) {
            best += (to & bbb);
          }
          break;
        }
      }
      vector<long long> new_a = a;
      for (long long &aa : new_a) {
        aa = (aa - x) >> d;
      }
      long long spent = __builtin_popcountll(best) + d;
      if (spent <= k) {
        long long extra = k - spent;
        extra = min(extra, new_a[0]);
        debug(d, x, new_a);
        vector<long long> diff(n - 1);
        for (int i = 0; i < n - 1; i++) {
          diff[i] = new_a[i + 1] - new_a[i];
        }
        mp[diff].push_back(make_pair(new_a[0] - extra, new_a[0]));
      }
    }
  }
  long long ans = 0;
  for (auto &p : mp) {
    auto &z = p.second;
    debug(p.first, z);
    sort(z.begin(), z.end());
    long long last = -1;
    for (int i = 0; i < (int) z.size(); i++) {
      if (z[i].first > last) {
        ans = (ans + (z[i].second - z[i].first + 1)) % md;
      } else {
        if (z[i].second > last) {
          ans = (ans + (z[i].second - last)) % md;
        }
      }
      last = max(last, z[i].second);
    }
  }
  cout << ans << endl;
  return 0;
}
