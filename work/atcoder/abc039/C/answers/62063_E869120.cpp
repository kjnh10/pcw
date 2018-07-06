#include<iostream>
#include<string>
using namespace std;
string S[12]={"Do","","Re","","Mi","Fa","","So","","La","","Si"};
string T="WBWBWWBWBWBW";string U;
int main(){
    T+=T;T+=T;cin>>U;
    for(int i=0;i<12;i++){
        string H=T.substr(i,20);
        if(H==U)cout<<S[i]<<endl;
    }
    return 0;
}