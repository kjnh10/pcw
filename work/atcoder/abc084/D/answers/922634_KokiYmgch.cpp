#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

//N以下の素数列挙。O(N log log N)
int N = 101000;
set<int> primes;
vector<bool> is_prime(N + 1, true);
void init() {
        is_prime[0] = is_prime[1] = false;
        for (int i = 2; i <= N; i ++) {
                if (is_prime[i]) {
                        primes.insert(i);
                        for (int j = i + i; j <= N; j += i) is_prime[j] = false;
                }
        }
}

int main() {
        init();
        vector<int> ok(101000, 0);
        for (int i = 1; i <= 100000; i ++) {
                if (i & 1) {
                        if (primes.count(i) && primes.count((i + 1) / 2)) ok[i] = 1;
                }
        }
        for (int i = 1; i <= 100000; i ++) {
                ok[i] += ok[i - 1];
        }
        int q;
        scanf("%d", &q);
        while (q --) {
                int l, r;
                scanf("%d%d", &l, &r);
                printf("%d\n", ok[r] - ok[l - 1]);
        }
        return 0;
}

