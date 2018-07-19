#include <bits/stdc++.h>
using namespace std;

template<class T> bool chmax(T &a, T b) {if (a < b) {a = b; return true;} else return false;}
template<class T> bool chmin(T &a, T b) {if (a > b) {a = b; return true;} else return false;}

int N, D, X, Y;

const int MAX_C = 1100;
double Com[MAX_C][MAX_C];
 
void calc_com() {
    for (int i = 0; i < MAX_C; ++i) for (int j = 0; j < MAX_C; ++j) Com[i][j] = 0.0;
    Com[0][0] = 1.0;
    for (int i = 1; i < MAX_C; ++i) {
        Com[i][0] = 1.0;
        for (int j = 1; j < MAX_C; ++j) {
            Com[i][j] = (Com[i-1][j-1] + Com[i-1][j]);
        }
    }
}

long double solve() {
  long double n4 = 1;
  for (int i = 0; i < N; ++i) n4 *= 4;
  
  X = abs(X);
  Y = abs(Y);
  if (X % D != 0) return 0;
  if (Y % D != 0) return 0;
  X /= D;
  Y /= D;

  if ( (N+X+Y) & 1 ) return 0.0;
  if ( N < X+Y ) return 0.0;
  int P = (N+X+Y)/2;
  int Q = (N-X-Y)/2;

  long double res = 0;
  for (int c = 0; c <= N; ++c) {
    if ( (N+X+Y) & 1 ) continue;
    int a = c+X;
    int b = (N - X + Y) / 2 - c;
    int d = (N - X - Y) / 2 - c;
    
    if (b < 0) continue;
    if (d < 0) continue;
    
    long double tmp = Com[a + b][a] * Com[c + d][c];
    res += tmp;
  }

  return res / n4 * Com[N][P];
}

int main() {
  calc_com();
  while (cin >> N >> D >> X >> Y) {
    cout << setprecision(15) << solve() << endl;
  }
}

