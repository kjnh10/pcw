#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <array>
#include <cmath>
#include <iterator>
#include <utility>
#include <set>
#include <random>
#include <map>
#include <stack>
#include <queue>
#include <list>

using namespace std;


int main() {
    string a, b;
    cin >> a >> b;
    if (a.size() > b.size())
    {
        cout << a << endl;
    }
    else
    {
        cout << b << endl;
    }
    return 0;
}