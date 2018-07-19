#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> a;
    int n;cin>>n;
    for(int i=1; i<10; i++){
        string s;
        for(int j=0; j<6; j++){
            s+=(char)(i+'0');
            a.push_back(stoi(s));
        }
    }
    sort(a.begin(),a.end());
    cout<<a[n-1]<<endl;
    return 0;
}
