#include "bits/stdc++.h"
using namespace std;
#define OUT(x) cout << #x << " = " << x << endl
#define rep(i, n)             for (int (i) = 0; (i) < (int)(n); (i)++)
#define rer(i, l, r)          for (int (i) = (int)(l); (i) <= (int)(r); (i)++)
#define reu(i, l, r)          for (int (i) = (int)(l); (i) < (int)(r); (i)++)
#define all(x)                (x).begin(), (x).end()
#define rall(x)               (x).rbegin(), (x).rend()
template<typename T> void pv(T a, T b) { for (T i = a; i != b; i ++) cout << *i << " "; cout << endl; }
template<typename T, typename U> inline void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if (x < y) x = y; }
int in() { int x; scanf("%d", &x); return x; }
long long lin() { long long x; scanf("%lld", &x); return x; }

static const int INF = 0x3f3f3f3f;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
#define int long long

signed main() { 
        int H, W;
        cin >> H >> W;
        vector<string> c(H);
        rep(i, H) cin >> c[i];
        int od = INFL, xd = INFL;
        rep(i, H) {
                rep(j, W) {
                        if (c[i][j] == 'x') {
                                amin(xd, j);
                                break;
                        } 
                        if (c[i][j] == 'o') break;
                }
                reverse(all(c[i]));
                rep(j, W) {
                        if(c[i][j] == 'o') {
                                amin(od, j);
                                break;
                        }
                        if (c[i][j] == 'x') break;
                }
                reverse(all(c[i]));
        }
        if (od != INFL || xd != INFL) {
                if (od <= xd) cout << 'o' << endl;
                else cout << 'x' << endl;
                return 0;
        }
        vector<pair<int, pair<vector<int>, vector<int>>>> P;
        vector<int> opoint;
        vector<int> xpoint;
        rep(i, H) {
                rep(j, W) {
                        if (c[i][j] == '.') continue;
                        if (c[i][j] == 'o') {
                                if (!xpoint.empty()) {
                                        reverse(all(opoint));
                                        P.push_back(make_pair(opoint.size() + xpoint.size() - 2, make_pair(opoint, xpoint)));
                                        opoint.clear();
                                        xpoint.clear();
                                }
                                opoint.push_back(j);
                        } else {
                                xpoint.push_back(j);
                        }
                }                 
        }
        reverse(all(opoint));
        if (!xpoint.empty()) P.push_back(make_pair(opoint.size() + xpoint.size() - 2, make_pair(opoint, xpoint)));
        sort(rall(P));
        //rep(i, P.size()) {
        //        cout << P[i].first << endl;
        //}
        bool oturn = true;
        int ocnt = 0, xcnt = 0;
        for (auto i : P) {
                int l = i.second.first.front();
                int r = i.second.second.front();
                int d = r - l;
                d --;
                //cout << d << endl;
                if (d & 1) { //ターンは変わらない
                        int mid = (l + r) / 2; //mid - 1にoがきて、mid + 1にxがくる
                        reu(j, 1, i.second.first.size()) ocnt += (mid - 1) - i.second.first[j] - j;
                        reu(j, 1, i.second.second.size()) xcnt += i.second.second[j] - (mid + 1) - j;
                } else { //ターンが必ず変わる
                        if (oturn) {
                                int mid = (l + r + 1) / 2;
                                reu(j, 1, i.second.first.size()) ocnt += (mid - 1) - i.second.first[j] - j;
                                reu(j, 1, i.second.second.size()) xcnt += i.second.second[j] - (mid + 1) - j;
                        } else {
                                int mid = (l + r) / 2;
                                reu(j, 1, i.second.first.size()) ocnt += (mid - 1) - i.second.first[j] - j;
                                reu(j, 1, i.second.second.size()) xcnt += i.second.second[j] - (mid + 1) - j;
                        }
                        oturn ^= 1;
                }
        }
        //OUT(ocnt);
        //OUT(xcnt);
        if (oturn) {
                cout << (ocnt > xcnt ? 'o' : 'x') << endl;
        } else {
                cout << (ocnt < xcnt ? 'x' : 'o') << endl;
        }
        return 0;
}               
