#include <bits/stdc++.h>
using namespace std;

int a[10005];

int ans[105][105];

int main()
{
    int h, w, n;
    scanf("%d%d%d",&h,&w,&n);
    for (int i = 1; i <= n; i++) scanf("%d",&a[i]);

    int p = 1;

    for (int i = 1; i <= h; i++)
    {
        if (i & 1)
        {
            for (int j = 1; j <= w; j++)
            {
                while (a[p] == 0) ++p;
                ans[i][j] = p;
                a[p]--;
            }
        }
        else
        {
            for (int j = w; j >= 1; j--)
            {  
                while (a[p] == 0) ++p;
                ans[i][j] = p;
                a[p]--;
            }
        }
    }
    for (int i = 1; i <= h; i++) for (int j = 1; j <= w; j++) printf("%d%c", ans[i][j], j == w ? '\n' : ' ');
}
