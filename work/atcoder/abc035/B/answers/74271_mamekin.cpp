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
    string s;
    int t;
    cin >> s >> t;

    int dx = abs(count(s.begin(), s.end(), 'L') - count(s.begin(), s.end(), 'R'));
    int dy = abs(count(s.begin(), s.end(), 'U') - count(s.begin(), s.end(), 'D'));
    int q  = count(s.begin(), s.end(), '?');

    int ans;
    if(t == 1){
        ans = dx + dy + q;
    }
    else{
        if(q <= dx + dy)
            ans = dx + dy - q;
        else if((q - dx - dy) % 2 == 0)
            ans = 0;
        else
            ans = 1;
    }
    cout << ans << endl;

    return 0;
}