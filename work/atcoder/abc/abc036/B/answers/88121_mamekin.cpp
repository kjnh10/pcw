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
    int n;
    cin >> n;
    vector<string> s(n);
    for(int i=0; i<n; ++i)
        cin >> s[i];

    vector<string> t(n, string(n, ' '));
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            t[j][n-1-i] = s[i][j];
        }
    }

    for(int i=0; i<n; ++i)
        cout << t[i] << endl;

    return 0;
}