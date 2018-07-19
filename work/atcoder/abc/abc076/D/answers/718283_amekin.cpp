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
#include <iterator>
using namespace std;

const double INF = DBL_MAX / 10;

int main()
{
    int n;
    cin >> n;
    vector<int> t(n), v(n);
    for(int i=0; i<n; ++i)
        cin >> t[i];
    for(int i=0; i<n; ++i)
        cin >> v[i];

    vector<double> dp(101, -INF);
    dp[0] = 0.0;
    for(int i=0; i<n; ++i){
        for(int j=0; j<t[i]; ++j){
            vector<double> nextDp(101, -INF);
            for(int k=0; k<=v[i]; ++k){
                nextDp[k] = max(nextDp[k], dp[k] + k);
                if(k < v[i]){
                    nextDp[k] = max(nextDp[k], dp[k] + k + 0.25);
                    nextDp[k+1] = max(nextDp[k+1], dp[k] + k + 0.5);
                }
                if(k > 0)
                    nextDp[k-1] = max(nextDp[k-1], dp[k] + k - 0.5);
            }
            dp.swap(nextDp);
        }
    }
    printf("%.10f\n", dp[0]);

    return 0;
}
