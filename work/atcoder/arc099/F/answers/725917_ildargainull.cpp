#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <bitset>
#include <sstream>

using namespace std;

typedef long long ll;

mt19937 rnd(228);

const int M = 1791791791;
const int M1 = 1e9 + 7;
const int M2 = 1e9 + 9;
const int B = 239;
const int B1 = 228;
const int B2 = 337;

inline int add(ll a, ll b, int M)
{
    a += b;
    if (a >= M) a -= M;
    if (a < 0) a += M;
    return a;
}

inline int mul(int a, int b, int M)
{
    return (a * (ll) b) % M;
}

inline int bin(int a, int n, int M)
{
    int res = 1;
    while (n)
    {
        if (n % 2 == 0)
        {
            a = mul(a, a, M);
            n /= 2;
        }
        else
        {
            res = mul(res, a, M);
            n--;
        }
    }
    return res;
}

const int rev_B = bin(B, M - 2, M);
const int rev_B1 = bin(B1, M1 - 2, M1);
const int rev_B2 = bin(B2, M2 - 2, M2);

string s;
int n;

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    cin >> s;
    int cur = 1;
    int hsh = 0;
    vector <int> p(n + 1);
    vector <int> p1(n + 1);
    vector <int> p2(n + 1);
    vector <int> h(n + 1);
    vector <int> h1(n + 1);
    vector <int> h2(n + 1);
    p[0] = 1;
    p1[0] = 1;
    p2[0] = 1;
    h[0] = 0;
    h1[0] = 0;
    h2[0] = 0;
    int cur_1 = 1;
    int hsh_1 = 0;
    int cur_2 = 1;
    int hsh_2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '>')
        {
            cur = mul(cur, B, M);
            cur_1 = mul(cur_1, B1, M1);
            cur_2 = mul(cur_2, B2, M2);
        }
        else if (s[i] == '<')
        {
            cur = mul(cur, rev_B, M);
            cur_1 = mul(cur_1, rev_B1, M1);
            cur_2 = mul(cur_2, rev_B2, M2);
        }
        else if (s[i] == '+')
        {
            hsh = add(hsh, cur, M);
            hsh_1 = add(hsh_1, cur_1, M1);
            hsh_2 = add(hsh_2, cur_2, M2);
        }
        else
        {
            hsh = add(hsh, -cur, M);
            hsh_1 = add(hsh_1, -cur_1, M1);
            hsh_2 = add(hsh_2, -cur_2, M2);
        }
        p[i + 1] = cur;
        h[i + 1] = hsh;
        p1[i + 1] = cur_1;
        h1[i + 1] = hsh_1;
        p2[i + 1] = cur_2;
        h2[i + 1] = hsh_2;
    }
    ll ans = 0;
    map <pair <int, pair <int, int> > , int> ret;
    for (int i = n; i >= 0; i--)
    {
        int need = add(mul(hsh, p[i], M), h[i], M);
        int need_1 = add(mul(hsh_1, p1[i], M1), h1[i], M1);
        int need_2 = add(mul(hsh_2, p2[i], M2), h2[i], M2);
        ans += ret[{need, {need_1, need_2}}];
        ret[{h[i], {h1[i], h2[i]}}]++;
    }
    cout << ans << '\n';
}
