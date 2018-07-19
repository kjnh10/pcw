#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int k;
    cin >> n >> k;
    int dis = 0;
    for(int i = 0;i < n;i++)
    {
        int x;
        cin >> x;
        dis += min(abs(x) * 2,abs(k-x) * 2);
    }
    cout << dis;
    return 0;
}
