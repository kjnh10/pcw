#include <bits/stdc++.h>
using namespace std;
#pragma GCC diagnostic ignored "-Wmissing-declarations"

#define FINAL_OUT(x) {cout << (x) << '\n'; exit(0);}

#define SHOW(x) std::cout << #x << " = " << x << std::endl;

int const maxn = 200005;

int fromone[maxn];
int ton[maxn];


int main()
{
//    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);


    long long k;
    cin >> k;
    int n = 50;

    long long t = (k + 49) / 50 * 50;
    vector<long long> a(n, t / 50 + 49);
    while (t > k)
    {
        auto it = max_element(begin(a), end(a));
        for(auto& x : a)
            ++x;
        (*it) -= 51;
        --t;
    }
    cout << 50 << endl;
    for(int i =0; i <n; ++i)
        cout << a[i] << " \n"[i == n - 1];
}
