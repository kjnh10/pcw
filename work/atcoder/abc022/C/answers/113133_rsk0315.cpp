#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstdint>

using namespace std;

using Weight=int64_t;
static const Weight INF=1LL<<61;

int main() {
    size_t N;
    int M;
    scanf("%zu %d", &N, &M);

    vector<vector<Weight>> g(N, vector<Weight>(N, INF));
    vector<Weight> h(N, INF);
    for (int i=0; i<M; ++i) {
        size_t u, v;
        Weight l;
        scanf("%zu %zu %lld", &u, &v, &l);
        --u, --v;
        if (u) {
            g[u][v] = g[v][u] = l;
        } else {
            h[v] = l;
        }
    }

    for (size_t k=0; k<N; ++k)
        for (size_t i=0; i<N; ++i)
            for (size_t j=0; j<N; ++j)
                if (g[i][j] > g[i][k] + g[k][j])
                    g[i][j] = g[i][k] + g[k][j];

    Weight res=INF;
    for (size_t s=1; s<N; ++s)
        for (size_t t=s+1; t<N; ++t)
            res = min(res, h[s]+g[s][t]+h[t]);

    printf("%lld\n", res<INF? res:-1);
    return 0;
}
