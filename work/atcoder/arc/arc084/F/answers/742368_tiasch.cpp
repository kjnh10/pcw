#include <cstdio>
#include <cstring>
#include <bitset>
#include <vector>

const int L = 4001;
const int MOD = 998244353;

using Bitset = std::bitset<L>;

int n, m, len[6], pow[L + 1];
char buf[L + 1];
Bitset x, a[6];

int main()
{
#ifdef LOCAL_JUDGE
    freopen("F.in", "r", stdin);
#endif
    scanf("%d", &n);
    scanf("%s", buf);
    m = strlen(buf);
    for (int j = 0; j < m; ++ j) {
        if (buf[j] == '1') {
            x.set(m - 1 - j);
        }
    }
    for (int i = 0; i < n; ++ i) {
        scanf("%s", buf);
        len[i] = strlen(buf);
        for (int j = 0; j < len[i]; ++ j) {
            if (buf[j] == '1') {
                a[i].set(len[i] - 1 - j);
            }
        }
    }
    int i0 = 0;
    for (int i = 0; i < n; ++ i) {
        if (len[i] < len[i0]) {
            i0 = i;
        }
    }
    while (true) {
        int new_i0 = i0;
        for (int i = 0; i < n; ++ i) {
            while (i != i0 && len[i] >= len[i0]) {
                a[i] ^= a[i0] << (len[i] - len[i0]);
                while (len[i] > 0 && !a[i].test(len[i] - 1)) {
                    len[i] --;
                }
            }
            if (len[i] > 0 && len[i] < len[new_i0]) {
                new_i0 = i;
            }
        }
        if (i0 == new_i0) {
            break;
        }
        i0 = new_i0;
    }
    pow[0] = 1;
    for (int i = 1; i <= L; ++ i) {
        pow[i] = (pow[i - 1] << 1) % MOD;
    }
    auto b = a[i0];
    Bitset s;
    int result = 0;
    for (int i = len[i0] - 1; i < L; ++ i) {
        if (x.test(i)) {
            s ^= b;
            result += pow[i - (len[i0] - 1)];
            if (result >= MOD) {
                result -= MOD;
            }
        }
        b <<= 1;
        if (b.test(len[i0] - 1)) {
            b ^= a[i0];
        }
    }
    bool ok = true;
    for (int i = len[i0] - 2; i >= 0; -- i) {
        if (x.test(i) < s.test(i)) {
            ok = false;
        }
        if (x.test(i) > s.test(i)) {
            break;
        }
    }
    result += ok;
    if (result >= MOD) {
        result -= MOD;
    }
    printf("%d\n", result);
}

