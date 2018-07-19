#include<iostream>

using namespace std;

int main(){

    string S;
    cin>> S;

    string ans;
    for(int i=0; i<S.size(); i++){
        if(S[i]=='B'){
            if(!ans.empty()){
                ans.pop_back();
            }
        }else{
            ans+=S[i];
        }
    }

    cout<< ans<< endl;

    return 0;
}
