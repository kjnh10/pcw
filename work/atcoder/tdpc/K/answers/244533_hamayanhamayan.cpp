#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)


vector<int> dp, id;
vector<int> LIS(vector<int>& v) {
    int i; int n = v.size();
    dp.resize(n, INT_MAX / 2);
    id.resize(n, 0);
    rep(i, 0, v.size()) {
        id[i] = lower_bound(dp.begin(), dp.end(), v[i]) - dp.begin();
        dp[id[i]] = v[i];
    }
    int nl = *max_element(id.begin(), id.end());
    vector<int> ret(nl + 1);
    rep(i, 0, n) if (id[n - 1 - i] == nl) ret[nl--] = v[n - 1 - i];
    return ret;
}
//-----------------------------------------------------------------------------------
int N, x[101010], r[101010], L[101010], R[101010];
int ord[101010];
int main() {
    cin >> N;
    rep(i, 0, N) scanf("%d%d", &x[i], &r[i]);
    rep(i, 0, N) L[i] = x[i] - r[i], R[i] = x[i] + r[i];

    rep(i, 0, N) ord[i] = i;
    sort(ord, ord + N, [&](int a, int b) {
        if (R[a] != R[b]) return R[a] > R[b];
        else return L[a] > L[b];
    });

    vector<int> v;
    rep(_i, 0, N) {
        int i = ord[_i];
        v.push_back(L[i]);
    }
    cout << LIS(v).size() << endl;
}