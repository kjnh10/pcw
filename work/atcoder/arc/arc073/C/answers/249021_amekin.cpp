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
    int n, t;
    cin >> n >> t;
    vector<int> a(n);
    for(int i=0; i<n; ++i)
        cin >> a[i];

    int ans = t;
    for(int i=0; i<n-1; ++i)
        ans += min(a[i+1] - a[i], t);
    cout << ans << endl;

    return 0;
}
