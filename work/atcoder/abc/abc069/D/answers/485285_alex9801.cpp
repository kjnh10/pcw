#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <tuple>

using namespace std;

int arr[10010];
int res[110][110];

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int h, w, n, p, c, i, j;
    scanf("%d%d%d", &h, &w, &n);
    for(i = 1; i<=n; i++)
        scanf("%d", &arr[i]);

    p = 1;
    c = 0;
    for(i = 0; i<h; i++)
    {
        if(i%2 == 0)
        {
            for(j = 0; j<w; j++)
            {
                res[i][j] = p;
                c++;
                if(c == arr[p])
                {
                    p++;
                    c = 0;
                }
            }
        }
        else
        {
            for(j = w-1; j>=0; j--)
            {
                res[i][j] = p;
                c++;
                if(c == arr[p])
                {
                    p++;
                    c = 0;
                }
            }
        }
    }

    for(i = 0; i<h; i++)
    {
        for(j = 0; j<w; j++)
            printf("%d ", res[i][j]);
        printf("\n");
    }

    return 0;
}