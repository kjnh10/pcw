#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int cnt=0;
    for(int i=0;i<12;i++){
        cin>>s;
        if(count(s.begin(),s.end(),'r')>=1){
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}