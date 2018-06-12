#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <sstream>
#include <algorithm>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <climits>
#include <bitset>
#include <functional>
#include <numeric>
#include <ctime>
#include <cassert>
#include <cstring>
#include <fstream>

using namespace std;

int main() {
    int a, b, k;
    cin >> a >> b >> k;
    set<int> ans;
    for (int i = a; i < min(b+1, a + k); i++)
        ans.insert(i);
    for (int i = b; i > max(a-1, b - k); i--) {
        ans.insert(i);
    }
    for (auto t : ans)
        cout << t << endl;

    return 0;
}