#include <bits/stdc++.h>
using namespace std;

char str[2000050];

int main() {
    scanf("%s", str);
    int idx = 0;
    while (str[idx] != 'A') idx++;
    int idx2 = strlen(str) - 1;
    while (str[idx2] != 'Z') idx2--;
    printf("%d\n", idx2 - idx + 1);
    return 0;
}

