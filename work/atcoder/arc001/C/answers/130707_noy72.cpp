#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
const int INF = 2000000000;
using namespace std;

const int N = 8;

//row[i] = j : (i,j)にクイーン
int row[N], col[N], dpos[2 * N - 1], dneg[2 * N - 1];
char x[8][8];
bool f = false;

void init(){
    rep(i,N){
        row[i] = 0;
        col[i] = 0;
    }
    rep(i,2 * N - 1){
        dpos[i] = 0;
        dneg[i] = 0;
    }
}

void printBoard(){
    rep(i,N){
        rep(j,N){
            if(x[i][j] == 'Q'){
                if(row[i] != j) return;
            }
        }
    }
    rep(i,N){
        rep(j,N){
            cout << ( (row[i] == j) ? "Q" : ".");
        }
        cout << endl;
    }
    f = true;
}

void recursive(int i){
    if(i == N){
        printBoard();
        return;
    }

    rep(j,N){
        if(col[j] || dpos[i + j] || dneg[i - j + N - 1]) continue;
        row[i] = j;
        col[j] = dpos[i + j] = dneg[i - j + N - 1] = 1;
        recursive(i + 1);
        row[i] = col[j] = dpos[i + j] = dneg[i - j + N - 1] = 0;
        if(f) return;
    }
}

int main(){
    rep(i,8) cin >> x[i];

    init();
    recursive(0);
    if(not f) cout << "No Answer" << endl;
}
