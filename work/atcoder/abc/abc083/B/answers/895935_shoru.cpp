#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <fstream>
#define case(t) printf("Case #%d: ", (t))
#define pii pair<int, int>
#define vii vector<pii>
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define f first
#define s second
typedef long long ll;
const double pi = acos(-1);
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;
const int MAXN = 1e5 + 5;
const double eps = 1e-9;
using namespace std;

int sum(int x)
{
    if (x < 10) return x;
    return (x % 10) + sum(x / 10);
}

int main()
{
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int x = sum(i);
        if (x >= a && x <= b) ans += i;
    }
    printf("%d\n", ans);
    return 0;
}
