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

const int INF = INT_MAX / 2;

int main()
{
    int n, t;
    cin >> n >> t;
    vector<int> a(n);
    for(int i=0; i<n; ++i)
        cin >> a[i];

    int aMin = INF;
    int diffMax = -INF;
    int cnt = 0;
    for(int i=0; i<n; ++i){
        int diff = a[i] - aMin;
        if(diff == diffMax){
            ++ cnt;
        }
        else if(diffMax < diff){
            diffMax = diff;
            cnt = 1;
        }
        aMin = min(aMin, a[i]);
    }
    cout << cnt << endl;

    return 0;
}