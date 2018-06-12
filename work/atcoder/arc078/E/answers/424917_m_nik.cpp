#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <string>
#include <cstring>
#include <complex>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair


int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    string r;
    cout << "? 10000000000" << endl;
    cin >> r;
    if (r == "Y") {
        ll x = 2;
        while(true) {
            cout << "? " << x << endl;
            cin >> r;
            if (r == "Y") {
                cout << "! " << x / 2 << endl;
                return 0;
            }
            x *= 10;
        }
    }

    ll R = 10;
    while(true) {
        cout << "? " << R << endl;
        cin >> r;
        if (r == "N") break;
        R *= 10;
    }

    ll L = R / 10;
    L--;
    R--;
    while(R - L > 1) {
        ll x = (L + R) / 2;
        cout << "? " << x << "0" << endl;
        cin >> r;
        if (r == "Y")
            R = x;
        else
            L = x;
    }
    cout << "! " << R << endl;

    return 0;
}