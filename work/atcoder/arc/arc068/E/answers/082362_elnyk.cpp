#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <cmath>
#include <list>
#include <cassert>

using namespace std;

#define y1 roman_kaban
#define rank oryshych_konb
#define ull unsigned long long
const int mod = int(1e9) + 7;
const long long infLL = 2e18;
const int MX = 300105;

pair<int,pair<int,int>> a[MX];
int r[MX];
const int delta = 1 << 17;
int b[2 * delta];

int get(int pos){
    pos += delta;
    int ans = 0;
    while(pos){
        ans += b[pos];
        pos >>= 1;
    }
    return ans;
}

void add(int l, int r, int val){
    l += delta;
    r += delta;
    while(l <= r){
        if(l & 1){
            b[l++] += val;
            continue;
        }
        if(r % 2 == 0){
            b[r--] += val;
            continue;
        }
        l >>= 1;
        r >>= 1;
    }
}

int main()
{
    //init();
    //cerr << delta << endl;
    //freopen("/Users/ozzy/Documents/in.txt","r", stdin);
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int l, r;
        cin >> l >> r;
        a[i] = {r - l + 1, {l, r}};
        add(l, r, 1);
    }
    sort(a, a + n);
    int to_add = 0;
    for(int i = m; i > 0; i--){
        while(n > 0 && a[n - 1].first == i){
            to_add++;
            add(a[n - 1].second.first, a[n - 1].second.second, -1);
            n--;
        }
        r[i] = to_add;
        for(int j = 0; j <= m; j += i){
            r[i] += get(j);
        }
    }
    for(int i = 1; i <= m; i++){
        cout << r[i] << '\n';
    }
    return 0;
}
