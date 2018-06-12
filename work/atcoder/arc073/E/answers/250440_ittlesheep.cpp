#include <functional>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <cctype>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>
#include <queue>
#include <stdint.h>
#include <stdio.h>
#include <stack>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <tuple>
#include <unordered_set>
#include <assert.h>
#define REP(i,n) for(int i=0;i<n;i++)
#define TR(i,x) for(__typeof(x.begin()) i=x.begin();i!=x.end();i++)
#define ALL(x) x.begin(),x.end()
#define SORT(x) sort(ALL(x))
#define CLEAR(x) memset(x,0,sizeof(x))
#define FILL(x,c) memset(x,c,sizeof(x))

using namespace std;

#define PB push_back
#define MP make_pair

typedef map<int,int> MII;
typedef map<string,int> MSI;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<long double> VD;
typedef pair<int,int> PII;
typedef long long int64;
typedef long long LL;
typedef unsigned int UI;
typedef long double LD;
typedef unsigned long long ULL;

int main() {
    int n;
    cin >> n;
    vector<PII> a(n);
    vector<PII> b;
    REP(i, n) {
        scanf("%d%d", &a[i].first, &a[i].second);
        b.PB(MP(a[i].first, i));
        b.PB(MP(a[i].second, i));
    }
    SORT(b);
    LL answer = 0x3F3F3F3F3F3F3F3FLL;
    LL delta = b[2 * n - 1].first - b[0].first;

    VI count(n, 0);
    int last = 0;
    int ones = 0;
    REP(i, 2 * n) {
        while (last < 2 * n && ones < n) {
            if (!count[b[last].second]) ++ones;
            ++count[b[last++].second];
        }
        if (ones == n) {
            answer = min(answer, delta * (b[last - 1].first - b[i].first));
        }

        if (!--count[b[i].second]) {
            --ones;
        }
    }

    fill(ALL(count), 0);
    last = 0;
    ones = 0;
    while (ones < n) {
        if (!count[b[last].second]) ++ones;
        ++count[b[last++].second];
    }

    LL len1 = b[last - 1].first - b[0].first;

    fill(ALL(count), 0);
    last = 2 * n - 1;
    ones = 0;
    while (ones < n) {
        if (!count[b[last].second]) ++ones;
        ++count[b[last--].second];
    }
    LL len2 = b[2 * n - 1].first - b[last + 1].first;
    answer = min(answer, len1 * len2);

    cout << answer << endl;
    return 0;
}