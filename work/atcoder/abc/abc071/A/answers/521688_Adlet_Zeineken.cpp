#include <bits/stdc++.h>

using namespace std;

int x, a, b;

int main() {
    cin >> x >> a >> b;
    cout << (abs(x - a) < abs(x - b) ? "A" : "B");
}
