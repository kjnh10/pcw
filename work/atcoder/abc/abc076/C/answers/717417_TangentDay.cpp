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

int main() {
    string s, t;
    cin >> s >> t;
    int n = s.length(), m = t.length();

    string ans;
    REP(i,n-m+1){
        bool ok = true;
        REP(j,m){
            if (s[i+j] != '?' && s[i+j] != t[j]) ok = false;
        }
        // cout << i << ok << endl;
        if (ok){
            string tmp = s;
            REP(j,m) tmp[i+j] = t[j];
            REP(i,n) if (tmp[i] == '?') tmp[i] = 'a';
            if (ans.empty()) ans = tmp;
            else ans = min(ans, tmp);
        }
    }

    cout << (ans.empty() ? "UNRESTORABLE" : ans) << endl;
    return 0;
}
