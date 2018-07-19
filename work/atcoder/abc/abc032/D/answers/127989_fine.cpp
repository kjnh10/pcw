#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll INF = 1e12;

int N;
ll W;
ll v[200], w[200];

ll solve1() {
	int n1 = N / 2, n2 = N - n1;
	map<ll, ll> nap1;
	for (int i = 0; i < (1 << n1); i++) {
		ll tmp_v = 0, tmp_w = 0;
		for (int j = 0; j < n1; j++) {
			if (i & (1 << j)) {
				tmp_v += v[j];
				tmp_w += w[j];
			}
		}
		if (nap1.find(tmp_w) == nap1.end()) nap1[tmp_w] = tmp_v;
		else nap1[tmp_w] = max(nap1[tmp_w], tmp_v);
	}
	map<ll, ll> nap2;
	for (int i = 0; i < (1 << n2); i++) {
		ll tmp_v = 0, tmp_w = 0;
		for (int j = 0; j < n2; j++) {
			if (i & (1 << j)) {
				tmp_v += v[n1 + j];
				tmp_w += w[n1 + j];
			}
		}
		if (nap2.find(tmp_w) == nap2.end()) nap2[tmp_w] = tmp_v;
		else nap2[tmp_w] = max(nap2[tmp_w], tmp_v);
	}

	vector<ll> v1, v2, w1, w2;
	for (auto p : nap1) {
		if (!v1.empty() && v1.back() > p.second) continue;
		w1.push_back(p.first);
		v1.push_back(p.second);
	}
	for (auto p : nap2) {
		if (!v2.empty() && v2.back() > p.second) continue;
		w2.push_back(p.first);
		v2.push_back(p.second);
	}

	ll res = 0;
	for (int i = 0; i < w1.size(); i++) {
		if (w1[i] > W) continue;
		int idx = upper_bound(w2.begin(), w2.end(), W - w1[i]) - w2.begin() - 1;
		res = max(res, v1[i] + v2[idx]);
	}
	return res;
}

ll solve2() {
	if (accumulate(w, w + N, 0LL) <= W) return accumulate(v, v + N, 0LL);
	vector<ll> dp(W + 1, 0);
	for (int i = 0; i < N; i++) {
		for (ll j = W; j >= w[i]; j--) {
			dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
		}
	}
	return dp[W];
}

ll solve3() {
	ll v_sum = accumulate(v, v + N, 0LL);
	vector<ll> dp(v_sum + 1, INF);
	dp[0] = 0;
	for (int i = 0; i < N; i++) {
		for (ll j = v_sum; j >= v[i]; j--) {
			dp[j] = min(dp[j], dp[j - v[i]] + w[i]);
		}
	}
	for (ll i = v_sum; i >= 0; i--) {
		if (dp[i] <= W) return i;
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> N >> W;
	ll w_max = 0;
	for (int i = 0; i < N; i++) {
		cin >> v[i] >> w[i];
		w_max = max(w_max, w[i]);
	}
	if (N <= 30) cout << solve1() << endl;
	else if (w_max <= 1000) cout << solve2() << endl;
	else cout << solve3() << endl;
	return 0;
}