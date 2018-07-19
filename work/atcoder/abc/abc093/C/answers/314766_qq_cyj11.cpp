#include <bits/stdc++.h>

using namespace std;

int a;
int b;
int c;
int res;

int main() {
    scanf("%d%d%d", &a, &b, &c);
    if(b < c) swap(b, c);
    if(a < b) swap(a, b);
    if(b < c) swap(b, c);
    if((2 * a - b - c) & 1) printf("%d\n", (2 * a - b - c + 3) / 2);
    else printf("%d\n", (2 * a - b - c) / 2);
    return 0;
}