#include <bits/stdc++.h>
using namespace std;

pair < long long, long long > cut(long long a, long long b){
    return { (a / 2) * b, (a / 2 + a % 2) * b };
}

int main(int argc, char **argv){
    long long x, y;
    cin >> x >> y;
    long long area = 0;
    long long ans = 1ll << 60;
    for(long long i = 1;i < x;i++){
        area += y;
        pair < long long, long long > a = cut(x - i, y);
        pair < long long, long long > b = cut(y, x - i);
        ans = min(ans, max({area, a.first, a.second}) - min({ area, a.first, a.second }));
        ans = min(ans, max({area, b.first, b.second}) - min({ area, b.first, b.second }));
    }
    area = 0;
    swap(x, y);
    for(long long i = 1;i < x;i++){
        area += y;
        pair < long long, long long > a = cut(x - i, y);
        pair < long long, long long > b = cut(y, x - i);
        ans = min(ans, max({area, a.first, a.second}) - min({ area, a.first, a.second }));
        ans = min(ans, max({area, b.first, b.second}) - min({ area, b.first, b.second }));
    }
    cout << ans;
}