#include <bits/stdc++.h>

#define VARNAME(x) #x
#define show(x) cerr << #x << " = " << x << endl

using namespace std;
using ll = long long;
using ld = long double;
template <typename T, typename A>
ostream& operator<<(ostream& os, const vector<T, A>& v)
{
    os << "sz:" << v.size() << "\n[";
    for (const auto& p : v) {
        os << p << ",";
    }
    os << "]\n";
    return os;
}

constexpr ll MOD = 1000000007LL;

template <typename T>
constexpr T INF = numeric_limits<T>::max() / 10;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<ll> a(N);
    vector<int> odd;
    vector<int> even;
    ll oddsum = 0;
    ll evensum = 0;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        if (a[i] > 0) {
            if (i % 2 == 0) {
                even.push_back(i);
                evensum += a[i];
            } else {
                odd.push_back(i);
                oddsum += a[i];
            }
        }
    }
    const vector<int> ind = (oddsum > evensum ? odd : even);
    if (ind.empty()) {
        const int maxind = max_element(a.begin(), a.end()) - a.begin();
        cout << a[maxind] << endl;
        vector<int> op;
        for (int i = N - 1; i > maxind; i--) {
            op.push_back(i);
        }
        for (int i = 0; i < maxind; i++) {
            op.push_back(0);
        }
        cout << op.size() << endl;
        for (const int e : op) {
            cout << e + 1 << endl;
        }
    } else {
        cout << max(oddsum, evensum) << endl;
        const int size = ind.size();
        vector<int> op;
        for (int i = N - 1; i > ind[size - 1]; i--) {
            op.push_back(i);
        }
        for (int i = size - 1; i >= 1; i--) {
            const int half = (ind[i] + ind[i - 1]) / 2;
            for (int j = half; j >= ind[i - 1] + 1; j--) {
                op.push_back(j);
            }
        }
        for (int i = ind[0] - 1; i >= 0; i--) {
            op.push_back(0);
        }
        cout << op.size() << endl;
        for (const int e : op) {
            cout << e + 1 << endl;
        }
    }
    return 0;
}
