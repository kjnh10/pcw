#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#pragma GCC optimize ("-O3")
using namespace std; void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
//---------------------------------------------------------------------------------------------------
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧  
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     
　　　　／　　　＼　 　  |　|     
　　　 /　　 /￣￣￣￣/　　|  
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿  
　 　　　＼/＿＿＿＿/　（u　⊃  
---------------------------------------------------------------------------------------------------*/





int N, Z, W, A[2010];
#define INF INT_MAX/2
//---------------------------------------------------------------------------------------------------
int memo[2010][2];
int f(int id, int turn, int x, int y) {
    if (id == N) return abs(x - y);

    if (0 <= memo[id][turn]) return memo[id][turn];

    if (turn == 0) {
        int ma = -1;
        rep(i, id, N) ma = max(ma, f(i + 1, 1 - turn, A[i], y));
        return memo[id][turn] = ma;
    } else {
        int mi = INF;
        rep(i, id, N) mi = min(mi, f(i + 1, 1 - turn, x, A[i]));
        return memo[id][turn] = mi;
    }
}
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N >> Z >> W;
    rep(i, 0, N) cin >> A[i];

    rep(i, 0, N) rep(t, 0, 2) memo[i][t] = -1;
    cout << f(0, 0, Z, W) << endl;
}