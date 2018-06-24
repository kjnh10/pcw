#define _USE_MATH_DEFINES
#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <complex>
#include <string>
#include <vector>
#include <array>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <limits>
#include <climits>
#include <cfloat>
#include <functional>
#include <iterator>
using namespace std;

const int INF = INT_MAX / 2;

int main()
{
    int n;
    cin >> n;

    vector<int> dp(n+1, INF);
    dp[n] = 0;
    for(int i=n; i>0; --i){
        for(int a=6; a<=i; a*=6)
            dp[i-a] = min(dp[i-a], dp[i] + 1);
        for(int a=9; a<=i; a*=9)
            dp[i-a] = min(dp[i-a], dp[i] + 1);
    }

    int ans = INF;
    for(int i=0; i<=n; ++i)
        ans = min(ans, dp[i] + i);
    cout << ans << endl;

    return 0;
}
