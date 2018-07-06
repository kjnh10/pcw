#include <cstdio>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

int main() {
    size_t N, K;
    scanf("%zu %zu", &N, &K);

    vector<int> R(N);
    for (size_t i=0; i<N; ++i)
        scanf("%d", &R[i]);

    sort(R.begin(), R.end(), greater<int>());

    double res=0.0;
    for (size_t i=K; i-->0;)
        (res += R[i]) *= 0.5;

    printf("%.9f\n", res);
    return 0;
}
