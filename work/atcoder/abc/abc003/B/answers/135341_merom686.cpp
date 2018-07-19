#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == t[i]) continue;
        if (t[i] == '@') swap(s[i], t[i]);
        if (s[i] == '@' && string("atcoder").find(t[i]) != string::npos) continue;

        cout << "You will lose" << endl;
        quick_exit(0);
    }

    cout << "You can win" << endl;

    return 0;
}
