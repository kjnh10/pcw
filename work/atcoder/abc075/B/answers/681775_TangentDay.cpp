#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <random>
using namespace std;

#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define ALL(c) (c).begin(), (c).end()

typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VL> VVL;
typedef vector<VI> VVI;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

int dx[] = {-1,-1,-1,0,0,1,1,1};
int dy[] = {-1,0,1,-1,1,-1,0,1};

int main() {
    int n;
    string s;

    int h, w;
    cin >> h >> w;
    vector<string> t(h), ans(h);
    REP(i,h) cin >> t[i];
    REP(i,h) REP(j,w){
        if (t[i][j] == '#') ans[i] += '#';
        else{
            ans[i] += '0';
            REP(k,8){
                int ii = i + dx[k];
                int jj = j + dy[k];
                if (ii < 0 || jj < 0 || ii >= h || jj >= w) continue;
                if (t[ii][jj] == '#') ans[i][j]++;
            }
        }
    }

    REP(i,h) cout << ans[i] << endl;

    return 0;
}