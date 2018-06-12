#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <numeric>
#include <utility>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <unordered_map>
using namespace std;

#define REP(i, s) for (int i = 0; i < s; ++i)
#define ALL(v) (v.begin(), v.end())
#define COUT(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl
#define EACH(i, s) for (__typeof__((s).begin()) i = (s).begin(); i != (s).end(); ++i)

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<class T1, class T2> ostream& operator << (ostream &s, pair<T1,T2> P)
{ return s << '<' << P.first << ", " << P.second << '>'; }
template<class T> ostream& operator << (ostream &s, vector<T> P)
{ for (int i = 0; i < P.size(); ++i) { if (i > 0) { s << " "; } s << P[i]; } return s; }
template<class T> ostream& operator << (ostream &s, vector<vector<T> > P)
{ for (int i = 0; i < P.size(); ++i) { s << endl << P[i]; } return s << endl; }
template<class T> ostream& operator << (ostream &s, set<T> P)
{ EACH(it, P) { s << "<" << *it << "> "; } return s << endl; }
template<class T1, class T2> ostream& operator << (ostream &s, map<T1,T2> P)
{ EACH(it, P) { s << "<" << it->first << "->" << it->second << "> "; } return s << endl; }


int N;
long long a[1100];

const long long INF = 1LL<<59;

long long dp[1100]; // i is last
int Prev[1100];

int main() {
    while (cin >> N) {
        for (int i = 0; i < N; ++i) cin >> a[i];
        for (int i = 0; i < 1100; ++i) {
            dp[i] = -INF;
            Prev[i] = -1;
        }
        dp[0] = 0;
        for (int i = 0; i < N; ++i) {
            dp[i+1] = a[i];
            Prev[i+1] = -1;
        }
        
        for (int i = 0; i <= N; ++i) {
            for (int j = i+2; j <= N; j += 2) {
                if (chmax(dp[j], dp[i] + a[j-1])) {
                    Prev[j] = i;
                }
            }
            //cout << i << ", " << dp[i] << ": " << Prev[i] << endl;
        }
        
        long long res = -INF;
        int cur = -1;
        for (int i = 1; i <= N; ++i) if (chmax(res, dp[i])) cur = i;
        
        cout << res << endl;
        vector<int> pls;
        while (cur != -1) {
            pls.push_back(cur - 1);
            cur = Prev[cur];
        }
        
        vector<int> tres;
        int pos = N-1;
        while (pos > pls[0]) {
            tres.push_back(pos);
            --pos;
        }
        
        for (int i = 0; i < (int)pls.size() - 1; ++i) {
            for (int j = pls[i] - 2; j > pls[i+1]; j -= 2) {
                tres.push_back(j);
            }
            tres.push_back(pls[i+1] + 1);
        }
        
        for (int i = 0; i < pls.back(); ++i) {
            tres.push_back(0);
        }
        
        cout << tres.size() << endl;
        for (int i = 0; i < tres.size(); ++i) {
            cout << tres[i] + 1 << endl;
        }
        
    }
}



    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
