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
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define ALL(c) (c).begin(), (c).end()

typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

int main() {
    int n;
    cin >> n;
    VI a(26,50);
    REP(i,n){
        string s;
        cin >> s;
        VI b(26);
        REP(j,s.length()){
            b[s[j]-'a']++;
        }
        REP(j,26){
            a[j] = min(a[j], b[j]);
        }
    }
    string ans;
    REP(i,26){
        REP(j,a[i]){
            ans += ('a' + i);
        }
    }
    cout << ans << endl;


    return 0;
}