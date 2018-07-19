#include<cstdio>
#include<cstdlib>
#include<algorithm>

using namespace std;

int n;
int a[100000];

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", a+i);
    }
    sort(a, a+n);
    printf("%d ", a[n-1]);
    int t = 0;
    int diff = abs(a[n-1]-a[0]*2);
    for(int i = 1; i < n; ++i) {
        int diff2 = abs(a[n-1]-a[i]*2);
        if(diff > diff2) {
            diff = diff2;
            t = i;
        }
    }
    printf("%d\n", a[t]);
    return 0;
}
