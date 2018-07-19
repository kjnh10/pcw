#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <cmath>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <numeric>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define all(x) (x).begin(), (x).end()
#define itr(i, x) for(auto i = (x).begin(); i != (x).end(); i++)
#define ritr(i, x) for(auto i = (x).rbegin(); i != (x).rend(); i++)
#define INF 1010101010
#define MOD 1000000007
#define LL long long

int main() {
    string a, b, c;
    int diff = 'A' - 'a';
    cin >> a >> b >> c;
    cout << (char)(a[0] + diff) << (char)(b[0] + diff) << (char)(c[0] + diff) << endl;
}