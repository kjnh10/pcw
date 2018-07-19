#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#include <unordered_map>
#define REP(i,n) for(long (i)=0;(i)<(n);(i)++)
#define REPI(i,a,b) for(long (i)=(a);(i)<(b);(i)++)
constexpr long MOD = 1e9 + 7;
using namespace std;
using P = pair<long, long>;
using VI = vector<long>;
using VP = vector<P>;
using VVI = vector<VI>;

bool isp(long p) {
    if (p == 2) return true;
    if (p < 3) return false;
    if (p % 2 == 0) return false;
    for (long i = 3; i * i <= p; i += 2) {
        if (p % i == 0) return false;
    }
    return true;
}

VI ps[5];

int main() {
    long n;
    cin >> n;
    REP(i,55556) {
        if (isp(i)) {
            ps[i%5].push_back(i);
        }
    }
    
    REP(i,n-1) {
        cout << ps[1][i] << " ";
    }
    cout << ps[1][n-1] << endl;
}
