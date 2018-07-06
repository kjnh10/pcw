#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
//#include<cctype>
#include<climits>
#include<iostream>
#include<string>
#include<vector>
#include<map>
//#include<list>
#include<queue>
#include<deque>
#include<algorithm>
//#include<numeric>
#include<utility>
#include<complex>
//#include<memory>
#include<functional>
#include<cassert>
#include<set>
#include<stack>

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    int t;
    cin >> t;
    int cnt = 0;
    int x = 0, y = 0;
    for (char c : s) {
        switch (c) {
        case 'U':
            y++;
            break;
        case 'D':
            y--;
            break;
        case 'L':
            x--;
            break;
        case 'R':
            x++;
            break;
        default:
            cnt++;
            break;
        }
    }
    if (t==1) {
        cout << abs(x) + abs(y) + cnt << endl;
    } else {
        int dist = abs(x)+abs(y);
        if (dist > cnt) cout << dist-cnt << endl;
        else {
            if ((cnt-dist)%2 == 0) cout << 0 << endl;
            else cout << 1 << endl;
        }
    }
    return 0;
}
