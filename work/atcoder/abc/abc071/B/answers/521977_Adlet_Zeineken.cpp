#include <bits/stdc++.h>

using namespace std;

string s;

map<char, int> mp;

int main() {
    cin >> s;
    for (auto it : s) {
        mp[it]++;
    }
    for (char it = 'a'; it <= 'z'; ++it) {
        if (!mp[it]) {
            cout << it;
            return 0;
        }
    }
    cout << "None";
}
