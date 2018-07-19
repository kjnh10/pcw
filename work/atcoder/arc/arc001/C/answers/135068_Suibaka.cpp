#include <iostream>
#include <vector>
#include <string>
using namespace std;

int f(int i, int j) {
    int res = i - j;
    if(res < 0) {
        res = abs(res) + 7;
    }
    return res;
}

bool solve(vector<string>& v, int i, vector<bool>& tate, vector<bool>& yoko, vector<bool>& naname1, vector<bool>& naname2) {
    if(i == 8) {
        return true;
    }
    if(tate[i]) {
        return solve(v, i+1, tate, yoko, naname1, naname2);
    }
    for(int j=0; j<8; ++j) {
        if(!yoko[j] && !naname1[f(i, j)] && !naname2[i+j]) {
            v[i][j] = 'Q';
            tate[i] = yoko[j] = naname1[f(i, j)] = naname2[i+j] = true;
            if(solve(v, i+1, tate, yoko, naname1, naname2)) {
                return true;
            }
            v[i][j] = '.';
            tate[i] = yoko[j] = naname1[f(i, j)] = naname2[i+j] = false;
        }
    }
    return false;
}

int main() {
    vector<string> v(8);
    for(int i=0; i<8; ++i) {
        cin >> v[i];
    }
    vector<bool> tate(8), yoko(8), naname1(15), naname2(15);
    for(int i=0; i<8; ++i) {
        for(int j=0; j<8; ++j) {
            if(v[i][j] == 'Q') {
                if(tate[i] || yoko[j] || naname1[f(i, j)] || naname2[i+j]) {
                    cout << "No Answer" << endl;
                    return 0;
                }
                tate[i] = yoko[j] = naname1[f(i, j)] = naname2[i+j] = true;
            }
        }
    }
    if(solve(v, 0, tate, yoko, naname1, naname2)) {
        for(auto& x : v) {
            cout << x << endl;
        }
    } else {
        cout << "No Answer" << endl;
    }
}
