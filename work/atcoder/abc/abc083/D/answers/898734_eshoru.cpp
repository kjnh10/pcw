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
const int MAXN = 3e5 + 5;
const double eps = 1e-9;
using namespace std;
char tmp[MAXN];
int sum[MAXN];

int main()
{
    scanf("%s", tmp);
    int n = strlen(tmp);
    int lo = 0, hi = n;
    while (lo <= hi)
    {
        int mid = (lo + hi) >> 1;
        int cur = 0, flag = 1;
        memset(sum, 0, sizeof sum);
        for (int i = 0; i < n; i++)
        {
            cur += sum[i];
            if (tmp[i] == '1' && cur % 2 == 0)
            {
                if (i + mid > n && i < mid )
                {
                    flag = 0;
                    hi = mid - 1;
                    break;
                }
                sum[i]++, cur++;
                sum[i + mid]--;
            }
            else if (tmp[i] == '1' && cur % 2 == 1) {}
            else if (tmp[i] == '0' && cur % 2 == 0) {}
            else if (tmp[i] == '0' && cur % 2 == 1)
            {
                if (i + mid > n && i < mid)
                {
                    flag = 0;
                    hi = mid - 1;
                    break;
                }
                sum[i]++, cur++;
                sum[i + mid]--;
            }
        }
        if (flag) lo = mid + 1;
    }
    printf("%d\n", lo - 1);
    return 0;
}
