#include <cstdio>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

static const double PI=3.14159165358979323;

int main() {
    size_t N;
    scanf("%zu", &N);

    vector<double> R(N);
    for (size_t i=0; i<N; ++i)
        scanf("%lf", &R[i]);

    sort(R.begin(), R.end(), greater<double>());
    double res=0, c=1;

    for (double r: R) {
        res += c * r * r;
        c = -c;
    }

    res *= PI;
    printf("%.9f\n", res);
    return 0;
}
