#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    size_t N;
    scanf("%zu", &N);

    vector<int> a(N);
    int sum=0;
    for (size_t i=0; i<N; ++i) {
        scanf("%d", &a[i]);
        sum += a[i];
    }

    if (sum % N)
        return !printf("-1\n");

    int tar=sum/N;
    int res=0, cur=1, psum=a[0];
    for (size_t i=1; i<N; ++i) {
        if (tar * cur != psum) {
            ++res;
            ++cur;
        } else {
            cur = 1;
            psum = 0;
        }

        psum += a[i];
    }

    printf("%d\n", res);
    return 0;
}
