#include <bits/stdc++.h>

using namespace std;

int a;
int b;
int k;
int jsq;
int res[2005];

int main() {
    scanf("%d%d%d", &a, &b, &k);
    for(int i = 0; i < k && a + i <= b; i++)
        res[++jsq] = a + i, res[++jsq] = b - i;
    sort(res + 1, res + 1 + jsq);
    for(int i = 1; i <= jsq; i++)
        if(res[i] != res[i - 1]) printf("%d\n", res[i]);
    return 0;
}