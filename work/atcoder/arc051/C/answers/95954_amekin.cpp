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
    int x1, y1, r;
    int x2, y2, x3, y3;
    cin >> x1 >> y1 >> r >> x2 >> y2 >> x3 >> y3;

    if(x2 <= x1 - r && x1 + r <= x3 && y2 <= y1 - r && y1 + r <= y3)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;

    bool isInside = true;
    for(int i=0; i<4; ++i){
        int x = (i & 1)? x2 : x3;
        int y = (i & 2)? y2 : y3;
        int dx = x - x1;
        int dy = y - y1;
        if(r * r < dx * dx + dy * dy)
            isInside = false;
    }
    if(isInside)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;

    return 0;
}