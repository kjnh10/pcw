#include <bits/stdc++.h>
using namespace std;
int cnt[8];
int main()
{
    int n;
    cin >> n;
    int alot = 0;
    for(int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if(x >= 3200) alot++;
        else cnt[x/400]++;
    }
    int c = 0;
    for(int i = 0; i < 8; i++) if(cnt[i] > 0) c++;
    int mn = c + alot;
    int mx;
    if(c == 0) mx = 1;
    else mx = c;
    printf("%d %d\n", mx, mn);
    return 0;
}
