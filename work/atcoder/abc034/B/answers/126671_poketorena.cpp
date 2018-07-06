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
    int n;
    cin >> n;
    if (n % 2 == 0)
    {
        cout << n - 1 << endl;
    }
    else
    {
        cout << n + 1 << endl;
    }
    return 0;
}