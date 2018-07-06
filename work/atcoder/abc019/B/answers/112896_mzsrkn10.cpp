#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int i=0;
    string ans = "";
    while(i < s.size()){
        int cnt = 1;
        while(s[i] == s[i+1]){
            ++cnt;
            ++i;
        }
        ans += s[i];
        ans += to_string(cnt);
        ++i;
    }
    cout << ans << endl;

    return 0;
}
