#include <bits/stdc++.h>
#define rep(i,j) for (int (i)=0;(i)<(int)(j);++(i))
#define put(i) cout << (i) << endl
using namespace std;
typedef long long ll;

int main() {
    vector<int> a(3);
    rep(i,3) cin >> a[i];
    sort(a.begin(),a.end());
    int b[] = {5,5,7};
    rep(i,3) {
        if (a[i] != b[i]) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}
