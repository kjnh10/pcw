#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

int n;
std::string s;

int main() {
    std::cin >> s;
    n = sz(s);
    if (((s[0] == s[n-1] ? 1 : 0) + (n%2)) % 2) printf("First\n");
    else printf("Second\n");
}
