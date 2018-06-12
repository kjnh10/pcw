#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int num=stoi(s);
    int digit_sum=0;
    for(int i=0; i<s.size(); i++){
        digit_sum+=(s[i]-'0');
    }
    bool flag1=!(num%2==0)&&!(num%5==0),
        flag2=digit_sum%3!=0;
    if(flag1&&flag2&&num!=1||num==2||num==3||num==5)cout<<"Prime"<<endl;
    else cout<<"Not Prime"<<endl;
    return 0;
}
