# include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define pll pair<ll, ll>

#define pb push_back
#define eb emplace_back
#define mp make_pair

#define fi first
#define se second

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int inf = (int)1e9 + 7;
const int maxn = (int)6e5 + 7;
const int lmaxn = (int)6e6 + 7;
const ll linf = (ll)1e16 + 7;

const ld eps = ld(1e-11);

const ll dx[] = {-1, 0, 0, 1};
const ll dy[] = {0, -1, 1, 0};

ll gcd(ll a, ll b){
    while(b) a %= b, swap(a, b);
    return a | b;
}

ll lcm(ll a, ll b){
    return a * b / gcd(a, b);
}

string s;
ll a[maxn], sz;

int main(){
    cin >> s;
    for(auto i : s){
        if(i == '0') a[++sz] = 0;
        else if(i == '1') a[++sz] = 1;
        else --sz;
        sz = max(0ll, sz);
    }
    for(ll i = 1; i <= sz; ++i)
        cout << a[i];
    return 0;
}

