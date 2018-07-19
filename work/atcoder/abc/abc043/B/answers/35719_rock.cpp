//#define M_PI 3.14159265358979323846
#define _USE_MATH_DEFINES

//#define _GLIBCXX_DEBUG
//#define all(x) (x).begin(),(x).end()

#include <bits/stdc++.h>

#define TASK ""
#define sqr(x) ((x)*(x))
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;
const ll INFLL = numeric_limits<int>::max();
const ll INFINT = numeric_limits<int>::max();
const ld EPS = 1e-7;
const ll MOD = 1000000000;
const ll MAXN = 123456;

void run()
{
    string s;
    cin >> s;
    string ans = "";
    for(char c: s)
    {
        if(c=='B')
        {
            if(ans.size()) ans.pop_back();
        }
        else ans.push_back(c);
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

#ifdef LOCAL
//#define STRESS
#ifdef STRESS
    freopen("input.txt", "w", stdout);
    cout << "1000 50\n";
    for (int i = 0; i < 999; i++)
    {
        for (int j = 0; j < 999; j++) cout << ".";
        cout << "X\n";
    }
    for (int j = 0; j < 1000; j++)
        if (j != 1000 / 50)cout << "X";
        else cout << ".";
    return 0;

#endif
    if (strcmp(TASK, "-") != 0)
    {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
#else
    if (strcmp(TASK, "")   != 0)
    {
        freopen(TASK".in", "r", stdin)  ;
        freopen(TASK".out", "w", stdout)  ;
    }
#endif
    run();

    return 0;
}