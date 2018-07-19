#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <limits>
#include <map>
#include <stack>
#include <map>
#include <unordered_map>
#define REP(i,n) for(long (i)=0;(i)<(n);(i)++)
#define REPI(i,a,b) for(long (i)=(a);(i)<(b);(i)++)
#define INF numeric_limits<double>::infinity()
constexpr long MOD = 1e9 + 7;
using namespace std;
using P = pair<long, long>;
using VI = vector<long>;

/*
 
 ######.
 #......
 ######.
 #......
 ######.
 
 */

int board[100][100];

void printb() {
    REP(i,100) {
        REP(j,100) {
            if (board[i][j]) {
                cout << "#";
            } else {
                cout << ".";
            }
        }
        cout << endl;
    }
}

int main() {
    REP(i,100) {
        if (i % 2 == 0) {
            REP(j,99) board[i][j] = 1;
        } else {
            board[i][0] = 1;
        }
    }
//    printb();
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    cout << 100 << " " << 100 << endl;
    int x = 1, y = 2;
    while (a) {
        board[x][y] = 1;
        if (y > 40) {
            y = 2;
            x += 2;
        } else {
            y += 2;
        }
        a--;
    }
    
    x = 0; y = 97;
    while (b) {
        board[x][y] = 0;
        if (y < 50) {
            y = 97;
            x += 2;
        } else {
            y -= 2;
        }
        b--;
    }
    printb();
}
