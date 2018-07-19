#include <bits/stdc++.h>

const int N = 100100;

int p[N];

int main(void) {
    int n;
    scanf("%d", &n);
    std::vector<int> res;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &p[i]);
        if (p[i] == i + 1) {
            res.push_back(i);
        }
    }
    int answer = 0;
    std::sort(res.begin(), res.end());
    while (res.size() > 1) {
        if (res.back() == res[res.size() - 2] + 1) {
            res.pop_back();
            res.pop_back();
            ++answer;
        } else {
            res.pop_back();
            ++answer;
        }
    }
    answer += res.size();
    printf("%d\n", answer);
    return 0;
}