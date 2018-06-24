#include <bits/stdc++.h>
using namespace std;

bool wolf[1<<20];
int n;
string s, ans;

bool tri(bool a0, bool a1) {
    wolf[0] = a0;
    wolf[1] = a1;
    for (int i = 2; i < n; i++) {
        if (wolf[i-1]) {
            if (s[i-1] == 'x') wolf[i] = wolf[i-2];
            else wolf[i] = !wolf[i-2];
        } else {
            if (s[i-1] == 'o') wolf[i] = wolf[i-2];
            else wolf[i] = !wolf[i-2];
        }
    }
    if (wolf[n-1]) {
        if (s[n-1] == 'o' && wolf[0] == wolf[n-2]) return false;
        if (s[n-1] == 'x' && wolf[0] != wolf[n-2]) return false;
    } else {
        if (s[n-1] == 'x' && wolf[0] == wolf[n-2]) return false;
        if (s[n-1] == 'o' && wolf[0] != wolf[n-2]) return false;
    }
    if (wolf[0]) {
        if (s[0] == 'o' && wolf[1] == wolf[n-1]) return false;
        if (s[0] == 'x' && wolf[1] != wolf[n-1]) return false;
    } else {
        if (s[0] == 'x' && wolf[1] == wolf[n-1]) return false;
        if (s[0] == 'o' && wolf[1] != wolf[n-1]) return false;
    }
    if (ans == "") {
        for (int i = 0; i < n; i++) {
            if (wolf[i]) ans += "W";
            else ans += "S";
        }
    }
}

int main() {
    //freopen("in.txt","r",stdin);
    cin >> n;
    getline(cin,s);
    getline(cin,s);
    wolf[0] = 1;
    wolf[1] = 1;
    if (tri(1,1) || tri(1,0) || tri(0,1) || tri(0,0)) cout << ans;
    else cout << -1;
	return 0;
}
