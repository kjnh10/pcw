#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll solve(ll h, ll w) {
  ll result = 1000000000000LL;
  for (ll i = 1; i < w; i++) {
    ll s1 = i * h;

    ll w2 = w - i;
    ll s21 = (w2 / 2) * h;
    ll s22 = ((w2 + 1) / 2) * h;

    ll s31 = (h / 2) * w2;
    ll s32 = ((h + 1) / 2) * w2;

    vector<ll> v1 = {s1, s21, s22}, v2 = {s1, s31, s32};
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    result = min(result, min(v1[2] - v1[0], v2[2] - v2[0]));
  }
  return result;
}

int main() {
  ll h, w;
  cin >> h >> w;
  cout << min(solve(h, w), solve(w, h)) << endl;
  return 0;
}
