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
    long long r, b, x, y;
    cin >> r >> b >> x >> y;

    long long left = 0;
    long long right = min(r, b);
    while(left < right){
        long long mid = (left + right + 1) / 2;
        long long a = (r - mid) / (x - 1) + (b - mid) / (y - 1);
        if(a < mid)
            right = mid - 1;
        else
            left = mid;
    }
    cout << left << endl;

    return 0;
}