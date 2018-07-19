#include <bits/stdc++.h>

int main(void) {
    std::map<int, int> cnt;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int a;
        scanf("%d", &a);
        ++cnt[a];
        ++cnt[a - 1];
        ++cnt[a + 1];
    }
    int max = 0;
    for (auto i: cnt) {
        max = std::max(max, i.second);
    }
    printf("%d\n", max);
    return 0;
}