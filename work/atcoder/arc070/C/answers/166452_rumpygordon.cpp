#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e5 + 100, inf = 1e9 + 100;



int main()
{
    #ifdef ONPC
    ifstream cin("a.in");
    ofstream cout("a.out");
    #else
    //ifstream cin("gift.in");
    //ofstream cout("gift.out");
    #endif // ONPC
    ios::sync_with_stdio(0);
    ll x;
    cin >> x;
    ll l = 0, r = x + 1;
    while (r - l > 1){
        ll m = (l + r) / 2;
        if (m * (m + 1) / 2 >= x)
            r = m;
        else
            l = m;
    }
    cout << r;
}
