/*
ЗАПУСКАЕМ 
░ГУСЯ░▄▀▀▀▄░РАБОТЯГУ░░
▄███▀░◐░░░▌░░░░░░░
░░░░▌░░░░░▐░░░░░░░
░░░░▐░░░░░▐░░░░░░░
░░░░▌░░░░░▐▄▄░░░░░
░░░░▌░░░░▄▀▒▒▀▀▀▀▄
░░░▐░░░░▐▒▒▒▒▒▒▒▒▀▀▄
░░░▐░░░░▐▄▒▒▒▒▒▒▒▒▒▒▀▄
░░░░▀▄░░░░▀▄▒▒▒▒▒▒▒▒▒▒▀▄
░░░░░░▀▄▄▄▄▄█▄▄▄▄▄▄▄▄▄▄▄▀▄
░░░░░░░░░░░▌▌░▌▌░░░░░
░░░░░░░░░░░▌▌░▌▌░░░░░
░░░░░░░░░▄▄▌▌▄▌▌░░░░░ 
 */
#pragma GCC target("sse4,tune=native")
#pragma GCC optimize("O3","unroll-loops")
#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
    
     
using namespace std;
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; } 
template<typename T, typename U> inline ostream &operator<< (ostream &_out, const pair<T, U> &_p) { _out << _p.first << ' ' << _p.second; return _out; }
template<typename T, typename U> inline istream &operator>> (istream &_in, pair<T, U> &_p) { _in >> _p.first >> _p.second; return _in; }
template<typename T> inline ostream &operator<< (ostream &_out, const vector<T> &_v) { if (_v.empty()) { return _out; } _out << _v.front(); for (auto _it = ++_v.begin(); _it != _v.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T> inline istream &operator>> (istream &_in, vector<T> &_v) { for (auto &_i : _v) { _in >> _i; } return _in; }
template<typename T> inline ostream &operator<< (ostream &_out, const set<T> &_s) { if (_s.empty()) { return _out; } _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T> inline ostream &operator<< (ostream &_out, const multiset<T> &_s) { if (_s.empty()) { return _out; } _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T> inline ostream &operator<< (ostream &_out, const unordered_set<T> &_s) { if (_s.empty()) { return _out; } _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T> inline ostream &operator<< (ostream &_out, const unordered_multiset<T> &_s) { if (_s.empty()) { return _out; } _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T, typename U> inline ostream &operator<< (ostream &_out, const map<T, U> &_m) { if (_m.empty()) { return _out; } _out << '(' << _m.begin()->first << ": " << _m.begin()->second << ')'; for (auto _it = ++_m.begin(); _it != _m.end(); ++_it) { _out << ", (" << _it->first << ": " << _it->second << ')'; } return _out; }
template<typename T, typename U> inline ostream &operator<< (ostream &_out, const unordered_map<T, U> &_m) { if (_m.empty()) { return _out; } _out << '(' << _m.begin()->first << ": " << _m.begin()->second << ')'; for (auto _it = ++_m.begin(); _it != _m.end(); ++_it) { _out << ", (" << _it->first << ": " << _it->second << ')'; } return _out; }
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define left left228
#define right right228
#define next next228
#define rank rank228
#define prev prev228
#define y1 y1228                                                         
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
#define pb push_back
#define x first
#define y second   
const string FILENAME = "input";
//WULD! NAH! KEST!
const int MAXN = 20;

int h, w;
int p[MAXN];
string s[MAXN];
bool used[MAXN];
bool used1[MAXN];
bool was = false;
bool was1 = false;
int cnt = 0;
int heh = -2;
vector<int> gs;


void get1(int i) {
    if (i == w) {
        cout << "YES\n";
        exit(0);
    }
    if (used1[i]) {
        get1(i + 1);
    } else {
        for (int j = i + 1; j < w; j++) {
            if (!used1[j]) {
                used1[j] = true;
                used1[i] = true;
                bool bad = false;
                for (auto x: gs) {
                    if (s[x][i] != s[p[x]][j]) {
                        bad = true;
                        break;
                    }
                    if (s[x][j] != s[p[x]][i]) {
                        bad = true;
                        break;
                    }
                }
                if (heh != -2) {
                    if (s[heh][i] != s[heh][j]) {
                        bad = true;
                    }
                    if (s[heh][j] != s[heh][i]) {
                        bad = true;
                    }
                }
                if (!bad) {
                get1(i + 1);
                }
                used1[j] = false;
                used1[i] = false;
            }
        }
        if (w % 2 == 1 && !was1) {
            was1 = true;
            bool bad = false;
            for (auto x: gs) {
                if (s[x][i] != s[p[x]][i]) {
                    bad = true;
                    break;
                }
            }
            if (!bad) {
            get1(i + 1);
            }
            was1 = false;
        }
    }
}

void check() {
    get1(0);
}


void get(int i) {
    if (i == h) {
        check();
        return ;
    }
    if (used[i]) {
        get(i + 1);
    } else {
        for (int j = i + 1; j < h; j++) {
            if (!used[j]) {
                used[j] = true;
                used[i] = true;
                p[i] = j;
                p[j] = i;
                gs.pb(i);
                get(i + 1);
                gs.pop_back();
                used[j] = false;
                used[i] = false;
            }
        }
        if (h % 2 == 1 && !was) {
            was = true;
            p[i] = -1;
            heh = i;
            get(i + 1);
            was = false;
        }
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
   // read(FILENAME);
    cin >> h >> w;
    for (int i = 0; i < h; i++) {
        cin >> s[i];
    }
    get(0);
    cout << "NO\n";
    return 0;     
}
