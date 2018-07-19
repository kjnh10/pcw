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

int main()
{
    long long n;
    cin >> n;

    int ans = INT_MAX;
    for(long long a=1; a*a<=n; ++a){
        if(n % a != 0)
            continue;
        long long b = n / a;
        int len = max(to_string(a).length(), to_string(b).length());
        ans = min(ans, len);
    }
    cout << ans << endl;

    return 0;
}
