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
    string s;
    cin >> s;
    int n = s.size();

    int ans = 0;
    for(int i=1; i<n; ++i){
        if(s[i] != s[i-1])
            ++ ans;
    }
    cout << ans << endl;

    return 0;
}