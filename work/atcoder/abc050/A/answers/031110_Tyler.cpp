#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>  // assert(x>=10), 部分点問題
#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <set>

#define repl(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(x) (x).begin(), (x).end()
#define SORT(v,n) sort(v,v+n)
#define VSORT(v) sort(all(x))
#define FILL(v, value) (v+(sizeof(v) / sizeof *(v)), value);
#define inf 999999999
#define dbg(x) cout<<#x<<":"<<x<<endl;
#define pb(a) push_back((a))
#define mp(a) make_pair((a))
#define pi 2*acos(0.0)
#define in scanf
#define out printf
#define fi first
#define se second

// --
#define bit(n) (1LL<<(n)) // 左bitシフト
// --

using namespace std;

typedef long long llong;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;
typedef pair<llong, pll> plp;

const int MOD=1000000007;
const int dx[]={1,0,-1,0}, dy[]={0,-1,0,1};  // 右下左上


int main(int argc, char**argv){
    int a, b;
    char op;
    cin >> a >> op >> b;

    if (op == '+') cout << a + b << endl;
    if (op == '-') cout << a - b << endl;

    return 0;
}


