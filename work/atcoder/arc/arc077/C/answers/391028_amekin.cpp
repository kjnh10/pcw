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
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; ++i)
        cin >> a[i];

    deque<int> b;
    for(int i=0; i<n; ++i){
        if(i % 2 == 0)
            b.push_back(a[i]);
        else
            b.push_front(a[i]);
    }
    if(n % 2 != 0)
        reverse(b.begin(), b.end());

    cout << b[0];
    for(int i=1; i<n; ++i)
        cout << ' ' << b[i];
    cout << endl;

    return 0;
}
