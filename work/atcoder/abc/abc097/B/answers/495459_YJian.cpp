#include <bits/stdc++.h>

using namespace std;

int a;
int res = 1;

int main() {
    cin >> a;
    for(int i = 2; i * i <= a; i++) {
        int k = i * i;
        while(k * i <= a) k *= i;
        res = max(res, k);
    }
    cout << res << endl;
    return 0;
}