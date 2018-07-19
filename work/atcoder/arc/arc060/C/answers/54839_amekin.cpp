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
using namespace std;

const int MAX = 50;

int main()
{
    int n, a;
    cin >> n >> a;

    vector<vector<long long> > dp(n+1, vector<long long>(MAX * n + 1, 0));
    dp[0][0] = 1;
    for(int i=0; i<n; ++i){
        int x;
        cin >> x;
        for(int j=i; j>=0; --j){
            for(int k=0; k<=MAX*i; ++k){
                dp[j+1][k+x] += dp[j][k];
            }
        }
    }

    long long ans = 0;
    for(int i=1; i<=n; ++i)
        ans += dp[i][i*a];
    cout << ans << endl;

    return 0;
}