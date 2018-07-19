#include <bits/stdc++.h>
using namespace std;

constexpr int M = 1e9 + 7;

class union_find {
public:
    union_find(int n)
        : par_(n, -1)
    {}

    int root(int x) {
        return par_[x] < 0 ? x : par_[x] = root(par_[x]);
    }

    bool unite(int x, int y) {
        x = root(x); y = root(y);
        if(x == y) {
            return false;
        } else {
            if(par_[x] < par_[y]) {
                par_[x] += par_[y];
                par_[y] = x;
            } else {
                par_[y] += par_[x];
                par_[x] = y;
            }
            return true;
        }
    }

private:
    std::vector<int> par_;
};


int main() {
    int h, w;
    cin >> h >> w;

    vector<int> pw(8);
    pw[0] = 1;
    for(int i = 1; i < 8; ++i) {
        pw[i] = pw[i - 1] * 7;
    }

    vector<int> cur(pw[h]);
    // 1 列目の計算
    for(int i = 0; i < (1 << h); ++i) {
        if(i % 2 == 0) {
            continue;
        }
        int s = 1; // 状態．最初 (0, 0) は必ず黒で塗られている．
        int label = 1; // 連結関係のラベル
        for(int j = 1; j < h; ++j) { // 0 行目は黒確定なので 1 から
            if(i >> j & 1) {
                s += label * pw[j]; // 7 進数 j 桁目が label という意味
            } else if(i >> (j - 1) & 1) { // 隙間が空いているので
                label++;                      // 連結関係をわける
            }
        }
        cur[s] = 1;
    }

    for(int i = 0; i < w - 1; ++i) {
        vector<int> nxt(pw[h]);
        for(int j = 0; j < pw[h]; ++j) { // 現状態．7 進数だと思えばよい．
            if(cur[j] == 0) {
                continue;
            }
            for(int k = 0; k < (1 << h); ++k) { // 次の状態（黒く塗られているかだけ）
                union_find uf(h); // 次の連結関係を求めるための union find 木
                vector<int> p(h); // 次状態の各行の連結関係を保存
                for(int l = 0; l < h; ++l) {
                    if(k >> l & 1) {             // 次状態の l 行目が黒
                        if(j / pw[l] % 7 == 1) { // 現状態で l 行目が (0, 0) と連結なら
                            p[l] = 1;            // 次状態でも l 行目は (0, 0) と連結
                        }

                        for(int m = l + 1; m < h; ++m) { // 連結関係を uf 木でまとめていく
                            if(k >> m & 1) {
                                if(m == l + 1) {    // l 行目と l + 1 行目がともに黒
                                    uf.unite(l, m); // 隣あってるので，l 行目と m 行目は連結
                                } else {
                                    int u = j / pw[l] % 7, // 現状態の l 行目，m 行目の連結関係
                                        v = j / pw[m] % 7;
                                    if(u > 0 && u == v) {  // どちらも現状態で同じ連結関係なら
                                        uf.unite(l, m);    // 次状態でも同じ連結関係
                                    }
                                }
                            }
                        }
                    }
                }

                for(int l = 0; l < h; ++l) {
                    if(p[l] == 1) {
                        p[uf.root(l)] = 1; // 次状態で (0, 0) と連結なものをまとめる
                    }
                }
                int nj = 0;     // 連結関係も含めた最終的な次状態
                int label = 2;  // 連結関係のラベル
                for(int l = 0; l < h; ++l) {
                    if(k >> l & 1) {        // 次状態で l 行目が黒である
                        int u = uf.root(l); // l 行目が連結関係にある集合
                        if(p[u] == 0) {     // その集合が (0, 0) に連結でなく，新しい連結関係であるなら
                            p[u] = label++; // どの連結関係かのラベルを割り当てる
                        }
                        nj += pw[l] * p[u];
                    }
                }
                nxt[nj] = (nxt[nj] + cur[j]) % M;
            }
        }
        cur.swap(nxt);
    }

    int res = 0;
    for(int i = 0; i < pw[h]; ++i) {
        if(i / pw[h - 1] % 7 == 1) {
            res = (res + cur[i]) % M;
        }
    }
    cout << res << endl;
}
