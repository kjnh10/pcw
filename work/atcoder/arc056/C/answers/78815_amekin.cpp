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

int main()
{
    long long a, b, k, l;
    cin >> a >> b >> k >> l;

    long long ans = min(k / l * b + k % l * a, (k + l - 1) / l * b);
    cout << ans << endl;

    return 0;
}