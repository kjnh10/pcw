#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
const int N = 204721;
using namespace std;
typedef long long ll;
int mod = 1e9 + 7;

int main()
{
#ifndef ONLINE_JUDGE  
  //  freopen("in.txt","r" ,stdin);
    // freopen("out.txt", "w", stdout);
#endif 
    ll n, m;
    while (cin >> n >> m)
    {
        ll c = n - m;
        if (c < 0)
            c = -c;
        printf("%s\n", c <= 1?"Brown":"Alice");

    }
    return 0;
}