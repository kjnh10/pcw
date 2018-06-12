#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);

    string s;
    cin >> s;

    for (int i = 0; i + 1 < sz(s); ++i) {
        if (s[i] == s[i + 1]) {
            cout << i + 1 << " " << i + 2 << '\n';
            return 0;
        }
    }

    for (int i = 0; i + 2 < sz(s); ++i) {
        if (s[i] == s[i + 2]) {
            cout << i + 1 << " " << i + 3 << "\n";
            return 0;
        }
    }
    cout << "-1 -1\n";

}
