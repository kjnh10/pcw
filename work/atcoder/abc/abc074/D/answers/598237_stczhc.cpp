#include <bits/stdc++.h>

using namespace std;

#define N 301
int n, mat[N][N], dirt[N][N], rmat[N][N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> mat[i][j];
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            dirt[i][j] = -1;
        dirt[i][i] = 0;
    }
    long long tot = 0;
    bool ook = true;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++) {
            int ok = 1;
            for (int k = 1; k <= n; k++)
                if (k != i && k != j) {
                    if (mat[i][k] + mat[j][k] < mat[i][j]) {
                        ok = -1;
                        break;
                    } else if (mat[i][k] + mat[j][k] == mat[i][j])
                        ok = 0;
                }
            if (ok == 1)
                tot += mat[i][j];
            else if (ok == -1) {
                ook = false;
                break;
            }
        }
    if (!ook) {
        cout << -1 << endl;
    } else {
        cout << tot << endl;
    }
    return 0;
}
