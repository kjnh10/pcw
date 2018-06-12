#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    map<string,char> henkan;
    henkan["Left"]='<',henkan["Right"]='>',henkan["AtCoder"]='A';
    getline(cin,s);
    int i=0;
    bool flag=false;
    while(true){
        string str;
        int j=0;
        while(s[i+j]!=' '){
            str+=s[i+j];
            j++;
            if(i+j==s.size()){
                flag=true;
                break;
            }
        }
        if(henkan[str]!=NULL){
            if(i!=0){
                cout<<' ';
            }
            cout<<henkan[str];
        }
        if(flag)break;
        i+=j+1;
    }
    cout<<endl;
    return 0;
}
