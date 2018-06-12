#include <iostream>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <vector>
#include <valarray>
#include <array>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <complex>
#include <random>

using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr int TEN(int n) {return (n==0)?1:10*TEN(n-1);}

const int MN = 1010;
int N, K;

double dp[MN][MN];
bool used[MN][MN];
double calc(int n, int k) {
    if (n == 0 or k == 0) return 0;
    if (used[n][k]) return dp[n][k];
    used[n][k] = true;
    int a = N-n;
    double ans = 0;
    ans += 1.0*a/(a+1) * calc(n-1, k);
    ans += 1.0/(a+1) * max(calc(n-1, k-1)+1.0*(a+1)/N, calc(n-1, k));
    return dp[n][k] = ans;
}

int main() {
    scanf("%d %d", &N, &K);
    printf("%.20lf\n", calc(N, K));
    return 0;
}