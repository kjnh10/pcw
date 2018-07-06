#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <array>
#include <cmath>
#include <iterator>
#include <utility>
#include <set>
#include <random>
#include <map>
#include <stack>
#include <queue>
#include <list>

using namespace std;


int main() {
    int n, x, tmp, tmp2, ans = 0;
    vector<int> a,b;
    cin >> n >> x;
    for (size_t i = 0; i < n; i++)
    {
        cin >> tmp;
        a.emplace_back(tmp);
    }

    for (size_t i = 0; i < n ; i++)
    {
        if (x > 0)
        {
            tmp2 = x % 2;
            x /= 2;
            b.emplace_back(tmp2);
        }
        else
        {
            b.emplace_back(0);
        }
    }

    for (size_t i = 0; i < n; i++)
    {
        ans += (a[i] * b[i]);
    }
    cout << ans << endl;
    return 0;
}