#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,l,tab=1,crash=0;
    string s;
    cin>>n>>l>>s;
    for(int i=0; i<n; i++){
        if(s[i]=='+')tab++;
        else tab--;
        if(tab>l){
            crash++;
            tab=1;
        }
    }
    cout<<crash<<endl;
    return 0;
}
