#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int (i)=(0);(i)<(int)(n);++(i))
using ll = long long;
using P = pair<int, int>;
using namespace std;

template<class T> void vin(vector<T>& v, int n) {
    v.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
}

int H, W;
int dr[] = { 1, 0, -1, 0 };
int dc[] = { 0, 1, 0, -1 };
bool ok(int r, int c) {
    return 0 <= r and r < H and 0 <= c and c < W;
}

int main() {
    cin >> H >> W;
    string b[51], b2[51];;
    rep(i, H) cin >> b[i];
    rep(r, H) {
        string tmp = "";
        rep(c, W) tmp += ".";
        b2[r] = tmp;
    }
    rep(r, H) rep(c, W) {
        if (b[r][c] == '#') {
            rep(d, 4) {
                int nr = r + dr[d], nc = c + dc[d];
                if (!ok(nr, nc)) continue;
                if (b[nr][nc] == '#') {
                    b2[r][c] = b2[nr][nc] = '#';
                }
            }
        }
    }
    bool ok = true;
    rep(r, H) {
        if (b[r] != b2[r]) {
            ok = false;
            break;
        }
    }
    cout << (ok ? "Yes" : "No") << endl;
    return 0;
}
