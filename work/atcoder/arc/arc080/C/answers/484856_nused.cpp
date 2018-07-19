#include <bits/stdc++.h>
using namespace std;

int a[100005];

int main()
{
    int n;
    scanf("%d",&n);
    for (int i = 1; i <= n; i++) scanf("%d",&a[i]);
    int z[3] = {};
    for (int i = 1; i <= n; i++)
    {
        if (a[i] & 1) z[0]++;
        else if (a[i] % 4 == 0) z[2]++;
        else z[1]++;
    }

    if (z[0] > z[2] + 1 || (z[0] == z[2] + 1 && z[1])) printf("No\n");
    else printf("Yes\n");
}

