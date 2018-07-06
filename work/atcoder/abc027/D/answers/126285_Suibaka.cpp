#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string S;
    cin >> S;
    reverse(S.begin(), S.end());
    vector<int> v;
    int cnt = 0;
    for(int i=0; i<S.size(); ++i) {
        if(S[i] == 'M') {
            v.push_back(cnt);
        } else if(S[i] == '+') {
            cnt++;
        } else {
            cnt--;
        }
    }
    sort(v.rbegin(), v.rend());
    int res = 0;
    for(int i=0; i<v.size(); ++i) {
        if(i < v.size()/2) {
            res += v[i];
        } else {
            res -= v[i];
        }
    }
    cout << res << endl;
}
