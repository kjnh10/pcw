#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int gpa(char c){
    if(c=='A') return 4;
    else if(c=='B') return 3;
    else if(c=='C') return 2;
    else if(c=='D') return 1;
    else return 0;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;cin>>n;
    string s;cin>>s;
    double res=0;
    for(int i=0;i<s.length();i++){
        res+=gpa(s[i]);
    }
    cout<<fixed<<setprecision(10)<<(res/n)<<endl;
}
