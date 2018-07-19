#include <bits/stdc++.h>

using namespace std;

int main() {
    string A, B, C;
    cin >> A >> B >> C;

    if (A[A.size() - 1] == B[0] && B[B.size() - 1] == C[0]) puts("YES");
    else puts("NO");

    return 0;
}