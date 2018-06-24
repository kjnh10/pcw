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
    int n, y;
    cin >> n >> y;

    for(int a=0; a<=n; ++a){
        for(int b=0; a+b<=n; ++b){
            int c = n - a - b;
            int x = a * 10000 + b * 5000 + c * 1000;
            if(x == y){
                cout << a << ' ' << b << ' ' << c << endl;
                return 0;
            }
        }
    }

    cout << "-1 -1 -1" << endl;
    return 0;
}
