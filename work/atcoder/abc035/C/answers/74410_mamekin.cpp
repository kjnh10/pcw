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
    int n, q;
    cin >> n >> q;

    vector<int> v(n+2, 0);
    while(--q >= 0){
        int l, r;
        cin >> l >> r;
        ++ v[l];
        -- v[r+1];
    }

    for(int i=1; i<=n; ++i){
        cout << (v[i] % 2);
        v[i+1] += v[i];
    }
    cout << endl;

    return 0;
}